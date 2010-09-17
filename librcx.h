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

static inline void init_buttons (void) {
    __rcall0 (0x1aba);
}

static inline void refresh_display (void) {
    __rcall0 (0x27c8);
}

/*
 * Set lcd number (short code, short value, short pointcode)
 *
 * code=3001: Set lcd main number signed
 *   Set main number on display to signed value, with no leading zeros
 *   If value > 9999, displayed value is 9999
 *   If value < -9999, displayed value is -9999
 * code=3017: Set lcd program number
 *   Set program number on display to value, use pointcode=0
 *   If value < 0, no value is displayed
 *   If value > 0, no value is displayed
 *   Pointcode is ignored, no real need to set to zero
 * code=301f: Set lcd main number unsigned
 *   Set main number on display to unsigned value, with leading zeros
 *   Value is unsigned, so it is never less than 0
 * For 3001, 301f:
 *   pointcode=3002: no decimal point
 *   pointcode=3003: 000.0 format
 *   pointcode=3004: 00.00 format
 *   pointcode=3005: 0.000 format
 */

/* code */
#define LCD_SIGNED           0x3001
#define LCD_PROGRAM          0x3017
#define LCD_UNSIGNED         0x301f

/* pointcode */
#define LCD_DECIMAL_0        0x3002
#define LCD_DECIMAL_1        0x3003
#define LCD_DECIMAL_2        0x3004
#define LCD_DECIMAL_3        0x3005

static inline void
set_lcd_number (short code, short value, short pointcode)
{
    __rcall3 (0x1ff2, code, value, pointcode);
}

#endif
