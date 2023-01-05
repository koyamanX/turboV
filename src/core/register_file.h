#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H
#include "riscv.h"

declare register_file {
    // 6 reads/ 3 writes
    input req_readA_addr[6];
    output rsp_readA_data[XLEN];
    func_in req_readA(req_readA_addr): rsp_readA_data;
    input req_readB_addr[6];
    output rsp_readB_data[XLEN];
    func_in req_readB(req_readB_addr): rsp_readB_data;
    input req_readC_addr[6];
    output rsp_readC_data[XLEN];
    func_in req_readC(req_readC_addr): rsp_readC_data;
    input req_readD_addr[6];
    output rsp_readD_data[XLEN];
    func_in req_readD(req_readD_addr): rsp_readD_data;
    input req_readE_addr[6];
    output rsp_readE_data[XLEN];
    func_in req_readE(req_readE_addr): rsp_readE_data;
    input req_readF_addr[6];
    output rsp_readF_data[XLEN];
    func_in req_readF(req_readF_addr): rsp_readF_data;
    input req_writeA_addr[6];
    input req_writeA_data[XLEN];
    func_in req_writeA(req_writeA_addr, req_writeA_data);
    input req_writeB_addr[6];
    input req_writeB_data[XLEN];
    func_in req_writeB(req_writeB_addr, req_writeB_data);
    input req_writeC_addr[6];
    input req_writeC_data[XLEN];
    func_in req_writeC(req_writeC_addr, req_writeC_data);
}

#endif
