#ifndef CONTROL_STATUS_REGISTER_H
#define CONTROL_STATUS_REGISTER_H

#include "priv.h"
#include "csr.h"

declare control_status_register {
    input mode[2];

    input csr_rnum[12];
    output csr_rdata[32];
    func_in read(csr_rnum): csr_rdata;
    input csr_wnum[12];
    input csr_wdata[32];
    func_in write(csr_wnum, csr_wdata);
    func_out csr_illegal_instruction();
    func_in reset();
}

#endif
