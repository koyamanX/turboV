#ifndef INSTRUCTION_DECODER_H
#define INSTRUCTION_DECODER_H

declare instruction_decoder {
	input inst0[32];
	input inst1[32];
	func_in decode(inst0, inst1);

	output uops0[7];
	output uops0_rd[5];
	output uops0_rs1[5];
	output uops0_rs2[5];
	output uops0_imm[32];
	func_out uops0_alu(uops0, uops0_rd, uops0_rs1, uops0_rs2, uops0_imm);
	func_out uops0_illegal_instruction();

	output uops1[7];
	output uops1_rd[5];
	output uops1_rs1[5];
	output uops1_rs2[5];
	output uops1_imm[32];
	func_out uops1_alu(uops1, uops1_rd, uops1_rs1, uops1_rs2, uops1_imm);
	func_out uops1_illegal_instruction();
}

#endif
