#include <iostream>
#include <verilated.h>
#include <stdint.h>
#include <string.h>
#include "Vinst_buffer_test.h"
#include "Vinst_buffer_test___024root.h"
#include "verilated_vcd_c.h"
#include <gtest/gtest.h>
#include "simulator.h"

class InstBufferTest : public Simulator<Vinst_buffer_test, VerilatedVcdC> {
protected:
	InstBufferTest(void) {

	}
	~InstBufferTest(void) {
		DummyClock(1);
	}
	void DummyClock(uint64_t i) {
		Autorun(i);
	}
};

TEST_F(InstBufferTest, push1) {
	SetUp("push1.vcd");
	
	UpdatePorts();
	ASSERT_EQ(sim->full, false);
	ASSERT_EQ(sim->empty, true);
	
	sim->push = true;	
	DummyClock(1);
	sim->push = false;

	DummyClock(1);	/* feed one clock to update internal register */
	ASSERT_EQ(sim->full, false);
	ASSERT_EQ(sim->empty, false);
}


TEST_F(InstBufferTest, pushUntilFull) {
	SetUp("pushUntilFull.vcd");
	
	UpdatePorts();
	ASSERT_EQ(sim->full, false);
	ASSERT_EQ(sim->empty, true);

	int push_cnt = 0;
	while(push_cnt < 8) {
		sim->push = true;	
		push_cnt++;
		DummyClock(1);
	}
	sim->push = false;

	DummyClock(1);	/* feed one clock to update internal register */
	ASSERT_EQ(push_cnt, 8);
	ASSERT_EQ(sim->full, true);
	ASSERT_EQ(sim->empty, false);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);

	return RUN_ALL_TESTS();
}
