#ifndef RESERVATION_STATION_H
#define RESERVATION_STATION_H

#include "reorder_buffer.h"

#define RS_NUM_OF_ENTRIES 4.0
#define LOG2_RS_NUM_OF_ENTRIES _int(_log10(RS_NUM_OF_ENTRIES)/_log10(2.0))

struct reservation_station_t {
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

declare reservation_station {
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
	func_in issue(Valid1, Op1, Vj1, Vk1, Qj1, Qk1, Dest1, A1, Valid0, Op0, Vj0, Vk0, Qj0, Qk0, Dest0, A0);
	func_in flush();
	func_out full();
	output dispatch0_Op[7];
	output dispatch0_Dest[ROB_TAG_SIZE];
	output dispatch0_Vj[32];
	output dispatch0_Vk[32];
	func_out dispatch0(dispatch0_Op, dispatch0_Dest, dispatch0_Vj, dispatch0_Vk);
	output dispatch1_Op[7];
	output dispatch1_Dest[ROB_TAG_SIZE];
	output dispatch1_Vj[32];
	output dispatch1_Vk[32];
	func_out dispatch1(dispatch1_Op, dispatch1_Dest, dispatch1_Vj, dispatch1_Vk);
	input CDB0Id[ROB_TAG_SIZE];
	input CDB0Val[32];
	func_in CDB0(CDB0Id, CDB0Val);
	input CDB1Id[ROB_TAG_SIZE];
	input CDB1Val[32];
	func_in CDB1(CDB1Id, CDB1Val);
}

#endif