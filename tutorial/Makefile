AS=riscv32-unknown-elf-as
LD=riscv32-unknown-elf-ld
OBJCOPY=riscv32-unknown-elf-objcopy
NSL2VL=nsl2vl
TARGET=-target top
NSLFLAGS=-verisim2 $(TARGET)
IVERILOG=iverilog
GTKWAVE=gtkwave

MEMORY=memory


tinyV.vvp: tinyV.nsl $(MEMORY).S
	$(NSL2VL) $(NSLFLAGS) tinyV.nsl
	$(IVERILOG) tinyV.v -o $@
	$(AS) $(MEMORY).S -o $(MEMORY).o
	$(LD) -section-start=.text=0 $(MEMORY).o -o $(MEMORY).elf
	$(OBJCOPY) --only-section=.text --reverse-bytes=4 --verilog-data-width=4 -O verilog $(MEMORY).elf $(MEMORY).hex

clean:
	rm -rf $(MEMORY).elf $(MEMORY).o $(MEMORY).hex tinyV.vvp tinyV.v top.vcd
