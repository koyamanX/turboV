#ifndef RESERVATION_STATION_IN_ORDER_2WAY_H
#define RESERVATION_STATION_IN_ORDER_2WAY_H

#include "reorder_buffer.h"

#define RS_IN_ORDER_2WAY_NUM_OF_ENTRIES 4.0
#define LOG2_RS_IN_ORDER_2WAY_NUM_OF_ENTRIES _int(_log10(RS_IN_ORDER_2WAY_NUM_OF_ENTRIES)/_log10(2.0))

struct reservation_station_2way_t {
	Busy0;
	Op0[7];
	Vj0[32];
	Vk0[32];
	Qj0[ROB_TAG_SIZE];
	Qk0[ROB_TAG_SIZE];
	Dest0[ROB_TAG_SIZE];
	A0[32];
	Busy1;
	Op1[7];
	Vj1[32];
	Vk1[32];
	Qj1[ROB_TAG_SIZE];
	Qk1[ROB_TAG_SIZE];
	Dest1[ROB_TAG_SIZE];
	A1[32];
	#define SIZEOF_RESERVATION_STATION_T 232
};

declare reservation_station_in_order_2way {
	input Valid0;
	input Op0[7];
	input Vj0[32];
	input Vk0[32];
	input Qj0[ROB_TAG_SIZE];
	input Qk0[ROB_TAG_SIZE];
	input Dest0[ROB_TAG_SIZE];
	input A0[32];
	input Valid1;
	input Op1[7];
	input Vj1[32];
	input Vk1[32];
	input Qj1[ROB_TAG_SIZE];
	input Qk1[ROB_TAG_SIZE];
	input Dest1[ROB_TAG_SIZE];
	input A1[32];
	func_in issue(Valid0, Op0, Vj0, Vk0, Qj0, Qk0, Dest0, A0, Valid1, Op1, Vj1, Vk1, Qj1, Qk1, Dest1, A1);
	func_in flush();
	func_out full();
	func_in stall();
	output dispatch_Op0[7];
	output dispatch_Dest0[ROB_TAG_SIZE];
	output dispatch_Vj0[32];
	output dispatch_Vk0[32];
	output dispatch_A0[32];
	func_out dispatch0(dispatch_Op0, dispatch_Dest0, dispatch_Vj0, dispatch_Vk0, dispatch_A0);
	output dispatch_Op1[7];
	output dispatch_Dest1[ROB_TAG_SIZE];
	output dispatch_Vj1[32];
	output dispatch_Vk1[32];
	output dispatch_A1[32];
	func_out dispatch1(dispatch_Op1, dispatch_Dest1, dispatch_Vj1, dispatch_Vk1, dispatch_A1);
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
