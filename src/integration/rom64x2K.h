#ifndef ROM64X2K_H
#define ROM64X2K_H

#include "wishbone_common.h"

declare rom64x2K {
	func_in reset();
	WISHBONE_GEN_SLAVE_IF(32, 64, 8)
	WISHBONE_GEN_SLAVE_TAG_IF()
}

#endif
