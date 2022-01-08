#ifndef INSTRUCTION_DECODER_H
#define INSTRUCTION_DECODER_H

declare instruction_decoder {
	input inst[32];
	func_in decode(inst);
	output rd[5];
	output rs1[5];
	output rs2[5];
	output funct3[3];
	output funct7[7];
	output funct12[12];
	output beq;
	output bne;
	output blt;
	output bltu;
	output bge;
	output bgeu;
	output imm[32];
	output fn[4];

	func_out load();
	func_out store();
	func_out branch();
	func_out jalr();
	func_out misc_mem();
	func_out amo();
	func_out jal();
	func_out op_imm();
	func_out op(rd, rs1, rs2, fn);
	func_out system();
	func_out auipc();
	func_out lui();
	func_out illegal_instruction();
}

#endif
