#ifndef TURBOV_H
#define TURBOV_H

#include "wishbone_common.h"

#define BUSY 1'b1
#define READY 1'b0

declare turboV {
    func_in reset();

    WISHBONE_GEN_MASTER_IF(32, 64, 8)
}

#endif
