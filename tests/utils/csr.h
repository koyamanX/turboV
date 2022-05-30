#ifndef CSR_H
#define CSR_H
#include "types.h"

#define def_csr_read_func(csrname) static inline uint32_t csrname##_read(void) { uint32_t x; asm volatile("csrr %0, " #csrname ";" : "=r"(x)); return x;}
#define def_csr_write_func(csrname) static inline void csrname##_write(uint32_t x) {asm volatile("csrw " #csrname ", %0;" :: "r"(x));}

def_csr_read_func(mcause);
def_csr_write_func(mie);
def_csr_write_func(mstatus);
def_csr_read_func(mstatus);

#endif
