#ifndef REORDER_BUFFER_H
#define REORDER_BUFFER_H

#include "uops.h"
#define PTR2AGE(ptr, head) (if(ptr<head) ptr+((NUMBER_OF_REORDER_BUFFER*2)-1) else ptr)

struct reorder_buffer_t {
    PC[30];        // {PC[29:0], 2'b00}
    valid0;
    uop0[SIZEOF_UOP_T];
    dreg0[5];
    preg0[6];
    ppreg0[6];
    cause0[SIZEOF_CAUSE_T];
    taken0;
    target0[32];
    completed0;
    valid1;
    uop1[SIZEOF_UOP_T];
    dreg1[5];
    preg1[6];
    ppreg1[6];
    cause1[SIZEOF_CAUSE_T];
    taken1;
    target1[32];
    completed1;
#ifdef ENABLE_DEBUG
    inst0[32];
    inst1[32];
#define SIZEOF_REORDER_BUFFER_T 55+SIZEOF_UOP_T+SIZEOF_UOP_T+SIZEOF_CAUSE_T+SIZEOF_CAUSE_T+32+32+12+2+64+1
#else
#define SIZEOF_REORDER_BUFFER_T 55+SIZEOF_UOP_T+SIZEOF_UOP_T+SIZEOF_CAUSE_T+SIZEOF_CAUSE_T+1
#endif
};

#define NUMBER_OF_REORDER_BUFFER 8
#define REORDER_BUFFER_NUM_OF_ENTRIES NUMBER_OF_REORDER_BUFFER.0
#define LOG2_REORDER_BUFFER_NUM_OF_ENTRIES _int(_log10(REORDER_BUFFER_NUM_OF_ENTRIES)/_log10(2.0))
#define REORDER_BUFFER_PTR_SIZE LOG2_REORDER_BUFFER_NUM_OF_ENTRIES+1

declare reorder_buffer {
    input PC[30];
    input valid0;
    input uop0[SIZEOF_UOP_T];
    input dreg0[5];
    input preg0[6];
    input ppreg0[6];
    input cause0[SIZEOF_CAUSE_T];
    input valid1;
    input uop1[SIZEOF_UOP_T];
    input dreg1[5];
    input preg1[6];
    input ppreg1[6];
    input cause1[SIZEOF_CAUSE_T];
    output ptr[REORDER_BUFFER_PTR_SIZE];
    output head_ptr[REORDER_BUFFER_PTR_SIZE];
    output head_o[LOG2_REORDER_BUFFER_NUM_OF_ENTRIES+1];
    output tail_o[LOG2_REORDER_BUFFER_NUM_OF_ENTRIES+1];
#ifdef ENABLE_DEBUG
    input inst0[32];
    input inst1[32];
    func_in issue(PC, valid0, uop0, dreg0, preg0, ppreg0, cause0,
                      valid1, uop1, dreg1, preg1, ppreg1, cause1, inst0, inst1): ptr;
    output debug_commit_ptr0[REORDER_BUFFER_PTR_SIZE];
    output debug_commit_kill0;
    output debug_commit_pc0[32];
    output debug_commit_inst0[32];
    output debug_commit_cause0[06];
    output debug_commit_rd_valid0;
    output debug_commit_dreg0[5];
    output debug_commit_preg0[6];
    output debug_commit_ppreg0[6];
    func_out debug_commit0(debug_commit_ptr0, debug_commit_kill0, debug_commit_pc0,
							debug_commit_inst0, debug_commit_cause0, debug_commit_rd_valid0,
							debug_commit_dreg0, debug_commit_preg0, debug_commit_ppreg0);
    output debug_commit_ptr1[REORDER_BUFFER_PTR_SIZE];
    output debug_commit_kill1;
    output debug_commit_pc1[32];
    output debug_commit_inst1[32];
    output debug_commit_cause1[16];
    output debug_commit_rd_valid1;
    output debug_commit_dreg1[5];
    output debug_commit_preg1[6];
    output debug_commit_ppreg1[6];
    func_out debug_commit1(debug_commit_ptr1, debug_commit_kill1, debug_commit_pc1,
							debug_commit_inst1, debug_commit_cause1, debug_commit_rd_valid1,
							debug_commit_dreg1, debug_commit_preg1, debug_commit_ppreg1);
#else
    func_in issue(PC, valid0, uop0, dreg0, preg0, ppreg0, cause0,
                      valid1, uop1, dreg1, preg1, ppreg1, cause1): ptr;
#endif
	/* Execution time exception
	 * Illegal instruction
	 * Instruction address misaligned
	 * Load address misaligned
	 * Load access fault
	 * Store/AMO address misaligned
	 * Store/AMO access fault
	 * Load page fault
	 * Store/AMO page fault
	 */
    input complete_alu0_ptr[REORDER_BUFFER_PTR_SIZE];
    input complete_alu0_taken;
    input complete_alu0_target[32];
    input complete_alu0_illegal;
    func_in complete_alu0(complete_alu0_ptr, complete_alu0_taken, complete_alu0_target, complete_alu0_illegal);
    input complete_alu1_ptr[REORDER_BUFFER_PTR_SIZE];
    input complete_alu1_taken;
    input complete_alu1_target[32];
    func_in complete_alu1(complete_alu1_ptr, complete_alu1_taken, complete_alu1_target);
    input complete_lsu0_ptr[REORDER_BUFFER_PTR_SIZE];
    func_in complete_lsu0(complete_lsu0_ptr);
    input readPC0_ptr[REORDER_BUFFER_PTR_SIZE];
    output PC0[32];
    func_in readPC0(readPC0_ptr): PC0;
    input readPC1_ptr[REORDER_BUFFER_PTR_SIZE];
    output PC1[32];
    func_in readPC1(readPC1_ptr): PC1;
	func_out full();

	// to frontend
	output redirect_frontend_pc[32];
	func_out redirect_frontend(redirect_frontend_pc);
	// to pipeline
	func_out stall_pipeline();
	func_out flush_pipeline();
	// to LSU
	output lsu_commit_ptr[REORDER_BUFFER_PTR_SIZE];
	func_out lsu_commit(lsu_commit_ptr);
	// TO CSR
	output csr_commit_ptr[REORDER_BUFFER_PTR_SIZE];
	func_out csr_commit(csr_commit_ptr);
    output csr_trap_cause[32];
    output csr_trap_pc[32];
    output csr_trap_val[32];
    func_out csr_trap(csr_trap_cause, csr_trap_pc, csr_trap_val);
	func_out csr_mret();
	// to Freelist
	output freelist_push0_data[6];
	func_out freelist_push0(freelist_push0_data);
	output freelist_push1_data[6];
	func_out freelist_push1(freelist_push1_data);
	// to RMT(Register Map Table)
	output rmt_update0_dreg[5];
	output rmt_update0_preg[6];
	func_out rmt_update0(rmt_update0_dreg, rmt_update0_preg);
	output rmt_update1_dreg[5];
	output rmt_update1_preg[6];
	func_out rmt_update1(rmt_update1_dreg, rmt_update1_preg);
}

#endif
