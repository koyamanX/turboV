#ifndef WISHBONE_SLAVE_H
#define WISHBONE_SLAVE_H

declare wishbone_slave interface {
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
	output req_addr[32];
	output req_data[64];
	output req_sel[8];
	func_out req_read(req_addr, req_sel);
	func_out req_write(req_addr, req_sel, req_data);
	func_out req_read_modify_write(req_addr, req_sel, req_data);
	input rsp_data[64];
	func_in rsp_valid(rsp_data);
	func_in rsp_error();
	func_in rsp_retry();
	func_in rsp_stall();
	func_in reset();
}

#endif
