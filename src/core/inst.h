#ifndef INST_H
#define INST_H

struct r_type_t {
	funct7[7];
	rs2[5];
	rs1[5];
	funct3[3];
	rd[5];
	opcode[7];
};

struct i_type_t {
	imm0[12];
	rs1[5];
	funct3[3];
	rd[5];
	opcode[7];
};

struct s_type_t {
	imm0[7];
	rs2[5];
	rs1[5];
	funct3[3];
	rd[5];
	opcode[7];
};

struct b_type_t {
	imm0[7];
	rs2[5];
	rs1[5];
	funct3[3];
	rd[5];
	opcode[7];
};

struct u_type_t {
	imm0[20];
	rd[5];
	opcode[7];
};

struct j_type_t {
	imm0[20];
	rd[5];
	opcode[7];
};

#endif
