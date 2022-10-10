#ifndef UOP_DECODER_H
#define UOP_DECODER_H

#define RS1_SEL_REG         2'b00
#define RS1_SEL_UIMM        2'b01
#define RS1_SEL_PC          2'b10

#define RS2_SEL_REG         2'b00
#define RS2_SEL_IMM         2'b01
#define RS2_SEL_CSR         2'b10
#define RS2_SEL_CSR_UIMM    2'b11

#include "uops.h"
#include "control_status_register.h"

struct decoder_packet_t {
	uop[SIZEOF_UOP_T];
	lrd[5];
    rs1_sel[2];
    lrs1[5];
    rs2_sel[2];
    lrs2[5];
    imm[32];
#define SIZEOF_DECODER_PACKET_T SIZEOF_UOP_T+51
};

declare uop_decoder {
    input inst[32];
    func_in decode(inst);
    output packet[SIZEOF_DECODER_PACKET_T];
    func_out uop_alu(packet);
    func_out uop_bru(packet);
    func_out uop_lsu(packet);
    func_out uop_system(packet);
    output decode_csr_rw[2];
    output decode_csr_addr[12];
    func_out decode_csr(decode_csr_rw, decode_csr_addr);
    func_in decode_csr_illegal();
}

#endif
