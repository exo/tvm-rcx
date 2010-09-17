#include "tvm-rcx.h"
#include <tvm.h>
#include <tvm_tbc.h>

static tvm_t tvm;
static tvm_ectx_t context;

void main ()
{
    UWORD  tbc_length   = 0;
    BYTE  *tbc_data     = NULL;
    tbc_t *tbc          = NULL;

    rcx_init ();

    while (1) {
        /* Assume bytecode */
        tvm_ectx_init(&tvm, &context);
        rcx_out_int(42);
        // TODO: Mem pool
        /*context.get_time = rcx_get_time;
        // TODO: Sync flags
        context.sffi_table = sffi_table;
        context.sffi_table_length = sffi_table_length;*/
    }
}

