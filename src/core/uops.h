#ifndef UOPS_H
#define UOPS_H

#include "consts.h"

#define uOP_SIZE                        7

/* Lower 4 bits corresponds to fn of ALU */
#define uOP_ALU                         3'b000
#define uOP_ALU_ADD                     7'b000_0000
#define uOP_ALU_SUB                     7'b000_1000
#define uOP_ALU_SLL                     7'b000_0001
#define uOP_ALU_SLT                     7'b000_0010
#define uOP_ALU_SLTU                    7'b000_0011
#define uOP_ALU_XOR                     7'b000_0100
#define uOP_ALU_SRL                     7'b000_0101
#define uOP_ALU_SRL                     7'b000_1101
#define uOP_ALU_OR                      7'b000_0110
#define uOP_ALU_AND                     7'b000_0111

/* Lower 4 bits corresponds to fn of BRU */
#define uOP_BRU                         3'b001
#define uOP_BRU_BEQ                     7'b001_0000
#define uOP_BRU_BNE                     7'b001_0001
#define uOP_BRU_BLT                     7'b001_0100
#define uOP_BRU_BGE                     7'b001_0101
#define uOP_BRU_BLTU                    7'b001_0110
#define uOP_BRU_BGEU                    7'b001_0111
#define uOP_BRU_JALR                    7'b001_1111
#define uOP_BRU_JAL                     7'b001_1000

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
    jal;
    jalr;
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
    // TODO: Not set
    prd[ROB_TAG_SIZE];
    prs1[ROB_TAG_SIZE];
    prs2[ROB_TAG_SIZE];
#define SIZEOF_UOP_T 107+ROB_TAG_SIZE+ROB_TAG_SIZE+ROB_TAG_SIZE
};

#endif
