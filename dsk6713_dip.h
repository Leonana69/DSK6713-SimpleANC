/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk6713_dip.h ========
 *
 *  Interface for DIP switches on the DSK6713 board
 */
#ifndef DSK6713_DIP_
#define DSK6713_DIP_

#ifdef __cplusplus
extern "C" {
#endif

#include <csl.h>

/* Initialize the DIP switches */
void DSK6713_DIP_init();

/* Retrieve the DIP switch value */
Uint32 DSK6713_DIP_get(Uint32 dipNum);

#ifdef __cplusplus
}
#endif

#endif
