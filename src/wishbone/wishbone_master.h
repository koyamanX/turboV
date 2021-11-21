#ifndef WISHBONE_MASTER_H
#define WISHBONE_MASTER_H

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

	input req_addr[32];
	input req_data[64];
	input req_sel[8];
	func_in req_read(req_addr, req_sel);
	func_in req_write(req_addr, req_sel, req_data);
	func_in req_read_modify_write(req_addr, req_sel, req_data);
	func_out req_stall();
	output rsp_data[64];
	func_out rsp_valid(rsp_data);
	func_out rsp_error();
	func_out rsp_retry();
	func_out rsp_stall();
}

#endif
