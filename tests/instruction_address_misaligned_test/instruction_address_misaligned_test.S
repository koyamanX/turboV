.globl main
main:
    li t0, 0xaaaaaaaa
    jr t0

.globl trap_handler
trap_handler:
    csrr t0, mcause
    bne t0, zero, fail
    csrr t0, mtval
    li t1, 0xaaaaaaaa
    bne t0, t1, fail
    la t0, pass
    csrw mepc, t0
    mret

pass:
    li x1, 0x80001000
    li x2, 1
    sw x2, 0(x1)
    j pass

fail:
    li x1, 0x80001000
    li x2, 2
    sw x2, 0(x1)
    j fail

