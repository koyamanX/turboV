#ifndef SIM_EXIT_H
#define SIM_EXIT_H

#define SIM_EXIT ((volatile unsigned int *)(0x80001000))
#define SIM_EXIT_FAILURE (!1)
#define SIM_EXIT_SUCCESS (!0)

void sim_exit(int status) {
    *SIM_EXIT = status;
_exit:
    goto _exit;
}

#endif
