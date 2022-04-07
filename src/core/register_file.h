#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H
#include "riscv.h"

declare register_file {
    input rnumA[5];
    output rdataA[XLEN];
    func_in readA(rnumA): rdataA;
    input rnumB[5];
    output rdataB[XLEN];
    func_in readB(rnumB): rdataB;
    input rnumC[5];
    output rdataC[XLEN];
    func_in readC(rnumC): rdataC;
    input rnumD[5];
    output rdataD[XLEN];
    func_in readD(rnumD): rdataD;
    input wnumA[5];
    input wdataA[XLEN];
    func_in writeA(wnumA, wdataA);
    input wnumB[5];
    input wdataB[XLEN];
    func_in writeB(wnumB, wdataB);
}

#endif
