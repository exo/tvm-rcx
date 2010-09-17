/**
 * ffi.c - Foreign function interface for RCX
 * Copyright (c) 2010, Jon Simpson <me@jonsimpson.co.uk>
 **/

#include "tvm-rcx.h"

#ifdef UNUSED 
#elif defined(__GNUC__) 
#define UNUSED(x) UNUSED_ ## x __attribute__((unused))
#else
#define UNUSED(x) x 
#endif

/* PROC out.int (VAL INT n) */
int _rcx_out_int (ECTX UNUSED(ectx), WORD args[]) {
    rcx_out_int(args[0]);
    return SFFI_OK;
}

SFFI_FUNCTION sffi_table[] = {
    _rcx_out_int
};

const int sffi_table_length = sizeof(sffi_table) / sizeof(SFFI_FUNCTION);
