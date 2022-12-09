#ifndef ISSUE_QUEUE_IN_ORDER_H
#define ISSUE_QUEUE_IN_ORDER_H

#include "uops.h"
#include "reorder_buffer.h"

#define READY 1'b1
#define BUSY 1'b0

#define NUMBER_OF_ISSUE_QUEUE_IN_ORDER 4
#define ISSUE_QUEUE_IN_ORDER_NUM_OF_ENTRIES NUMBER_OF_ISSUE_QUEUE_IN_ORDER.0
#define LOG2_ISSUE_QUEUE_IN_ORDER_NUM_OF_ENTRIES _int(_log10(ISSUE_QUEUE_IN_ORDER_NUM_OF_ENTRIES)/_log10(2.0))

struct issue_queue_in_order_t {
    valid;
    ptr[REORDER_BUFFER_PTR_SIZE];
    uop[SIZEOF_UOP_T];
    prs1[6];
    prs1_ready;
    prs2[6];
    prs2_ready;
    prd[6];
    // pure IMM or IMM+PC
    imm[32];
    #define SIZEOF_ISSUE_QUEUE_IN_ORDER_T REORDER_BUFFER_PTR_SIZE+uOP_SIZE+18+32+1
};

declare issue_queue_in_order {
    input req_issue_ptr[REORDER_BUFFER_PTR_SIZE];
    input req_issue_uop[SIZEOF_UOP_T];
    input req_issue_prd[6];
    input req_issue_prs1_ready;
    input req_issue_prs1[6];
    input req_issue_prs2_ready;
    input req_issue_prs2[6];
    input req_issue_imm[32];
    func_in req_issue(req_issue_ptr, req_issue_uop, req_issue_prd,
			req_issue_prs1_ready, req_issue_prs1,
			req_issue_prs2_ready, req_issue_prs2,
			req_issue_imm);
    func_in req_flush();
    output full;
    func_in req_stall();
    output req_dispatch_ptr[REORDER_BUFFER_PTR_SIZE];
    output req_dispatch_uop[SIZEOF_UOP_T];
    output req_dispatch_prd[6];
    output req_dispatch_prs1[6];
    output req_dispatch_prs2[6];
    output req_dispatch_imm[32];
    func_out req_dispatch(req_dispatch_ptr, req_dispatch_uop, req_dispatch_prd,
			req_dispatch_prs1, req_dispatch_prs2, req_dispatch_imm);
    input req_wakeup0_prd[6];
    func_in req_wakeup0(req_wakeup0_prd);
    input req_wakeup1_prd[6];
    func_in req_wakeup1(req_wakeup1_prd);
    input req_wakeup2_prd[6];
    func_in req_wakeup2(req_wakeup2_prd);
}

#endif
