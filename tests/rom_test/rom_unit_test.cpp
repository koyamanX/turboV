#include <iostream>
#include <verilated.h>
#include <stdint.h>
#include <string.h>
#include "Vrom_unit_test.h"
#include "Vrom_unit_test___024root.h"
#include "verilated_vcd_c.h"
#include "Vrom_unit_test.h"
#include <gtest/gtest.h>
#include "simulator.h"

class rom_unit_test : public Simulator<Vrom_unit_test, VerilatedVcdC> {
protected:
	rom_unit_test(void) {

	}
	~rom_unit_test(void) {

	}
	void Step() {
		sim->req_read = req_read;
		sim->req_write = req_write;
		sim->req_read_modify_write = req_read_modify_write;
		sim->req_addr = req_addr;
		sim->req_data = req_data;
		sim->req_sel = req_sel;
		Tick();
	}
	void ReadReq(uint32_t addr, uint8_t sel) {
		req_read = true;
		req_addr = addr;
		req_sel = sel;
		Step();
		req_read = false;
		req_addr = 0;
		req_sel = 0;
	}

	uint32_t req_addr;
	uint64_t req_data;
	uint8_t req_sel;
	bool req_read = false;
	bool req_write = false;
	bool req_read_modify_write = false;
};

TEST_F(rom_unit_test, ReadTest) {
	SetUp("ReadTest.vcd");
	
	ReadReq(0x0, 0x01);
	Tick();
	UpdatePorts();
	ASSERT_TRUE(sim->rsp_valid);
	EXPECT_EQ(sim->rsp_data&0xff, 0xcc);
	ASSERT_TRUE(sim->req_stall);
	ASSERT_FALSE(sim->rsp_error);
	ASSERT_FALSE(sim->rsp_retry);
	ASSERT_FALSE(sim->rsp_stall);

	Tick();
	Tick();

	ReadReq(0x0, 0x0f);
	Tick();
	UpdatePorts();
	ASSERT_TRUE(sim->rsp_valid);
	EXPECT_EQ(sim->rsp_data&0xffffffff, 0xffaabbcc);
	ASSERT_TRUE(sim->req_stall);
	ASSERT_FALSE(sim->rsp_error);
	ASSERT_FALSE(sim->rsp_retry);
	ASSERT_FALSE(sim->rsp_stall);

}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);

	return RUN_ALL_TESTS();
}
