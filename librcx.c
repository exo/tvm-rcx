/*
 *  librcx.c
 *  Collected functions from librcx required for the TVM wrapper
 *
 *  The contents of this file are subject to the Mozilla Public License
 *  Version 1.0 (the "License"); you may not use this file except in
 *  compliance with the License. You may obtain a copy of the License at
 *  http://www.mozilla.org/MPL/
 *
 *  Software distributed under the License is distributed on an "AS IS"
 *  basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
 *  License for the specific language governing rights and limitations
 *  under the License.
 *
 *  The Original Code is Librcx code, released February 9, 1999.
 *
 *  The Initial Developer of the Original Code is Kekoa Proudfoot.
 *  Portions created by Kekoa Proudfoot are Copyright (C) 1999
 *  Kekoa Proudfoot. All Rights Reserved.
 *
 *  Contributor(s): Kekoa Proudfoot <kekoa@graphics.stanford.edu>
 *                  Jon Simpson <me@jonsimpson.co.uk>
 */

#include "librcx.h"

/* extern char __rcall0 (short a); */
__asm__ (
".section .text\n\t"
".global ___rcall0\n\t"
"___rcall0:\n\t"
    "push   r6\n\t"
    "jsr    @r0\n\t"
    "mov.w  r6,r0\n\t"
    "pop    r6\n\t"
    "rts\n\t"
);


/* extern char __rcall1 (short a, short p0); */
__asm__ (
".section .text\n\t"
".global ___rcall1\n\t"
"___rcall1:\n\t"
    "push    r6\n\t"
    "mov.w   r1,r6\n\t"
    "jsr     @r0\n\t"
    "mov.w   r6,r0\n\t"
    "pop     r6\n\t"
    "rts\n\t"
);

/* extern char __rcall2 (short a, short p0, short p1); */
__asm__ (
".section .text\n\t"
".global ___rcall2\n\t"
"___rcall2:\n\t"
    "push    r6\n\t"
    "push    r2\n\t"
    "mov.w   r1,r6\n\t"
    "jsr     @r0\n\t"
    "adds    #2,r7\n\t"
    "mov.w   r6,r0\n\t"
    "pop     r6\n\t"
    "rts\n\t"
);

/* extern char __rcall3 (short a, short p0, short p1, short p2); */
__asm__ (
".section .text\n\t"
".global ___rcall3\n\t"
"___rcall3:\n\t"
    "push    r6\n\t"
    "mov.w   @(4,r7),r3\n\t"
    "push    r3\n\t"
    "push    r2\n\t"
    "mov.w   r1,r6\n\t"
    "jsr     @r0\n\t"
    "adds    #2,r7\n\t"
    "adds    #2,r7\n\t"
    "mov.w   r6,r0\n\t"
    "pop     r6\n\t"
    "rts\n\t"
);

/* extern char __rcall4 (short a, short p0, short p1, short p2, short p3); */
__asm__ (
".section .text\n\t"
".global ___rcall4\n\t"
"___rcall4:\n\t"
    "push    r6\n\t"
    "mov.w   @(6,r7),r3\n\t"
    "push    r3\n\t"
    "mov.w   @(6,r7),r3\n\t"
    "push    r3\n\t"
    "push    r2\n\t"
    "mov.w   r1,r6\n\t"
    "jsr     @r0\n\t"
    "add.b   #6,r7l\n\t"
    "addx.b  #0,r7h\n\t"
    "mov.w   r6,r0\n\t"
    "pop     r6\n\t"
    "rts\n\t"
);

__asm__ (
    ".section .text\n\t"
    ".global ___mulhi3\n\t"
"___mulhi3:\n\t"
    "mov.b   r1h,r2l\n\t"
    "mov.b   r0h,r1h\n\t"
    "mulxu.b r0l,r2\n\t"
    "mulxu.b r1l,r0\n\t"
    "mulxu.b r1h,r1\n\t"
    "add.b   r1l,r0h\n\t"
    "add.b   r2l,r0h\n\t"
    "rts\n\t"
);

__asm__ (
    ".section .text\n\t"
    ".global ___divhi3\n\t"
"___divhi3:\n\t"
    "push    r5\n\t"
    "push    r6\n\t"
    "mov.w   r0,r6\n\t"
    "mov.w   r1,r5\n\t"
    "jsr     @@82\n\t"
    "mov.w   r6,r0\n\t"
    "pop     r6\n\t"
    "pop     r5\n\t"
    "rts\n\t"
);

__asm__ (
    ".section .text\n\t"
    ".global ___modhi3\n\t"
"___modhi3:\n\t"
    "push    r5\n\t"
    "push    r6\n\t"
    "mov.w   r0,r6\n\t"
    "mov.w   r1,r5\n\t"
    "jsr     @@80\n\t"
    "mov.w   r6,r0\n\t"
    "pop     r6\n\t"
    "pop     r5\n\t"
    "rts\n\t"
);

__asm__ (
    ".section .init\n\t"
    ".global __start\n"
    "__start:\n\t"
    "push r0\n\t"
    "push r1\n\t"
    "push r2\n\t"
    "push r3\n\t"
    "jsr __init\n\t"
    "pop r3\n\t"
    "pop r2\n\t"
    "pop r1\n\t"
    "pop r0\n\t"
    "rts\n\t"
    ".string \"Do you byte, when I knock?\""
);

typedef unsigned int size_t;

extern void __bzero (void *start, void *end) __asm__("0x0436");

void bzero (void *start, size_t len) {
	__bzero(start, ((char *)start) + len);
}

extern int main (void);

extern char _bss_start, _end;

void _init (void) {
    //char *p;

    /* Clear the .bss data */
    __bzero(&_bss_start, &_end);

#if 0
    /* Clear the shadow registers */
    __bzero((void *)0xfd80, (void *)0xfd86);
#endif

    /* Call main */
    main();

    /* Delete the firmware */
    *(char *)0xffcc = 1;
    (*(void (**)(void))0)();
}
