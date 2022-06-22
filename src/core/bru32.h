#ifndef BRU32_H
#define BRU32_H

#define BRU_EQ  4'b0000
#define BRU_NE  4'b0001
#define BRU_LT  4'b0100
#define BRU_GE  4'b0101
#define BRU_LTU 4'b0110
#define BRU_GEU 4'b0111

#define BRU_JALR 4'b1111

declare bru32 {
    input a[32];
    input b[32];
    input fn[4];
    output taken;
    func_in exe(a, b, fn): taken;
}

#endif
