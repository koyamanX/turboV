#include <iostream>
#include <verilated.h>
#include <stdint.h>
#include "verilated_vcd_c.h"
#include "Vwishbone_slave_mem_test.h"
#include <gtest/gtest.h>
#include "simulator.h"


class WishboneSlaveMemTest : public Simulator<Vwishbone_slave_mem_test, VerilatedVcdC> {
protected:
	WishboneSlaveMemTest(void) {

	}
	~WishboneSlaveMemTest(void) {

	}
	void ReadReq(uint32_t addr, uint8_t sel) {
		sim->req_read = true;
		sim->req_addr = addr;
		sim->req_sel = sel;
		Tick();
		sim->req_read = false;
	}
	void WriteReq(uint32_t addr, uint8_t sel, uint64_t data) {
		sim->req_write = true;
		sim->req_addr = addr;
		sim->req_sel = sel;
		sim->req_data = data;
		Tick();
		sim->req_write = false;
	}
	void DummyClock(uint64_t i) {
		Autorun(i);
	}
};
#define WRITE_TEST_DATA 0xdeadbeefaa55aa55

TEST_F(WishboneSlaveMemTest, ReadTest) {
	SetUp("ReadTest.vcd");

	ReadReq(0x0, 0xff);
	Tick();
	UpdatePorts();
	ASSERT_TRUE(sim->rsp_valid);
	EXPECT_EQ(sim->req_data, 0x0);
	ASSERT_TRUE(sim->req_stall);
	ASSERT_FALSE(sim->rsp_error);
	ASSERT_FALSE(sim->rsp_retry);
	ASSERT_FALSE(sim->rsp_stall);
	DummyClock(5);
}

TEST_F(WishboneSlaveMemTest, WriteTest) {
	SetUp("WriteTest.vcd");

	WriteReq(0x0, 0xff, 0xdeadbeefaa55aa55);
	Tick();
	UpdatePorts();
	ASSERT_TRUE(sim->rsp_valid);
	ASSERT_TRUE(sim->req_stall);
	ASSERT_FALSE(sim->rsp_error);
	ASSERT_FALSE(sim->rsp_retry);
	ASSERT_FALSE(sim->rsp_stall);
	DummyClock(5);
}

TEST_F(WishboneSlaveMemTest, WriteReadTest) {
	SetUp("WriteReadTest.vcd");

	WriteReq(0x0, 0xff, WRITE_TEST_DATA);
	Tick();
	UpdatePorts();
	ASSERT_TRUE(sim->rsp_valid);
	ASSERT_TRUE(sim->req_stall);
	ASSERT_FALSE(sim->rsp_error);
	ASSERT_FALSE(sim->rsp_retry);
	ASSERT_FALSE(sim->rsp_stall);
	DummyClock(3);

	ReadReq(0x0, 0xff);
	Tick();
	UpdatePorts();
	ASSERT_TRUE(sim->rsp_valid);
	ASSERT_EQ(sim->req_data, WRITE_TEST_DATA);
	ASSERT_TRUE(sim->req_stall);
	ASSERT_FALSE(sim->rsp_error);
	ASSERT_FALSE(sim->rsp_retry);
	ASSERT_FALSE(sim->rsp_stall);
	DummyClock(5);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);

	return RUN_ALL_TESTS();
}
