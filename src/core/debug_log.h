#ifndef DEBUG_LOG_H
#define DEBUG_LOG_H
#ifdef ENABLE_DEBUG

#define DEBUG_IO output debug_decode0_pc[32]; \
    output debug_decode0_inst[32]; \
    output debug_decode0_pred; \
    func_out debug_decode0(debug_decode0_pc, debug_decode0_inst, debug_decode0_pred); \
    output debug_decode1_pc[32]; \
    output debug_decode1_inst[32]; \
    output debug_decode1_pred; \
    func_out debug_decode1(debug_decode1_pc, debug_decode1_inst, debug_decode1_pred); \
    output debug_rename0_ptr[REORDER_BUFFER_PTR_SIZE]; \
    output debug_rename0_pc[32]; \
    output debug_rename0_inst[32]; \
    output debug_rename0_rd_valid; \
    output debug_rename0_lrd[5]; \
    output debug_rename0_prd[6]; \
    output debug_rename0_pprd[6]; \
    output debug_rename0_rs1_valid; \
    output debug_rename0_rs1_ready; \
    output debug_rename0_lrs1[5]; \
    output debug_rename0_prs1[6]; \
    output debug_rename0_rs2_valid; \
    output debug_rename0_rs2_ready; \
    output debug_rename0_lrs2[5]; \
    output debug_rename0_prs2[6]; \
    output debug_rename0_cause[16]; \
    output debug_rename0_imm[32]; \
    func_out debug_rename0(debug_rename0_ptr, debug_rename0_pc, debug_rename0_inst, \
            debug_rename0_rd_valid, debug_rename0_lrd, debug_rename0_prd, debug_rename0_pprd, \
            debug_rename0_rs1_valid, debug_rename0_rs1_ready, debug_rename0_lrs1, debug_rename0_prs1, \
            debug_rename0_rs2_valid, debug_rename0_rs2_ready, debug_rename0_lrs2, debug_rename0_prs2, \
            debug_rename0_cause, debug_rename0_imm); \
    output debug_rename1_ptr[REORDER_BUFFER_PTR_SIZE]; \
    output debug_rename1_pc[32]; \
    output debug_rename1_inst[32]; \
    output debug_rename1_rd_valid; \
    output debug_rename1_lrd[5]; \
    output debug_rename1_prd[6]; \
    output debug_rename1_pprd[6]; \
    output debug_rename1_rs1_valid; \
    output debug_rename1_rs1_ready; \
    output debug_rename1_lrs1[5]; \
    output debug_rename1_prs1[6]; \
    output debug_rename1_rs2_valid; \
    output debug_rename1_rs2_ready; \
    output debug_rename1_lrs2[5]; \
    output debug_rename1_prs2[6]; \
    output debug_rename1_cause[16]; \
    output debug_rename1_imm[32]; \
    func_out debug_rename1(debug_rename1_ptr, debug_rename1_pc, debug_rename1_inst, \
            debug_rename1_rd_valid, debug_rename1_lrd, debug_rename1_prd, debug_rename1_pprd, \
            debug_rename1_rs1_valid, debug_rename1_rs1_ready, debug_rename1_lrs1, debug_rename1_prs1, \
            debug_rename1_rs2_valid, debug_rename1_rs2_ready, debug_rename1_lrs2, debug_rename1_prs2, \
            debug_rename1_cause, debug_rename1_imm); \
    output debug_dispatch0_ptr[REORDER_BUFFER_PTR_SIZE]; \
    output debug_dispatch0_pc[32]; \
    output debug_dispatch0_rd_valid; \
    output debug_dispatch0_prd[6]; \
    output debug_dispatch0_rs1_sel[2]; \
    output debug_dispatch0_rs1_valid; \
    output debug_dispatch0_prs1[6]; \
    output debug_dispatch0_rs1_data[32]; \
    output debug_dispatch0_rs2_sel[2]; \
    output debug_dispatch0_rs2_valid; \
    output debug_dispatch0_prs2[6]; \
    output debug_dispatch0_rs2_data[32]; \
    func_out debug_dispatch0(debug_dispatch0_ptr, debug_dispatch0_pc, debug_dispatch0_rd_valid, debug_dispatch0_prd, \
            debug_dispatch0_rs1_sel, debug_dispatch0_rs1_valid, debug_dispatch0_prs1, debug_dispatch0_rs1_data, \
            debug_dispatch0_rs2_sel, debug_dispatch0_rs2_valid, debug_dispatch0_prs2, debug_dispatch0_rs2_data); \
    output debug_dispatch1_ptr[REORDER_BUFFER_PTR_SIZE]; \
    output debug_dispatch1_pc[32]; \
    output debug_dispatch1_rd_valid; \
    output debug_dispatch1_prd[6]; \
    output debug_dispatch1_rs1_sel[2]; \
    output debug_dispatch1_rs1_valid; \
    output debug_dispatch1_prs1[6]; \
    output debug_dispatch1_rs1_data[32]; \
    output debug_dispatch1_rs2_sel[2]; \
    output debug_dispatch1_rs2_valid; \
    output debug_dispatch1_prs2[6]; \
    output debug_dispatch1_rs2_data[32]; \
    func_out debug_dispatch1(debug_dispatch1_ptr, debug_dispatch1_pc, debug_dispatch1_rd_valid, debug_dispatch1_prd, \
            debug_dispatch1_rs1_sel, debug_dispatch1_rs1_valid, debug_dispatch1_prs1, debug_dispatch1_rs1_data, \
            debug_dispatch1_rs2_sel, debug_dispatch1_rs2_valid, debug_dispatch1_prs2, debug_dispatch1_rs2_data); \
    output debug_dispatch2_ptr[REORDER_BUFFER_PTR_SIZE]; \
    output debug_dispatch2_pc[32]; \
    output debug_dispatch2_rd_valid; \
    output debug_dispatch2_prd[6]; \
    output debug_dispatch2_rs1_sel[2]; \
    output debug_dispatch2_rs1_valid; \
    output debug_dispatch2_prs1[6]; \
    output debug_dispatch2_rs1_data[32]; \
    output debug_dispatch2_rs2_sel[2]; \
    output debug_dispatch2_rs2_valid; \
    output debug_dispatch2_prs2[6]; \
    output debug_dispatch2_rs2_data[32]; \
    func_out debug_dispatch2(debug_dispatch2_ptr, debug_dispatch2_pc, debug_dispatch2_rd_valid, debug_dispatch2_prd, \
            debug_dispatch2_rs1_sel, debug_dispatch2_rs1_valid, debug_dispatch2_prs1, debug_dispatch2_rs1_data, \
            debug_dispatch2_rs2_sel, debug_dispatch2_rs2_valid, debug_dispatch2_prs2, debug_dispatch2_rs2_data); \
    output debug_execute0_ptr[REORDER_BUFFER_PTR_SIZE]; \
    output debug_execute0_rd_valid; \
    output debug_execute0_prd[6]; \
    output debug_execute0_a[32]; \
    output debug_execute0_b[32]; \
    output debug_execute0_q[32]; \
    output debug_execute0_addr[32]; \
    func_out debug_execute0(debug_execute0_ptr, debug_execute0_rd_valid, debug_execute0_prd, debug_execute0_a, debug_execute0_b, debug_execute0_q, debug_execute0_addr); \
    output debug_execute1_ptr[REORDER_BUFFER_PTR_SIZE]; \
    output debug_execute1_rd_valid; \
    output debug_execute1_prd[6]; \
    output debug_execute1_a[32]; \
    output debug_execute1_b[32]; \
    output debug_execute1_q[32]; \
    output debug_execute1_addr[32]; \
    func_out debug_execute1(debug_execute1_ptr, debug_execute1_rd_valid, debug_execute1_prd, debug_execute1_a, debug_execute1_b, debug_execute1_q, debug_execute1_addr); \
    output debug_execute2_ptr[REORDER_BUFFER_PTR_SIZE]; \
    output debug_execute2_rd_valid; \
    output debug_execute2_prd[6]; \
    output debug_execute2_a[32]; \
    output debug_execute2_b[32]; \
    output debug_execute2_data[32]; \
    func_out debug_execute2(debug_execute2_ptr, debug_execute2_rd_valid, debug_execute2_prd, debug_execute2_a, debug_execute2_b, debug_execute2_data); \
    output debug_writeback0_ptr[REORDER_BUFFER_PTR_SIZE]; \
    output debug_writeback0_rd_valid; \
    output debug_writeback0_prd[6]; \
    output debug_writeback0_q[32]; \
    output debug_writeback0_target[32]; \
    func_out debug_writeback0(debug_writeback0_ptr, debug_writeback0_rd_valid, debug_writeback0_prd, debug_writeback0_q, debug_writeback0_target); \
    output debug_writeback1_ptr[REORDER_BUFFER_PTR_SIZE]; \
    output debug_writeback1_rd_valid; \
    output debug_writeback1_prd[6]; \
    output debug_writeback1_q[32]; \
    output debug_writeback1_target[32]; \
    func_out debug_writeback1(debug_writeback1_ptr, debug_writeback1_rd_valid, debug_writeback1_prd, debug_writeback1_q, debug_writeback1_target); \
    output debug_writeback2_ptr[REORDER_BUFFER_PTR_SIZE]; \
    output debug_writeback2_rd_valid; \
    output debug_writeback2_prd[6]; \
    output debug_writeback2_data[32]; \
    func_out debug_writeback2(debug_writeback2_ptr, debug_writeback2_rd_valid, debug_writeback2_prd, debug_writeback2_data); \
    output debug_commit_ptr0[REORDER_BUFFER_PTR_SIZE]; \
    output debug_commit_kill0; \
    output debug_commit_pc0[32]; \
    output debug_commit_inst0[32]; \
    output debug_commit_cause0[06]; \
    output debug_commit_rd_valid0; \
    output debug_commit_dreg0[5]; \
    output debug_commit_preg0[6]; \
    output debug_commit_ppreg0[6]; \
    func_out debug_commit0(debug_commit_ptr0, debug_commit_kill0, debug_commit_pc0, debug_commit_inst0, debug_commit_cause0, debug_commit_rd_valid0, debug_commit_dreg0, debug_commit_preg0, debug_commit_ppreg0); \
    output debug_commit_ptr1[REORDER_BUFFER_PTR_SIZE]; \
    output debug_commit_kill1; \
    output debug_commit_pc1[32]; \
    output debug_commit_inst1[32]; \
    output debug_commit_cause1[16]; \
    output debug_commit_rd_valid1; \
    output debug_commit_dreg1[5]; \
    output debug_commit_preg1[6]; \
    output debug_commit_ppreg1[6]; \
    func_out debug_commit1(debug_commit_ptr1, debug_commit_kill1, debug_commit_pc1, debug_commit_inst1, debug_commit_cause1, debug_commit_rd_valid1, debug_commit_dreg1, debug_commit_preg1, debug_commit_ppreg1); \
    output debug_rewind0_dreg[5]; \
    output debug_rewind0_preg[6]; \
    output debug_rewind0_ppreg[6]; \
    func_out debug_rewind0(debug_rewind0_dreg, debug_rewind0_preg, debug_rewind0_ppreg); \
    output debug_rewind1_dreg[5]; \
    output debug_rewind1_preg[6]; \
    output debug_rewind1_ppreg[6]; \
    func_out debug_rewind1(debug_rewind1_dreg, debug_rewind1_preg, debug_rewind1_ppreg); \
    output debug_flush_newpc[32]; \
    func_out debug_flush(debug_flush_newpc); \

