.globl _boot
_boot:
    li x1, 0x80001000
    li x2, 0
    sw x2, 0(x1)
    j _boot

