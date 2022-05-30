#include "csr.h"
#include "sim_exit.h"

typedef unsigned int uint32_t;

#define CLINT_MSIP ((volatile unsigned int *)0x02000000)
#define SOFTWARE_INTERRUPT 0x80000003

void exit(int status) {
    sim_exit(status);
}
void trap_handler(void) {
    if(mcause_read() == SOFTWARE_INTERRUPT) {
        asm volatile("csrsi mtvec, 1");
        asm volatile("mret");
    } else {
        exit(SIM_EXIT_FAILURE);
    }
}
void software_interrupt_handler(void) {
    exit(SIM_EXIT_SUCCESS);
}
int main(void) {
    // Enable mstatus.MIE
    mstatus_write(mstatus_read()|0x8);
    // Enable M-mode software interrupt
    mie_write(0x8);
    *CLINT_MSIP = 1;

loop:
    goto loop;

    __builtin_unreachable();
    return 0;
}
