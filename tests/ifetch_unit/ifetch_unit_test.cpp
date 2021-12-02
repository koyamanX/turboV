#include <iostream>
#include <verilated.h>
#include <stdint.h>
#include "verilated_vcd_c.h"
#include "Vifetch_unit_test.h"
#include <gtest/gtest.h>
#include "simulator.h"


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
};

TEST_F(IFetchUnitTest, Redirect) {
	SetUp("redirect.vcd");
	Redirect(0x0);
	DummyClock(128);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);

	return RUN_ALL_TESTS();
}
