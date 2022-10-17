#ifndef REORDER_BUFFER_H
#define REORDER_BUFFER_H

#include "uops.h"

struct reorder_buffer_t {
	PC[29];		// {PC[28:0], offset_in_reorder_buffer, 2'b00}
	valid0;
	uop0[SIZEOF_UOP_T];
	dreg0[5];
	preg0[6];
	ppreg0[6];
	cause0[SIZEOF_CAUSE_T];
	completed0;
	valid1;
	uop1[SIZEOF_UOP_T];
	dreg1[5];
	preg1[6];
	ppreg1[6];
	cause1[SIZEOF_CAUSE_T];
	completed1;
#ifdef ENABLE_DEBUG
	inst0[32];
	inst1[32];
#define SIZEOF_REORDER_BUFFER_T 55+SIZEOF_UOP_T+SIZEOF_UOP_T+SIZEOF_CAUSE_T+SIZEOF_CAUSE_T+32+32+12
#else
#define SIZEOF_REORDER_BUFFER_T 55+SIZEOF_UOP_T+SIZEOF_UOP_T+SIZEOF_CAUSE_T+SIZEOF_CAUSE_T
#endif
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
	input preg0[6];
	input ppreg0[6];
	input cause0[SIZEOF_CAUSE_T];
	input valid1;
	input uop1[SIZEOF_UOP_T];
	input dreg1[5];
	input preg1[6];
	input ppreg1[6];
	input cause1[SIZEOF_CAUSE_T];
	output ptr[REORDER_BUFFER_PTR_SIZE];
#ifdef ENABLE_DEBUG
	input inst0[32];
	input inst1[32];
	func_in issue(PC, valid0, uop0, dreg0, preg0, ppreg0, cause0,
					  valid1, uop1, dreg1, preg1, ppreg1, cause1, inst0, inst1): ptr;
#else
	func_in issue(PC, valid0, uop0, dreg0, preg0, ppreg0, cause0,
					  valid1, uop1, dreg1, preg1, ppreg1, cause1): ptr;

#endif
	output commit_entry[SIZEOF_REORDER_BUFFER_T];
	func_in commit(): commit_entry;
	func_out commitable();
	input complete0_ptr[REORDER_BUFFER_PTR_SIZE];
	func_in complete0(complete0_ptr);
	input complete1_ptr[REORDER_BUFFER_PTR_SIZE];
	func_in complete1(complete1_ptr);
	input complete2_ptr[REORDER_BUFFER_PTR_SIZE];
	func_in complete2(complete2_ptr);
	func_in flush();
	func_out full();
}

#endif
