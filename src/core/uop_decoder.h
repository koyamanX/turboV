#ifndef UOP_DECODER_H
#define UOP_DECODER_H

#include "uops.h"
#include "control_status_register.h"

#define IMM_GEN_ITYPE(inst) (inst[31:20])
#define IMM_GEN_STYPE(inst) ({inst[31:25], inst[11:7]})
#define IMM_GEN_BTYPE(inst) ({inst[31], inst[7], inst[30:25], inst[11:8], 1'b0})
#define IMM_GEN_UTYPE(inst) ({inst[31:12], 12'b000000000000})
#define IMM_GEN_JTYPE(inst) ({inst[31], inst[19:12], inst[20], inst[30:21], 1'b0})

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
	output decode_csr_num[12];
	output decode_csr_rw[2];
	input decode_csr_illegal;
	func_out decode_csr(decode_csr_num, decode_csr_rw): decode_csr_illegal;
}

#endif
