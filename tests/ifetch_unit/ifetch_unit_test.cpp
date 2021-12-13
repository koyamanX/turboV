#include <iostream>
#include <verilated.h>
#include <stdint.h>
#include <string.h>
#include "Vifetch_unit_test.h"
#include "Vifetch_unit_test___024root.h"
#include "verilated_vcd_c.h"
#include "Vifetch_unit_test.h"
#include <gtest/gtest.h>
#include "simulator.h"

#define WATCH(s, v, f) do {if(s == v) {f();}} while(0)

typedef struct {
	uint32_t inst1;
	uint32_t inst0;
	uint32_t pc;
} fetch_packet_t;

class IFetchUnitTest : public Simulator<Vifetch_unit_test, VerilatedVcdC> {
protected:
	IFetchUnitTest(void) {

	}
	~IFetchUnitTest(void) {

	}
	void DummyClock(uint64_t i) {
		Autorun(i);
	}
	void Redirect(uint32_t pc) {
		sim->redirect = true;
		sim->newpc = pc;
		Tick();
		sim->redirect = false;
	}
	void push2(void) {
		auto rootp = sim->rootp;

		ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_pc0, pc);
		ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_pc1, pc+4);
		ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_inst0, 0x00000000);
		ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_inst1, 0x00000000);
		ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_valid0, true);
		ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_valid1, true);

		pc+=8;
	}
	uint32_t pc = 0;
};

TEST_F(IFetchUnitTest, Fetch) {
	SetUp("fetch.vcd");
	Redirect(0x0);

	for(int i = 0; i < 128; i++) {
		WATCH(sim->push2, true, push2);
		DummyClock(1);
	}
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);

	return RUN_ALL_TESTS();
}
