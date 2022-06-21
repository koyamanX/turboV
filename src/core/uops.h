#ifndef UOPS_H
#define UOPS_H

#define uOP_SIZE                        7

/* uOps for ALU */
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

#define uOP_BRU_BEQ                     7'b000_0000
#define uOP_BRU_BNE                     7'b000_0001
#define uOP_BRU_BLT                     7'b000_0100
#define uOP_BRU_BGE                     7'b000_0101
#define uOP_BRU_BLTU                    7'b000_0110
#define uOP_BRU_BGEU                    7'b000_0111
#define uOP_BRU_JALR                    7'b000_1111

#define uOP_SYSTEM_CSRRW                7'b110_0110
#define uOP_SYSTEM_CSRRS                7'b110_0110
#define uOP_SYSTEM_CSRRC                7'b110_1111
#define uOP_SYSTEM_CSRRS_NO_UPDATE_CSR  7'b010_0110
#define uOP_SYSTEM_CSRRC_NO_UPDATE_CSR  7'b010_1111

#define uOP_SYSTEM_MRET                 7'b001_1111
#define uOP_SYSTEM_ECALL                7'b001_1100
#define uOP_SYSTEM_EBREAK               7'b001_1110

#define uOP_LSU_LOAD_WORD               7'b000_0010
#define uOP_LSU_LOAD_HALFWORD           7'b000_0001
#define uOP_LSU_LOAD_BYTE               7'b000_0000
#define uOP_LSU_LOAD_HALFWORD_UNSIGNED  7'b000_0101
#define uOP_LSU_LOAD_BYTE_UNSIGNED      7'b000_0100

#define uOP_LSU_STORE_WORD              7'b000_1010
#define uOP_LSU_STORE_HALFWORD          7'b000_1001
#define uOP_LSU_STORE_BYTE              7'b000_1000

#endif
