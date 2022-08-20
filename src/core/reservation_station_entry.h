#ifndef RESERVATION_STATION_ENTRY_H
#define RESERVATION_STATION_ENTRY_H

#include "uops.h"

struct reservation_station_entry_t {
    Busy;
    Op[7];
    Vj[32];
    Vk[32];
    Qj[ROB_TAG_SIZE];
    Qk[ROB_TAG_SIZE];
    Dest[ROB_TAG_SIZE];
    A[32];
    #define SIZEOF_RESERVATION_STATION_ENTRY_T 104+ROB_TAG_SIZE+ROB_TAG_SIZE+ROB_TAG_SIZE
};

declare reservation_station_entry {
    input Valid;
    input Op[7];
    input Vj[32];
    input Vk[32];
    input Qj[ROB_TAG_SIZE];
    input Qk[ROB_TAG_SIZE];
    input Dest[ROB_TAG_SIZE];
    input A[32];
    func_in issue(Valid, Op, Vj, Vk, Qj, Qk, Dest, A);
    output Busy;
    func_in isBusy(): Busy;
    func_in flush();
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
    func_out dispatchable();
    output dispatch_entry[SIZEOF_RESERVATION_STATION_ENTRY_T];
    func_in dispatch(): dispatch_entry;
}

#endif
