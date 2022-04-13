#ifndef CSR_H
#define CSR_H

#define MVENDORID           0xf11
#define MARCHID             0xf12
#define MIMPID              0xf13
#define MHARTID             0xf14
#define MCONFIGPTR          0x1f5

#define MSTATUS             0x300
#define MISA                0x301
#define MEDELEG             0x302
#define MIDELEG             0x303
#define MIE                 0x304
#define MTVEC               0x305
#define MCOUNTEREN          0x306
#define MSTATUSH            0x310

#define MSCRATCH            0x340
#define MEPC                0x341
#define MCAUSE              0x342
#define MTVAL               0x343
#define MIP                 0x344
#define MINST               0x34a
#define MTVAL2              0x34b

#define MENVCFG             0x30a
#define MENVCFGH            0x31a
#define MSECCFG             0x747
#define MSECCFGH            0x757

#define PMPCFG0             0x3a0
#define PMPCFG1             0x3a1
#define PMPCFG2             0x3a2
#define PMPCFG3             0x3a3
#define PMPCFG4             0x3a4
#define PMPCFG5             0x3a5
#define PMPCFG6             0x3a6
#define PMPCFG7             0x3a7
#define PMPCFG8             0x3a8
#define PMPCFG9             0x3a9
#define PMPCFG10            0x3aa
#define PMPCFG11            0x3ab
#define PMPCFG12            0x3ac
#define PMPCFG13            0x3ad
#define PMPCFG14            0x3ae
#define PMPCFG15            0x3af

#define PMPADDR0            0x3b0
#define PMPADDR1            0x3b1
#define PMPADDR2            0x3b2
#define PMPADDR3            0x3b3
#define PMPADDR4            0x3b4
#define PMPADDR5            0x3b5
#define PMPADDR6            0x3b6
#define PMPADDR7            0x3b7
#define PMPADDR8            0x3b8
#define PMPADDR9            0x3b9
#define PMPADDR10           0x3ba
#define PMPADDR11           0x3bb
#define PMPADDR12           0x3bc
#define PMPADDR13           0x3bd
#define PMPADDR14           0x3be
#define PMPADDR15           0x3bf
#define PMPADDR16           0x3c0
#define PMPADDR17           0x3c1
#define PMPADDR18           0x3c2
#define PMPADDR19           0x3c3
#define PMPADDR20           0x3c4
#define PMPADDR21           0x3c5
#define PMPADDR22           0x3c6
#define PMPADDR23           0x3c7
#define PMPADDR24           0x3c8
#define PMPADDR25           0x3c9
#define PMPADDR26           0x3ca
#define PMPADDR27           0x3cb
#define PMPADDR28           0x3cc
#define PMPADDR29           0x3cd
#define PMPADDR30           0x3ce
#define PMPADDR31           0x3cf
#define PMPADDR32           0x3d0
#define PMPADDR33           0x3d1
#define PMPADDR34           0x3d2
#define PMPADDR35           0x3d3
#define PMPADDR36           0x3d4
#define PMPADDR37           0x3d5
#define PMPADDR38           0x3d6
#define PMPADDR39           0x3d7
#define PMPADDR40           0x3d8
#define PMPADDR41           0x3d9
#define PMPADDR42           0x3da
#define PMPADDR43           0x3db
#define PMPADDR44           0x3dc
#define PMPADDR45           0x3dd
#define PMPADDR46           0x3de
#define PMPADDR47           0x3df
#define PMPADDR48           0x3e0
#define PMPADDR49           0x3e1
#define PMPADDR50           0x3e2
#define PMPADDR51           0x3e3
#define PMPADDR52           0x3e4
#define PMPADDR53           0x3e5
#define PMPADDR54           0x3e6
#define PMPADDR55           0x3e7
#define PMPADDR56           0x3e8
#define PMPADDR57           0x3e9
#define PMPADDR58           0x3ea
#define PMPADDR59           0x3eb
#define PMPADDR60           0x3ec
#define PMPADDR61           0x3ed
#define PMPADDR62           0x3ee
#define PMPADDR63           0x3ef

