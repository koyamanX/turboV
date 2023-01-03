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
    input req_decode_inst[32];
    input req_decode_pred;
    output rsp_decode_packet[SIZEOF_DECODER_PACKET_T];
    func_in req_decode(req_decode_inst, req_decode_pred): rsp_decode_packet;
	output req_decode_csr_addr[12];
	output req_decode_csr_rw[2];
	input rsp_decode_csr_illegal;
	func_out req_decode_csr(req_decode_csr_addr, req_decode_csr_rw): rsp_decode_csr_illegal;
}

#endif
