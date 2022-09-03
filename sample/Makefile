CC=riscv32-unknown-elf-gcc
CFLAGS=-march=rv32i -mabi=ilp32 -nostartfiles -nostdlib -nostdinc -nodefaultlibs
STARTUP=crt0.S
MAIN=main
LINKERSCRIPT=-T linker.ldS 
SIMULATOR_PATH=../build/Debug/turboVSim/turboVSim

$(MAIN): $(MAIN).c
	$(CC) $(CFLAGS) $(STARTUP) $< -o $@ $(LINKERSCRIPT)
run: $(MAIN)
	$(SIMULATOR_PATH) $(MAIN)
clean:
	rm -rf $(MAIN)
