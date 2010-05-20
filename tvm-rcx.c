#include "tvm-rcx.h"
#include "librcx.h"
#include "systime.h"

char dispatch[6];
async_t async;

/* Initialisation */
void rcx_init (int *w) {
    init_timer(&async, &dispatch[0]);
    init_power();
    systime_init();
    /* init_serial(&dispatch[4], &async, 1, 1); */
    init_serial(0, 0, 1, 1);
    init_sensors();
}

/* Timer call */
int rcx_get_time (void)
{
    /* Time from a 32 bit value updated by the millisecond handler */
    unsigned int time_16 = ((unsigned int*) &sys_time)[1];
    return time_16;
}

/* FFI functions to call generic ROM routine wrappers */
void rcall_0 (int *w) {
    __rcall0 (w[0]);
}

void rcall_1 (int *w) {
    __rcall1 (w[0], w[1]);
}

void rcall_vp (int *w) {
    __rcall1 (w[0], *((int*) w[1]));
}

void rcall_2 (int *w) {
    __rcall2 (w[0], w[1], w[2]);
}

void rcall_2_vvp (int *w) {
    __rcall2 (w[0], w[1], *((int*) w[2]));
}

void rcall_3 (int *w) {
    __rcall3 (w[0], w[1], w[2], w[3]);
}

void rcall_4 (int *w) {
    __rcall4 (w[0], w[1], w[2], w[3], w[4]);
}

