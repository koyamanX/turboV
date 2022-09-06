.text
.globl _start
_start:
	li x1, 0
	li x2, 16
_loop:
	addi x1, x1, 4
	beq x1, x2, _end
	beq x0, x0, _loop
_end:
	lw x1, 0(x0)

exit:
	beq x0, x0, exit
	nop
