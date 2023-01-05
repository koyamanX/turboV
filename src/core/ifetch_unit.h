#ifndef IFETCH_UNIT_H
#define IFETCH_UNIT_H

#include "wishbone_common.h"
#include "riscv.h"

struct fetch_packet_t {
    // TODO: 29 bit
    pc[XLEN];
    inst0[ILEN];
    inst1[ILEN];
    pred0[1];
    pred1[1];
    valid0[1];
    valid1[1];

#define SIZEOF_FETCH_PACKET_T 100
};


declare ifetch_unit {
    func_in reset();
    input newpc[XLEN];
    func_in redirect(newpc);
    output ibuf_fetch_packet[SIZEOF_FETCH_PACKET_T];
    func_in ibuf_pop(): ibuf_fetch_packet;
    func_out ibuf_full();
    func_out ibuf_empty();
    func_in ibuf_flush();
	func_in req_invalidate_all();
	func_out rsp_invalidate_all_done();

	input req_update_predict0_pc[32];
	input req_update_predict0_target[32];
	func_in req_update_predict0(req_update_predict0_pc, req_update_predict0_target);
	input req_update_predict1_pc[32];
	input req_update_predict1_target[32];
	func_in req_update_predict1(req_update_predict1_pc, req_update_predict1_target);

    WISHBONE_GEN_MASTER_IF(32, 64, 8)
}

#endif
