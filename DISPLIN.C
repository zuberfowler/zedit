#include "zedit.h"

void  displin(
              union both_scr  *posptr,
              char  ln[],
              int  line_no,
              char  dots[] [14])
/**********************************************************************/
/*                                                                    */
/* Copy into screen position a line of text.                          */
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
#ifndef S370
extern unsigned int  graphic;

register int  c; /* col   */
register int  d; /* down  */
register int  e; /* down+ */
register int  f; /* field */


#ifdef VMS
#include <stdio.h>

register int  tab;
int  start_field;


if (graphic & DISPL)
    {
    for (e = line_no * 28, d = 0; d < 14; e += 2, ++d)
        {
        f = NO;
        start_field = NO;
        for (c = 0; c < 80; ++c)
            for(tab = c * 9; tab < c * 9 + 9; ++tab)
                {
                switch(tab % 9)
                    {
                    case 0:
                        f = NO;
                        break;
                    case 1:
                        f = (0x80u & dots[ln[c]] [d]);
                        break;
                    case 2:
                        f = (0x40u & dots[ln[c]] [d]);
                        break;
                    case 3:
                        f = (0x20u & dots[ln[c]] [d]);
                        break;
                    case 4:
                        f = (0x10u & dots[ln[c]] [d]);
                        break;
                    case 5:
                        f = (0x08u & dots[ln[c]] [d]);
                        break;
                    case 6:
                        f = (0x04u & dots[ln[c]] [d]);
                        break;
                    case 7:
                        f = (0x02u & dots[ln[c]] [d]);
                        break;
                    case 8:
                        f = (0x01u & dots[ln[c]] [d]);
                        break;
                    } /* end switch */
                if (!f  &&  start_field)
                    {
                    printf("V[%d]", tab);
                    start_field = NO;
                    } /* end then */
                else if (f  &&  !start_field)
                    {
                    printf("P[%d,%d]", tab, e);
                    start_field = YES;
                    } /* end then */
                } /* end for */

        if (start_field)
            printf("V[%d]", tab);
        } /* end for */
    } /* end then */
else
    {
    wmove(posptr, line_no, 0);
    waddstr(posptr, line);
    } /* end else */

#else


if (graphic & IBM1)
    dsplibm(posptr, ln, line_no, dots);

else if (graphic & IBM2)
    dsplib2(posptr, ln, line_no, dots);

#ifdef DOS
else if (graphic & HMONO)
    dsplhmn(posptr, ln, line_no, dots);
#endif

else if (graphic & XGA)
    dsplxga(posptr, ln, line_no, dots);

else if (graphic & CGA)
    for (d = 0, e = line_no * 7;  d < 14;  ++e)
        for (f = 0;  f < 2;  ++f, ++d)
            for (c = 0; c < 80; ++c)
                posptr -> cs.cpos[f].cscr[e] [c] = dots[ln[c]] [d];

else if (graphic & EGA)
    for (d = 0; d < 14; ++d)
        for (c = 0; c < 80; ++c)
            posptr -> es.escr[line_no] [d] [c] = dots[ln[c]] [d];

else if (graphic & VGA)
    for (d = -2, e = 0;  e < 19;  ++d, ++e)
        for (c = 0; c < 80; ++c)
            if (d < 0  ||  d > 13)
                posptr -> vs.vscr[line_no] [e] [c] = 0x00u;
            else
                posptr -> vs.vscr[line_no] [e] [c] = dots[ln[c]] [d];

else
    for (c = 0; c < 80; ++c)
        posptr -> ns.nline[line_no].ncol[c].char_byte = ln[c];

#endif
#endif
} /* end displin */
