.globl main
main:

/*
Test case 1:
    fence.i works correctly.
	fence.i instruction invalidates icache and flushes instruction buffer.
	Then flush the following instructions.
Steps:
	Set x1 to address of simulator env (0x80001000).
	Set x2 to 2.
	Write next instruction address of fence.i to .word `li x2, 1`.
	Execute fence.i.
	If successfuly fence.i is handled, next instruction will be `li x2, 1`.
	Write host x2 to 0x80001000 to exit tests.
Notes:
*/
test1:
    li x1, 0x80001000
	la x3, self_modify_code
	li x4, 0x00100113
	nop
	nop
	sw x4, 0(x3)
	fence.i
self_modify_code:
    li x2, 2	# Will be replaced by `li x2, 1`
    sw x2, 0(x1)
    j fail # Just in case

fail:
    li x1, 0x80001000
    li x2, 2
    sw x2, 0(x1)
    j fail

.globl trap_handler
trap_handler:
    j fail
