#ifndef STORE_QUEUE_H
#define STORE_QUEUE_H

#include "reorder_buffer.h"

#define MOB_NUM_OF_ENTRIES 8.0
#define LOG2_STQ_NUM_OF_ENTRIES _int(_log10(STQ_NUM_OF_ENTRIES)/_log10(2.0))

struct store_queue_t {
	Valid;
	A[32];
	Qj[ROB_TAG_SIZE];
	Vj[32];
	RobId[ROB_TAG_SIZE];
	Commited;
#define SIZEOF_STORE_QUEUE_T 64+2+ROB_TAG_SIZE+ROB_TAG_SIZE
};

declare store_queue {
	input A[32];
	input Qj[ROB_TAG_SIZE];
	input Vj[32];
	input RobId[ROB_TAG_SIZE];
	func_in push(A, Qj, Vj, RobId);
	func_out full();
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
	input commitId[LOG2_ROB_NUM_OF_ENTRIES];
	func_in commit(commitId);
}

#endif
