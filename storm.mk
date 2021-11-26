NSL2VL:=nsl2vl
IVERILOG:=iverilog
VERILATOR:=verilator
GTKWAVE:=gtkwave
CXX:=g++
CPP:=cpp

WISHBONE_DIR:=$(PROJECT_ROOT)/src/wishbone
INTEGRATION_DIR:=$(PROJECT_ROOT)/src/integration
CORE_DIR:=$(PROJECT_ROOT)/src/core
NSL_INCLUDE_DIRS:= \
	-I$(WISHBONE_DIR) \
	-I$(INTEGRATION_DIR) \
	-I$(CORE_DIR)
NSL_SOURCE_FILES:= \
	$(wildcard *.nsl) \
	$(wildcard $(WISHBONE_DIR)/*.nsl) \
	$(wildcard $(INTEGRATION_DIR)/*.nsl) \
	$(wildcard $(CORE_DIR)/*.nsl)
NSL_SOURCE_FILES:=$(notdir $(NSL_SOURCE_FILES))
NSL_SOURCE_DEPENDS:=$(addprefix out/, $(NSL_SOURCE_FILES:.nsl=.d))
VERILOG_SOURCE_FILES:=$(addprefix out/, $(NSL_SOURCE_FILES:.nsl=.v))

NSLFLAGS:=$(NSL_INCLUDE_DIRS) -O2
CXXFLAGS=
LDFLAGS=
VERILATOR_FLAGS=

.PHONY: all out clean

$(OUTDIR):
	@if [ ! -d $(OUTDIR) ]; then \
		mkdir $@; \
	fi

$(OUTDIR)/%.d: %.nsl
	@if [ ! -d $(OUTDIR) ]; then \
		mkdir $(OUTDIR); \
	fi
	$(CPP) -MM $(NSL_INCLUDE_DIRS) $< | sed "s/\.o/\.v/g" > $@
$(OUTDIR)/%.d: $(WISHBONE_DIR)/%.nsl
	if [ ! -d $(OUTDIR) ]; then \
		mkdir $(OUTDIR); \
	fi
	$(CPP) -MM $(NSL_INCLUDE_DIRS) $< | sed "s/\.o/\.v/g" > $@
$(OUTDIR)/%.d: $(INTEGRATION_DIR)/%.nsl
	if [ ! -d $(OUTDIR) ]; then \
		mkdir $(OUTDIR); \
	fi
	$(CPP) -MM $(NSL_INCLUDE_DIRS) $< | sed "s/\.o/\.v/g" > $@
$(OUTDIR)/%.d: $(CORE_DIR)/%.nsl
	if [ ! -d $(OUTDIR) ]; then \
		mkdir $(OUTDIR); \
	fi
	$(CPP) -MM $(NSL_INCLUDE_DIRS) $< | sed "s/\.o/\.v/g" > $@

-include $(NSL_SOURCE_DEPENDS)

$(OUTDIR)/%.v: %.nsl $(OUTDIR)
	$(NSL2VL) $(NSLFLAGS) $< -o $@
$(OUTDIR)/%.v: $(WISHBONE_DIR)/%.nsl $(OUTDIR)
	$(NSL2VL) $(NSLFLAGS) -clock_name CLK_I -reset_name RST_I $< -o $@
$(OUTDIR)/%.v: $(INTEGRATION_DIR)/%.nsl $(OUTDIR)
	$(NSL2VL) $(NSLFLAGS) $< -o $@
$(OUTDIR)/%.v: $(CORE_DIR)/%.nsl $(OUTDIR)
	$(NSL2VL) $(NSLFLAGS) $< -o $@
clean:
	rm -rf $(OUTDIR)
