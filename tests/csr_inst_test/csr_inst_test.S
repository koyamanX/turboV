.globl main
main:
test1:
    li x1, 0x5555aaaa
    csrw mscratch, x1
    csrr x2, mscratch
    bne x1, x2, fail

test2:
    li x1, 0xffffffff
    csrw mscratch, x1
    li x1, 0x5555aaaa
    csrc mscratch, x1
    csrr x2, mscratch
    li x3, 0xaaaa5555
    bne x2, x3, fail

test3:
    li x1, 0x5555aaaa
    csrs mscratch, x1
    csrr x2, mscratch
    li x3, 0xffffffff
    bne x2, x3, fail

test4:
    li x1, 0x1f
    csrw mscratch, x0
    csrwi mscratch, 0x1f
    csrr x2, mscratch
    bne x1, x2, fail

test5:
    li x1, 0xfffffff0
    csrw mscratch, x1
    csrwi mscratch, 0xf
    csrr x2, mscratch
    bne x1, x2, fail

test6:
    li x1, 0xffffffff
    csrw mscratch, x1
    csrci mscratch, 0xf
    csrr x2, mscratch
    li x3, 0xfffffff0
    bne x2, x3, fail

    j pass

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

.globl trap_handler
trap_handler:
    j fail
