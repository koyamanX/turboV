.globl main
main:

/*
Test case 1:
    Test CSRRW with rd != x0, works correctly
Steps:
    - Reads old value of mscratch, writes 0x5555aaaa to mscratch.
    - Compare read value is equal to zero.
    - Reads mscratch, compare read value to written value.
Notes:
    mscratch is initialized to zero on CPU reset.
*/
test1:
    li x1, 0x5555aaaa
    csrrw x2, mscratch, x1
    bne x2, zero, fail
    csrrw x2, mscratch, zero
    bne x2, x1, fail

/*
Test case 2:
    Test CSRRW with rd == x0, works correctly
Steps:
    - Writes 0x5555aaaa to mscratch.
    - Reads mscratch, compare read value to written value.
Notes:
    CSR is not read in this case, but no way to find out
    that CSR is not read.
*/
test2:
    li x1, 0x5555aaaa
    csrrw x0, mscratch, x1
    csrrw x2, mscratch, zero
    bne x2, x1, fail

/*
Test case 3:
    Test CSRRS with rs1 != x0, works correctly
Steps:
    - Writes 0x5555aaaa to mscratch.
    - Mask mscratch with value 0xaaaa5555
    - Reads mscratch, compare read value to 0xffffffff
Notes:
    0x5555aaaa | 0xaaaa5555 => 0xffffffff
*/
test3:
    li x1, 0x5555aaaa
    csrrw x0, mscratch, x1
    li x1, 0xaaaa5555
    csrrs x0, mscratch, x1
    csrr x2, mscratch
    li x1, 0xffffffff
    bne x2, x1, fail

/*
Test case 4:
    Test CSRRS with rs1 == x0, works correctly
Steps:
    - Writes 0x5555aaaa to mscratch.
    - Mask mscratch with x0.
    - Reads mscratch, compare read value to 0x5555aaaa
Notes:
    CSRRS with rs1 == x0, never writes CSR
*/
test4:
    li x1, 0x5555aaaa
    csrrw x0, mscratch, x1
    csrrs x0, mscratch, x0
    csrr x2, mscratch
    bne x2, x1, fail

/*
Test case 5:
    Test CSRRS with rs1 == x0, works correctly for no write side effect
Steps:
    - Mask read only CSR with x0.
Notes:
    CSRRS with rs1 == x0, never writes CSR
    Any side effect regarding CSR write must no be happen
*/
test5:
    csrrs x0, mhartid, x0

/*
Test case 6:
    Test CSRRC with rs1 != x0, works correctly
Steps:
    - Writes 0xffffffff to mscratch.
    - Mask mscratch with value 0x5555aaaa
    - Reads mscratch, compare read value to 0xaaaa5555
Notes:
    0xffffffff & 0x5555aaaa => 0xaaaa5555
*/
test6:
    li x1, 0xffffffff
    csrrw x0, mscratch, x1
    li x1, 0x5555aaaa
    csrrc x0, mscratch, x1
    csrr x2, mscratch
    li x1, 0xaaaa5555
    bne x2, x1, fail

/*
Test case 7:
    Test CSRRC with rs1 == x0, works correctly
Steps:
    - Writes 0x5555aaaa to mscratch.
    - Mask mscratch with x0.
    - Reads mscratch, compare read value to 0x5555aaaa
Notes:
    CSRRS with rs1 == x0, never writes CSR
*/
test7:
    li x1, 0x5555aaaa
    csrrw x0, mscratch, x1
    csrrc x0, mscratch, x0
    csrr x2, mscratch
    bne x2, x1, fail

/*
Test case 8:
    Test CSRRC with rs1 == x0, works correctly for no write side effect
Steps:
    - Mask read only CSR with x0.
Notes:
    CSRRS with rs1 == x0, never writes CSR
    Any side effect regarding CSR write must no be happen
*/
test8:
    csrrc x0, mhartid, x0

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
