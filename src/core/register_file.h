#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H

declare register_file {
	input rnuma[5];
	output rdataa[32];
	func_in reada(rnuma): rdataa;
	input rnumb[5];
	output rdatab[32];
	func_in readb(rnumb): rdatab;
	input wnuma[5];
	input wdataa[32];
	func_in writea(wnuma, wdataa);
}

#endif
