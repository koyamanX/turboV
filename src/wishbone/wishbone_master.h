#ifndef WISHBONE_MASTER_H
#define WISHBONE_MASTER_H

#include "wishbone_common.h"

declare wishbone_master interface {
    WISHBONE_GEN_MASTER_IF(32, 64, 8)
    WISHBONE_MASTER_ACCESS_IN_PORTS(32, 64, 8)
}

#endif
