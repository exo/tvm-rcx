#include "tvm-rcx.h"

char dispatch[6];
async_t async;

void main ()
{
    /* Platform initialisation */
    rcx_init();

    rcx_out_int(42);

    while (1) {
    }
}

