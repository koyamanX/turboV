#include "csr.h"
#include "sim_exit.h"
#include  "types.h"

void exit(int status) {
    sim_exit(status);
}
void trap_handler(void) {
    exit(SIM_EXIT_FAILURE);
}
uint32_t csrrw_mscratch(uint32_t v) {
    uint32_t x;
    
    asm volatile("csrrw %0, mscratch, %1;" : "=r"(x) : "r"(v));
    return x;
}
uint32_t csrrs_mscratch(uint32_t v) {
    uint32_t x;
    
    asm volatile("csrrs %0, mscratch, %1;" : "=r"(x) : "r"(v));
    return x;
}
uint32_t csrrc_mscratch(uint32_t v) {
    uint32_t x;
    
    asm volatile("csrrc %0, mscratch, %1;" : "=r"(x) : "r"(v));
    return x;
}
int main(void) {
    if(csrrw_mscratch(0xffffffff) != 0) {
        exit(SIM_EXIT_FAILURE);
    }
    if(csrrc_mscratch(0x5555aaaa) != 0xffffffff) {
        exit(SIM_EXIT_FAILURE);
    }
    if(csrrs_mscratch(0x5555aaaa) != 0x5555aaaa) {
        exit(SIM_EXIT_FAILURE);
    }
    if(csrrw_mscratch(0x0) != 0xffffffff) {
        exit(SIM_EXIT_FAILURE);
    }
    exit(SIM_EXIT_SUCCESS);

loop:
    goto loop;

    __builtin_unreachable();
    return 0;
}