#define DEBUG_RENAME0(ptr, pc, inst, rd_valid, lrd, prd, pprd, \
			rs1_valid, rs1_ready, lrs1, prs1, \
			rs2_valid, rs2_ready, lrs2, prs2, cause, imm) \
        debug_rename0(ptr, pc, inst, rd_valid, lrd, prd, pprd, \
			rs1_valid, rs1_ready, lrs1, prs1, \
			rs2_valid, rs2_ready, lrs2, prs2, cause, imm)
#define DEBUG_RENAME1(ptr, pc, inst, rd_valid, lrd, prd, pprd, \
			rs1_valid, rs1_ready, lrs1, prs1, \
			rs2_valid, rs2_ready, lrs2, prs2, cause, imm) \
        debug_rename1(ptr, pc, inst, rd_valid, lrd, prd, pprd, \
			rs1_valid, rs1_ready, lrs1, prs1, \
			rs2_valid, rs2_ready, lrs2, prs2, cause, imm)
#define DEBUG_COMMIT0(ptr, kill, pc, inst, cause, rd_valid, dreg, preg, ppreg) \
		debug_commit0(ptr, kill, pc, inst, cause, rd_valid, dreg, preg, ppreg)
#define DEBUG_COMMIT1(ptr, kill, pc, inst, cause, rd_valid, dreg, preg, ppreg) \
		debug_commit1(ptr, kill, pc, inst, cause, rd_valid, dreg, preg, ppreg)
