#ifndef INSTRUCTION_DECODER_H
#define INSTRUCTION_DECODER_H

#define RS_SEL_IMM	2'b00
#define RS_SEL_REG	2'b01
#define RS_SEL_PC 	2'b10
#define RS_SEL_ZERO	2'b11

declare instruction_decoder {
	input inst[32];
	func_in decode(inst);
	output opcode[7];
	output uops[7];
	output uops_rd[5];
	output uops_rs1_sel[2];
	output uops_rs1[5];
	output uops_rs2_sel[2];
	output uops_rs2[5];
	output uops_imm[32];
	func_out uops_alu(opcode, uops, uops_rd, uops_rs1_sel, uops_rs1, uops_rs2_sel, uops_rs2, uops_imm);
	func_out uops_bru(opcode, uops, uops_rd, uops_rs1_sel, uops_rs1, uops_rs2_sel, uops_rs2, uops_imm);
	func_out uops_illegal_instruction();
	func_out jump();
	func_out branch();
}

#endif
