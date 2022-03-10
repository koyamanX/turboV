#ifndef LOAD_QUEUE_H
#define LOAD_QUEUE_H

#include "reorder_buffer.h"

#define MOB_NUM_OF_ENTRIES 4.0
#define LOG2_MOB_NUM_OF_ENTRIES _int(_log10(MOB_NUM_OF_LDQ_ENTRIES)/_log10(2.0))

struct load_queue_t {
	Valid;
	A[32];
	RobId[LOG2_ROB_NUM_OF_ENTRIES];
};

declare load_queue {
	input A[32];
	input RobId[LOG2_ROB_NUM_OF_ENTRIES];
	func_in push(A, RobId);
	func_out full();
	func_in flush();
	func_in stall();
	func_out searchSTQ();
}

#endif
