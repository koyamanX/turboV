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
	while(push_cnt <= 8) {
		sim->push = true;	
		push_cnt++;
		DummyClock(1);
	}
	sim->push = false;

	DummyClock(1);	/* feed one clock to update internal register */
	ASSERT_EQ(push_cnt, 9);
	ASSERT_EQ(sim->full, true);
	ASSERT_EQ(sim->empty, false);
}

TEST_F(InstBufferTest, push1ThenPop1) {
	SetUp("push1ThenPop1.vcd");

	UpdatePorts();
	ASSERT_EQ(sim->full, false);
	ASSERT_EQ(sim->empty, true);
	
	sim->push = true;	
	DummyClock(1);
	sim->push = false;

	DummyClock(1);	/* feed one clock to update internal register */
	ASSERT_EQ(sim->full, false);
	ASSERT_EQ(sim->empty, false);

	sim->pop = true;
	DummyClock(1);
	sim->pop = false;

	DummyClock(1);	/* feed one clock to update internal register */
	ASSERT_EQ(sim->full, false);
	ASSERT_EQ(sim->empty, true);
}
TEST_F(InstBufferTest, pushUntilFullThenPopUntilEmpty) {
	SetUp("pushUntilFullThenPopUntilEmpty.vcd");
	
	UpdatePorts();
	ASSERT_EQ(sim->full, false);
	ASSERT_EQ(sim->empty, true);

	int push_cnt = 0;
	while(push_cnt <= 8) {
		sim->push = true;	
		push_cnt++;
		DummyClock(1);
	}
	sim->push = false;

	DummyClock(1);	/* feed one clock to update internal register */
	ASSERT_EQ(push_cnt, 9);
	ASSERT_EQ(sim->full, true);
	ASSERT_EQ(sim->empty, false);

	int pop_cnt = 0;
	while(pop_cnt <= 8) {
		sim->pop = true;
		pop_cnt++;
		DummyClock(1);
	}
	sim->pop = false;

	DummyClock(1);	/* feed one clock to update internal register */
	ASSERT_EQ(push_cnt, pop_cnt);
	ASSERT_EQ(sim->full, false);
	ASSERT_EQ(sim->empty, true);
}
TEST_F(InstBufferTest, flush) {
	SetUp("flush.vcd");

	UpdatePorts();
	ASSERT_EQ(sim->full, false);
	ASSERT_EQ(sim->empty, true);

	int push_cnt = 0;
	while(push_cnt <= 8) {
		sim->push = true;	
		push_cnt++;
		DummyClock(1);
	}
	sim->push = false;

	DummyClock(1);	/* feed one clock to update internal register */
	ASSERT_EQ(push_cnt, 9);
	ASSERT_EQ(sim->full, true);
	ASSERT_EQ(sim->empty, false);

	sim->flush = true;
	DummyClock(1);
	sim->flush = false;

	DummyClock(1);	/* feed one clock to update internal register */
	ASSERT_EQ(sim->full, false);
	ASSERT_EQ(sim->empty, true);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);

	return RUN_ALL_TESTS();
}