#define MCYCLE              0xb00
#define MINSTRET            0xb02
#define MHPMCOUNTER3        0xb03
#define MHPMCOUNTER4        0xb04
#define MHPMCOUNTER5        0xb05
#define MHPMCOUNTER6        0xb06
#define MHPMCOUNTER7        0xb07
#define MHPMCOUNTER8        0xb08
#define MHPMCOUNTER9        0xb09
#define MHPMCOUNTER10       0xb0a
#define MHPMCOUNTER11       0xb0b
#define MHPMCOUNTER12       0xb0c
#define MHPMCOUNTER13       0xb0d
#define MHPMCOUNTER14       0xb0e
#define MHPMCOUNTER15       0xb0f
#define MHPMCOUNTER16       0xb10
#define MHPMCOUNTER17       0xb11
#define MHPMCOUNTER18       0xb12
#define MHPMCOUNTER19       0xb13
#define MHPMCOUNTER20       0xb14
#define MHPMCOUNTER21       0xb15
#define MHPMCOUNTER22       0xb16
#define MHPMCOUNTER23       0xb17
#define MHPMCOUNTER24       0xb18
#define MHPMCOUNTER25       0xb19
#define MHPMCOUNTER26       0xb1a
#define MHPMCOUNTER27       0xb1b
#define MHPMCOUNTER28       0xb1c
#define MHPMCOUNTER29       0xb1d
#define MHPMCOUNTER30       0xb1e
#define MHPMCOUNTER31       0xb1f

#define MCYCLEH             0xb80
#define MINSTRETH           0xb82
#define MHPMCOUNTER3H       0xb83
#define MHPMCOUNTER4H       0xb84
#define MHPMCOUNTER5H       0xb85
#define MHPMCOUNTER6H       0xb86
#define MHPMCOUNTER7H       0xb87
#define MHPMCOUNTER8H       0xb88
#define MHPMCOUNTER9H       0xb89
#define MHPMCOUNTER10H      0xb8a
#define MHPMCOUNTER11H      0xb8b
#define MHPMCOUNTER12H      0xb8c
#define MHPMCOUNTER13H      0xb8d
#define MHPMCOUNTER14H      0xb8e
#define MHPMCOUNTER15H      0xb8f
#define MHPMCOUNTER16H      0xb90
#define MHPMCOUNTER17H      0xb91
#define MHPMCOUNTER18H      0xb92
#define MHPMCOUNTER19H      0xb93
#define MHPMCOUNTER20H      0xb94
#define MHPMCOUNTER21H      0xb95
#define MHPMCOUNTER22H      0xb96
#define MHPMCOUNTER23H      0xb97
#define MHPMCOUNTER24H      0xb98
#define MHPMCOUNTER25H      0xb99
#define MHPMCOUNTER26H      0xb9a
#define MHPMCOUNTER27H      0xb9b
#define MHPMCOUNTER28H      0xb9c
#define MHPMCOUNTER29H      0xb9d
#define MHPMCOUNTER30H      0xb9e
#define MHPMCOUNTER31H      0xb9f

#define MCOUNTINHIBIT       0x320
#define MHPMEVENT3          0x323
#define MHPMEVENT4          0x324
#define MHPMEVENT5          0x325
#define MHPMEVENT6          0x326
#define MHPMEVENT7          0x327
#define MHPMEVENT8          0x328
#define MHPMEVENT9          0x329
#define MHPMEVENT10         0x32a
#define MHPMEVENT11         0x32b
#define MHPMEVENT12         0x32c
#define MHPMEVENT13         0x32d
#define MHPMEVENT14         0x32e
#define MHPMEVENT15         0x32f
#define MHPMEVENT16         0x330
#define MHPMEVENT17         0x331
#define MHPMEVENT18         0x332
#define MHPMEVENT19         0x333
#define MHPMEVENT20         0x334
#define MHPMEVENT21         0x335
#define MHPMEVENT22         0x336
#define MHPMEVENT23         0x337
#define MHPMEVENT24         0x338
#define MHPMEVENT25         0x339
#define MHPMEVENT26         0x33a
#define MHPMEVENT27         0x33b
#define MHPMEVENT28         0x33c
#define MHPMEVENT29         0x33d
#define MHPMEVENT30         0x33e
#define MHPMEVENT31         0x33f

