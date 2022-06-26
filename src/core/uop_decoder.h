#ifndef UOP_DECODER_H
#define UOP_DECODER_H

#define RS1_SEL_REG     2'b00
#define RS1_SEL_UIMM    2'b01
#define RS1_SEL_PC      2'b10

#define RS2_SEL_REG     2'b00
#define RS2_SEL_IMM     2'b01
#define RS2_SEL_CSR     2'b10

struct cause_t {
	store_amo_page_fault;
	reserved1[1];
	load_page_fault;
	instruction_page_fault;
	environment_call_from_m_mode;
	reserved2[1];
	environment_call_from_s_mode;
	environment_call_from_u_mode;
	store_amo_access_fault;
	store_amo_address_misaligned;
	load_access_fault;
	load_address_misaligned;
	breakpoint;
	illegal_instruction;
	instruction_access_fault;
	instruction_address_misaligned;
#define SIZEOF_CAUSE_T 16
};

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
    cause[16];
#define SIZEOF_UOP_T 106
};

declare uop_decoder {
    input inst[32];
    func_in decode(inst);
    output uop[SIZEOF_UOP_T];
    func_out uop_alu(uop);
    func_out uop_bru(uop);
    func_out uop_lsu(uop);
    func_out uop_system(uop);
}

#endif
