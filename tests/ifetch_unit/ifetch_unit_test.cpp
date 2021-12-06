#include <iostream>
#include <verilated.h>
#include <stdint.h>
#include <string.h>
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
		fetch_packet_t buf;	

		memcpy(&buf, sim->fetch_packet, sizeof(fetch_packet_t));
		ASSERT_EQ(buf.pc, pc);
		ASSERT_EQ(buf.inst0, 0x00000000);
		ASSERT_EQ(buf.inst1, 0x00000000);

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
