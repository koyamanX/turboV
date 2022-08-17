#ifndef REORDER_BUFFER_EXEC_H
#define REORDER_BUFFER_EXEC_H

declare reorder_buffer_exec {
    input read_operandA_addr[LOG2_ROB_NUM_OF_ENTRIES];
    output read_operandA_data[SIZEOF_REORDER_BUFFER_CDB_T];
    func_in read_operandA(read_operandA_addr): read_operandA_data;
    input read_operandB_addr[LOG2_ROB_NUM_OF_ENTRIES];
    output read_operandB_data[SIZEOF_REORDER_BUFFER_CDB_T];
    func_in read_operandB(read_operandB_addr): read_operandB_data;
    input read_operandC_addr[LOG2_ROB_NUM_OF_ENTRIES];
    output read_operandC_data[SIZEOF_REORDER_BUFFER_CDB_T];
    func_in read_operandC(read_operandC_addr): read_operandC_data;
    input read_operandD_addr[LOG2_ROB_NUM_OF_ENTRIES];
    output read_operandD_data[SIZEOF_REORDER_BUFFER_CDB_T];
    func_in read_operandD(read_operandD_addr): read_operandD_data;
    input commit_addr[LOG2_ROB_NUM_OF_ENTRIES];
    output commit_data[SIZEOF_REORDER_BUFFER_CDB_T];
    func_in commit(commit_addr): commit_data;

    input CDB0_addr[LOG2_ROB_NUM_OF_ENTRIES];
    input CDB0_data[SIZEOF_REORDER_BUFFER_CDB_T];
    func_in CDB0(CDB0_addr, CDB0_data);
    input CDB1_addr[LOG2_ROB_NUM_OF_ENTRIES];
    input CDB1_data[SIZEOF_REORDER_BUFFER_CDB_T];
    func_in CDB1(CDB1_addr, CDB1_data);
    input CDB2_addr[LOG2_ROB_NUM_OF_ENTRIES];
    input CDB2_data[SIZEOF_REORDER_BUFFER_CDB_T];
    func_in CDB2(CDB2_addr, CDB2_data);
    input CDB3_addr[LOG2_ROB_NUM_OF_ENTRIES];
    input CDB3_data[SIZEOF_REORDER_BUFFER_CDB_T];
    func_in CDB3(CDB3_addr, CDB3_data);
    input issue_addr[LOG2_ROB_NUM_OF_ENTRIES];
    input issue_data[SIZEOF_REORDER_BUFFER_CDB_T];
    func_in issue(issue_addr, issue_data);
}

#endif
