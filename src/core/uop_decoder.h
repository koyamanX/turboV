#ifndef UOP_DECODER_H
#define UOP_DECODER_H

#include "uops.h"
#include "control_status_register.h"

struct decoder_packet_t {
    uop[SIZEOF_UOP_T];
    lrd[5];
    lrs1[5];
    lrs2[5];
    // pure IMM or IMM+PC
    imm[32];
    cause[SIZEOF_CAUSE_T];
#ifdef ENABLE_DEBUG
    inst[32];
#define SIZEOF_DECODER_PACKET_T SIZEOF_UOP_T+SIZEOF_CAUSE_T+47+32
#else
#define SIZEOF_DECODER_PACKET_T SIZEOF_UOP_T+SIZEOF_CAUSE_T+47
#endif
};

declare uop_decoder {
    input inst[32];
    func_in decode(inst);
    output packet[SIZEOF_DECODER_PACKET_T];
    func_out uop_alu(packet);
    func_out uop_bru(packet);
    func_out uop_lsu(packet);
    func_out uop_system(packet);
}

#endif