#define DEBUG_REWIND0(dreg, preg, ppreg) debug_rewind0(dreg, preg, ppreg)
#define DEBUG_REWIND1(dreg, preg, ppreg) debug_rewind1(dreg, preg, ppreg)
#define DEBUG_FLUSH(newpc) debug_flush(newpc)
#define DEBUG_DISPATCH0(ptr, pc, rd_valid, prd, \
			rs1_sel, rs1_valid, prs1, rs1_data, \
			rs2_sel, rs2_valid, prs2, rs2_data) \
		debug_dispatch0(ptr, pc, rd_valid, prd, \
			rs1_sel, rs1_valid, prs1, rs1_data, rs2_sel, rs2_valid, prs2, rs2_data)
#define DEBUG_DISPATCH1(ptr, pc, rd_valid, prd, \
			rs1_sel, rs1_valid, prs1, rs1_data, rs2_sel, rs2_valid, prs2, rs2_data) \
		debug_dispatch1(ptr, pc, rd_valid, prd, rs1_sel, rs1_valid, prs1, rs1_data, \
			rs2_sel, rs2_valid, prs2, rs2_data)
#define DEBUG_DISPATCH2(ptr, pc, rd_valid, prd, rs1_sel, rs1_valid, prs1, rs1_data, \
			rs2_sel, rs2_valid, prs2, rs2_data) \
		debug_dispatch2(ptr, pc, rd_valid, prd, rs1_sel, rs1_valid, prs1, rs1_data, \
			rs2_sel, rs2_valid, prs2, rs2_data)