struct misa_t {
    mxl[2];
    reserved0[4];
    extensions[26]; 
};
#define MISA_MXL_XLEN32     0x1
#define MISA_MXL_XLEN64     0x2
#define MISA_MXL_XLEN128    0x3

#define MISA_EXTENSIONS_A   26'b00000_00000_00000_00000_00000_1
#define MISA_EXTENSIONS_B   26'b00000_00000_00000_00000_00001_0
#define MISA_EXTENSIONS_C   26'b00000_00000_00000_00000_00010_0
#define MISA_EXTENSIONS_D   26'b00000_00000_00000_00000_00100_0
#define MISA_EXTENSIONS_E   26'b00000_00000_00000_00000_01000_0
#define MISA_EXTENSIONS_F   26'b00000_00000_00000_00000_10000_0
#define MISA_EXTENSIONS_G   26'b00000_00000_00000_00001_00000_0
#define MISA_EXTENSIONS_H   26'b00000_00000_00000_00010_00000_0
#define MISA_EXTENSIONS_I   26'b00000_00000_00000_00100_00000_0
#define MISA_EXTENSIONS_J   26'b00000_00000_00000_01000_00000_0
#define MISA_EXTENSIONS_K   26'b00000_00000_00000_10000_00000_0
#define MISA_EXTENSIONS_L   26'b00000_00000_00001_00000_00000_0
#define MISA_EXTENSIONS_M   26'b00000_00000_00010_00000_00000_0
#define MISA_EXTENSIONS_N   26'b00000_00000_00100_00000_00000_0
#define MISA_EXTENSIONS_O   26'b00000_00000_01000_00000_00000_0
#define MISA_EXTENSIONS_P   26'b00000_00000_10000_00000_00000_0
#define MISA_EXTENSIONS_Q   26'b00000_00001_00000_00000_00000_0
#define MISA_EXTENSIONS_R   26'b00000_00010_00000_00000_00000_0
#define MISA_EXTENSIONS_S   26'b00000_00100_00000_00000_00000_0
#define MISA_EXTENSIONS_T   26'b00000_01000_00000_00000_00000_0
#define MISA_EXTENSIONS_U   26'b00000_10000_00000_00000_00000_0
#define MISA_EXTENSIONS_V   26'b00001_00000_00000_00000_00000_0
#define MISA_EXTENSIONS_W   26'b00010_00000_00000_00000_00000_0
#define MISA_EXTENSIONS_X   26'b00100_00000_00000_00000_00000_0
#define MISA_EXTENSIONS_Y   26'b01000_00000_00000_00000_00000_0
#define MISA_EXTENSIONS_Z   26'b10000_00000_00000_00000_00000_0

struct mvendorid_t {
    bank[25];
    offset[7];
};

struct marchid_t {
    architecture_id[32];
};

struct mimpid_t {
    implementation[32];
};

struct mhartid_t {
    hart_id[32];
};

struct mstatus_t {
    sd;
    reserved0[8];
    tsr;
    tw;
    tvm;
    mxr;
    sum;
    mprv;
    xs[2];
    fs[2];
    mpp[2];
    vs[2];
    spp;
    mpie;
    ube;
    spie;
    reserved1;
    mie;
    reserved2;
    sie;
    reserved3;
};

struct mstatush_t {
    reserved0[26];
    mbe;
    sbe;
    reserved1[4];
};

struct mtvec_t {
    base[30];
    mode[2];
};

#define MTVEC_MODE_DIRECT   0x0
#define MTVEC_MODE_VECTORED 0x1

struct medeleg_t {
    exceptions[32];
};

struct mideleg_t {
    interrupts[32];
};

struct mip_t {
    interrupts[32];
};

struct mie_t {
    interrupts[32];
};

struct mscratch_t {
    mscratch[32];
};

struct mepc_t {
    mepc[32];
};

struct mtval_t {
    mtval[32];
};

struct mcause_t {
    interrupt;
    exception_code[31];
};

#endif
