TOP_MODULE=inst_buffer_test
OUTDIR=out
PROJECT_ROOT=../../
CPP_SOURCE_FILES:=$(TOP_MODULE)_sim.cpp

-include $(PROJECT_ROOT)/storm.mk

VERILATOR_FLAGS+=-cc -Wno-lint --trace --trace-underscore -Wno-TIMESCALEMOD -O3 --autoflush -flatten
LDFLAGS+=-lgtest
CFLAGS+=-I/usr/src/googletest/googletest/include -I../../common -O3
CLEAN_FILES+=obj_dir $(TOP_MODULE)

.DEFAULT_GOAL:=run

$(OUTDIR)/$(TOP_MODULE).v: $(TOP_MODULE).nsl $(OUTDIR)
	$(NSL2VL) $(NSLFLAGS) -O0 -verisim2 -target $(TOP_MODULE) $< -o $@
$(OUTDIR)/obj_dir: $(VERILOG_SOURCE_FILES)
	$(VERILATOR) $(VERILATOR_FLAGS) $^ --top-module $(TOP_MODULE) --exe $(TOP_MODULE).cpp -LDFLAGS "$(LDFLAGS)" -CFLAGS "$(CFLAGS)"
$(TOP_MODULE): $(OUTDIR)/obj_dir
	cd obj_dir && make -f V$(TOP_MODULE).mk V$(TOP_MODULE)
	cp obj_dir/V$(TOP_MODULE) $(TOP_MODULE)
all: $(TOP_MODULE)
run: $(TOP_MODULE)
	./$(TOP_MODULE)
