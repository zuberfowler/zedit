#include <stdio.h>
#include "zedit.h"

void  zedpx24(
              FILE  *prn)
/**********************************************************************/
/*                                                                    */
/* Download printer half height fonts to printer ram (Proprinter X24).*/
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
extern char  zedascb[94] [8];
extern char  zedasct[94] [8];
extern char  zedgrkb[94] [8];
extern char  zedgrkt[94] [8];
extern char  zedhebb[94] [8];
extern char  zedhebt[94] [8];
extern char  zedlatb[94] [8];
extern char  zedlatt[94] [8];

/* table also in zedplup */
static int  addr[8] = {0xA414, 0xAF18, 0xBA1C, 0xC520, 0xD024,
    0xDB28, 0xE62C, 0xF130};  /* FC34 - FFFF also available */
register int  c;
register int  i;
register int  j;
int  z;
char  (*zedchr[8])[94] [8];
unsigned short  llen;
char  bout[3];


zedchr[asc_bot] = (char (*)[94][8]) zedascb;
zedchr[asc_top] = (char (*)[94][8]) zedasct;
zedchr[grk_bot] = (char (*)[94][8]) zedgrkb;
zedchr[grk_top] = (char (*)[94][8]) zedgrkt;
zedchr[heb_bot] = (char (*)[94][8]) zedhebb;
zedchr[heb_top] = (char (*)[94][8]) zedhebt;
zedchr[lat_bot] = (char (*)[94][8]) zedlatb;
zedchr[lat_top] = (char (*)[94][8]) zedlatt;

/* initialize */
fputc(0x1B, prn);                     /* ESC */
fputc(0x3D, prn);                     /*  = - define download chars */
fputc(0x00, prn);                     /* NUL */
fputc(0x00, prn);                     /* NUL */

for (z = asc_bot; z < lat_top; ++z)
    {
    fputc(0x1B, prn);                 /* ESC */
    fputc(0x3D, prn);                 /*  = - define download chars */
    llen = 94 * 30 + 3;
    fputc(((char *)&llen)[0], prn);   /* count low  order byte */
    fputc(((char *)&llen)[1], prn);   /* count high order byte */
    fputc(0x23, prn);                 /* X24 printer ID */
    llen = (unsigned short) addr[z];  /* start address */
    fputc(((char *)&llen)[0], prn);   /* addr low  order byte */
    fputc(((char *)&llen)[1], prn);   /* addr high order byte */

    for (c = 0; c < 94; ++c)
        {
        for (i = 0; i < 8; ++i)
            {
            bytemap((*zedchr[z])[c] [i], bout);
            for (j = 0; j < 3; ++j)
                fputc(bout[j], prn);  /* char codes */
            } /* end for */
        for (i = 0; i < 6; ++i)
            fputc(0x00, prn);           /* filler */
        } /* end for */
    } /* end for */

} /* end zedpx24 */
