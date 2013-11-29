#include <stdio.h>
#include "zedit.h"

void  zedplup(
              int  graph,
              FILE  *prn)
/**********************************************************************/
/*                                                                    */
/* Switch the font lookup tables for the Proprinter X24 line.         */
/*                                                                    */
/**********************************************************************/
/*                                                                    */
/* This is ZEDIT source material.                                     */
/*                                                                    */
/* ZEDIT Source Materials are intellectual property                   */
/*     (c) Copyright 1987,2001 by Clyde Thomas Zuber.                 */
/*                                                                    */
/**********************************************************************/
{
/* table also in zedpx24 */
static int  addr[8] = {0xA414, 0xAF18, 0xBA1C, 0xC520, 0xD024,
    0xDB28, 0xE62C, 0xF130};  /* FC34 - FFFF also available */
register int  c;
register int  i;
unsigned short  llen;


fputc(0x1B, prn);                 /* ESC */
fputc(0x3D, prn);                 /*  = - define download chars */
llen = 9 * 94 + 3;
fputc(((char *)&llen)[0], prn);   /* count low  order byte */
fputc(((char *)&llen)[1], prn);   /* count high order byte */
fputc(0x23, prn);                 /* X24 printer ID */
/* each entry is 9 bytes * starting after blank x'20' + zero point */
llen = 9 * 33 + 0x8011;           /* start address */
fputc(((char *)&llen)[0], prn);   /* addr low  order byte */
fputc(((char *)&llen)[1], prn);   /* addr high order byte */

for (c = 0; c < 94; ++c)
    {
    llen = (unsigned short) (addr[graph] + c * 30); /* addr char map */
    fputc(((char *)&llen)[0], prn);   /* addr low  order byte */
    fputc(((char *)&llen)[1], prn);   /* addr high order byte */
    fputc(0x0A, prn);                 /* number of columns */
    fputc(0x09, prn);                 /* columns of print */
    for (i = 0; i < 5; ++i)
        fputc(0x00, prn);             /* mask bytes */
    } /* end for */

} /* end zedplup */
