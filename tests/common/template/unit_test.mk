TOP_MODULE=_TEMPLATE_UNIT_TEST_NAME_
OUTDIR=out
PROJECT_ROOT=../../
CPP_SOURCE_FILES:=$(TOP_MODULE)_sim.cpp

-include $(PROJECT_ROOT)/storm.mk
-include ../common/unittest.mk
