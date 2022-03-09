#ifndef UOPS_H
#define UOPS_H

/* uOps for ALU */
#define uOPS_ALU_ADD	4'b0000
#define uOPS_ALU_SUB	4'b1000
#define uOPS_ALU_SLL	4'b0001
#define uOPS_ALU_SLT	4'b0010
#define uOPS_ALU_SLTU	4'b0011
#define uOPS_ALU_XOR	4'b0100
#define uOPS_ALU_SRL	4'b0101
#define uOPS_ALU_SRL	4'b1101
#define uOPS_ALU_OR		4'b0110
#define uOPS_ALU_AND	4'b0111

#define uOPS_BRU_BEQ	4'b0000
#define uOPS_BRU_BNE	4'b0001
#define uOPS_BRU_BLT	4'b0100
#define uOPS_BRU_BGE	4'b0101
#define uOPS_BRU_BLTU	4'b0110
#define uOPS_BRU_BGEU	4'b0111

#define uOPS_LOAD_WORD	4'b0010

#endif
