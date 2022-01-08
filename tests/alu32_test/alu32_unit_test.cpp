#include <iostream>
#include <verilated.h>
#include <stdint.h>
#include <string.h>
#include "Valu32_unit_test.h"
#include "Valu32_unit_test___024root.h"
#include "verilated_vcd_c.h"
#include "Valu32_unit_test.h"
#include <gtest/gtest.h>
#include "simulator.h"

#define ALU_ADD (0x0)
#define ALU_SUB (0x1<<3 | 0x0)
#define ALU_SLL (0x1)
#define ALU_SLT (0x2)
#define ALU_SLTU (0x3)
#define ALU_XOR (0x4)
#define ALU_SRL (0x5)
#define ALU_SRA (0x1<<3 | 0x5)
#define ALU_OR  (0x6)
#define ALU_AND (0x7)

class alu32_unit_test : public Simulator<Valu32_unit_test, VerilatedVcdC> {
protected:
	alu32_unit_test(void) {

	}
	~alu32_unit_test(void) {

	}
	void Exe(uint32_t x, uint32_t y, uint8_t z) {
		exe = true;
		a = x;
		b = y;
		fn = z;
	}
	void Step(void) {
		sim->exe = exe;
		sim->a = a;
		sim->b = b;
		sim->fn = fn;
		Tick();
		sim->exe = false;
		sim->a = 0x0;
		sim->b = 0x0;
		sim->fn = 0x0;
		exe = false;
		a = 0;
		b = 0;
		fn = 0;
	}
	bool exe = false;
	uint32_t a;
	uint32_t b;
	uint8_t fn;
};

TEST_F(alu32_unit_test, ADD) {
	SetUp("Add32.vcd");

	/* 0xfe + 0x1 = 0xff */
	Exe(0xfe, 0x1, ALU_ADD);
	Step();
	ASSERT_EQ(sim->q, 0xff);

	/* 0x0 + 0x0 = 0x0 */
	Exe(0x0, 0x0, ALU_ADD);
	Step();
	ASSERT_EQ(sim->q, 0x0);

	/* 0xffffffff + 0x0 = 0xffffffff */
	Exe(0xffffffff, 0x0, ALU_ADD);
	Step();
	ASSERT_EQ(sim->q, 0xffffffff);

	/* 0xffffffff + 0x1 = 0x0 */
	Exe(0xffffffff, 0x1, ALU_ADD);
	Step();
	ASSERT_EQ(sim->q, 0x0);

	/* 1000 + 2000 = 3000 */
	Exe(1000, 2000, ALU_ADD);
	Step();
	ASSERT_EQ(sim->q, 3000);
}
TEST_F(alu32_unit_test, SUB) {
	SetUp("Sub32.vcd");

	/* 1000 - 2000 = -1000 */
	Exe(1000, 2000, ALU_SUB);
	Step();
	ASSERT_EQ(sim->q, -1000);

	/* -1000 - 1000 = -2000 */
	Exe(-1000, 1000, ALU_SUB);
	Step();
	ASSERT_EQ(sim->q, -2000);
}
TEST_F(alu32_unit_test, SLL) {
	SetUp("SLL32.vcd");

	/* 0x1 << 0x5 */
	Exe(0x1, 0x5, ALU_SLL);
	Step();
	ASSERT_EQ(sim->q, 0x1<<0x5);
}
TEST_F(alu32_unit_test, SLT) {
	SetUp("SLT32.vcd");

	/* 0x1 < 0x2 */
	Exe(0x1, 0x2, ALU_SLT);
	Step();
	ASSERT_EQ(sim->q, 0x1<0x2);

	/* -1 < 1 */
	Exe(-1, 1, ALU_SLT);
	Step();
	ASSERT_EQ(sim->q, -1 < 1);

	/* -1 < -1 */
	Exe(-1, -1, ALU_SLT);
	Step();
	ASSERT_EQ(sim->q, -1 < -1);

	/* 1 < -1 */
	Exe(1, -1, ALU_SLT);
	Step();
	ASSERT_EQ(sim->q, 1 < -1);
}
TEST_F(alu32_unit_test, SLTU) {
	SetUp("SLTU32.vcd");

	/* 0x1 < 0x2 */
	Exe(0x1, 0x2, ALU_SLTU);
	Step();
	ASSERT_EQ(sim->q, 0x1<0x2);

	/* 1 < 1 */
	Exe(1, 1, ALU_SLTU);
	Step();
	ASSERT_EQ(sim->q, 1 < 1);

	/* 0xffffffff < 1 */
	Exe(0xffffffff, 1, ALU_SLTU);
	Step();
	ASSERT_EQ(sim->q, 0xffffffff < 1);

	/* 1 < 0xffffffff */
	Exe(1, 0xffffffff, ALU_SLTU);
	Step();
	ASSERT_EQ(sim->q, 1 < 0xffffffff);
}
TEST_F(alu32_unit_test, XOR) {
	SetUp("XOR32.vcd");

	Exe(0xffffffff, 0xffaaffaa, ALU_XOR);
	Step();
	ASSERT_EQ(sim->q, 0xffffffff ^ 0xffaaffaa);
}
TEST_F(alu32_unit_test, SRL) {
	SetUp("SRL32.vcd");

	Exe(0x1, 0x2, ALU_SRL);
	Step();
	ASSERT_EQ(sim->q, 0x1 >> 0x2);
}
TEST_F(alu32_unit_test, SRA) {
	SetUp("SRA32.vcd");

	Exe(-1, 0x2, ALU_SRA);
	Step();
	ASSERT_EQ(sim->q, -1 >> 0x2);
}
TEST_F(alu32_unit_test, OR) {
	SetUp("OR32.vcd");

	Exe(0xffffffff, 0xffaaffaa, ALU_OR);
	Step();
	ASSERT_EQ(sim->q, 0xffffffff | 0xffaaffaa);
}
TEST_F(alu32_unit_test, AND) {
	SetUp("AND32.vcd");

	Exe(0xffffffff, 0xffaaffaa, ALU_AND);
	Step();
	ASSERT_EQ(sim->q, 0xffffffff & 0xffaaffaa);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);

	return RUN_ALL_TESTS();
}
