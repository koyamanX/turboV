CC=gcc
INCLUDE_DIR=-I/opt/riscv/x86_64-pc-linux-gnu/riscv32-elflittle/include/ 
LIBRARY_DIR=-L/opt/riscv/x86_64-pc-linux-gnu/riscv32-elflittle/lib/
LIBRARIES=-lopcodes -lbfd -liberty -lz -ldl
APP=disasm

$(APP): main.c
	$(CC) $< -o $@ $(INCLUDE_DIR) $(LIBRARIES) $(LIBRARY_DIR)
clean:
	rm -rf $(APP)
