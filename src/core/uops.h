#ifndef UOPS_H
#define UOPS_H

#define uOP_SIZE                        8
#define FN_SIZE                            5

#define ALU_ADD    5'b00000
#define ALU_SUB    5'b01000
#define ALU_SLL    5'b00001
#define ALU_SLT    5'b00010
#define ALU_SLTU   5'b00011
#define ALU_XOR    5'b00100
#define ALU_SRL    5'b00101
#define ALU_SRA    5'b01101
#define ALU_OR     5'b00110
#define ALU_AND    5'b00111
#define ALU_NAAND  5'b01111
/* Lower 4 bits corresponds to fn of ALU */
#define uOP_ALU                         3'b000
#define uOP_ALU_ADD                     {uOP_ALU, ALU_ADD}
#define uOP_ALU_SUB                     {uOP_ALU, ALU_SUB}
#define uOP_ALU_SLL                     {uOP_ALU, ALU_SLL}
#define uOP_ALU_SLT                     {uOP_ALU, ALU_SLT}
#define uOP_ALU_SLTU                    {uOP_ALU, ALU_SLTU}
#define uOP_ALU_XOR                     {uOP_ALU, ALU_XOR}
#define uOP_ALU_SRL                     {uOP_ALU, ALU_SRL}
#define uOP_ALU_SRA                     {uOP_ALU, ALU_SRA}
#define uOP_ALU_OR                      {uOP_ALU, ALU_OR}
#define uOP_ALU_AND                     {uOP_ALU, ALU_AND}
#define uOP_ALU_NAAND                   {uOP_ALU, ALU_NAAND}

#define BRU_EQ                          5'b10000
#define BRU_NE                          5'b10001
#define BRU_LT                          5'b10100
#define BRU_GE                          5'b10101
#define BRU_LTU                         5'b10110
#define BRU_GEU                         5'b10111
#define BRU_JALR                        5'b11111
#define BRU_JAL                         5'b11000
/* Lower 4 bits corresponds to fn of BRU */
#define uOP_BRU                         3'b001
#define uOP_BRU_BEQ                     {uOP_BRU, BRU_EQ}
#define uOP_BRU_BNE                     {uOP_BRU, BRU_NE}
#define uOP_BRU_BLT                     {uOP_BRU, BRU_LT}
#define uOP_BRU_BGE                     {uOP_BRU, BRU_GE}
#define uOP_BRU_BLTU                    {uOP_BRU, BRU_LTU}
#define uOP_BRU_BGEU                    {uOP_BRU, BRU_GEU}
#define uOP_BRU_JALR                    {uOP_BRU, BRU_JALR}
#define uOP_BRU_JAL                     {uOP_BRU, BRU_JAL}

/* Lower 4 bits corresponds to fn of LSU */
#define uOP_LSU                         3'b010
#define uOP_LSU_LOAD_WORD               7'b010_0010
#define uOP_LSU_LOAD_HALFWORD           7'b010_0001
#define uOP_LSU_LOAD_BYTE               7'b010_0000
#define uOP_LSU_LOAD_HALFWORD_UNSIGNED  7'b010_0101
#define uOP_LSU_LOAD_BYTE_UNSIGNED      7'b010_0100
#define uOP_LSU_STORE_WORD              7'b010_1010
#define uOP_LSU_STORE_HALFWORD          7'b010_1001
#define uOP_LSU_STORE_BYTE              7'b010_1000

#define uOP_SYSTEM                      3'b011
#define uOP_SYSTEM_CSRRW                7'b110_0110
#define uOP_SYSTEM_CSRRS                7'b110_0110
#define uOP_SYSTEM_CSRRC                7'b110_1111
#define uOP_SYSTEM_MRET                 7'b001_1111
#define uOP_SYSTEM_ECALL                7'b001_1100
#define uOP_SYSTEM_EBREAK               7'b001_1110

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

#define SIZEOF_REG_SEL        2
#define RS1_SEL_REG         2'b00
#define RS1_SEL_UIMM        2'b01
#define RS1_SEL_PC        2'b10

#define RS2_SEL_REG         2'b00
#define RS2_SEL_IMM         2'b01
#define RS2_SEL_CSR         2'b10
#define RS2_SEL_CSR_UIMM    2'b11

struct uop_t {
    uop[uOP_SIZE];
    rd_valid;
    rs1_valid;
    rs1_sel[SIZEOF_REG_SEL];
    rs2_valid;
    rs2_sel[SIZEOF_REG_SEL];
	// TODO: 
    jal;
    jalr;
    load;
    store;
    branch;
    csr;
    csr_write;
    csr_read;
    mret;
    ecall;
    ebreak;
	uimm[5];
#define SIZEOF_UOP_T uOP_SIZE+13+SIZEOF_REG_SEL+SIZEOF_REG_SEL+1+5
};

#endif
