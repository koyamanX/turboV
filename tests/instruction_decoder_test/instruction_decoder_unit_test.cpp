#include <iostream>
#include <verilated.h>
#include <stdint.h>
#include <string.h>
#include "Vinstruction_decoder_unit_test.h"
#include "Vinstruction_decoder_unit_test___024root.h"
#include "verilated_vcd_c.h"
#include "Vinstruction_decoder_unit_test.h"
#include <gtest/gtest.h>
#include "simulator.h"

class instruction_decoder_unit_test : public Simulator<Vinstruction_decoder_unit_test, VerilatedVcdC> {
protected:
	instruction_decoder_unit_test(void) {

	}
	~instruction_decoder_unit_test(void) {

	}
	void Step(void) {
		Tick();
	}
};

TEST_F(instruction_decoder_unit_test, ReadWrite) {

}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);

	return RUN_ALL_TESTS();
}
