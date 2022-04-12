#ifndef INSTRUCTION_DECODER_H
#define INSTRUCTION_DECODER_H

#define RS1_SEL_ZERO    2'b00
#define RS1_SEL_REG     2'b01
#define RS1_SEL_PC      2'b10
#define RS1_SEL_NOT_CSR 2'b11

#define RS2_SEL_ZERO    2'b00
#define RS2_SEL_REG     2'b01
#define RS2_SEL_IMM     2'b10
#define RS2_SEL_CSR     2'b11

declare instruction_decoder {
    input inst[32];
    func_in decode(inst);
    output opcode[7];
    output uop[7];
    output uop_rd[5];
    output uop_rs1_sel[2];
    output uop_rs1[5];
    output uop_rs2_sel[2];
    output uop_rs2[5];
    output uop_imm[32];
    func_out uop_alu(opcode, uop, uop_rd, uop_rs1_sel, uop_rs1, uop_rs2_sel, uop_rs2, uop_imm);
    func_out uop_bru(opcode, uop, uop_rd, uop_rs1_sel, uop_rs1, uop_rs2_sel, uop_rs2, uop_imm);
    func_out uop_lsu(opcode, uop, uop_rd, uop_rs1_sel, uop_rs1, uop_rs2_sel, uop_rs2, uop_imm);
    func_out uop_system(opcode, uop, uop_rd, uop_rs1_sel, uop_rs1, uop_rs2_sel, uop_rs2, uop_imm);
    func_out uop_illegal_instruction();
    func_out jump();
    func_out load();
    func_out store();
    func_out branch();
}

#endif
