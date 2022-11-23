#ifndef TURBOV_H
#define TURBOV_H

#include "wishbone_common.h"
#include "reorder_buffer.h"
#include "debug_log.h"

declare turboV {
    func_in reset();
    func_in timer_interrupt_req_hart0();
    func_in software_interrupt_req_hart0();

    WISHBONE_GEN_MASTER_IF(32, 64, 8)
	DEBUG_IO
}

#endif
