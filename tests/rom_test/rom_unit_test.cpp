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
	void DummyClock(uint64_t i) {
		Autorun(i);
	}
};

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);

	return RUN_ALL_TESTS();
}
