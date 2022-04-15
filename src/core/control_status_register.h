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
    func_out csr_illegal_instruction();
    func_in reset();

    input trap_cause[32];
    input trap_pc[32];
    input trap_val[32];
    output trap_vector[32];
    func_in trap(trap_cause, trap_pc, trap_val): trap_vector;
    output mret_pc[32];
    func_in mret(): mret_pc;
}

#endif
