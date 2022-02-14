#ifndef RESERVATION_STATION_H
#define RESERVATION_STATION_H

#include "reorder_buffer.h"

#define RS_NUM_OF_ENTRIES 4.0
#define LOG2_RS_NUM_OF_ENTRIES _int(_log10(RS_NUM_OF_ENTRIES)/_log10(2.0))

struct reservation_station_t {
	Busy;
	Op[7];
	Vj[32];
	Vk[32];
	Qj[ROB_TAG_SIZE];
	Qk[ROB_TAG_SIZE];
	Dest[ROB_TAG_SIZE];
	A[32];
	#define SIZEOF_RESERVATION_STATION_T 116
};

declare reservation_station {
	input Valid;
	input Op[7];
	input Vj[32];
	input Vk[32];
	input Qj[ROB_TAG_SIZE];
	input Qk[ROB_TAG_SIZE];
	input Dest[ROB_TAG_SIZE];
	input A[32];
	func_in issue(Valid, Op, Vj, Vk, Qj, Qk, Dest, A);
	func_in flush();
	func_out full();
	output dispatch_Op[7];
	output dispatch_Dest[ROB_TAG_SIZE];
	output dispatch_Vj[32];
	output dispatch_Vk[32];
	func_out dispatch(dispatch_Op, dispatch_Dest, dispatch_Vj, dispatch_Vk);
	input CDB0Id[ROB_TAG_SIZE];
	input CDB0Val[32];
	func_in CDB0(CDB0Id, CDB0Val);
	input CDB1Id[ROB_TAG_SIZE];
	input CDB1Val[32];
	func_in CDB1(CDB1Id, CDB1Val);
	input CDB2Id[ROB_TAG_SIZE];
	input CDB2Val[32];
	func_in CDB2(CDB2Id, CDB2Val);
}

#endif
