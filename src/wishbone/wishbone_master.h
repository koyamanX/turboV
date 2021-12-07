#ifndef WISHBONE_MASTER_H
#define WISHBONE_MASTER_H

#include "wishbone_common.h"

declare wishbone_master interface {
	input CLK_I;
	input RST_I;

	output ADR_O[32];
	input DAT_I[64];
	output DAT_O[64];
	output SEL_O[8];
	input TGD_I[1];
	output TGD_O[1];
	output TGA_O[1];
	output TGC_O[1];

	func_out CYC_O();
	func_out STB_O();
	func_out WE_O();
	func_out LOCK_O();
	func_in ACK_I();
	func_in ERR_I();
	func_in RTY_I();
	func_in STALL_I();

	WISHBONE_MASTER_ACCESS_PORT(32, 64, 8)
}

#endif
