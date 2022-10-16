#ifndef REORDER_BUFFER_H
#define REORDER_BUFFER_H

#include "uops.h"

struct reorder_buffer_t {
	PC[29];		// {PC[28:0], offset_in_reorder_buffer, 2'b00}
	valid0;
	uop0[SIZEOF_UOP_T];
	dreg0[5];
	ppreg0[6];
	cause0[SIZEOF_CAUSE_T];
	retired0;
	valid1;
	uop1[SIZEOF_UOP_T];
	dreg1[5];
	ppreg1[6];
	cause1[SIZEOF_CAUSE_T];
	retired1;
#define SIZEOF_REORDER_BUFFER_T 55+SIZEOF_UOP_T+SIZEOF_UOP_T+SIZEOF_CAUSE_T+SIZEOF_CAUSE_T
};

#define NUMBER_OF_REORDER_BUFFER 8
#define REORDER_BUFFER_NUM_OF_ENTRIES NUMBER_OF_REORDER_BUFFER.0
#define LOG2_REORDER_BUFFER_NUM_OF_ENTRIES _int(_log10(REORDER_BUFFER_NUM_OF_ENTRIES)/_log10(2.0))
#define REORDER_BUFFER_PTR_SIZE LOG2_REORDER_BUFFER_NUM_OF_ENTRIES+1

declare reorder_buffer {
	input PC[29];
	input valid0;
	input uop0[SIZEOF_UOP_T];
	input dreg0[5];
	input ppreg0[6];
	input cause0[SIZEOF_CAUSE_T];
	input valid1;
	input uop1[SIZEOF_UOP_T];
	input dreg1[5];
	input ppreg1[6];
	input cause1[SIZEOF_CAUSE_T];
	output ptr[REORDER_BUFFER_PTR_SIZE];
	func_in issue(PC, valid0, uop0, dreg0, ppreg0, cause0,
					  valid1, uop1, dreg1, ppreg1, cause1): ptr;
	output commit_entry[SIZEOF_REORDER_BUFFER_T];
	func_in commit(): commit_entry;
	func_out commitable();
	input retire0_ptr[REORDER_BUFFER_PTR_SIZE];
	func_in retire0(retire0_ptr);
	input retire1_ptr[REORDER_BUFFER_PTR_SIZE];
	func_in retire1(retire1_ptr);
	input retire2_ptr[REORDER_BUFFER_PTR_SIZE];
	func_in retire2(retire2_ptr);
	func_in flush();
	func_out full();
}

#endif
