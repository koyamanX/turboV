#ifndef CLINT_H
#define CLINT_H

#include "wishbone_common.h"

#define CLINT_BASE          0x0200_0000
#define CLINT_LENGTH        0x0000_FFFF
#define MSIP_HART0          0x0200_0000
#define MTIMECMP_HART0      0x0200_4000 
#define MTIME               0x0200_BFF8

#define msip_t

struct mtimecmp_t {
    hi[32];
    lo[32];
};
struct mtime_t {
    hi[32];
    lo[32];
};

declare clint {
    func_in reset();
    WISHBONE_GEN_SLAVE_IF(32, 64, 8)
    WISHBONE_GEN_SLAVE_TAG_IF()
    func_out timer_interrupt_hart0();
    func_out software_interrupt_hart0();
}

#endif
