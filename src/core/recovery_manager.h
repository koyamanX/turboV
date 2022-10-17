#ifndef RECOVERY_MANAGER_H
#define RECOVERY_MANAGER_H
#include "reorder_buffer.h"

struct recovery_manager_t {
	valid;
	uops[SIZEOF_UOP_T];
	ptr[REORDER_BUFFER_PTR_SIZE];
	target[32];
#define SIZEOF_RECOVERY_MANAGER_T 1+SIZEOF_UOP_T+REORDER_BUFFER_PTR_SIZE+32
};

declare recovery_manager {
	input head[REORDER_BUFFER_PTR_SIZE];
#define PTR2AGE(ptr) (if(ptr<head) ptr+NUMBER_OF_REORDER_BUFFER*2 else ptr)
	input complete0_ptr[REORDER_BUFFER_PTR_SIZE];
	input complete0_entry[SIZEOF_RECOVERY_MANAGER_T];
	func_in complete0(complete0_ptr, complete0_entry);
	input complete1_ptr[REORDER_BUFFER_PTR_SIZE];
	input complete1_entry[SIZEOF_RECOVERY_MANAGER_T];
	func_in complete1(complete1_ptr, complete1_entry);
	input complete2_ptr[REORDER_BUFFER_PTR_SIZE];
	input complete2_entry[SIZEOF_RECOVERY_MANAGER_T];
	func_in complete2(complete2_ptr, complete2_entry);
	input commit0_ptr[REORDER_BUFFER_PTR_SIZE];
	output commit0_trap;
	func_in commit0(commit0_ptr): commit0_trap;
	input commit1_ptr[REORDER_BUFFER_PTR_SIZE];
	output commit1_trap;
	func_in commit1(commit1_ptr): commit1_trap;
	output recovery_entry[SIZEOF_RECOVERY_MANAGER_T];
	func_out recovery(recovery_entry);
	func_in flush();
}

#endif
