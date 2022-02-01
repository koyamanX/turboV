#ifndef REORDER_BUFFER_H
#define REORDER_BUFFER_H

#define ROB_NUM_OF_ENTRIES 4.0
#define LOG2_ROB_NUM_OF_ENTRIES _int(_log10(ROB_NUM_OF_ENTRIES)/_log10(2.0))

struct reorder_buffer_t {
	Valid0;
	Busy0;
	PC0[32];
	Inst0[32];
	Dest0[5];
	Value0[32];
	Valid1;
	Busy1;
	PC1[32];
	Inst1[32];
	Dest1[5];
	Value1[32];
#define SIZEOF_REORDER_BUFFER_T 206
};
declare reorder_buffer {
	input valid0;
	input pc0[32];
	input inst0[32];
	input dest0[5];
	input valid1;
	input pc1[32];
	input inst1[32];
	input dest1[5];
	/* tag start from 0 */
	output tag[LOG2_ROB_NUM_OF_ENTRIES+1];
	func_in push(valid0, pc0, inst0, dest0, valid1, pc1, inst1, dest1): tag;
	func_in flush();
	func_out full();
	output commit_Dest0[5];
	output commit_Value0[32];
	output commit_Dest1[5];
	output commit_Value1[32];
	func_out commit(commit_Dest0, commit_Value0, commit_Dest1, commit_Value1);
	input CDB0Id[LOG2_ROB_NUM_OF_ENTRIES];
	input CDB0Val[32];
	func_in CDB0(CDB0Id, CDB0Val);
	input CDB1Id[LOG2_ROB_NUM_OF_ENTRIES];
	input CDB1Val[32];
	func_in CDB1(CDB1Id, CDB1Val);
	output read_operandA_val[32];
	input read_operandA_id[LOG2_ROB_NUM_OF_ENTRIES];
	output read_operandA_busy;
	func_in read_operandA(read_operandA_id): read_operandA_busy;
	output read_operandB_val[32];
	input read_operandB_id[LOG2_ROB_NUM_OF_ENTRIES];
	output read_operandB_busy;
	func_in read_operandB(read_operandB_id): read_operandB_busy;
	output read_operandC_val[32];
	input read_operandC_id[LOG2_ROB_NUM_OF_ENTRIES];
	output read_operandC_busy;
	func_in read_operandC(read_operandC_id): read_operandC_busy;
	output read_operandD_val[32];
	input read_operandD_id[LOG2_ROB_NUM_OF_ENTRIES];
	output read_operandD_busy;
	func_in read_operandD(read_operandD_id): read_operandD_busy;
}
#endif
