/*
 *  librcx.h
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

#ifndef LIBRCX_H
#define LIBRCX_H

/* Generic wrappers for calls to ROM routines */
extern char __rcall0 (short a);
extern char __rcall1 (short a, short p0);
extern char __rcall2 (short a, short p0, short p1);
extern char __rcall3 (short a, short p0, short p1, short p2);
extern char __rcall4 (short a, short p0, short p1, short p2, short p3);

/* Disable IRQ1, register button inputs, enable ram & setup standby */
static inline void init_power (void) {
    __rcall0 (0x2964);
}

/* Set bits on port6 for output, allow sensor active mode. */
static inline void init_sensors (void) {
    __rcall0(0x1498);
}

/* Initialise ports and serial routines. */
static inline void init_serial (void *ptr0, void *ptr1, char code0, char code1) {
    __rcall4 (0x30d0, (short)ptr0, (short)ptr1, code0, code1);
}

typedef struct {
    short serial;
    short timers[4];
    short clock_minutes;
    short shutoff_minutes;
    short task_wakeup[10];
    short motor_wakeup[3];
} async_t;

static inline void init_timer (void *ptr0, void *ptr1) {
    __rcall2 (0x3b9a, (short)ptr0, (short)ptr1);
}

#endif
