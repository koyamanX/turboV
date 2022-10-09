#ifndef ISSUE_QUEUE_H
#define ISSUE_QUEUE_H

#include "uops.h"

struct issue_queue_t {
	valid;
    uop[uOP_SIZE];
    prs1[6];
	prs1_valid;
	prs1_ready;
    prs2[6];
	prs2_ready;
	prs2_valid;
    prd[6];
    imm[32];
    #define SIZEOF_ISSUE_QUEUE_T uOP_SIZE+18+32+3
};

declare issue_queue {
    input uop[uOP_SIZE];
    input prd[6];
	input prs1_valid;
	input prs1_ready;
    input prs1[6];
	input prs2_valid;
	input prs2_ready;
    input prs2[6];
    input imm[32];
    func_in issue(uop, prd, prs1_valid, prs1_ready, prs1, prs2_valid, prs2_ready, prs2, imm);
    func_in flush();
    func_out full();
    func_in stall();
    output dispatch_uop[uOP_SIZE];
    output dispatch_prd[6];
    output dispatch_prs1[6];
    output dispatch_prs2[6];
    output dispatch_imm[32];
    func_out dispatch(dispatch_uop, dispatch_prd, dispatch_prs1, dispatch_prs2, dispatch_imm);
	input wakeup0_prd[6];
	func_in wakeup0(wakeup0_prd);
	input wakeup1_prd[6];
	func_in wakeup1(wakeup1_prd);
	input wakeup2_prd[6];
	func_in wakeup2(wakeup2_prd);
}

#endif
