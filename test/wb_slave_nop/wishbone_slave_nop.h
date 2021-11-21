#ifndef WISHBONE_SLAVE_NOP_H
#define WISHBONE_SLAVE_NOP_H

declare wishbone_slave_nop interface {
	input CLK_I;
	input RST_I;
	input ADR_I[32];
	input SEL_I[8];
	input DAT_I[64];
	output DAT_O[64];
	func_in WE_I();
	func_in CYC_I();
	func_in STB_I();
	func_in LOCK_I();
	func_out ACK_O();
	func_out STALL_O();
	func_out ERR_O();
	func_out RTY_O();

/*
	input TGD_I[];
	output TGD_O[];
	input TGA_I[];
	input TGC_I[];
*/
}

#endif
