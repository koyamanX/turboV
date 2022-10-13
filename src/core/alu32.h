#ifndef ALU32_H
#define ALU32_H

#include "uops.h"

declare alu32 {
    input a[32];
    input b[32];
    input fn[FN_SIZE];
    output q[32];
    func_out zero;
    func_in exe(a, b, fn): q;
}

#endif
