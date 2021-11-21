NSL2VL=nsl2vl
IVERILOG=iverilog
VERILATOR=verilator
GTKWAVE=gtkwave
CXX=g++
CPP=cpp

WISHBONE_DIR=../../src/wishbone
WISHBONE_MASTER=wishbone_master
WISHBONE_SLAVE=wishbone_slave
WISHBONE_TEST=wishbone_slave_reg

NSLINCLUDEDIR=-I$(WISHBONE_DIR)
NSLFLAGS=$(NSLINCLUDEDIR) -O0
CXXFLAGS=
LDFLAGS=

NSLFILES:=$(wildcard *.nsl) $(wildcard $(WISHBONE_DIR)/*.nsl)
NSLFILES:=$(notdir $(NSLFILES))
VFILES:=$(patsubst %.nsl,%.v,$(NSLFILES))
DEPENDS:=$(patsubst %.nsl,%.d,$(NSLFILES))


.PHONY: all clean

all: wishbone_slave_reg_test

%.d: %.nsl
	$(CPP) -MM $(NSLFLAGS) $< | sed "s/\.o/\.v/g" > $@
%.d: $(WISHBONE_DIR)/%.nsl
	$(CPP) -MM $(NSLFLAGS) $< | sed "s/\.o/\.v/g" > $@
-include $(DEPENDS)

$(WISHBONE_MASTER).v: $(WISHBONE_DIR)/$(WISHBONE_MASTER).nsl
	$(NSL2VL) $(NSLFLAGS) -clock_name CLK_I -reset_name RST_I $< -o $@
$(WISHBONE_SLAVE).v: $(WISHBONE_DIR)/$(WISHBONE_SLAVE).nsl
	$(NSL2VL) $(NSLFLAGS) -clock_name CLK_I -reset_name RST_I $< -o $@
$(WISHBONE_TEST).v: $(WISHBONE_TEST).nsl
	$(NSL2VL) $(NSLFLAGS) -clock_name CLK_I -reset_name RST_I $< -o $@
$(WISHBONE_TEST)_test.v: $(WISHBONE_TEST)_test.nsl
	$(NSL2VL) $(NSLFLAGS) -O2 -verisim2 -target wishbone_slave_reg_test $< -o $@
$(WISHBONE_TEST)_test: $(VFILES)
	$(IVERILOG) $^ -o $@
%.v: %.nsl
	$(NSL2VL) $(NSLFLAGS) $< -o $@
%.v: $(WISHBONE_DIR)/%.nsl
	$(NSL2VL) $(NSLFLAGS) $< -o $@

clean:
	rm -rf $(DEPENDS) $(VFILES) $(WISHBONE_TEST)_test $(WISHBONE_TEST)_test.vcd
