.globl _boot
_boot:
    csrrci t0, mstatus, 0x4
    la t1, _trap
    csrrw zero, mtvec, t1
    csrrci zero, mtvec, 0x3
    li t1, 0x80000000
    csrrw zero, mepc, t1
    csrrw zero, mstatus, t0
    mv t0, zero
    mv t1, zero
    mret

_trap:
    j _trap
