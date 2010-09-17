#include "librcx.h"
#include "systime.h"

char dispatch[6];
async_t async;

void main ()
{
    /* Platform initialisation */
    init_timer(&async, &dispatch[0]);
    init_power();
    systime_init();

    init_sensors();
    //init_motors
    init_buttons(); // Buttons & display pins
    init_serial(0, 0, 1, 1);

    __rcall3(0x1ff2, 0x301f, 42, 0x3002);
    __rcall0(0x27c8);

    while (1) {
    }
}

