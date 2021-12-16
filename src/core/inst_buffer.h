#ifndef INST_BUFFER_H
#define INST_BUFFER_H

#include "ifetch_unit.h"

declare inst_buffer {
	input idata[SIZEOF_FETCH_PACKET_T];
	func_in push(idata);
	output odata[SIZEOF_FETCH_PACKET_T];
	func_in pop() : odata;
	func_out full();
	func_out empty();
	func_in flush();
}

#endif
