#ifndef IFETCH_UNIT_H
#define IFETCH_UNIT_H

#include "wishbone_common.h"
#include "riscv.h"

struct fetch_packet_t {
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

    WISHBONE_GEN_MASTER_IF(32, 64, 8)
}

#endif
