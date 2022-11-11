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

#define ENABLE_DEBUG

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
			if(sim->debug_dispatch0) {
				fprintf(stdout, "dispatch0: pc: %08x,  ptr: 0x%02x", sim->debug_dispatch0_pc, sim->debug_dispatch0_ptr);
				if(sim->debug_dispatch0_rd_valid) {
					fprintf(stdout, ", ");
					fprintf(stdout, "prd: 0x%02x", sim->debug_dispatch0_prd);
				}
				if(sim->debug_dispatch0_rs1_valid) {
					fprintf(stdout, ", ");
					fprintf(stdout, "prs1: 0x%02x", sim->debug_dispatch0_prs1);
				}
				fprintf(stdout, ", ");
				fprintf(stdout, "rs1_sel: %s, rs1_data: 0x%08x", rs1_sel_str[sim->debug_dispatch0_rs1_sel&0x3], sim->debug_dispatch0_rs1_data);
				if(sim->debug_dispatch0_rs2_valid) {
					fprintf(stdout, ", ");
					fprintf(stdout, "prs2: 0x%02x", sim->debug_dispatch0_prs2);
				}
				fprintf(stdout, ", ");
				fprintf(stdout, "rs2_sel: %s, rs2_data: 0x%08x", rs2_sel_str[sim->debug_dispatch0_rs2_sel&0x3], sim->debug_dispatch0_rs2_data);
				fprintf(stdout, "\n");
			}
			if(sim->debug_dispatch1) {
				fprintf(stdout, "dispatch1: pc: %08x,  ptr: 0x%02x", sim->debug_dispatch1_pc, sim->debug_dispatch1_ptr);
				if(sim->debug_dispatch1_rd_valid) {
					fprintf(stdout, ", ");
					fprintf(stdout, "prd: 0x%02x", sim->debug_dispatch1_prd);
				}
				if(sim->debug_dispatch1_rs1_valid) {
					fprintf(stdout, ", ");
					fprintf(stdout, "prs1: 0x%02x", sim->debug_dispatch1_prs1);
				}
				fprintf(stdout, ", ");
				fprintf(stdout, "rs1_sel: %s, rs1_data: 0x%08x", rs1_sel_str[sim->debug_dispatch1_rs1_sel&0x3], sim->debug_dispatch1_rs1_data);
				if(sim->debug_dispatch1_rs2_valid) {
					fprintf(stdout, ", ");
					fprintf(stdout, "prs2: 0x%02x", sim->debug_dispatch1_prs2);
				}
				fprintf(stdout, ", ");
				fprintf(stdout, "rs2_sel: %s, rs2_data: 0x%08x", rs2_sel_str[sim->debug_dispatch1_rs2_sel&0x3], sim->debug_dispatch1_rs2_data);
				fprintf(stdout, "\n");
			}
			if(sim->debug_rename0) {
				fprintf(stdout, "rename: pc: %08x, inst: DASM(%08x), ptr: 0x%02x", sim->debug_rename0_pc, sim->debug_rename0_inst, sim->debug_rename0_ptr);
				if(sim->debug_rename0_rd_valid) {
					fprintf(stdout, ", ");
					fprintf(stdout, "prd: 0x%02x, pprd: 0x%02x", sim->debug_rename0_prd, sim->debug_rename0_pprd);
				}
				if(sim->debug_rename0_rs1_valid) {
					fprintf(stdout, ", ");
					fprintf(stdout, "rs1_ready: %s, prs1: 0x%02x", sim->debug_rename0_rs1_ready ? "true" : "false", sim->debug_rename0_prs1);
				}
				if(sim->debug_rename0_rs2_valid) {
					fprintf(stdout, ", ");
					fprintf(stdout, "rs2_ready: %s, prs2: 0x%02x", sim->debug_rename0_rs2_ready ? "true" : "false", sim->debug_rename0_prs2);
				}
				fprintf(stdout, "\n");
			}
			if(sim->debug_rename1) {
				fprintf(stdout, "rename: pc: %08x, inst: DASM(%08x), ptr: 0x%02x", sim->debug_rename1_pc, sim->debug_rename1_inst, sim->debug_rename1_ptr);
				if(sim->debug_rename1_rd_valid) {
					fprintf(stdout, ", ");
					fprintf(stdout, "prd: 0x%02x, pprd: 0x%02x", sim->debug_rename1_prd, sim->debug_rename1_pprd);
				}
				if(sim->debug_rename1_rs1_valid) {
					fprintf(stdout, ", ");
					fprintf(stdout, "rs1_ready: %s, prs1: 0x%02x", sim->debug_rename1_rs1_ready ? "true" : "false", sim->debug_rename1_prs1);
				}
				if(sim->debug_rename1_rs2_valid) {
					fprintf(stdout, ", ");
					fprintf(stdout, "rs2_ready: %s, prs2: 0x%02x", sim->debug_rename1_rs2_ready ? "true" : "false", sim->debug_rename1_prs2);
				}
				fprintf(stdout, "\n");
			}
			if(sim->debug_commit0) {
				fprintf(stdout, "commit: pc: %08x, inst: DASM(%08x), ptr: 0x%02x, killed: %s", sim->debug_commit_pc0, sim->debug_commit_inst0, sim->debug_commit_ptr0, sim->debug_commit_kill0 ? "true" : "false");
				if(sim->debug_commit_rd_valid0) {
					fprintf(stdout, ", ");
					fprintf(stdout, "dreg: 0x%02x, preg: 0x%02x, ppreg: 0x%02x", sim->debug_commit_dreg0, sim->debug_commit_preg0, sim->debug_commit_ppreg0);
				}
				fprintf(stdout, "\n");
			}
			if(sim->debug_commit1) {
				fprintf(stdout, "commit: pc: %08x, inst: DASM(%08x), ptr: 0x%02x, killed: %s", sim->debug_commit_pc1, sim->debug_commit_inst1, sim->debug_commit_ptr1, sim->debug_commit_kill1 ? "true" : "false");
				if(sim->debug_commit_rd_valid1) {
					fprintf(stdout, ", ");
					fprintf(stdout, "dreg: 0x%02x, preg: 0x%02x, ppreg: 0x%02x", sim->debug_commit_dreg1, sim->debug_commit_preg1, sim->debug_commit_ppreg1);
				}
				fprintf(stdout, "\n");
			}
			if(sim->debug_flush) {
				fprintf(stdout, "flush: %08x\n", sim->debug_flush_newpc);
			}
			if(sim->debug_rewind0) {
				fprintf(stdout, "rewind: dreg: %02x, preg: %02x, ppreg: %02x\n", sim->debug_rewind0_dreg, sim->debug_rewind0_preg, sim->debug_rewind0_ppreg);
			}
			if(sim->debug_rewind1) {
				fprintf(stdout, "rewind: dreg: %02x, preg: %02x, ppreg: %02x\n", sim->debug_rewind1_dreg, sim->debug_rewind1_preg, sim->debug_rewind1_ppreg);
			}
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
