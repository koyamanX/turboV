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
bool m_clock = false;
bool p_reset = false;
uint64_t m_clock_count = 0;
Trace_t *tfp;
Sim_t *sim;
};
int main(int argc, char **argv) {
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);
    int fd;
    uint8_t *buf;
    Elf32_Ehdr *ehdr;
    Elf32_Phdr *phdr;
    struct stat st;
    uint8_t *mem;
    size_t mem_size = 1*1024*1024;
    Simulator<VturboVSim, VerilatedVcdC> sim;
    bool sim_done = false;
    uint32_t sim_done_cnt = 0;
    uint32_t sim_done_result = 0;

    if(argc != 2) {
        fprintf(stderr, "Insufficient arguments\n");
        exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);
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

#if ELF_TXT_DUMP
    FILE *fp = fopen("elf.dump", "w");
    for(size_t i = 0; i < mem_size-4; i+=4) {
        fprintf(fp, "%08lx: %08x\n", i, *((uint32_t *) &mem[i]));
    }
    fclose(fp);
#endif

    sim.Reset();
    while(1) {
        sim.sim->rsp_error = false;
        sim.sim->rsp_retry = false;
        sim.sim->rsp_stall = false;
        sim.sim->rsp_valid = false;
        if(sim.sim->req_read) {
            assert(0x80000000 <= sim.sim->req_addr && sim.sim->req_addr < 0x80000000+mem_size-sizeof(uint64_t));
            sim.sim->rsp_data = *((uint64_t *)&mem[sim.sim->req_addr-0x80000000]);
            sim.sim->rsp_valid = true;
        }
        if(sim.sim->req_write) {
            assert("a");
            assert(0x80000000 <= sim.sim->req_addr && sim.sim->req_addr < 0x80000000+mem_size-sizeof(uint64_t));
            *((uint64_t *)&mem[sim.sim->req_addr-0x80000000]) = sim.sim->req_data;
            sim.sim->rsp_valid = true;
            if(sim.sim->req_addr == 0x80001000) {
                sim_done = true;
                sim_done_result = sim.sim->req_data;
            }
        }
        if(sim_done) {
            if(sim_done_cnt >= 64) {
                break;
            } else {
                sim_done_cnt++;
            }
        }
        sim.Tick();
    }

    return sim_done_result;
}
