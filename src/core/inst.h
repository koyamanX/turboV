#ifndef INST_H
#define INST_H

struct {
	funct7[7];
	rs2[5];
	rs1[5];
	funct3[3];
	rd[5];
	opcode[7];
} r_type_t;

struct {
	imm0[12];
	rs1[5];
	imm1[3];
	rd[5];
	opcode[7];
} i_type_t;

struct {
	imm0[7];
	rs2[5];
	rs1[5];
	imm1[3];
	rd[5];
	opcode[7];
} s_type_t;

struct {
	imm0[7];
	rs2[5];
	rs1[5];
	imm1[3];
	rd[5];
	opcode[7];
} b_type_t;

struct {
	imm0[20];
	rd[5];
	opcode[7];
} u_type_t;

struct {
	imm0[20];
	rd[5];
	opcode[7];
} j_type_t;

#endif
