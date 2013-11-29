#include <stdio.h>
#include "zedit.h"

void  zedplsp(
              FILE  *prn)
/**********************************************************************/
/*                                                                    */
/* This subroutine causes the printer to switch to the correct line   */
/* spacing mode so as to leave no gap.                                */
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


if (prtmode & PRDENS)
    {
    /* 24 pin mode */
    if (!(prtmode & ALTCDE))
        {
        fputc(0x1B, prn);  /* ESC */
        fputc(0x5B, prn);  /* [ - Set vertical units */
        fputc(0x5C, prn);  /* \ - Set vertical units */
        fputc(0x04, prn);  /* byte count low */
        fputc(0x00, prn);  /* byte count high */
        fputc(0x00, prn);  /* text units low */
        fputc(0x00, prn);  /* text units high */
        fputc(0xB4, prn);  /* graphic units low (180) */
        fputc(0x00, prn);  /* graphic units high */
        } /* end then */
    fputc(0x1B, prn);  /* ESC */
    fputc(0x33, prn);  /* nn/180 Line Spacing */
    fputc(0x18, prn);  /* 24/180 line spacing */
    } /* end then */
else if (prtmode & ALTCDE)
    {
    /* IBM 5182 Color Printer */
    fputc(0x1B, prn);  /* ESC */
    fputc(0x41, prn);  /* n/72 line spacing */
    fputc(0x07, prn);  /* 7/72 line spacing */
    fputc(0x1B, prn);  /* ESC */
    fputc(0x32, prn);  /* change line spacing */
    } /* end then */
else
    {
    /* Epson, Proprinter, etc. */
    fputc(0x1B, prn);  /* ESC */
    fputc(0x33, prn);  /* nn/216 line spacing */
    fputc(0x18, prn);  /* 24/216 line spacing */
    } /* end else */

} /* end zedplsp */
