#ifndef LOAD_STORE_UNIT_H
#define LOAD_STORE_UNIT_H

#include "wishbone_common.h"
#include "reorder_buffer.h"

declare load_store_unit {
    input issue_uOp[uOP_SIZE];
    input issue_addr[32];
    input issue_wdata[32];
	input issue_prd[6];
    input issue_ptr[REORDER_BUFFER_PTR_SIZE];
    func_in issue(issue_ptr, issue_prd, issue_uOp, issue_addr, issue_wdata);
    func_out stall();
    func_out full();
    func_in flush();
    output writeback_ptr[REORDER_BUFFER_PTR_SIZE];
    output writeback_prd[6];
    output writeback_data[32];
    func_out writeback(writeback_ptr, writeback_prd, writeback_data);
    input commit_ptr[REORDER_BUFFER_PTR_SIZE];
    func_in commit(commit_ptr);

    WISHBONE_GEN_MASTER_IF(32, 64, 8)
}

#endif
