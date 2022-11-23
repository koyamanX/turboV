#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <elf.h>
#include <sys/stat.h>
#include <assert.h>
#include <string.h>
#include "VturboVSim.h"
#include "VturboVSim___024root.h"
#include "verilated_vcd_c.h"
#include "VturboVSim.h"
#include "version.h"
#include <nlohmann/json.hpp>
#include <iomanip>
#include <iostream>
#include <fstream>

#define ENABLE_DEBUG

using ordered_json = nlohmann::ordered_json;

const char *rs1_sel_str[] = {
    "REG",
    "UIMM",
    "PC",
    "UNIMP"
};
const char *rs2_sel_str[] = {
    "REG",
    "IMM",
    "CSR",
    "CSR_UIMM"
};

std::string to_hex(uint64_t v, uint64_t w) {
    std::ostringstream ss;
    ss << "0x" << std::setfill('0') << std::setw(w) << std::hex << v;
    return ss.str();
}

std::string to_hex(uint64_t v) {
    std::ostringstream ss;
    ss << "0x" << std::hex << v;
    return ss.str();
}

template <typename Sim_t, typename Trace_t>
class Simulator {
public:
    Simulator(void) {
        tfp = new Trace_t();
        sim = new Sim_t();
        sim->trace(tfp, 99);
        tfp->open("turboVSim.vcd");
    }
    ~Simulator(void) {
        tfp->close();
        free(mem);
        delete sim;
        delete tfp;
    }
    void Tick(void) {
        sim->p_reset = p_reset;
        sim->m_clock = m_clock;
        m_clock = !m_clock;
        sim->eval();
        tfp->dump(m_clock_count);
        m_clock_count++;
        sim->p_reset = p_reset;
        sim->m_clock = m_clock;
        m_clock = !m_clock;
        sim->eval();
        tfp->dump(m_clock_count);
        m_clock_count++;
    }
    void Reset(void) {
        p_reset = true;
        m_clock = true;
        Tick();
        p_reset = false;
        Tick();
        sim->reset = true;
        Tick();
        sim->reset = false;
    }
    uint8_t *LoadElf(const char *path) {
        int fd;
        uint8_t *buf;
        Elf32_Ehdr *ehdr;
        Elf32_Phdr *phdr;
        struct stat st;

        fd = open(path, O_RDONLY);
        if(fd < 0) {
            perror("open");
            exit(1);
        }
        if(fstat(fd, &st) < 0) {
            perror("fstat");
            exit(1);
        }
        buf = (uint8_t *)mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
        if(buf == MAP_FAILED) {
            perror("mmap");
            exit(1);
        }
        ehdr = (Elf32_Ehdr *)buf;
        assert(ehdr->e_ident[0] == ELFMAG0);
        assert(ehdr->e_ident[1] == ELFMAG1);
        assert(ehdr->e_ident[2] == ELFMAG2);
        assert(ehdr->e_ident[3] == ELFMAG3);
        assert(ehdr->e_ident[4] == ELFCLASS32);
        assert(ehdr->e_ident[5] == ELFDATA2LSB);
        assert(ehdr->e_ident[6] == EV_CURRENT);
        assert(ehdr->e_type == ET_EXEC);
        assert(ehdr->e_machine == EM_RISCV);

        phdr = (Elf32_Phdr *)(buf + ehdr->e_phoff);
        mem = (uint8_t *)calloc(mem_size, sizeof(uint8_t));
        for(int i = 0; i < ehdr->e_phnum; i++) {
            if(phdr->p_type == PT_LOAD) {
                assert(0x80000000 <= phdr->p_vaddr && phdr->p_vaddr+phdr->p_memsz < 0x80000000+mem_size);
                memcpy((mem+phdr->p_vaddr-0x80000000), buf+phdr->p_offset, phdr->p_filesz);
            }
            phdr++;
        }
        munmap(buf, st.st_size);
        close(fd);

        return mem;
    }
    inline uint8_t read_byte(uint64_t addr) {
        uint8_t ret = 0;

        ret |= (uint8_t)mem[addr+0] << 0;

        return ret;
    }
    inline uint16_t read_halfword(uint64_t addr) {
        uint16_t ret = 0;

        ret |= (uint16_t)mem[addr+1] << 8;
        ret |= (uint16_t)mem[addr+0] << 0;

        return ret;
    }
    inline uint32_t read_word(uint64_t addr) {
        uint32_t ret = 0;

        ret |= (uint32_t)mem[addr+3] << 24;
        ret |= (uint32_t)mem[addr+2] << 16;
        ret |= (uint32_t)mem[addr+1] << 8;
        ret |= (uint32_t)mem[addr+0] << 0;

        return ret;
    }
    inline uint64_t read_dword(uint64_t addr) {
        uint64_t ret = 0;

        ret |= (uint64_t)mem[addr+7] << 56;
        ret |= (uint64_t)mem[addr+6] << 48;
        ret |= (uint64_t)mem[addr+5] << 40;
        ret |= (uint64_t)mem[addr+4] << 32;
        ret |= (uint64_t)mem[addr+3] << 24;
        ret |= (uint64_t)mem[addr+2] << 16;
        ret |= (uint64_t)mem[addr+1] << 8;
        ret |= (uint64_t)mem[addr+0] << 0;

        return ret;
    }
    inline void write_byte(uint64_t addr, uint8_t data) {
        mem[addr+0] = data;
    }
    inline void write_halfword(uint64_t addr, uint16_t data) {
        mem[addr+1] = data << 8;
        mem[addr+0] = data << 0;
    }
    inline void write_word(uint64_t addr, uint32_t data) {
        mem[addr+3] = data << 24;
        mem[addr+2] = data << 16;
        mem[addr+1] = data << 8;
        mem[addr+0] = data << 0;
    }
    inline void write_dword(uint64_t addr, uint64_t data) {
        mem[addr+7] = data << 56;
        mem[addr+6] = data << 48;
        mem[addr+5] = data << 40;
        mem[addr+4] = data << 32;
        mem[addr+3] = data << 24;
        mem[addr+2] = data << 16;
        mem[addr+1] = data << 8;
        mem[addr+0] = data << 0;
    }
    uint8_t Run(void) {
        while(1) {
#ifdef ENABLE_DEBUG
            ordered_json j;
            j["cycle"] = m_clock_count >> 1;
            if(sim->debug_decode0) {
                j["stages"]["decode0"]["pc"] = to_hex(sim->debug_decode0_pc, 8);
                j["stages"]["decode0"]["inst"] = to_hex(sim->debug_decode0_inst, 8);
                j["stages"]["decode0"]["pred"] = sim->debug_decode0_pred == true;
            }
            if(sim->debug_decode1) {
                j["stages"]["decode1"]["pc"] = to_hex(sim->debug_decode1_pc, 8);
                j["stages"]["decode1"]["inst"] = to_hex(sim->debug_decode1_inst, 8);
                j["stages"]["decode1"]["pred"] = sim->debug_decode1_pred == true;
            }
            if(sim->debug_rename0) {
                j["stages"]["rename0"]["pc"] = to_hex(sim->debug_rename0_pc, 8);
                j["stages"]["rename0"]["ptr"] = to_hex(sim->debug_rename0_ptr, 2);
                j["stages"]["rename0"]["inst"] = "DASM(" + to_hex(sim->debug_rename0_inst, 8) + ")";
                j["stages"]["rename0"]["cause"] = to_hex(sim->debug_rename0_cause, 8);
                j["stages"]["rename0"]["imm"] = to_hex(sim->debug_rename0_imm, 8);
                if(sim->debug_rename0_rd_valid) {
                    j["stages"]["rename0"]["prd"] = to_hex(sim->debug_rename0_prd, 2);
                    j["stages"]["rename0"]["pprd"] = to_hex(sim->debug_rename0_pprd, 2);
                }
                if(sim->debug_rename0_rs1_valid) {
                    j["stages"]["rename0"]["rs1_ready"] = sim->debug_rename0_rs1_ready == true;
                    j["stages"]["rename0"]["prs1"] = to_hex(sim->debug_rename0_prs1, 2);
                }
                if(sim->debug_rename0_rs2_valid) {
                    j["stages"]["rename0"]["rs2_ready"] = sim->debug_rename0_rs2_ready == true;
                    j["stages"]["rename0"]["prs2"] = to_hex(sim->debug_rename0_prs2, 2);
                }
            }
            if(sim->debug_rename1) {
                j["stages"]["rename1"]["pc"] = to_hex(sim->debug_rename1_pc, 8);
                j["stages"]["rename1"]["ptr"] = to_hex(sim->debug_rename1_ptr, 2);
                j["stages"]["rename1"]["inst"] = "DASM(" + to_hex(sim->debug_rename1_inst, 8) + ")";
                j["stages"]["rename1"]["cause"] = to_hex(sim->debug_rename1_cause, 8);
                j["stages"]["rename1"]["imm"] = to_hex(sim->debug_rename1_imm, 8);
                if(sim->debug_rename1_rd_valid) {
                    j["stages"]["rename1"]["prd"] = to_hex(sim->debug_rename1_prd, 2);
                    j["stages"]["rename1"]["pprd"] = to_hex(sim->debug_rename1_pprd, 2);
                }
                if(sim->debug_rename1_rs1_valid) {
                    j["stages"]["rename1"]["rs1_ready"] = sim->debug_rename1_rs1_ready == true;
                    j["stages"]["rename1"]["prs1"] = to_hex(sim->debug_rename1_prs1, 2);
                }
                if(sim->debug_rename1_rs2_valid) {
                    j["stages"]["rename1"]["rs2_ready"] = sim->debug_rename1_rs2_ready == true;
                    j["stages"]["rename1"]["prs2"] = to_hex(sim->debug_rename1_prs2, 2);
                }
            }
            if(sim->debug_dispatch0) {
                j["stages"]["dispatch0"]["ptr"] = to_hex(sim->debug_dispatch0_ptr, 2);
                j["stages"]["dispatch0"]["pc"] = to_hex(sim->debug_dispatch0_pc, 8);

                if(sim->debug_dispatch0_rd_valid) {
                    j["stages"]["dispatch0"]["prd"] = to_hex(sim->debug_dispatch0_prd, 2);
                }
                if(sim->debug_dispatch0_rs1_valid) {
                    j["stages"]["dispatch0"]["prs1"] = to_hex(sim->debug_dispatch0_prs1, 2);
                }
                j["stages"]["dispatch0"]["rs1_sel"] = rs1_sel_str[sim->debug_dispatch0_rs1_sel&0x3];
                j["stages"]["dispatch0"]["rs1_data"] = to_hex(sim->debug_dispatch0_rs1_data, 8);
                if(sim->debug_dispatch0_rs2_valid) {
                    j["stages"]["dispatch0"]["prs2"] = to_hex(sim->debug_dispatch0_prs2, 2);
                }
                j["stages"]["dispatch0"]["rs2_sel"] = rs2_sel_str[sim->debug_dispatch0_rs2_sel&0x3];
                j["stages"]["dispatch0"]["rs2_data"] = to_hex(sim->debug_dispatch0_rs2_data, 8);
            }
            if(sim->debug_dispatch1) {
                j["stages"]["dispatch1"]["ptr"] = to_hex(sim->debug_dispatch1_ptr, 2);
                j["stages"]["dispatch1"]["pc"] = to_hex(sim->debug_dispatch1_pc, 8);

                if(sim->debug_dispatch1_rd_valid) {
                    j["stages"]["dispatch1"]["prd"] = to_hex(sim->debug_dispatch1_prd, 2);
                }
                if(sim->debug_dispatch1_rs1_valid) {
                    j["stages"]["dispatch1"]["prs1"] = to_hex(sim->debug_dispatch1_prs1, 2);
                }
                j["stages"]["dispatch1"]["rs1_sel"] = rs1_sel_str[sim->debug_dispatch1_rs1_sel&0x3];
                j["stages"]["dispatch1"]["rs1_data"] = to_hex(sim->debug_dispatch1_rs1_data, 8);
                if(sim->debug_dispatch1_rs2_valid) {
                    j["stages"]["dispatch1"]["prs2"] = to_hex(sim->debug_dispatch1_prs2, 8);
                }
                j["stages"]["dispatch1"]["rs2_sel"] = rs2_sel_str[sim->debug_dispatch1_rs2_sel&0x3];
                j["stages"]["dispatch1"]["rs2_data"] = to_hex(sim->debug_dispatch1_rs2_data, 8);
            }
            if(sim->debug_dispatch2) {
                j["stages"]["dispatch2"]["ptr"] = to_hex(sim->debug_dispatch2_ptr, 2);
                j["stages"]["dispatch2"]["pc"] = to_hex(sim->debug_dispatch2_pc, 8);

                if(sim->debug_dispatch2_rd_valid) {
                    j["stages"]["dispatch2"]["prd"] = to_hex(sim->debug_dispatch2_prd, 2);
                }
                if(sim->debug_dispatch2_rs1_valid) {
                    j["stages"]["dispatch2"]["prs1"] = to_hex(sim->debug_dispatch2_prs1, 2);
                }
                j["stages"]["dispatch2"]["rs1_sel"] = rs1_sel_str[sim->debug_dispatch2_rs1_sel&0x3];
                j["stages"]["dispatch2"]["rs1_data"] = to_hex(sim->debug_dispatch2_rs1_data, 8);
                if(sim->debug_dispatch2_rs2_valid) {
                    j["stages"]["dispatch2"]["prs2"] = to_hex(sim->debug_dispatch2_prs2, 2);
                }
                j["stages"]["dispatch2"]["rs2_sel"] = rs2_sel_str[sim->debug_dispatch2_rs2_sel&0x3];
                j["stages"]["dispatch2"]["rs2_data"] = to_hex(sim->debug_dispatch2_rs2_data, 8);
            }
            if(sim->debug_execute0) {
                j["stages"]["execute0"]["ptr"] = to_hex(sim->debug_execute0_ptr, 2);
                if(sim->debug_execute0_rd_valid) {
                    j["stages"]["execute0"]["prd"] = to_hex(sim->debug_execute0_prd, 2);
                }
                j["stages"]["execute0"]["a"] = to_hex(sim->debug_execute0_a, 8);
                j["stages"]["execute0"]["b"] = to_hex(sim->debug_execute0_b, 8);
                j["stages"]["execute0"]["q"] = to_hex(sim->debug_execute0_q, 8);
                j["stages"]["execute0"]["addr"] = to_hex(sim->debug_execute0_addr, 8);
            }
            if(sim->debug_execute1) {
                j["stages"]["execute1"]["ptr"] = to_hex(sim->debug_execute1_ptr, 2);
                if(sim->debug_execute1_rd_valid) {
                    j["stages"]["execute1"]["prd"] = to_hex(sim->debug_execute1_prd, 2);
                }
                j["stages"]["execute1"]["a"] = to_hex(sim->debug_execute1_a, 8);
                j["stages"]["execute1"]["b"] = to_hex(sim->debug_execute1_b, 8);
                j["stages"]["execute1"]["q"] = to_hex(sim->debug_execute1_q, 8);
                j["stages"]["execute1"]["addr"] = to_hex(sim->debug_execute1_addr, 8);
            }
            if(sim->debug_execute2) {
                j["stages"]["execute2"]["ptr"] = to_hex(sim->debug_execute2_ptr, 2);
                if(sim->debug_execute2_rd_valid) {
                    j["stages"]["execute2"]["prd"] = to_hex(sim->debug_execute2_prd, 2);
                }
                j["stages"]["execute2"]["a"] = to_hex(sim->debug_execute2_a, 8);
                j["stages"]["execute2"]["b"] = to_hex(sim->debug_execute2_b, 8);
                j["stages"]["execute2"]["data"] = to_hex(sim->debug_execute2_data, 8);
            }
            if(sim->debug_writeback0) {
                j["stages"]["writeback0"]["ptr"] = to_hex(sim->debug_writeback0_ptr, 2);
                if(sim->debug_writeback0_rd_valid) {
                    j["stages"]["writeback0"]["prd"] = to_hex(sim->debug_writeback0_prd, 2);
                }
                j["stages"]["writeback0"]["q"] = to_hex(sim->debug_writeback0_q, 8);
                j["stages"]["writeback0"]["target"] = to_hex(sim->debug_writeback0_target, 8);
            }
            if(sim->debug_writeback1) {
                j["stages"]["writeback1"]["ptr"] = to_hex(sim->debug_writeback1_ptr, 2);
                if(sim->debug_writeback1_rd_valid) {
                    j["stages"]["writeback1"]["prd"] = to_hex(sim->debug_writeback1_prd, 2);
                }
                j["stages"]["writeback1"]["q"] = to_hex(sim->debug_writeback1_q, 8);
                j["stages"]["writeback1"]["target"] = to_hex(sim->debug_writeback1_target, 8);
            }
            if(sim->debug_writeback2) {
                j["stages"]["writeback2"]["ptr"] = to_hex(sim->debug_writeback2_ptr, 2);
                if(sim->debug_writeback2_rd_valid) {
                    j["stages"]["writeback2"]["prd"] = to_hex(sim->debug_writeback2_prd, 2);
                }
                j["stages"]["writeback2"]["data"] = to_hex(sim->debug_writeback2_data, 8);
            }
            if(sim->debug_commit0) {
                j["stages"]["commit0"]["pc"] = to_hex(sim->debug_commit_pc0, 8);
                j["stages"]["commit0"]["inst"] = "DASM(" + to_hex(sim->debug_commit_inst0, 8) + ")";
                j["stages"]["commit0"]["ptr"] = to_hex(sim->debug_commit_ptr0, 2);
                j["stages"]["commit0"]["cause"] = to_hex(sim->debug_commit_cause0, 8);
                j["stages"]["commit0"]["killed"] = sim->debug_commit_kill0 == true;
                if(sim->debug_commit_rd_valid0) {
                    j["stages"]["commit0"]["dreg"] = to_hex(sim->debug_commit_dreg0, 2);
                    j["stages"]["commit0"]["preg"] = to_hex(sim->debug_commit_preg0, 2);
                    j["stages"]["commit0"]["ppreg"] = to_hex(sim->debug_commit_ppreg0, 2);
                }
            }
            if(sim->debug_commit1) {
                j["stages"]["commit1"]["pc"] = to_hex(sim->debug_commit_pc1, 8);
                j["stages"]["commit1"]["inst"] = "DASM(" + to_hex(sim->debug_commit_inst1, 8) + ")";
                j["stages"]["commit1"]["ptr"] = to_hex(sim->debug_commit_ptr1, 2);
                j["stages"]["commit1"]["cause"] = to_hex(sim->debug_commit_cause1, 8);
                j["stages"]["commit1"]["killed"] = sim->debug_commit_kill1 == true;
                if(sim->debug_commit_rd_valid0) {
                    j["stages"]["commit1"]["dreg"] = to_hex(sim->debug_commit_dreg1, 2);
                    j["stages"]["commit1"]["preg"] = to_hex(sim->debug_commit_preg1, 2);
                    j["stages"]["commit1"]["ppreg"] = to_hex(sim->debug_commit_ppreg1, 2);
                }
            }
            if(sim->debug_flush) {
                j["flush"]["newpc"] = to_hex(sim->debug_flush_newpc, 8);
            }
            if(sim->debug_rewind0) {
                j["stages"]["rewind0"]["dreg"] = to_hex(sim->debug_rewind0_dreg, 2);
                j["stages"]["rewind0"]["preg"] = to_hex(sim->debug_rewind0_preg, 2);
                j["stages"]["rewind0"]["ppreg"] = to_hex(sim->debug_rewind0_ppreg, 2);
            }
            if(sim->debug_rewind1) {
                j["stages"]["rewind1"]["dreg"] = to_hex(sim->debug_rewind1_dreg, 2);
                j["stages"]["rewind1"]["preg"] = to_hex(sim->debug_rewind1_preg, 2);
                j["stages"]["rewind1"]["ppreg"] = to_hex(sim->debug_rewind1_ppreg, 2);
            }

            std::cout << std::setw(4) << j << std::endl;
#endif
            sim->rsp_error = false;
            sim->rsp_retry = false;
            sim->rsp_stall = false;
            sim->rsp_valid = false;
            if(sim->req_read) {
                assert(0x80000000 <= sim->req_addr && sim->req_addr < 0x80000000+mem_size);
                if(sim->req_sel == 0xff) {
                    sim->rsp_data = read_dword(sim->req_addr-0x80000000);
                } else if(sim->req_sel == 0x0f) {
                    sim->rsp_data = read_word(sim->req_addr-0x80000000);
                } else if(sim->req_sel == 0x03) {
                    sim->rsp_data = read_halfword(sim->req_addr-0x80000000);
                } else if(sim->req_sel == 0x01) {
                    sim->rsp_data = read_byte(sim->req_addr-0x80000000);
                }
                sim->rsp_valid = true;
            }
            if(sim->req_write) {
                assert(0x80000000 <= sim->req_addr && sim->req_addr < 0x80000000+mem_size);
                if(sim->req_sel == 0xff) {
                    write_dword(sim->req_addr-0x80000000, sim->req_data);
                } else if(sim->req_sel == 0x0f) {
                    write_word(sim->req_addr-0x80000000, sim->req_data);
                } else if(sim->req_sel == 0x03) {
                    write_halfword(sim->req_addr-0x80000000, sim->req_data);
                } else if(sim->req_sel == 0x01) {
                    write_byte(sim->req_addr-0x80000000, sim->req_data);
                }
                sim->rsp_valid = true;
                if(sim->req_addr == 0x80001000) {
                    sim_result = sim->req_data;
                    Tick();
                    break;
                }
            }
            Tick();
        }
        return (sim_result == 1) ? 0 : sim_result;
    }
private:
    uint32_t sim_result = 0;
    bool m_clock = false;
    bool p_reset = false;
    uint64_t m_clock_count = 0;
    Trace_t *tfp;
    Sim_t *sim;
    uint8_t *mem = NULL;
    const size_t mem_size = 64*1024*1024;
};

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    Simulator<VturboVSim, VerilatedVcdC> sim;

    if(argc != 2) {
        fprintf(stdout, "turboVSim %s.%s.%s\n", MAJOR_VERSION, MINOR_VERSION, REVISION);
        fprintf(stderr, "Insufficient arguments\n");
        exit(EXIT_FAILURE);
    }

    sim.LoadElf(argv[1]);
    sim.Reset();
    return sim.Run();
}
