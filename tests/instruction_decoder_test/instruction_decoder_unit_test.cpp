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
	void Decode(uint32_t i) {
		decode = true;
		inst = i;
	}
	void Step(void) {
		sim->decode = decode;
		sim->inst = inst;
		Tick();
		sim->decode = false;
		sim->inst = 0x0;
	}
	uint32_t inst;
	bool decode = false;
};

TEST_F(instruction_decoder_unit_test, OP) {
	SetUp("Op.vcd");

	// add x0, x0, x0
	Decode(0x00000033);
	Step();
	ASSERT_EQ(sim->op, true);
	ASSERT_EQ(sim->illegal_instruction, false);
	ASSERT_EQ(sim->rd, 0x0);
	ASSERT_EQ(sim->rs1, 0x0);
	ASSERT_EQ(sim->rs2, 0x0);
	ASSERT_EQ(sim->fn, 0x0);

	// add x31, x0, x0
	Decode(0x00000fb3);
	Step();
	ASSERT_EQ(sim->op, true);
	ASSERT_EQ(sim->illegal_instruction, false);
	ASSERT_EQ(sim->rd, 31);
	ASSERT_EQ(sim->rs1, 0x0);
	ASSERT_EQ(sim->rs2, 0x0);
	ASSERT_EQ(sim->fn, 0x0);

	// add x0, x31, x0
	Decode(0x000f8033);
	Step();
	ASSERT_EQ(sim->op, true);
	ASSERT_EQ(sim->illegal_instruction, false);
	ASSERT_EQ(sim->rd, 0x0);
	ASSERT_EQ(sim->rs1, 31);
	ASSERT_EQ(sim->rs2, 0x0);
	ASSERT_EQ(sim->fn, 0x0);

	// add x0, x0, x31
	Decode(0x01f00033);
	Step();
	ASSERT_EQ(sim->op, true);
	ASSERT_EQ(sim->illegal_instruction, false);
	ASSERT_EQ(sim->rd, 0x0);
	ASSERT_EQ(sim->rs1, 0x0);
	ASSERT_EQ(sim->rs2, 31);
	ASSERT_EQ(sim->fn, 0x0);

	// add x31, x31, x31
	Decode(0x01ff8fb3);
	Step();
	ASSERT_EQ(sim->op, true);
	ASSERT_EQ(sim->illegal_instruction, false);
	ASSERT_EQ(sim->rd, 31);
	ASSERT_EQ(sim->rs1, 31);
	ASSERT_EQ(sim->rs2, 31);
	ASSERT_EQ(sim->fn, 0x0);

	// ecall
	Decode(0x00000073);
	Step();
	ASSERT_EQ(sim->op, false);
	ASSERT_EQ(sim->illegal_instruction, true);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);

	return RUN_ALL_TESTS();
}
