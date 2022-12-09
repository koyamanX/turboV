#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H
#include "riscv.h"

declare register_file {
    // 6 reads/ 3 writes
    input rnumA[6];
    output rdataA[XLEN];
    func_in readA(rnumA): rdataA;
    input rnumB[6];
    output rdataB[XLEN];
    func_in readB(rnumB): rdataB;
    input rnumC[6];
    output rdataC[XLEN];
    func_in readC(rnumC): rdataC;
    input rnumD[6];
    output rdataD[XLEN];
    func_in readD(rnumD): rdataD;
    input rnumE[6];
    output rdataE[XLEN];
    func_in readE(rnumE): rdataE;
    input rnumF[6];
    output rdataF[XLEN];
    func_in readF(rnumF): rdataF;
    input wnumA[6];
    input wdataA[XLEN];
    func_in writeA(wnumA, wdataA);
    input wnumB[6];
    input wdataB[XLEN];
    func_in writeB(wnumB, wdataB);
    input wnumC[6];
    input wdataC[XLEN];
    func_in writeC(wnumC, wdataC);
}

#endif
