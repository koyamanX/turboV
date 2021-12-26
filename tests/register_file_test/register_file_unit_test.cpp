#include <iostream>
#include <verilated.h>
#include <stdint.h>
#include <string.h>
#include "Vregister_file_unit_test.h"
#include "Vregister_file_unit_test___024root.h"
#include "verilated_vcd_c.h"
#include "Vregister_file_unit_test.h"
#include <gtest/gtest.h>
#include "simulator.h"

class register_file_unit_test : public Simulator<Vregister_file_unit_test, VerilatedVcdC> {
protected:
	register_file_unit_test(void) {

	}
	~register_file_unit_test(void) {

	}
	void Step(void) {
		sim->reada = reada;
		sim->rnuma = rnuma;
		sim->readb = readb;
		sim->rnumb = rnumb;
		sim->writea = writea;
		sim->wnuma = wnuma;
		sim->wdataa = wdataa;
		Tick();
		reada = false;
		rnuma = 0;
		readb = false;
		rnumb = 0;
		writea = false;
		wnuma = 0;
		wdataa = 0;
	}
	void Reada(uint8_t num) {
		reada = true;
		rnuma = num;
	}
	void Readb(uint8_t num) {
		readb = true;
		rnumb = num;
	}
	void Writea(uint8_t num, uint32_t data) {
		writea = true;
		wnuma = num;
		wdataa = data;
	}
	bool reada = false;
	uint8_t rnuma = 0;
	bool readb = false;
	uint8_t rnumb = 0;
	bool writea = false;
	uint8_t wnuma = 0;
	uint32_t wdataa;
};

TEST_F(register_file_unit_test, ReadWrite) {
	SetUp("ReadWrite.vcd");

	Reada(0x0);
	Step();
	ASSERT_EQ(sim->rdataa, 0x0);

	Writea(0x1, 0xffff55aa);
	Reada(0x1);
	Readb(0x1);
	Step();
	ASSERT_EQ(sim->rdataa, 0xffff55aa);
	ASSERT_EQ(sim->rdatab, 0xffff55aa);
	
	Reada(0x1);
	Readb(0x0);
	Step();
	ASSERT_EQ(sim->rdataa, 0xffff55aa);
	ASSERT_EQ(sim->rdatab, 0x0);

	Reada(0x0);
	Readb(0x0);
	Writea(0x0, 0xffff55aa);
	Step();
	ASSERT_EQ(sim->rdataa, 0x0);
	ASSERT_EQ(sim->rdatab, 0x0);


	for(int i = 0; i < 32; i++) {
		Writea(i, i);
		Step();
	}

	for(int i = 0; i < 32; i++) {
		Reada(i);
		Readb(i);
		Step();
		ASSERT_EQ(sim->rdataa, i);
		ASSERT_EQ(sim->rdatab, i);
	}
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);

	return RUN_ALL_TESTS();
}
