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
	output debug_rename0_ptr[REORDER_BUFFER_PTR_SIZE];
	output debug_rename0_pc[32];
	output debug_rename0_inst[32];
	output debug_rename0_rd_valid;
	output debug_rename0_lrd[5];
	output debug_rename0_prd[6];
	output debug_rename0_pprd[6];
	output debug_rename0_rs1_valid;
	output debug_rename0_rs1_ready;
	output debug_rename0_lrs1[5];
	output debug_rename0_prs1[6];
	output debug_rename0_rs2_valid;
	output debug_rename0_rs2_ready;
	output debug_rename0_lrs2[5];
	output debug_rename0_prs2[6];
	output debug_rename0_cause[16];
	output debug_rename0_imm[32];
	func_out debug_rename0(debug_rename0_ptr, debug_rename0_pc, debug_rename0_inst,
			debug_rename0_rd_valid, debug_rename0_lrd, debug_rename0_prd, debug_rename0_pprd,
			debug_rename0_rs1_valid, debug_rename0_rs1_ready, debug_rename0_lrs1, debug_rename0_prs1,
			debug_rename0_rs2_valid, debug_rename0_rs2_ready, debug_rename0_lrs2, debug_rename0_prs2,
			debug_rename0_cause, debug_rename0_imm);

	output debug_rename1_ptr[REORDER_BUFFER_PTR_SIZE];
	output debug_rename1_pc[32];
	output debug_rename1_inst[32];
	output debug_rename1_rd_valid;
	output debug_rename1_lrd[5];
	output debug_rename1_prd[6];
	output debug_rename1_pprd[6];
	output debug_rename1_rs1_valid;
	output debug_rename1_rs1_ready;
	output debug_rename1_lrs1[5];
	output debug_rename1_prs1[6];
	output debug_rename1_rs2_valid;
	output debug_rename1_rs2_ready;
	output debug_rename1_lrs2[5];
	output debug_rename1_prs2[6];
	output debug_rename1_cause[16];
	output debug_rename1_imm[32];
	func_out debug_rename1(debug_rename1_ptr, debug_rename1_pc, debug_rename1_inst,
			debug_rename1_rd_valid, debug_rename1_lrd, debug_rename1_prd, debug_rename1_pprd,
			debug_rename1_rs1_valid, debug_rename1_rs1_ready, debug_rename1_lrs1, debug_rename1_prs1,
			debug_rename1_rs2_valid, debug_rename1_rs2_ready, debug_rename1_lrs2, debug_rename1_prs2,
			debug_rename1_cause, debug_rename1_imm);

	output debug_dispatch0_ptr[REORDER_BUFFER_PTR_SIZE];
	output debug_dispatch0_pc[32];
	output debug_dispatch0_rd_valid;
	output debug_dispatch0_prd[6];
	output debug_dispatch0_rs1_sel[2];
	output debug_dispatch0_rs1_valid;
	output debug_dispatch0_prs1[6];
	output debug_dispatch0_rs1_data[32];
	output debug_dispatch0_rs2_sel[2];
	output debug_dispatch0_rs2_valid;
	output debug_dispatch0_prs2[6];
	output debug_dispatch0_rs2_data[32];
	func_out debug_dispatch0(debug_dispatch0_ptr, debug_dispatch0_pc, debug_dispatch0_rd_valid, debug_dispatch0_prd,
			debug_dispatch0_rs1_sel, debug_dispatch0_rs1_valid, debug_dispatch0_prs1, debug_dispatch0_rs1_data,
			debug_dispatch0_rs2_sel, debug_dispatch0_rs2_valid, debug_dispatch0_prs2, debug_dispatch0_rs2_data);

	output debug_dispatch1_ptr[REORDER_BUFFER_PTR_SIZE];
	output debug_dispatch1_pc[32];
	output debug_dispatch1_rd_valid;
	output debug_dispatch1_prd[6];
	output debug_dispatch1_rs1_sel[2];
	output debug_dispatch1_rs1_valid;
	output debug_dispatch1_prs1[6];
	output debug_dispatch1_rs1_data[32];
	output debug_dispatch1_rs2_sel[2];
	output debug_dispatch1_rs2_valid;
	output debug_dispatch1_prs2[6];
	output debug_dispatch1_rs2_data[32];
	func_out debug_dispatch1(debug_dispatch1_ptr, debug_dispatch1_pc, debug_dispatch1_rd_valid, debug_dispatch1_prd,
			debug_dispatch1_rs1_sel, debug_dispatch1_rs1_valid, debug_dispatch1_prs1, debug_dispatch1_rs1_data,
			debug_dispatch1_rs2_sel, debug_dispatch1_rs2_valid, debug_dispatch1_prs2, debug_dispatch1_rs2_data);

	output debug_dispatch2_ptr[REORDER_BUFFER_PTR_SIZE];
	output debug_dispatch2_pc[32];
	output debug_dispatch2_rd_valid;
	output debug_dispatch2_prd[6];
	output debug_dispatch2_rs1_sel[2];
	output debug_dispatch2_rs1_valid;
	output debug_dispatch2_prs1[6];
	output debug_dispatch2_rs1_data[32];
	output debug_dispatch2_rs2_sel[2];
	output debug_dispatch2_rs2_valid;
	output debug_dispatch2_prs2[6];
	output debug_dispatch2_rs2_data[32];
	func_out debug_dispatch2(debug_dispatch2_ptr, debug_dispatch2_pc, debug_dispatch2_rd_valid, debug_dispatch2_prd,
			debug_dispatch2_rs1_sel, debug_dispatch2_rs1_valid, debug_dispatch2_prs1, debug_dispatch2_rs1_data,
			debug_dispatch2_rs2_sel, debug_dispatch2_rs2_valid, debug_dispatch2_prs2, debug_dispatch2_rs2_data);

    output debug_commit_ptr0[REORDER_BUFFER_PTR_SIZE];
	output debug_commit_kill0;
    output debug_commit_pc0[32];
    output debug_commit_inst0[32];
    output debug_commit_cause0[06];
    output debug_commit_rd_valid0;
    output debug_commit_dreg0[5];
    output debug_commit_preg0[6];
    output debug_commit_ppreg0[6];
    func_out debug_commit0(debug_commit_ptr0, debug_commit_kill0, debug_commit_pc0, debug_commit_inst0, debug_commit_cause0, debug_commit_rd_valid0, debug_commit_dreg0, debug_commit_preg0, debug_commit_ppreg0);
    output debug_commit_ptr1[REORDER_BUFFER_PTR_SIZE];
	output debug_commit_kill1;
    output debug_commit_pc1[32];
    output debug_commit_inst1[32];
    output debug_commit_cause1[16];
    output debug_commit_rd_valid1;
    output debug_commit_dreg1[5];
    output debug_commit_preg1[6];
    output debug_commit_ppreg1[6];
    func_out debug_commit1(debug_commit_ptr1, debug_commit_kill1, debug_commit_pc1, debug_commit_inst1, debug_commit_cause1, debug_commit_rd_valid1, debug_commit_dreg1, debug_commit_preg1, debug_commit_ppreg1);
	
	output debug_rewind0_dreg[5];
	output debug_rewind0_preg[6];
	output debug_rewind0_ppreg[6];
	func_out debug_rewind0(debug_rewind0_dreg, debug_rewind0_preg, debug_rewind0_ppreg);
	output debug_rewind1_dreg[5];
	output debug_rewind1_preg[6];
	output debug_rewind1_ppreg[6];
	func_out debug_rewind1(debug_rewind1_dreg, debug_rewind1_preg, debug_rewind1_ppreg);

	output debug_flush_newpc[32];
	func_out debug_flush(debug_flush_newpc);
#endif
}

#endif
