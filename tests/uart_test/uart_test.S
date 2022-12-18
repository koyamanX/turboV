.globl main
main:

/*
Test case 1:
Steps:
Notes:
*/
test1:
    li x1, 0x40000000
	li x2, 1
	sw x2, 8(x1)
	li x2, 0x41
	sw x2, 0(x1)

fail:
    li x1, 0x80001000
    li x2, 1
    sw x2, 0(x1)
    j fail

.globl trap_handler
trap_handler:
    j fail
