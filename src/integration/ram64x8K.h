#ifndef RAM64X8K_H
#define RAM64X8K_H

#include "wishbone_common.h"

declare ram64x8K {
    func_in reset();
    WISHBONE_GEN_SLAVE_IF(32, 64, 8)
    WISHBONE_GEN_SLAVE_TAG_IF()
}

#endif
