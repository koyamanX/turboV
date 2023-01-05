#ifndef UART_H
#define UART_H

#include "wishbone_common.h"

#define UART_BASE 0x40000000
#define UART_LENGTH 0x1000

#define TXDATA	0x0
#define RXDATA	0x4
#define TXCTRL	0x8
#define RXCTRL	0xc
#define IE		0x10
#define IP		0x14
#define DIV		0x18

struct txdata_t {
	full;
	reserved[23];
	data[8];
#define SIZEOF_TXDATA_T 32
};

struct rxdata_t {
	empty;
	reserved[23];
	data[8];
#define SIZEOF_RXDATA_T 32
};

struct txctrl_t {
	reserved0[13];
	txcnt[3];
	reserved1[14];
	nstop;
	txen;
#define SIZEOF_TXCTRL 32
};

struct rxctrl_t {
	reserved0[13];
	rxcnt[3];
	reserved1[15];
	rxen;
#define SIZEOF_RXCTRL 32
};

struct ie_t {
	reserved[30];
	rxwm;
	txwm;
#define SIZEOF_IE_T 32
};

struct ip_t {
	reserved[30];
	rxwm;
	txwm;
#define SIZEOF_IP_T 32
};

// baud_t -> div_t
// div_t is used in standard c library,
// so renamed not to be same.
struct baud_t {
	reserved[16];
	div[16];
#define SIZEOF_BAUD_T 32
};

declare uart {
    func_in reset();
	func_out req_txwm_interrupt();
	func_out req_rxwm_interrupt();
    WISHBONE_GEN_SLAVE_IF(32, 64, 8)
    WISHBONE_GEN_SLAVE_TAG_IF()
}

#endif
