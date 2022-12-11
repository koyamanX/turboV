#ifndef INST_BUFFER_H
#define INST_BUFFER_H

#include "ifetch_unit.h"

#define NUMBER_OF_INST_BUFFER 8
#define INST_BUFFER_NUM_OF_ENTRIES NUMBER_OF_INST_BUFFER.0
#define LOG2_INST_BUFFER_NUM_OF_ENTRIES _int(_log10(INST_BUFFER_NUM_OF_ENTRIES)/_log10(2.0))

declare inst_buffer {
    input req_push_data[SIZEOF_FETCH_PACKET_T];
    func_in req_push(req_push_data);
    output rsp_pop_data[SIZEOF_FETCH_PACKET_T];
    func_in req_pop() : rsp_pop_data;
    output full_o;
    output empty_o;
    func_in req_flush();
}

#endif
