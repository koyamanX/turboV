#ifndef IFETCH_UNIT_H
#define IFETCH_UNIT_H

#include "wishbone_common.h"

struct fetch_packet_t {
	ppc[32];
	inst0[32];
	inst1[32];
};

declare ifetch_unit {
	func_in reset();
	input newpc[32];
	func_in redirect(newpc);
	/* fetch_packet_t */
	output fetch_packet[96];
	func_out push2(fetch_packet);

	WISHBONE_GEN_MASTER_IF(32, 64, 8)
}

#endif
