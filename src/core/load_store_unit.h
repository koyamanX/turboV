#ifndef LOAD_STORE_UNIT_H
#define LOAD_STORE_UNIT_H

#include "wishbone_common.h"
#include "reorder_buffer.h"

declare load_store_unit {
    input issue_A[32];
    input issue_uOp[7];
    input issue_Qj[ROB_TAG_SIZE];
    input issue_Vj[32];
    input issue_RobId[ROB_TAG_SIZE];
    func_in issue(issue_A, issue_uOp, issue_Qj, issue_Vj, issue_RobId);
    func_out stall();
    func_out full();
    func_in flush();
    output CDBOutId[ROB_TAG_SIZE];
    output CDBOutVal[32];
    func_out CDBOut(CDBOutId, CDBOutVal);
    input commitId[ROB_TAG_SIZE];
    func_in commit(commitId);

    WISHBONE_GEN_MASTER_IF(32, 64, 8)
}

#endif
