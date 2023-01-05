#ifndef OPCODE_MAP_H
#define OPCODE_MAP_H

#define LOAD            7'b0000011
#define STORE           7'b0100011
#define BRANCH          7'b1100011
#define JALR            7'b1100111
#define MISC_MEM        7'b0001111
#define AMO             7'b0101111
#define JAL             7'b1101111
#define OP_IMM          7'b0010011
#define OP              7'b0110011
#define SYSTEM          7'b1110011
#define AUIPC           7'b0010111
#define LUI             7'b0110111

#define SYSTEM_CSRRW    3'b001
#define SYSTEM_CSRRS    3'b010
#define SYSTEM_CSRRC    3'b011
#define SYSTEM_CSRRWI   3'b101
#define SYSTEM_CSRRSI   3'b110
#define SYSTEM_CSRRCI   3'b111
#define SYSTEM_PRIV     3'b000 
#define SYSTEM_MRET     12'b0011_0000_0010
#define SYSTEM_ECALL    12'b0000_0000_0000
#define SYSTEM_EBREAK   12'b0000_0000_0001

#endif
