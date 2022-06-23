#ifndef UOP_DECODER_H
#define UOP_DECODER_H

#define RS1_SEL_REG     2'b00
#define RS1_SEL_UIMM    2'b01
#define RS1_SEL_PC      2'b10

#define RS2_SEL_REG     2'b00
#define RS2_SEL_IMM     2'b01
#define RS2_SEL_CSR     2'b10

struct uop_t {
    opcode[7];
    uop[7];
    fn[4];
    lrd[5];
    lrs1[5];
    rs1_sel[2];
    lrs2[5];
    rs2_sel[2];
    imm[32];
    jump;
    load;
    store;
    branch;
    csr_write;
    csr_read;
    csr_addr[12];
    mret;
    ecall;
    ebreak;
#define SIZEOF_UOP_T 90
};

declare uop_decoder {
    input inst[32];
    func_in decode(inst);
    output uop[SIZEOF_UOP_T];
    func_out uop_alu(uop);
    func_out uop_bru(uop);
    func_out uop_lsu(uop);
    func_out uop_system(uop);
    func_out uop_illegal_instruction();
}

#endif
