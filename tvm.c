#include "tvm-rcx.h"
#include "librcx.h"

static tvm_t tvm;
static tvm_ectx_t context;

void main ()
{
    UWORD tbc_length    = 0;
    BYTE *tbc_data      = NULL;
    tbc_t *tbc          = NULL;

    /* Platform initialisation */
    init_timer(&async, &dispatch[0]);
    init_power();
    systime_init();
    init_serial(0, 0, 1, 1);
    init_sensors();
    
}

