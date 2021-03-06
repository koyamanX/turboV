#ifndef RESERVATION_STATION_H
#define RESERVATION_STATION_H

#include "consts.h"
#include "reorder_buffer.h"
#include "uops.h"

struct reservation_station_t {
    Busy;
    Op[SIZEOF_UOP_T];
    Vj[32];
    Vk[32];
    Qj[ROB_TAG_SIZE];
    Qk[ROB_TAG_SIZE];
    Dest[ROB_TAG_SIZE];
    A[32];
    #define SIZEOF_RESERVATION_STATION_T 109+SIZEOF_UOP_T
};

declare reservation_station {
    input Valid;
    input Op[SIZEOF_UOP_T];
    input Vj[32];
    input Vk[32];
    input Qj[ROB_TAG_SIZE];
    input Qk[ROB_TAG_SIZE];
    input Dest[ROB_TAG_SIZE];
    input A[32];
    func_in issue(Valid, Op, Vj, Vk, Qj, Qk, Dest, A);
    func_in flush();
    func_out full();
    func_in stall();
    output dispatch_Op[SIZEOF_UOP_T];
    output dispatch_Dest[ROB_TAG_SIZE];
    output dispatch_Vj[32];
    output dispatch_Vk[32];
    output dispatch_A[32];
    func_out dispatch(dispatch_Op, dispatch_Dest, dispatch_Vj, dispatch_Vk, dispatch_A);
    input CDB0Id[ROB_TAG_SIZE];
    input CDB0Val[32];
    func_in CDB0(CDB0Id, CDB0Val);
    input CDB1Id[ROB_TAG_SIZE];
    input CDB1Val[32];
    func_in CDB1(CDB1Id, CDB1Val);
    input CDB2Id[ROB_TAG_SIZE];
    input CDB2Val[32];
    func_in CDB2(CDB2Id, CDB2Val);
    input CDB3Id[ROB_TAG_SIZE];
    input CDB3Val[32];
    func_in CDB3(CDB3Id, CDB3Val);
}

#endif
