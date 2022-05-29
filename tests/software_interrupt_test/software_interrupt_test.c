#define SIM_EXIT ((volatile unsigned int *)(0x80001000))
#define CLINT_MSIP ((volatile unsigned int *)0x02000000)
#define SIM_EXIT_FAILURE (!1)
#define SIM_EXIT_SUCCESS (!0)
typedef unsigned int uint32_t;

void exit(int status) {
    *SIM_EXIT = status;
_exit:
    goto _exit;
}
void trap_handler(void) {
    exit(SIM_EXIT_FAILURE);
}
void software_interrupt_handler(void) {
    exit(SIM_EXIT_SUCCESS);
}
static inline void mstatus_w(uint32_t x) {
    asm volatile(
        "csrw mstatus, %0;"
        :: "r"(x)
    );
}
static inline uint32_t mstatus_r(void) {
    uint32_t x;
    asm volatile(
        "csrr %0, mstatus;"
        : "=r"(x)
    );
    return x;
}
static inline void mie_w(uint32_t x) {
    asm volatile(
        "csrw mie, %0;"
        :: "r"(x)
    );
}
int main(void) {
    // Enable mstatus.MIE
    mstatus_w(mstatus_r()|0x8);
    // Enable M-mode software interrupt
    mie_w(0x8);
    *CLINT_MSIP = 1;

loop:
    goto loop;

    __builtin_unreachable();
    return 0;
}
