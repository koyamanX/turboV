#ifndef FREE_LIST_H
#define FREE_LIST_H

#define SIZEOF_FREE_LIST_ENTRY 6
#define NUMBER_OF_FREE_LIST 64
#define FREE_LIST_NUM_OF_ENTRIES NUMBER_OF_FREE_LIST.0
#define LOG2_FREE_LIST_NUM_OF_ENTRIES _int(_log10(FREE_LIST_NUM_OF_ENTRIES)/_log10(2.0))

declare free_list {
	func_in reset();
	input push0_data[SIZEOF_FREE_LIST_ENTRY];
	func_in push0(push0_data);
	input push1_data[SIZEOF_FREE_LIST_ENTRY];
	func_in push1(push1_data);
	output pop0_data[SIZEOF_FREE_LIST_ENTRY];
	func_in pop0(): pop0_data;
	output pop1_data[SIZEOF_FREE_LIST_ENTRY];
	func_in pop1(): pop1_data;
	output count[SIZEOF_FREE_LIST_ENTRY];
	func_in flush();
}
#endif
