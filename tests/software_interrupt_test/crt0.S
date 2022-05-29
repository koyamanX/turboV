.globl _start
_start:
    csrwi mstatus, 0
    la t0, _early_trap_vector
    csrw mtvec, t0
    csrsi mtvec, 1
    la t0, _bss_start
    la t1, _bss_end
_clear_bss:
    sw zero, 0(t0)
    add t0, t0, 4
    bltu t0, t1, _clear_bss
.extern main
.extern exit
    li t0, 0
    li t1, 0
    li t2, 0
    la sp, _stack_top
    la ra, exit
    call main
    tail exit
.weak exit
exit:
    j exit
_early_trap_vector:
.globl trap_handler
.globl software_interrupt_handler
    j trap_handler
    j trap_handler
    j trap_handler
    j software_interrupt_handler
    j trap_handler
    j trap_handler
    j trap_handler
    j trap_handler
    j trap_handler
    j trap_handler
    j trap_handler
    j trap_handler
