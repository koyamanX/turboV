#ifndef INST_H
#define INST_H

struct r_type_t {
    funct7[7];
    rs2[5];
    rs1[5];
    funct3[3];
    rd[5];
    opcode[7];
#define SIZEOF_R_TYPE_T 32
};

struct i_type_t {
    imm0[12];
    rs1[5];
    funct3[3];
    rd[5];
    opcode[7];
#define SIZEOF_I_TYPE_T 32
};

struct s_type_t {
    imm0[7];
    rs2[5];
    rs1[5];
    funct3[3];
    imm1[5];
    opcode[7];
#define SIZEOF_S_TYPE_T 32
};

struct b_type_t {
    imm0[7];
    rs2[5];
    rs1[5];
    funct3[3];
    imm1[5];
    opcode[7];
#define SIZEOF_B_TYPE_T 32
};

struct u_type_t {
    imm0[20];
    rd[5];
    opcode[7];
#define SIZEOF_U_TYPE_T 32
};

struct j_type_t {
    imm0[20];
    rd[5];
    opcode[7];
#define SIZEOF_J_TYPE_T 32
};

#endif
