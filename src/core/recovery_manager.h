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
	input retire0_ptr[REORDER_BUFFER_PTR_SIZE];
	input retire0_entry[SIZEOF_RECOVERY_MANAGER_T];
	func_in retire0(retire0_ptr, retire0_entry);
	input retire1_ptr[REORDER_BUFFER_PTR_SIZE];
	input retire1_entry[SIZEOF_RECOVERY_MANAGER_T];
	func_in retire1(retire1_ptr, retire1_entry);
	input retire2_ptr[REORDER_BUFFER_PTR_SIZE];
	input retire2_entry[SIZEOF_RECOVERY_MANAGER_T];
	func_in retire2(retire2_ptr, retire2_entry);
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
