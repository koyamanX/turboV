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
	Qj0[LOG2_ROB_NUM_OF_ENTRIES];
	Qk0[LOG2_ROB_NUM_OF_ENTRIES];
	Dest0[LOG2_ROB_NUM_OF_ENTRIES];
	A0[32];
	Busy1;
	Op1[7];
	Vj1[32];
	Vk1[32];
	Qj1[LOG2_ROB_NUM_OF_ENTRIES];
	Qk1[LOG2_ROB_NUM_OF_ENTRIES];
	Dest1[LOG2_ROB_NUM_OF_ENTRIES];
	A1[32];
#define SIZEOF_RESERVATION_STATION_T 220
};

declare reservation_station {
	input Valid0;
	input Op0[7];
	input Vj0[32];
	input Vk0[32];
	input Qj0[LOG2_ROB_NUM_OF_ENTRIES];
	input Qk0[LOG2_ROB_NUM_OF_ENTRIES];
	input Dest0[LOG2_ROB_NUM_OF_ENTRIES];
	input A0[32];
	input Valid1;
	input Op1[7];
	input Vj1[32];
	input Vk1[32];
	input Qj1[LOG2_ROB_NUM_OF_ENTRIES];
	input Qk1[LOG2_ROB_NUM_OF_ENTRIES];
	input Dest1[LOG2_ROB_NUM_OF_ENTRIES];
	input A1[32];
	func_in issue(Valid1, Op1, Vj1, Vk1, Qj1, Qk1, Dest1, A1, Valid0, Op0, Vj0, Vk0, Qj0, Qk0, Dest0, A0);
	func_in flush();
	func_out full();
	output dispatch0_Op[7];
	output dispatch0_Dest[LOG2_ROB_NUM_OF_ENTRIES];
	output dispatch0_Vj[32];
	output dispatch0_Vk[32];
	func_out dispatch0(dispatch0_Op, dispatch0_Dest, dispatch0_Vj, dispatch0_Vk);
	output dispatch1_Op[7];
	output dispatch1_Dest[LOG2_ROB_NUM_OF_ENTRIES];
	output dispatch1_Vj[32];
	output dispatch1_Vk[32];
	func_out dispatch1(dispatch1_Op, dispatch1_Dest, dispatch1_Vj, dispatch1_Vk);
	input CDB0Id[LOG2_ROB_NUM_OF_ENTRIES];
	input CDB0Val[32];
	func_in CDB0(CDB0Id, CDB0Val);
	input CDB1Id[LOG2_ROB_NUM_OF_ENTRIES];
	input CDB1Val[32];
	func_in CDB1(CDB1Id, CDB1Val);
}

#endif
