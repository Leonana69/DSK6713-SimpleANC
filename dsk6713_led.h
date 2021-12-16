/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk6713_led.h ========
 *
 *  Interface for LEDs on the DSK6713 board
 */
#ifndef DSK6713_LED_
#define DSK6713_LED_

#ifdef __cplusplus
extern "C" {
#endif

#include <csl.h>

/* Initialize the LEDs */
void DSK6713_LED_init();

/* Turn the LED numbered ledNum off */
void DSK6713_LED_off(Uint32 ledNum);

/* Turn the LED numbered ledNum on */
void DSK6713_LED_on(Uint32 ledNum);

/* Toggle the LED numbered ledNum */
void DSK6713_LED_toggle(Uint32 ledNum);

#ifdef __cplusplus
}
#endif

#endif

