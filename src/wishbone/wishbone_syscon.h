#ifndef WISHBONE_SYSCON_H
#define WISHBONE_SYSCON_H

declare wishbone_syscon interface {
    input CLK_I;
    input RST_I;
    /* The system clock output which coordinates
        all activities for the internal logic within
        the WISHBONE interconnect.
    */
    output CLK_O;
    /* The reset output which forces all WISHBONE
        interfaces to restart.
    */
    output RST_O;
}

#endif
