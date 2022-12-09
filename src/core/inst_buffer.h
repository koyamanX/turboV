#ifndef INST_BUFFER_H
#define INST_BUFFER_H

#include "ifetch_unit.h"

#define NUMBER_OF_INST_BUFFER 8
#define INST_BUFFER_NUM_OF_ENTRIES NUMBER_OF_INST_BUFFER.0
#define LOG2_INST_BUFFER_NUM_OF_ENTRIES _int(_log10(INST_BUFFER_NUM_OF_ENTRIES)/_log10(2.0))

declare inst_buffer {
    input idata[SIZEOF_FETCH_PACKET_T];
    func_in push(idata);
    output odata[SIZEOF_FETCH_PACKET_T];
    func_in pop() : odata;
    func_out full();
    func_out empty();
    func_in flush();
}

#endif
