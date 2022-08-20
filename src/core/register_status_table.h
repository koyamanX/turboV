#ifndef REGISTER_STATUS_TABLE_H
#define REGISTER_STATUS_TABLE_H

#include "consts.h"

#define BUSY 1'b1
#define READY 1'b0

declare register_status_table {
    func_in flush();
    input readA_lrs[5];
    output readA_busy;
    output readA_ROB[ROB_TAG_SIZE];
    func_in readA(readA_lrs): readA_busy;
    input readB_lrs[5];
    output readB_busy;
    output readB_ROB[ROB_TAG_SIZE];
    func_in readB(readB_lrs): readB_busy;
    input readC_lrs[5];
    output readC_busy;
    output readC_ROB[ROB_TAG_SIZE];
    func_in readC(readC_lrs): readC_busy;
    input readD_lrs[5];
    output readD_busy;
    output readD_ROB[ROB_TAG_SIZE];
    func_in readD(readD_lrs): readD_busy;
    input issue0_lrd[5];
    input issue0_ROB[ROB_TAG_SIZE];
    func_in issue0(issue0_lrd, issue0_ROB);
    input issue1_lrd[5];
    input issue1_ROB[ROB_TAG_SIZE];
    func_in issue1(issue1_lrd, issue1_ROB);
    input commit0_lrd[5];
    input commit0_ROB[ROB_TAG_SIZE];
    func_in commit0(commit0_lrd, commit0_ROB);
    input commit1_lrd[5];
    input commit1_ROB[ROB_TAG_SIZE];
    func_in commit1(commit1_lrd, commit1_ROB);
}
#endif
