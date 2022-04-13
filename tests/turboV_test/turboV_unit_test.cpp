#include <iostream>
#include <verilated.h>
#include <stdint.h>
#include <string.h>
#include "VturboV_unit_test.h"
#include "VturboV_unit_test___024root.h"
#include "verilated_vcd_c.h"
#include "VturboV_unit_test.h"
#include <gtest/gtest.h>
#include "simulator.h"

class turboV_unit_test : public Simulator<VturboV_unit_test, VerilatedVcdC> {
protected:
	turboV_unit_test(void) {

	}
	~turboV_unit_test(void) {

	}
	void Step() {
		sim->reset = reset;
		Tick();
		reset = false;
		sim->reset = reset;
	}
	bool reset = false;
};
TEST_F(turboV_unit_test, Reset) {
	SetUp("Reset.vcd");

    reset = true;
	Step();
	for(int i = 0; i < 1024; i++) {
		Tick();
	}
}
int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);

	return RUN_ALL_TESTS();
}
