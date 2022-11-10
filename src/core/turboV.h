#ifndef TURBOV_H
#define TURBOV_H

#include "wishbone_common.h"
#include "reorder_buffer.h"

declare turboV {
    func_in reset();
    func_in timer_interrupt_req_hart0();
    func_in software_interrupt_req_hart0();

    WISHBONE_GEN_MASTER_IF(32, 64, 8)
#ifdef ENABLE_DEBUG
    output debug_commit_ptr0[REORDER_BUFFER_PTR_SIZE];
    output debug_commit_pc0[32];
    output debug_commit_inst0[32];
    output debug_commit_cause0[06];
    output debug_commit_rd_valid0;
    output debug_commit_dreg0[5];
    output debug_commit_preg0[6];
    output debug_commit_ppreg0[6];
    func_out debug_commit0(debug_commit_ptr0, debug_commit_pc0, debug_commit_inst0, debug_commit_cause0, debug_commit_rd_valid0, debug_commit_dreg0, debug_commit_preg0, debug_commit_ppreg0);
    output debug_commit_ptr1[REORDER_BUFFER_PTR_SIZE];
    output debug_commit_pc1[32];
    output debug_commit_inst1[32];
    output debug_commit_cause1[16];
    output debug_commit_rd_valid1;
    output debug_commit_dreg1[5];
    output debug_commit_preg1[6];
    output debug_commit_ppreg1[6];
    func_out debug_commit1(debug_commit_ptr1, debug_commit_pc1, debug_commit_inst1, debug_commit_cause1, debug_commit_rd_valid1, debug_commit_dreg1, debug_commit_preg1, debug_commit_ppreg1);
#endif
}

#endif
