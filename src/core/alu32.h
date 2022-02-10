#ifndef ALU32_H
#define ALU32_H

declare alu32 {
	input a[32];
	input b[32];
	input fn[4];
	output q[32];
	func_out zero;
	func_in exe(a, b, fn): q;
}

#define ALU_ADD    3'b000
#define ALU_SUB    3'b000
#define ALU_SLL    3'b001
#define ALU_SLT	   3'b010
#define ALU_SLTU   3'b011
#define ALU_XOR    3'b100
#define ALU_SRL    3'b101
#define ALU_SRA    3'b101
#define ALU_OR     3'b110
#define ALU_AND    3'b111

#endif
