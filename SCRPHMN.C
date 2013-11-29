#include <stdio.h>
#include "zedit.h"

void  scrphmn(
              union both_scr  *posptr,
              FILE  *prn)
/**********************************************************************/
/*                                                                    */
/* Dump the content of the graphic screen to a graphic printer.       */
/*                                                                    */
/* This code for the Hercules monochrome graphics adapter only        */
/* supports the Epson FX printer.  This screen print code rotates     */
/* the image to print vertical on the paper.                          */
/*                                                                    */
/* Hercules mono-graphic screen:                                      */
/* The screen size is 720h X 348v, text is 80 X 25.                   */
/* The screen has four fields (0:3) of rows with each having a range  */
/* of 0:86.  Adjacent rows from the same field are displayed four     */
/* lines apart on the screen.                                         */
/* The character patterns are 7 X 9 (columns X rows) and are framed   */
/* by a 9 X (12 + 2) box (the 2 does not occur on row 25).            */
/* Each char code is translated to an index into the array "dots".    */
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
register int  r; /* range */
register int  f; /* field */
register int  tab;
register int  n;

int  hold;
char  mout[8];
char  min[8];


for (r = 0; r <= 86; )
    {
    fputc(0x0D, prn);  /* CR */
    fputc(0x0A, prn);  /* LF */

    /* graphics command required before each output line */
    /* mode 6 is CRT II, 720 columns in 8 inches */
    fputc(0x1B, prn);  /* ESC */
    fputc(0x2A, prn);  /* graphic */
    fputc(0x06, prn);  /* mode 6 */
    fputc(0xD0, prn);  /* 0x02D0 */
    fputc(0x02, prn);  /* ie. 720 bytes */

    hold = r;
    for (tab = 0; tab <= 89; ++tab)
        {
        for (r = hold; r <= hold + 1; ++r)
            for (f = 0; f <= 3; ++f)
                if (r % 2)
                    min[f + 4] = posptr ->
                        sa.pos[f].scr[r] [tab];
                else
                    min[f] = posptr ->
                        sa.pos[f].scr[r] [tab];

        invert(min[0], min[1], min[2], min[3], min[4], min[5],
            min[6], min[7], mout);

        for (n = 0; n < 8; ++n)
            fputc(mout[n], prn);

        } /* end for */
    } /* end for */

} /* end scrphmn */