#define DEBUG_EXECUTE0(ptr, rd_valid, prd, a, b, q, addr) debug_execute0(ptr, rd_valid, prd, a, b, q, addr)
#define DEBUG_EXECUTE1(ptr, rd_valid, prd, a, b, q, addr) debug_execute1(ptr, rd_valid, prd, a, b, q, addr)
#define DEBUG_EXECUTE2(ptr, rd_valid, prd, a, b, data) debug_execute2(ptr, rd_valid, prd, a, b, data)
#define DEBUG_WRITEBACK0(ptr, rd_valid, prd, q, target) debug_writeback0(ptr, rd_valid, prd, q, target)
#define DEBUG_WRITEBACK1(ptr, rd_valid, prd, q, target) debug_writeback1(ptr, rd_valid, prd, q, target)
#define DEBUG_WRITEBACK2(ptr, rd_valid, prd, data) debug_writeback2(ptr, rd_valid, prd, data)
#define DEBUG_DECODE0(pc, inst, pred) debug_decode0(pc, inst, pred)
#define DEBUG_DECODE1(pc, inst, pred) debug_decode1(pc, inst, pred)
#else	// ENABLE_DEBUG
#define DEBUG_RENAME0(ptr, pc, inst, rd_valid, lrd, prd, pprd, \
			rs1_valid, rs1_ready, lrs1, prs1, \
			rs2_valid, rs2_ready, lrs2, prs2, cause, imm)
#define DEBUG_RENAME1(ptr, pc, inst, rd_valid, lrd, prd, pprd, \
			rs1_valid, rs1_ready, lrs1, prs1, \
			rs2_valid, rs2_ready, lrs2, prs2, cause, imm)
#define DEBUG_COMMIT0(ptr, kill, pc, inst, cause, rd_valid, dreg, preg, ppreg)
#define DEBUG_COMMIT1(ptr, kill, pc, inst, cause, rd_valid, dreg, preg, ppreg)
#define DEBUG_REWIND0(dreg, preg, ppreg)
#define DEBUG_REWIND1(dreg, preg, ppreg)
#define DEBUG_FLUSH(newpc)
#define DEBUG_DISPATCH0(ptr, pc, rd_valid, prd, rs1_sel, rs1_valid, prs1, rs1_data, \
				rs2_sel, rs2_valid, prs2, rs2_data)
#define DEBUG_DISPATCH1(ptr, pc, rd_valid, prd, rs1_sel, rs1_valid, prs1, rs1_data, \
				rs2_sel, rs2_valid, prs2, rs2_data)
#define DEBUG_DISPATCH2(ptr, pc, rd_valid, prd, rs1_sel, rs1_valid, prs1, rs1_data, \
				rs2_sel, rs2_valid, prs2, rs2_data)
#define DEBUG_EXECUTE0(ptr, rd_valid, prd, a, b, q, addr)
#define DEBUG_EXECUTE1(ptr, rd_valid, prd, a, b, q, addr)
#define DEBUG_EXECUTE2(ptr, rd_valid, prd, a, b, data)
#define DEBUG_WRITEBACK0(ptr, rd_valid, prd, q, target, csr_write)
#define DEBUG_WRITEBACK1(ptr, rd_valid, prd, q, target, csr_write)
#define DEBUG_WRITEBACK2(ptr, rd_valid, prd, data)
#define DEBUG_DECODE0(pc, inst, pred)
#define DEBUG_DECODE1(pc, inst, pred)
#endif	// ENABLE_DEBUG
#endif	// DEBUG_LOG_H
