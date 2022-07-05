#ifndef REORDER_BUFFER_H
#define REORDER_BUFFER_H

#include "uops.h"
#define ROB_NUM_OF_ENTRIES 4.0
#define LOG2_ROB_NUM_OF_ENTRIES _int(_log10(ROB_NUM_OF_ENTRIES)/_log10(2.0))
#define ROB_TAG_SIZE LOG2_ROB_NUM_OF_ENTRIES+2

struct reorder_buffer_t {
    Valid0;
    Busy0;
    PC0[32];
    Inst0[32];
    Value0[32];
    uOp0[SIZEOF_UOP_T];
    Target0[32];
    Valid1;
    Busy1;
    PC1[32];
    Inst1[32];
    Value1[32];
    uOp1[SIZEOF_UOP_T];
    Target1[32];
    CSR_num[12];
    CSR_Value[32];
#define SIZEOF_REORDER_BUFFER_T 304+SIZEOF_UOP_T+SIZEOF_UOP_T
};
declare reorder_buffer {
    input valid0;
    input pc0[32];
    input inst0[32];
    input uop0[SIZEOF_UOP_T];
    input valid1;
    input pc1[32];
    input inst1[32];
    input uop1[SIZEOF_UOP_T];
    input csr_num[12];
    input csr_value[32];
    output tag[ROB_TAG_SIZE];
    func_in issue(valid0, pc0, inst0, uop0, valid1, pc1, inst1, uop1, csr_num, csr_value): tag;
    func_in flush();
    func_out full();
    func_in commit_stall();
    output commit_Valid0;
    output commit_Value0[32];
    output commit_uOp0[SIZEOF_UOP_T];
    output commit_PC0[32];
    output commit_Target0[32];
    output commit_Inst0[32];
    output commit_Valid1;
    output commit_Value1[32];
    output commit_uOp1[SIZEOF_UOP_T];
    output commit_PC1[32];
    output commit_Target1[32];
    output commit_Inst1[32];
    output commit_CSR_num[12];
    output commit_CSR_Value[32];
    output commit_Id[ROB_TAG_SIZE];
    func_out commit(commit_Id,
                    commit_Valid0, commit_Value0, commit_uOp0, commit_PC0, commit_Target0, commit_Inst0,
                    commit_Valid1, commit_Value1, commit_uOp1, commit_PC1, commit_Target1, commit_Inst1,
                    commit_CSR_num, commit_CSR_Value);
    input CDB0Id[ROB_TAG_SIZE];
    input CDB0Val[32];
    func_in CDB0(CDB0Id, CDB0Val);
    input CDB1Id[ROB_TAG_SIZE];
    input CDB1Val[32];
    func_in CDB1(CDB1Id, CDB1Val);
    input CDB2Id[ROB_TAG_SIZE];
    input CDB2Val[32];
    input CDB2Target[32];
    func_in CDB2(CDB2Id, CDB2Val, CDB2Target);
    input CDB3Id[ROB_TAG_SIZE];
    input CDB3Val[32];
    func_in CDB3(CDB3Id, CDB3Val);
    // TODO:
    input StqId[ROB_TAG_SIZE];
    func_in Store(StqId);
    output read_operandA_val[32];
    input read_operandA_id[ROB_TAG_SIZE];
    output read_operandA_busy;
    func_in read_operandA(read_operandA_id): read_operandA_busy;
    output read_operandB_val[32];
    input read_operandB_id[ROB_TAG_SIZE];
    output read_operandB_busy;
    func_in read_operandB(read_operandB_id): read_operandB_busy;
    output read_operandC_val[32];
    input read_operandC_id[ROB_TAG_SIZE];
    output read_operandC_busy;
    func_in read_operandC(read_operandC_id): read_operandC_busy;
    output read_operandD_val[32];
    input read_operandD_id[ROB_TAG_SIZE];
    output read_operandD_busy;
    func_in read_operandD(read_operandD_id): read_operandD_busy;
}
#endif
