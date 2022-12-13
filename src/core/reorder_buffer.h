#ifndef REORDER_BUFFER_H
#define REORDER_BUFFER_H

#include "uops.h"
#define PTR2AGE(ptr, head) (if(ptr<head) ptr+((NUMBER_OF_REORDER_BUFFER*2)) else ptr)

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
    input req_issue_PC[30];
    input req_issue_valid0;
    input req_issue_uop0[SIZEOF_UOP_T];
    input req_issue_dreg0[5];
    input req_issue_preg0[6];
    input req_issue_ppreg0[6];
    input req_issue_cause0[SIZEOF_CAUSE_T];
    input req_issue_valid1;
    input req_issue_uop1[SIZEOF_UOP_T];
    input req_issue_dreg1[5];
    input req_issue_preg1[6];
    input req_issue_ppreg1[6];
    input req_issue_cause1[SIZEOF_CAUSE_T];
    output rsp_issue_ptr[REORDER_BUFFER_PTR_SIZE];
    output head_ptr_o[REORDER_BUFFER_PTR_SIZE];
    output head_o[LOG2_REORDER_BUFFER_NUM_OF_ENTRIES+1];
    output tail_o[LOG2_REORDER_BUFFER_NUM_OF_ENTRIES+1];
#ifdef ENABLE_DEBUG
    input req_issue_inst0[32];
    input req_issue_inst1[32];
    func_in req_issue(req_issue_PC, req_issue_valid0, req_issue_uop0, req_issue_dreg0, req_issue_preg0, req_issue_ppreg0, req_issue_cause0,
                      req_issue_valid1, req_issue_uop1, req_issue_dreg1, req_issue_preg1, req_issue_ppreg1, req_issue_cause1, req_issue_inst0, req_issue_inst1): rsp_issue_ptr;
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
    func_in req_issue(req_issue_PC, req_issue_valid0, req_issue_uop0, req_issue_dreg0, req_issue_preg0, req_issue_ppreg0, req_issue_cause0,
                      req_issue_valid1, req_issue_uop1, req_issue_dreg1, req_issue_preg1, req_issue_ppreg1, req_issue_cause1): rsp_issue_ptr;
#endif
	/* Execution time exception
	 * Instruction address misaligned
	 * Load address misaligned
	 * Load access fault
	 * Store/AMO address misaligned
	 * Store/AMO access fault
	 * Load page fault
	 * Store/AMO page fault
	 */
    input req_complete_alu0_ptr[REORDER_BUFFER_PTR_SIZE];
    input req_complete_alu0_taken;
    input req_complete_alu0_target[32];
	input req_complete_alu0_instruction_address_misaligned;
    func_in req_complete_alu0(req_complete_alu0_ptr, req_complete_alu0_taken, req_complete_alu0_target, req_complete_alu0_instruction_address_misaligned);
    input req_complete_alu1_ptr[REORDER_BUFFER_PTR_SIZE];
    input req_complete_alu1_taken;
    input req_complete_alu1_target[32];
	input req_complete_alu1_instruction_address_misaligned;
    func_in req_complete_alu1(req_complete_alu1_ptr, req_complete_alu1_taken, req_complete_alu1_target, req_complete_alu1_instruction_address_misaligned);
    input req_complete_lsu0_ptr[REORDER_BUFFER_PTR_SIZE];
    func_in req_complete_lsu0(req_complete_lsu0_ptr);
    input req_readPC0_ptr[REORDER_BUFFER_PTR_SIZE];
    output rsp_readPC0_PC[32];
    func_in req_readPC0(req_readPC0_ptr): rsp_readPC0_PC;
    input req_readPC1_ptr[REORDER_BUFFER_PTR_SIZE];
    output rsp_readPC1_PC[32];
    func_in req_readPC1(req_readPC1_ptr): rsp_readPC1_PC;
	output full_o;

    input meip_i;
    input msip_i;
    input mtip_i;
    input meie_i;
    input msie_i;
    input mtie_i;
    input mstatus_mie_i;
    input priv_mode_i[2];

	// to frontend
	output req_redirect_frontend_pc[32];
	func_out req_redirect_frontend(req_redirect_frontend_pc);
	// to pipeline
	func_out req_stall_pipeline();
	func_out req_flush_pipeline();
	// to LSU
	output req_lsu_commit_ptr[REORDER_BUFFER_PTR_SIZE];
	func_out req_lsu_commit(req_lsu_commit_ptr);
	output req_lsu_fencei_nextpc[32];
	func_out req_lsu_fencei(req_lsu_fencei_nextpc);
	// TO CSR
	output req_csr_commit_ptr[REORDER_BUFFER_PTR_SIZE];
	func_out req_csr_commit(req_csr_commit_ptr);
    output req_csr_trap_cause[32];
    output req_csr_trap_pc[32];
    output req_csr_trap_val[32];
    func_out req_csr_trap(req_csr_trap_cause, req_csr_trap_pc, req_csr_trap_val);
	func_out req_csr_mret();
	// to Freelist
	output req_freelist_push0_data[6];
	func_out req_freelist_push0(req_freelist_push0_data);
	output req_freelist_push1_data[6];
	func_out req_freelist_push1(req_freelist_push1_data);
	// to RMT(Register Map Table)
	output req_rmt_update0_dreg[5];
	output req_rmt_update0_preg[6];
	func_out req_rmt_update0(req_rmt_update0_dreg, req_rmt_update0_preg);
	output req_rmt_update1_dreg[5];
	output req_rmt_update1_preg[6];
	func_out req_rmt_update1(req_rmt_update1_dreg, req_rmt_update1_preg);
}

#endif
