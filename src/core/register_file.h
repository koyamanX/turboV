#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H
#include "riscv.h"

declare register_file {
	input rnuma[5];
	output rdataa[XLEN];
	func_in reada(rnuma): rdataa;
	input rnumb[5];
	output rdatab[XLEN];
	func_in readb(rnumb): rdatab;
	input wnuma[5];
	input wdataa[XLEN];
	func_in writea(wnuma, wdataa);
}

#endif
