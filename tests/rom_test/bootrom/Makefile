NSL2VL:=nsl2vl
AS=riscv32-unknown-elf-as
LD=riscv32-unknown-elf-ld
OBJCOPY=riscv32-unknown-elf-objcopy
GEN_ROM_DATA=../../../tools/gen_rom_data.py

all: bootrom rom64x2K.v
bootrom: bootrom.s
	$(AS) $< -o bootrom.o
	$(LD) bootrom.o -o $@ -Tbootrom.ld
	$(OBJCOPY) -O verilog bootrom.o bootrom.hex
	$(GEN_ROM_DATA) bootrom.hex 8
	
rom64x2K.v: bootrom rom64x2K.nsl rom64x2K.h
	$(NSL2VL) rom64x2K.nsl -o rom64x2K.v -I./ -I../../../src/wishbone -O2
clean:
	rm -rf *.hex bootrom bootrom.o
