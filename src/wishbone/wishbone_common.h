#ifndef WISHBONE_COMMON_H
#define WISHBONE_COMMON_H

#define WRITE 1'b1
#define READ 1'b0

/*
	Connect all of WISHBONE signals each other
	to form Point-to-Point connection.
	@params:
		master: WISHBONE master
		slave: WISHBONE slave
		syscon: WISHBONE syscon
*/
#define WISHBONE_P2P(master, slave, syscon) { \
	master.CLK_I = syscon.CLK_O; master.RST_I = syscon.RST_O; \
	slave.CLK_I = syscon.CLK_O; slave.RST_I = syscon.RST_O; \
	slave.ADR_I = master.ADR_O; slave.SEL_I = master.SEL_O; \
	slave.DAT_I = master.DAT_O; master.DAT_I = slave.DAT_O; \
	func master.CYC_O slave.CYC_I(); func master.STB_O slave.STB_I(); \
	func master.WE_O slave.WE_I(); func master.LOCK_O slave.LOCK_I(); \
	func slave.ACK_O master.ACK_I(); func slave.STALL_O master.STALL_I(); \
	func slave.ERR_O master.ERR_I(); func slave.RTY_O master.RTY_I(); }

#define WISHBONE_SLAVE_IF(slave) { \
	slave.CLK_I = CLK_I; slave.RST_I = RST_I; \
	slave.ADR_I = ADR_I; slave.SEL_I = SEL_I; \
	slave.DAT_I = DAT_I; DAT_O = slave.DAT_O; \
	func WE_I slave.WE_I(); func CYC_I slave.CYC_I(); \
	func STB_I slave.STB_I(); func LOCK_I slave.LOCK_I(); \
	func slave.ACK_O ACK_O(); func slave.STALL_O STALL_O(); \
	func slave.ERR_O ERR_O(); func slave.RTY_O RTY_O(); }

#define WISHBONE_GEN_SLAVE_IF(AWIDTH, DWIDTH, SWIDTH) \
	input CLK_I; input RST_I; \
	input ADR_I[AWIDTH]; input SEL_I[SWIDTH]; \
	input DAT_I[DWIDTH]; output DAT_O[DWIDTH]; \
	func_in WE_I(); func_in CYC_I(); \
	func_in STB_I(); func_in LOCK_I(); \
	func_out ACK_O(); func_out STALL_O(); \
	func_out ERR_O(); func_out RTY_O();

#define WISHBONE_GEN_SLAVE_TAG_IF()

#endif

