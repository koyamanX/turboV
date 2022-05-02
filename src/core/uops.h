#ifndef UOPS_H
#define UOPS_H

/* uOps for ALU */
#define uOP_ALU_ADD 4'b0000
#define uOP_ALU_SUB 4'b1000
#define uOP_ALU_SLL 4'b0001
#define uOP_ALU_SLT 4'b0010
#define uOP_ALU_SLTU    4'b0011
#define uOP_ALU_XOR 4'b0100
#define uOP_ALU_SRL 4'b0101
#define uOP_ALU_SRL 4'b1101
#define uOP_ALU_OR      4'b0110
#define uOP_ALU_AND 4'b0111

#define uOP_BRU_BEQ 4'b0000
#define uOP_BRU_BNE 4'b0001
#define uOP_BRU_BLT 4'b0100
#define uOP_BRU_BGE 4'b0101
#define uOP_BRU_BLTU    4'b0110
#define uOP_BRU_BGEU    4'b0111
#define uOP_BRU_JALR    4'b1111

#define uOP_SYSTEM_CSRRW  7'b110_0110
#define uOP_SYSTEM_CSRRS  7'b110_0110
#define uOP_SYSTEM_CSRRC  7'b110_0111
#define uOP_SYSTEM_CSRRS_NO_UPDATE_CSR 7'b010_0110
#define uOP_SYSTEM_CSRRC_NO_UPDATE_CSR 7'b010_0111

#define uOP_SYSTEM_MRET     7'b001_1111
#define uOP_SYSTEM_ECALL    7'b001_1100

#define uOP_LSU_LOAD_WORD   4'b0010
#define uOP_LSU_LOAD_HALFWORD   4'b0001
#define uOP_LSU_LOAD_BYTE   4'b0000
#define uOP_LSU_LOAD_HALFWORD_UNSIGNED   4'b0101
#define uOP_LSU_LOAD_BYTE_UNSIGNED   4'b0100

#define uOP_LSU_STORE_WORD  4'b1010

#endif
