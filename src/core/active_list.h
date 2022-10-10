#ifndef ACTIVE_LIST_H
#define ACTIVE_LIST_H

#include "uops.h"

struct active_list_t {
	PC[29];		// {PC[28:0], offset_in_active_list, 2'b00}
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
#define SIZEOF_ACTIVE_LIST_T 57+SIZEOF_UOP_T+SIZEOF_UOP_T
};

#define NUMBER_OF_ACTIVE_LIST 16
#define ACTIVE_LIST_NUM_OF_ENTRIES NUMBER_OF_ACTIVE_LIST.0
#define LOG2_ACTIVE_LIST_NUM_OF_ENTRIES _int(_log10(ACTIVE_LIST_NUM_OF_ENTRIES)/_log10(2.0))

declare active_list {
	input new_entry[SIZEOF_ACTIVE_LIST_T];
	func_in issue(new_entry);
	output commit_entry[SIZEOF_ACTIVE_LIST_T];
	func_in commit(): commit_entry;
	func_out commitable();
	func_in flush();
	func_out full();
}

#endif
