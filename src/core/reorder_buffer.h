#ifndef REORDER_BUFFER_H
#define REORDER_BUFFER_H

#include "uops.h"

struct reorder_buffer_t {
	PC[29];		// {PC[28:0], offset_in_reorder_buffer, 2'b00}
	valid0;
	uop0[SIZEOF_UOP_T];
	dreg0[5];
	ppreg0[6];
	exception0;
	retired0;
	valid1;
	uop1[SIZEOF_UOP_T];
	dreg1[5];
	ppreg1[6];
	exception1;
	retired1;
#define SIZEOF_REORDER_BUFFER_T 57+SIZEOF_UOP_T+SIZEOF_UOP_T
};

#define NUMBER_OF_REORDER_BUFFER 16
#define REORDER_BUFFER_NUM_OF_ENTRIES NUMBER_OF_REORDER_BUFFER.0
#define LOG2_REORDER_BUFFER_NUM_OF_ENTRIES _int(_log10(REORDER_BUFFER_NUM_OF_ENTRIES)/_log10(2.0))

declare reorder_buffer {
	input new_entry[SIZEOF_REORDER_BUFFER_T];
	output ptr[LOG2_REORDER_BUFFER_NUM_OF_ENTRIES+1];
	func_in issue(new_entry): ptr;
	output commit_entry[SIZEOF_REORDER_BUFFER_T];
	func_in commit(): commit_entry;
	func_out commitable();
	func_in flush();
	func_out full();
}

#endif
