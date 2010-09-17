#ifndef TVM_RCX_H
#define TVM_RCX_H

/* Platform */
#include "systime.h"
#include "librcx.h"

#include <tvm.h>
#include <tvm_tbc.h>

/* tvm.c */
extern char dispatch[6];
extern async_t async;

/* ffi.c */
extern SFFI_FUNCTION sffi_table[];
extern const int sffi_table_length;

/* tvm-rcx.c */

void rcx_init (void);
void rcx_out_int (short n);

int rcx_get_time (void);

void rcall_0 (int *w);
void rcall_1 (int *w);
void rcall_vp (int *w);
void rcall_2 (int *w);
void rcall_2_vvp (int *w);
void rcall_3 (int *w);
void rcall_4 (int *w);

#endif
