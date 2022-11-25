#ifndef CONTROL_STATUS_REGISTER_H
#define CONTROL_STATUS_REGISTER_H

#include "priv.h"
#include "csr.h"
#include "reorder_buffer.h"

#define IALIGN (if(misa.extensions & MISA_EXTENSIONS_C) 2'b01 else 2'b11)

struct csr_write_buffer_t {
    valid;
    addr[12];
    data[32];
    ptr[REORDER_BUFFER_PTR_SIZE];
#define SIZEOF_CSR_WRITE_BUFFER_T 45+REORDER_BUFFER_PTR_SIZE
};

declare control_status_register {
    input csr_rnum[12];
    output csr_rdata[32];
    func_in read(csr_rnum): csr_rdata;
    func_out read_error();
    input rob_head_ptr[REORDER_BUFFER_PTR_SIZE];
    input write_ptr[REORDER_BUFFER_PTR_SIZE];
    input write_addr[12];
    input write_data[32];
    func_in write(rob_head_ptr, write_ptr, write_addr, write_data);
    func_out write_error();
    input commit_ptr[REORDER_BUFFER_PTR_SIZE];
    func_in commit(commit_ptr);
    func_in reset();
	func_in flush();
    func_in timer_interrupt_req_hart0();
    func_in software_interrupt_req_hart0();

    output meip;
    output msip;
    output mtip;
    output meie;
    output msie;
    output mtie;
    output mstatus_mie;
    output priv_mode[2];

    input trap_cause[32];
    input trap_pc[32];
    input trap_val[32];
    output trap_vector[32];
    func_in trap(trap_cause, trap_pc, trap_val): trap_vector;
    output mret_pc[32];
    func_in mret(): mret_pc;
    output ialign[2];

    func_in update_instret();
}

#endif
