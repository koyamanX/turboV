.section .text.init

.weak _reset_vector
.weak _trap_vector
.weak _trap_handler
.weak _start

_reset_vector:
	j _start
_trap_vector:
	j _trap_handler
	j _trap_handler
	j _trap_handler
	j _trap_handler
	j _trap_handler
	j _trap_handler
	j _trap_handler
	j _trap_handler
	j _trap_handler
	j _trap_handler
	j _trap_handler
	j _trap_handler
_trap_handler:
	j _trap_handler

.globl _start
_start:
	csrwi mstatus, 0
	la t0, _trap_vector
	csrw mtvec, t0
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
	la sp, _stack_top
	la ra, exit
	call main
	tail exit
