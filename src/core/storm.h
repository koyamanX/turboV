#ifndef STORM_H
#define STORM_H

#include "wishbone_common.h"

declare storm {
	input resetvector[32];
	func_in reset(resetvector);

	WISHBONE_GEN_MASTER_IF(32, 64, 8)
}

#endif
