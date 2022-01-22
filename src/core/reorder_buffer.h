#ifndef REORDER_BUFFER_H
#define REORDER_BUFFER_H

struct reorder_buffer_t {
	Valid0;
	Busy0;
	PC0[32];
	Inst0[32];
	Dest0[4];
	Value0[32];
	Valid1;
	Busy1;
	PC1[32];
	Inst1[32];
	Dest1[4];
	Value1[32];
#define SIZEOF_REORDER_BUFFER_T 204
};
declare reorder_buffer {
	input valid0;
	input pc0[32];
	input inst0[32];
	input dest0[4];
	input valid1;
	input pc1[32];
	input inst1[32];
	input dest1[4];
	output tag[2];
	func_in push(valid0, pc0, inst0, dest0, valid1, pc1, inst1, dest1): tag;
	func_in flush();
	func_out full();
	func_out commit();
}

#endif
