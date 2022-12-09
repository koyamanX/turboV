#ifndef FREE_LIST_H
#define FREE_LIST_H

#define SIZEOF_FREE_LIST_ENTRY 6
#define NUMBER_OF_FREE_LIST 32
#define FREE_LIST_NUM_OF_ENTRIES NUMBER_OF_FREE_LIST.0
#define LOG2_FREE_LIST_NUM_OF_ENTRIES _int(_log10(FREE_LIST_NUM_OF_ENTRIES)/_log10(2.0))

declare free_list {
    func_in req_reset();
    input req_push0_data[SIZEOF_FREE_LIST_ENTRY];
    func_in req_push0(req_push0_data);
    input req_push1_data[SIZEOF_FREE_LIST_ENTRY];
    func_in req_push1(req_push1_data);
    output rsp_pop0_data[SIZEOF_FREE_LIST_ENTRY];
    func_in req_pop0(): rsp_pop0_data;
    output rsp_pop1_data[SIZEOF_FREE_LIST_ENTRY];
    func_in req_pop1(): rsp_pop1_data;
    output count[SIZEOF_FREE_LIST_ENTRY];
}
#endif
