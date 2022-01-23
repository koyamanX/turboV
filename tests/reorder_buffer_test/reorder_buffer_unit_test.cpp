#include <iostream>
#include <verilated.h>
#include <stdint.h>
#include <string.h>
#include "Vreorder_buffer_unit_test.h"
#include "Vreorder_buffer_unit_test___024root.h"
#include "verilated_vcd_c.h"
#include "Vreorder_buffer_unit_test.h"
#include <gtest/gtest.h>
#include "simulator.h"

class reorder_buffer_unit_test : public Simulator<Vreorder_buffer_unit_test, VerilatedVcdC> {
protected:
	reorder_buffer_unit_test(void) {

	}
	~reorder_buffer_unit_test(void) {

	}
	void Step(void) {
		sim->flush = flush;
		sim->push = push;
		sim->valid0 = valid0;
		sim->pc0 = pc0;
		sim->inst0 = inst0;
		sim->dest0 = dest0;
		sim->valid1 = valid1;
		sim->pc1 = pc1;
		sim->inst1 = inst1;
		sim->dest1 = dest1;
		Tick();	
		flush = false;
		push = false;
		valid0 = false;
		pc0 = 0;
		inst0 = 0;
		dest0 = 0;
		valid1 = false;
		pc1 = 0;
		inst1 = 0;
		dest1 = 0;
		sim->flush = flush;
		sim->push = push;
		sim->valid0 = valid0;
		sim->pc0 = pc0;
		sim->inst0 = inst0;
		sim->dest0 = dest0;
		sim->valid1 = valid1;
		sim->pc1 = pc1;
		sim->inst1 = inst1;
		sim->dest1 = dest1;
	}
	void Push(bool v0, uint32_t p0, uint32_t i0, uint8_t d0, bool v1, uint32_t p1, uint32_t i1, uint8_t d1) {
		push = true;
		valid0 = v0;
		pc0 = p0;
		inst0 = i0;
		dest0 = d0;
		valid1 = v1;
		pc1 = p1;
		inst1 = i1;
		dest1 = d1;
	}
	void Flush(void) {
		flush = true;
	}
	bool valid0 = false;
	uint32_t pc0 = 0;
	uint32_t inst0 = 0;
	uint8_t dest0 = 0;
	bool valid1 = false;
	uint32_t pc1 = 0;
	uint32_t inst1 = 0;
	uint8_t dest1 = 0;
	bool push = false;
	bool flush = 0;
};

TEST_F(reorder_buffer_unit_test, push) {
	SetUp("push.vcd");

	ASSERT_FALSE(sim->full);
	Push(true, 0x0, 0x7c000000, 0, true, 0x4, 0x7c000000, 0);
	Step();
	ASSERT_FALSE(sim->full);
	Push(true, 0x8, 0x7c000000, 0, true, 0xc, 0x7c000000, 0);
	Step();
	ASSERT_FALSE(sim->full);
	Push(true, 0x10, 0x7c000000, 0, true, 0x14, 0x7c000000, 0);
	Step();
	ASSERT_FALSE(sim->full);
	Push(true, 0x18, 0x7c000000, 0, true, 0x1c, 0x7c000000, 0);
	Step();
	Step();
	ASSERT_TRUE(sim->full);


	for(int i = 0; i < 32; i++) {
		Step();
	}
}
TEST_F(reorder_buffer_unit_test, flush) {
	SetUp("flush.vcd");

	ASSERT_FALSE(sim->full);
	Push(true, 0x0, 0x7c000000, 0, true, 0x4, 0x7c000000, 0);
	Step();
	ASSERT_FALSE(sim->full);
	Push(true, 0x8, 0x7c000000, 0, true, 0xc, 0x7c000000, 0);
	Step();
	ASSERT_FALSE(sim->full);
	Push(true, 0x10, 0x7c000000, 0, true, 0x14, 0x7c000000, 0);
	Step();
	ASSERT_FALSE(sim->full);
	Push(true, 0x18, 0x7c000000, 0, true, 0x1c, 0x7c000000, 0);
	Step();
	Step();
	ASSERT_TRUE(sim->full);

	Flush();
	Step();
	Step();
	ASSERT_FALSE(sim->full);
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);

	return RUN_ALL_TESTS();
}
