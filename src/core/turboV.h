#ifndef TURBOV_H
#define TURBOV_H

#include "wishbone_common.h"

declare turboV {
    func_in reset();
    func_in timer_interrupt_req_hart0();
    func_in software_interrupt_req_hart0();

    WISHBONE_GEN_MASTER_IF(32, 64, 8)
#ifdef ENABLE_DEBUG
    output debug_commit_pc0[32];
    output debug_commit_inst0[32];
    output debug_commit_cause0[16];
    func_out debug_commit0(debug_commit_pc0, debug_commit_inst0, debug_commit_cause0);
    output debug_commit_pc1[32];
    output debug_commit_inst1[32];
    output debug_commit_cause1[16];
    func_out debug_commit1(debug_commit_pc1, debug_commit_inst1, debug_commit_cause1);
#endif
}

#endif
