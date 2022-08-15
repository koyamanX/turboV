#ifndef REORDER_BUFFER_ENTRY_H
#define REORDER_BUFFER_ENTRY_H

#include "consts.h"
#include "uops.h"
#include "csr.h"

struct reorder_buffer_entry_t {
   Valid;
   Busy;
   PC[32];
   Inst[32];
   Value[32];
   uOp[SIZEOF_UOP_T];
   Target[32];
   Cause[16];
   CSRAddr[12];
   CSRValue[32];
#define SIZEOF_REORDER_BUFFER_ENTRY 190+SIZEOF_UOP_T
};

declare reorder_buffer_entry {
    input valid;
    input pc[32];
    input inst[32];
    input uop[SIZEOF_UOP_T];
    input cause[16];
    input csr_addr[12];
    input csr_value[32];
    func_in issue(valid, pc, inst, uop, cause, csr_addr, csr_value);
    func_in flush();
    func_out busy();
    output commit_entry[SIZEOF_REORDER_BUFFER_ENTRY];
    func_in commit(): commit_entry;
    input CDB0Val[32];
    func_in CDB0(CDB0Val);
    input CDB1Val[32];
    func_in CDB1(CDB1Val);
    input CDB2Val[32];
    input CDB2Target[32];
    input CDB2InstructionAddressMisaligned;
    func_in CDB2(CDB2Val, CDB2Target, CDB2InstructionAddressMisaligned);
    input CDB3Val[32];
    func_in CDB3(CDB3Val);
    output read_operandA_val[32];
    func_in read_operandA(): read_operandA_val;
    output read_operandB_val[32];
    func_in read_operandB(): read_operandB_val;
    output read_operandC_val[32];
    func_in read_operandC(): read_operandC_val;
    output read_operandD_val[32];
    func_in read_operandD(): read_operandD_val;
}
#endif
