#ifndef CONTROL_STATUS_REGISTER_H
#define CONTROL_STATUS_REGISTER_H

#include "priv.h"
#include "csr.h"

declare control_status_register {
    input csr_rnum[12];
    output csr_rdata[32];
    func_in read(csr_rnum): csr_rdata;
    input csr_wnum[12];
    input csr_wdata[32];
    func_in write(csr_wnum, csr_wdata);
    func_in reset();
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

    input has_mapped_csr_addr[12];
    output has_mapped_ok;
    func_in has_mapped(has_mapped_csr_addr): has_mapped_ok;
    func_out has_mapped_readonly();

    input trap_cause[32];
    input trap_pc[32];
    input trap_val[32];
    output trap_vector[32];
    func_in trap(trap_cause, trap_pc, trap_val): trap_vector;
    output mret_pc[32];
    func_in mret(): mret_pc;
}

#endif
