#include <stdio.h>
#include "zedit.h"

void  scrpesc(
              FILE  *prn,
              short  llen)
/**********************************************************************/
/*                                                                    */
/* Put out common printer escape codes for each line of a screen      */
/* print.                                                             */
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
extern unsigned int  prtmode;


fputc(0x0D, prn);  /* CR */
fputc(0x0A, prn);  /* LF */

/* graphics command required before each output line */
fputc(0x1B, prn);  /* ESC */

if (prtmode & PRDENS)
    {
    if (prtmode & ALTCDE)
        {
        fputc(0x2A, prn);  /*  * - 24 pin graphics */
        fputc(0x20, prn);  /* SP - single density graphic */
        } /* end then */
    else
        {
        fputc(0x5B, prn);  /*  [ - 24 pin graphics */
        fputc(0x67, prn);  /*  g - 24 pin graphics */
        } /* end then */
    } /* end then */
else
    fputc(0x4B, prn);      /*  K - single density graphic */

fputc(((char *)&llen)[0], prn); /* length low  order byte */
fputc(((char *)&llen)[1], prn); /* length high order byte */

if ((prtmode & PRDENS)  &&  !(prtmode & ALTCDE))
    fputc(0x08, prn);  /* mode 8, high resolution like K */

} /* end scrpesc */
