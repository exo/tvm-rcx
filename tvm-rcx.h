#ifndef TVM_RCX_H
#define TVM_RCX_H

/* Platform */
#include "systime.h"
#include "librcx.h"

#include <tvm.h>
#include <tvm_tbc.h>

extern char dispatch[6];
extern async_t async;

void rcx_init (int w[]);

int rcx_get_time (void);

void rcall_0 (int *w);
void rcall_1 (int *w);
void rcall_vp (int *w);
void rcall_2 (int *w);
void rcall_2_vvp (int *w);
void rcall_3 (int *w);
void rcall_4 (int *w);

#endif
