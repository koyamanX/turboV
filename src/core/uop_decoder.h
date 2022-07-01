#ifndef UOP_DECODER_H
#define UOP_DECODER_H

#define RS1_SEL_REG     2'b00
#define RS1_SEL_UIMM    2'b01
#define RS1_SEL_PC      2'b10

#define RS2_SEL_REG     2'b00
#define RS2_SEL_IMM     2'b01
#define RS2_SEL_CSR     2'b10

#include "uops.h"

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