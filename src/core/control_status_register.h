#ifndef CONTROL_STATUS_REGISTER_H
#define CONTROL_STATUS_REGISTER_H

#include "priv.h"
#include "csr.h"
#include "reorder_buffer.h"

#define IALIGN (if(misa.extensions & MISA_EXTENSIONS_C) 2'b01 else 2'b11)

#define DECODE_CSR_RO	2'b00
#define DECODE_CSR_WO	2'b01
#define DECODE_CSR_RW	2'b11

struct csr_write_buffer_t {
    valid;
    addr[12];
    data[32];
    ptr[REORDER_BUFFER_PTR_SIZE];
#define SIZEOF_CSR_WRITE_BUFFER_T 45+REORDER_BUFFER_PTR_SIZE
};

declare control_status_register {
    output meip_o;
    output msip_o;
    output mtip_o;
    output meie_o;
    output msie_o;
    output mtie_o;
    output mstatus_mie_o;
    output priv_mode_o[2];
    output ialign_o[2];

	input req_decode_csr_num[12];
	input req_decode_csr_rw[2];
	output rsp_decode_illegal;
	func_in req_decode(req_decode_csr_num, req_decode_csr_rw): rsp_decode_illegal;
    input req_read_csr_num[12];
    output req_read_csr_data[32];
    func_in req_read(req_read_csr_num): req_read_csr_data;
    input req_write_rob_head_ptr[REORDER_BUFFER_PTR_SIZE];
    input req_write_ptr[REORDER_BUFFER_PTR_SIZE];
    input req_write_addr[12];
    input req_write_data[32];
	output rsp_write_old_data[32];
    func_in req_write(req_write_rob_head_ptr, req_write_ptr, req_write_addr, req_write_data): rsp_write_old_data;
    input req_commit_ptr[REORDER_BUFFER_PTR_SIZE];
    func_in req_commit(req_commit_ptr);
    func_in req_reset();
	func_in req_flush();
    func_in req_timer_interrupt_req_hart0();
    func_in req_software_interrupt_req_hart0();
    input req_trap_cause[32];
    input req_trap_pc[32];
    input req_trap_val[32];
    output rsp_trap_vector[32];
    func_in req_trap(req_trap_cause, req_trap_pc, req_trap_val): rsp_trap_vector;
    output rsp_mret_pc[32];
    func_in req_mret(): rsp_mret_pc;
    func_in req_update_instret();
}

#endif
