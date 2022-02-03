#ifndef INSTRUCTION_DECODER_H
#define INSTRUCTION_DECODER_H

declare instruction_decoder {
	input inst[32];
	func_in decode(inst);

	output uops[7];
	output uops_rd[5];
	output uops_rs1_valid;
	output uops_rs1[5];
	output uops_rs2_valid;
	output uops_rs2[5];
	output uops_imm[32];
	func_out uops_alu(uops, uops_rd, uops_rs1_valid, uops_rs1, uops_rs2_valid, uops_rs2, uops_imm);
	func_out uops_illegal_instruction();
}

#endif
