#ifndef OPCODE_MAP_H
#define OPCODE_MAP_H

#define LOAD        7'b0000011
#define STORE       7'b0100011
#define BRANCH      7'b1100011
#define JALR        7'b1100111
#define MISC_MEM    7'b1101111
#define AMO         7'b0101111
#define JAL         7'b1101111
#define OP_IMM      7'b0010011
#define OP          7'b0110011
#define SYSTEM      7'b1110011
#define AUIPC       7'b0010111
#define LUI         7'b0110111

#endif
