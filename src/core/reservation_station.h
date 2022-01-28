#ifndef RESERVATION_STATION_H
#define RESERVATION_STATION_H

/* TODO: fix field size */
struct reservation_station_t {
	Busy0;
	Tag0[4];
	Op0[7];
	Vj0[32];
	Vk0[32];
	Qj0[6];
	Qk0[6];
	Dest0[6];
	A0[32];
	Busy1;
	Tag1[4];
	Op1[7];
	Vj1[32];
	Vk1[32];
	Qj1[6];
	Qk1[6];
	Dest1[6];
	A1[32];
#define SIZEOF_RESERVATION_STATION_T 252
};

declare reservation_station {
	input Valid0;
	input Op0[7];
	input Vj0[32];
	input Vk0[32];
	input Qj0[6];
	input Qk0[6];
	input Dest0[6];
	input A0[32];
	input Valid1;
	input Op1[7];
	input Vj1[32];
	input Vk1[32];
	input Qj1[6];
	input Qk1[6];
	input Dest1[6];
	input A1[32];
	output rs_tag[4];
	func_in issue(Valid1, Op1, Vj1, Vk1, Qj1, Qk1, Dest1, A1, Valid0, Op0, Vj0, Vk0, Qj0, Qk0, Dest0, A0): rs_tag;
	func_in flush();
	func_out full();
	func_out dispatch0();
	func_out dispatch1();
	input CDB0Id[6];
	input CDB0Val[32];
	func_in CDB0(CDB0Id, CDB0Val);
	input CDB1Id[6];
	input CDB1Val[32];
	func_in CDB1(CDB1Id, CDB1Val);
}

#endif
