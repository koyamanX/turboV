#ifndef TURBOV_H
#define TURBOV_H

#include "wishbone_common.h"
#include "consts.h"

#define BUSY 1'b1
#define READY 1'b0

declare turboV {
    func_in reset();
    func_in timer_interrupt_req_hart0();
    func_in software_interrupt_req_hart0();

    WISHBONE_GEN_MASTER_IF(32, 64, 8)
#ifdef ENABLE_DEBUG
    output debug_commit_pc0[32];
    output debug_commit_inst0[32];
    output debug_commit_cause0[16];
    output debug_commit0_prd[ROB_TAG_SIZE];
    output debug_commit0_prs1[ROB_TAG_SIZE];
    output debug_commit0_prs2[ROB_TAG_SIZE];
    func_out debug_commit0(debug_commit_pc0, debug_commit_inst0, debug_commit_cause0, debug_commit0_prd, debug_commit0_prs1, debug_commit0_prs2);
    output debug_commit_pc1[32];
    output debug_commit_inst1[32];
    output debug_commit_cause1[16];
    output debug_commit1_prd[ROB_TAG_SIZE];
    output debug_commit1_prs1[ROB_TAG_SIZE];
    output debug_commit1_prs2[ROB_TAG_SIZE];
    func_out debug_commit1(debug_commit_pc1, debug_commit_inst1, debug_commit_cause1, debug_commit1_prd, debug_commit1_prs1, debug_commit1_prs2);
#endif
}

#endif
