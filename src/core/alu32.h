#ifndef ALU32_H
#define ALU32_H

#include "uops.h"

declare alu32 {
    input req_exe_a[32];
    input req_exe_b[32];
    input req_exe_fn[FN_SIZE];
    output rsp_exe_q[32];
    func_in req_exe(req_exe_a, req_exe_b, req_exe_fn): rsp_exe_q;
}

#endif
