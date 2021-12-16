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
	void Redirect(uint32_t newpc) {
		sim->redirect = true;
		sim->newpc = newpc;
		pc = newpc;
		Tick();
		sim->redirect = false;
	}
	uint32_t pc = 0;
};

TEST_F(IFetchUnitTest, Fetch) {
	SetUp("fetch.vcd");
	Redirect(0x0);

	for(int i = 0; i < 128; i++) {
		auto rootp = sim->rootp;

		if(sim->push2) {
			ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_pc0, pc);
			ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_pc1, pc+4);
			ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_inst0, 0x00000000);
			ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_inst1, 0x00000000);
			ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_valid0, true);
			ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_valid1, true);
			pc+=8;
		}

		DummyClock(1);
	}
}
TEST_F(IFetchUnitTest, FetchAt4) {
	static bool firstFetch = true;

	SetUp("fetchAt4.vcd");
	Redirect(0x4);

	for(int i = 0; i < 128; i++) {
		auto rootp = sim->rootp;

		if(sim->push2) {
			if(firstFetch) {
				ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_pc0, pc);
				ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_pc1, pc+4);
				ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_inst0, 0x00000000);
				ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_inst1, 0x00000000);
				ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_valid0, true);
				ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_valid1, false);
				firstFetch = false;
				pc+=4;
			} else {
				ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_pc0, pc);
				ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_pc1, pc+4);
				ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_inst0, 0x00000000);
				ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_inst1, 0x00000000);
				ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_valid0, true);
				ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_valid1, true);
				pc+=8;
			}
		}

		DummyClock(1);
	}
}

TEST_F(IFetchUnitTest, Redirect) {
	SetUp("Redirect.vcd");
	Redirect(0x0);

	DummyClock(1);
	DummyClock(1);
	Redirect(0x80000000);

	for(int i = 0; i < 128; i++) {
		auto rootp = sim->rootp;

		if(sim->push2) {
			ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_pc0, pc);
			ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_pc1, pc+4);
			ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_inst0, 0x00000000);
			ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_inst1, 0x00000000);
			ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_valid0, true);
			ASSERT_EQ(rootp->ifetch_unit_test__DOT___packet_valid1, true);
			pc+=8;
		}

		DummyClock(1);
	}
}



int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);

	return RUN_ALL_TESTS();
}
