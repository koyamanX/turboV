#include "csr.h"
#include "sim_exit.h"
#include  "types.h"

#define CLINT_MTIMECMP_HI ((volatile unsigned int *)0x02004004)
#define CLINT_MTIMECMP_LO ((volatile unsigned int *)0x02004000)
#define CLINT_MTIME_HI    ((volatile unsigned int *)0x0200BFFc)
#define CLINT_MTIME_LO    ((volatile unsigned int *)0x0200BFF8)
#define TIMER_INTERRUPT 0x80000007

void exit(int status) {
    sim_exit(status);
}
void trap_handler(void) {
    if(mcause_read() == TIMER_INTERRUPT) {
        asm volatile("csrsi mtvec, 1");
        asm volatile("mret");
    } else {
        exit(SIM_EXIT_FAILURE);
    }
}
void timer_interrupt_handler(void) {
    exit(SIM_EXIT_SUCCESS);
}
int main(void) {
    // Enable mstatus.MIE
    mstatus_write(mstatus_read()|0x8);
    // Enable M-mode software interrupt
    *CLINT_MTIME_HI = 0;
    *CLINT_MTIME_LO = 0;
    *CLINT_MTIMECMP_HI = 0x0;
    *CLINT_MTIMECMP_LO = 128;
    mie_write(0x80);

loop:
    goto loop;

    __builtin_unreachable();
    return 0;
}
