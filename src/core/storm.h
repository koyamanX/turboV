#ifndef STORM_H
#define STORM_H

#include "wishbone_common.h"

#define BUSY 1'b1
#define READY 1'b0

declare storm {
	input resetvector[32];
	func_in reset(resetvector);

	WISHBONE_GEN_MASTER_IF(32, 64, 8)
}

#endif
