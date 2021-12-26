#include <iostream>
#include <verilated.h>
#include <stdint.h>
#include <string.h>
#include "V_TEMPLATE_UNIT_TEST_NAME_.h"
#include "V_TEMPLATE_UNIT_TEST_NAME____024root.h"
#include "verilated_vcd_c.h"
#include "V_TEMPLATE_UNIT_TEST_NAME_.h"
#include <gtest/gtest.h>
#include "simulator.h"

class _TEMPLATE_UNIT_TEST_NAME_UnitTest : public Simulator<V_TEMPLATE_UNIT_TEST_NAME_, VerilatedVcdC> {
protected:
	_TEMPLATE_UNIT_TEST_NAME_Test(void) {

	}
	~_TEMPLATE_UNIT_TEST_NAME_Test(void) {

	}
	void DummyClock(uint64_t i) {
		Autorun(i);
	}
};
