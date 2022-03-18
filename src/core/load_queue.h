#ifndef LOAD_QUEUE_H
#define LOAD_QUEUE_H

#include "reorder_buffer.h"

#define LDQ_NUM_OF_ENTRIES 4.0
#define LOG2_LDQ_NUM_OF_ENTRIES _int(_log10(LDQ_NUM_OF_ENTRIES)/_log10(2.0))

struct load_queue_t {
	Valid;
	A[32];
	Op[7];
	RobId[LOG2_ROB_NUM_OF_ENTRIES];
#define SIZEOF_LOAD_QUEUE_T 40+LOG2_ROB_NUM_OF_ENTRIES
};

declare load_queue {
	input push_A[32];
	input push_Op[7];
	input push_RobId[LOG2_ROB_NUM_OF_ENTRIES];
	func_in push(push_A, push_Op, push_RobId);
	output pop_ldq_entry[SIZEOF_LOAD_QUEUE_T];
	func_in pop(): pop_ldq_entry;
	func_out full();
	func_out empty();
	func_in flush();
}

#endif
