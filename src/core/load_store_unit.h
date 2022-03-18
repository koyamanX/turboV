#ifndef LOAD_STORE_UNIT_H
#define LOAD_STORE_UNIT_H

#include "wishbone_common.h"
#include "reorder_buffer.h"

declare load_store_unit {
	input issue0_A[32];
	input issue0_uOp[7];
	input issue0_Qj[LOG2_ROB_NUM_OF_ENTRIES];
	input issue0_Vj[32];
	input issue0_RobId[LOG2_ROB_NUM_OF_ENTRIES];
	func_in issue0(issue0_A, issue0_uOp, issue0_Qj, issue0_Vj, issue0_RobId);
	input issue1_A[32];
	input issue1_uOp[7];
	input issue1_Qj[LOG2_ROB_NUM_OF_ENTRIES];
	input issue1_Vj[32];
	input issue1_RobId[LOG2_ROB_NUM_OF_ENTRIES];
	func_in issue1(issue1_A, issue1_uOp, issue1_Qj, issue1_Vj, issue1_RobId);
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
	output CDBOutId[ROB_TAG_SIZE];
	output CDBOutVal[32];
	func_out CDBOut(CDBOutId, CDBOutVal);
	input commitId[LOG2_ROB_NUM_OF_ENTRIES];
	func_in commit(commitId);
	func_out stall();

	WISHBONE_GEN_MASTER_IF(32, 64, 8)
}

#endif
