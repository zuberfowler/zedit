#include <stdio.h>
#include "zedit.h"

void  zedpfnt(
              int   graph,
              char  sel,
              FILE  *prn,
              char  halfch[94] [8])
/**********************************************************************/
/*                                                                    */
/* Download printer half height fonts to printer ram.                 */
/*                                                                    */
/* Epson note:                                                        */
/* This code was originally written to define the whole range of      */
/* characters at once.  For some reason the Hebrew character set gets */
/* messed up if done that way, thus the code defines each character   */
/* to the printer individually.                                       */
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

register int  c;
register int  i;
register int  j;
short  llen;
char  bout[3];


if (prtmode & PROPRT)
    {
    fputc(0x1B, prn);         /* ESC */
    fputc(0x3D, prn);         /*  = - define download chars */
    llen = 94 * 13 + 2;
    fputc(((char *)&llen)[0], prn); /* count low  order byte */
    fputc(((char *)&llen)[1], prn); /* count high order byte */
    fputc(0x14, prn);         /* printer ID */
    fputc(0x21 + sel, prn);   /* first char to be defined */

    for (c = 0; c < 94; ++c)
        {
        fputc(0x00, prn);         /* top eight pins */
        fputc(0x00, prn);         /* no proportional mode */
        for (i = 0; i < 8; ++i)
            fputc(halfch[c] [i], prn);  /* char codes */
        for (i = 0; i < 3; ++i)
            fputc(0x00, prn);           /* filler */
        } /* end for */
    } /* end then */

/* Proprinter X24 and Epson LQ printer */
else if (prtmode & PRDENS)
    {
    if (prtmode & ALTCDE)
        {
        fputc(0x1B, prn);         /* ESC */
        fputc(0x26, prn);         /*  & - define range */
        fputc(0x00, prn);         /* NUL */
        fputc(0x21 + sel, prn);   /* ascii codes 33 - 126 | beginning */
        fputc(0x7E + sel, prn);   /* or codes   161 - 254 | end range */
        for (c = 0; c < 94; ++c)
            for (i = 0; i < 8; ++i)
                {
                bytemap(halfch[c] [i], bout);
                for (j = 0; j < 3; ++j)
                    fputc(bout[j], prn);
                } /* end for */
        } /* end then */
    else
        zedplup(graph, prn);
    } /* end then, else */

/* Epson FX printer */
else for (c = 0; c < 94; ++c)
    {
    fputc(0x1B, prn);             /* ESC */
    fputc(0x26, prn);             /*  & - define range */
    fputc(0x00, prn);             /* NUL */
    fputc(c + 0x21 + sel, prn);   /* ascii codes 33 - 126 | beginning */
    fputc(c + 0x21 + sel, prn);   /* or codes   161 - 254 | end range */
    fputc(0x80, prn);             /* top eight pins */
    for (i = 0; i < 8; ++i)
        fputc(halfch[c] [i], prn);  /* char codes */
    for (i = 0; i < 3; ++i)
        fputc(0x00, prn);          /* filler */
    } /* end for, else */

} /* end zedpfnt */
