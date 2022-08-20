#ifndef BRU32_H
#define BRU32_H

#include "uops.h"

declare bru32 {
    input a[32];
    input b[32];
    input fn[4];
    output taken;
    func_in exe(a, b, fn): taken;
}

#endif
