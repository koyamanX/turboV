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
	void Reset(uint32_t v) {
		reset = true;
		resetvector = v;
	}
	void Step() {
		sim->reset = reset;
		sim->resetvector = resetvector;
		Tick();
		reset = false;
		resetvector = 0x0;
		sim->reset = reset;
		sim->resetvector = resetvector;
	}
	bool reset = false;
	uint32_t resetvector;
};
TEST_F(turboV_unit_test, Reset) {
	SetUp("Reset.vcd");

	Reset(0x0);
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
