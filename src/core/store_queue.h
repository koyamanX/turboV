#ifndef STORE_QUEUE_H
#define STORE_QUEUE_H

#include "reorder_buffer.h"

#define STQ_NUM_OF_ENTRIES 8.0
#define LOG2_STQ_NUM_OF_ENTRIES _int(_log10(STQ_NUM_OF_ENTRIES)/_log10(2.0))

struct store_queue_t {
	Valid;
	A[32];
	Qk[ROB_TAG_SIZE];
	Vk[32];
	Op[7];
	RobId[ROB_TAG_SIZE];
	Commited;
#define SIZEOF_STORE_QUEUE_T 64+2+ROB_TAG_SIZE+ROB_TAG_SIZE+7
};

declare store_queue {
	input A[32];
	input Qk[ROB_TAG_SIZE];
	input Vk[32];
	input Op[7];
	input RobId[ROB_TAG_SIZE];
	func_in push(A, Qk, Vk, Op, RobId);
	func_out full();
	func_out empty();
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
	input commitId[ROB_TAG_SIZE];
	func_in commit(commitId);
}

#endif
