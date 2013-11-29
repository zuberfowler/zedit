#include <stdio.h>
#include "zedit.h"

void  scrpxga(
              union both_scr  *posptr,
              FILE  *prn)
/**********************************************************************/
/*                                                                    */
/* Dump the content of the graphic screen to a graphic printer - XGA  */
/* display.  This screen print code rotates the image to print        */
/* veritcal on the paper.                                             */
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
extern union both_scr  *posxga[2];
extern int  p;

register int  r; /* range */
register int  f; /* field */
register int  tab;
register int  i;

short  llen;
char  mout[8];
char  min[8];
char  bout[3];


llen = 960;
if ((prtmode & PRDENS)  && !(prtmode & ALTCDE))
    llen = (short) (llen * 3);

/* top two thirds of screen */
for (f = 0; f < 60; ++f)
    {
    fputc(0x0D, prn);  /* CR */
    fputc(0x0A, prn);  /* LF */

    /* graphics command required before each output line */
    fputc(0x1B, prn);  /* ESC */
    if (prtmode & PRDENS)
        {
        if (prtmode & ALTCDE)
            {
            fputc(0x2A, prn);  /*  * - 24 pin graphics */
            fputc(0x21, prn);  /*  ! - dual density graphic */
            } /* end then */
        else
            {
            fputc(0x5B, prn);  /*  [ - 24 pin graphics */
            fputc(0x67, prn);  /*  g - 24 pin graphics */
            } /* end then */
        } /* end then */
    else
        fputc(0x4C, prn);      /*  L - dual density graphic */

    fputc(((char *)&llen)[0], prn); /* length low  order byte */
    fputc(((char *)&llen)[1], prn); /* length high order byte */

    if ((prtmode & PRDENS)  && !(prtmode & ALTCDE))
        fputc(0x09, prn);  /* mode 9, high resolution like L */

    for (tab = 0; tab < 120; ++tab)
        {
        for (r = 0; r < 8; ++r)
            min[r] = posptr -> xi.xj[f] [r].xk[tab];

        invert(min[0], min[1], min[2], min[3], min[4], min[5],
            min[6], min[7], mout);

        for (r = 0; r < 8; ++r)
            {
#ifdef DOS
            xepslot(&mout[r]);
#endif
            if (prtmode & PRDENS)
                {
                bytemap(mout[r], bout);
                for (i = 0; i < 3; ++i)
                    fputc(bout[i], prn);
                } /* end then */
            else
                fputc(mout[r], prn);
            } /* end for */
        } /* end for */
    } /* end for */


/* bottom third of screen */
for (f = 0; f < 34; ++f)
    {
    fputc(0x0D, prn);  /* CR */
    fputc(0x0A, prn);  /* LF */

    /* graphics command required before each output line */
    fputc(0x1B, prn);  /* ESC */
    if (prtmode & PRDENS)
        {
        if (prtmode & ALTCDE)
            {
            fputc(0x2A, prn);  /*  * - 24 pin graphics */
            fputc(0x21, prn);  /*  ! - dual density graphic */
            } /* end then */
        else
            {
            fputc(0x5B, prn);  /*  [ - 24 pin graphics */
            fputc(0x67, prn);  /*  g - 24 pin graphics */
            } /* end then */
        } /* end then */
    else
        fputc(0x4C, prn);      /*  L - dual density graphic */

    fputc(((char *)&llen)[0], prn); /* length low  order byte */
    fputc(((char *)&llen)[1], prn); /* length high order byte */

    if ((prtmode & PRDENS)  && !(prtmode & ALTCDE))
        fputc(0x09, prn);  /* mode 9, high resolution like L */

    for (tab = 0; tab < 120; ++tab)
        {
        for (r = 0; r < 8; ++r)
            min[r] = posxga[p] -> xi.xj[f] [r].xk[tab];

        invert(min[0], min[1], min[2], min[3], min[4], min[5],
            min[6], min[7], mout);

        for (r = 0; r < 8; ++r)
            {
#ifdef DOS
            xepslot(&mout[r]);
#endif
            if (prtmode & PRDENS)
                {
                bytemap(mout[r], bout);
                for (i = 0; i < 3; ++i)
                    fputc(bout[i], prn);
                } /* end then */
            else
                fputc(mout[r], prn);
            } /* end for */
        } /* end for */
    } /* end for */

} /* end scrpxga */
