/*
 *  Copyright 2002 by Spectrum Digital Incorporated.
 *  All rights reserved. Property of Spectrum Digital Incorporated.
 */

/*
 *  ======== dsk6713_flash.h ========
 *
 *  Interface for the AMD29LV400BT Flash on the DSK6713 board
 */
#ifndef DSK6713_FLASH_
#define DSK6713_FLASH_

#ifdef __cplusplus
extern "C" {
#endif

#include <csl.h>

/* Flash address definitions */
#define DSK6713_FLASH_BASE          0x90000000
#define DSK6713_FLASH_PAGESIZE      0x08000
#define DSK6713_FLASH_PAGES         0x8
#define DSK6713_FLASH_SIZE          0x040000
#define DSK6713_FLASH_CTL555        (DSK6713_FLASH_BASE + (0x555 << 0))
#define DSK6713_FLASH_CTL2AA        (DSK6713_FLASH_BASE + (0x2aa << 0))
#define DSK6713_FLASH_CTLAAA        (DSK6713_FLASH_BASE + (0xaaa << 0))
#define DSK6713_FLASH_SUPPORT       1

/* Calculate the checksum of a data range in Flash */
Uint32 DSK6713_FLASH_checksum(Uint32 start, Uint32 length);

/* Erase a segment of Flash memory */
void DSK6713_FLASH_erase(Uint32 start, Uint32 length);

/* Read data from a range in Flash */
void DSK6713_FLASH_read(Uint32 src, Uint32 dst, Uint32 length);

/* Write data to a data range in Flash */
void DSK6713_FLASH_write(Uint32 src, Uint32 dst, Uint32 length);

#ifdef __cplusplus
}
#endif

#endif
