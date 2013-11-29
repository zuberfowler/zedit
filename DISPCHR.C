#include "zedit.h"

void  dispchr(
              union both_scr  *posptr,
              char  c,
              int  line_no,
              int  col_no,
              char  dots[] [14])
/**********************************************************************/
/*                                                                    */
/* Copy into screen position one character.                           */
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

register int  d; /* down  */
register int  e; /* down+ */
register int  f; /* field */


#ifdef VMS
#include <stdio.h>

register int  tab;

int  start_field;
if (graphic & DISPL)
    {
    printf("P[%d,%d]W(E,S1)P[,%d]V[%d]W(V,S0)",
        col_no * 9 + 1, (line_no + 1) * 28 - 1, line_no * 28,
        col_no * 9 + 8);

    for (e = line_no * 28, d = 0; d < 14; e += 2, ++d)
        {
        f = NO;
        start_field = NO;
            for (tab = col_no * 9; tab < (col_no + 1) * 9; ++tab)
                {
                switch(tab % 9)
                    {
                    case 0:
                        break;
                    case 1:
                        f = (0x80u & dots[c] [d]);
                        break;
                    case 2:
                        f = (0x40u & dots[c] [d]);
                        break;
                    case 3:
                        f = (0x20u & dots[c] [d]);
                        break;
                    case 4:
                        f = (0x10u & dots[c] [d]);
                        break;
                    case 5:
                        f = (0x08u & dots[c] [d]);
                        break;
                    case 6:
                        f = (0x04u & dots[c] [d]);
                        break;
                    case 7:
                        f = (0x02u & dots[c] [d]);
                        break;
                    case 8:
                        f = (0x01u & dots[c] [d]);
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
    wmove(posptr, line_no, col_no);
    if (c == 0x00)
        waddch(posptr, ' ');
    else
        waddch(posptr, c);
    } /* end else */


#else


if (graphic & IBM1)
    dspcibm(posptr, c, line_no, col_no, dots);

else if (graphic & IBM2)
    dspcib2(posptr, c, line_no, col_no, dots);

#ifdef DOS
else if (graphic & HMONO)
    dspchmn(posptr, c, line_no, col_no, dots);
#endif

else if (graphic & XGA)
    dspcxga(posptr, c, line_no, col_no, dots);

else if (graphic & CGA)
    for (d = 0, e = line_no * 7;  d < 14;  ++e)
        for (f = 0; f < 2; ++f)
            posptr -> cs.cpos[f].cscr[e] [col_no] = dots[c] [d++];

else if (graphic & EGA)
    for (d = 0; d < 14; ++d)
        posptr -> es.escr[line_no] [d] [col_no] = dots[c] [d];

else if (graphic & VGA)
    for (d = -2, e = 0;  e < 19;  ++d, ++e)
        if (d < 0  ||  d > 13)
            posptr -> vs.vscr[line_no] [e] [col_no] = 0x00u;
        else
            posptr -> vs.vscr[line_no] [e] [col_no] = dots[c] [d];

else posptr -> ns.nline[line_no].ncol[col_no].char_byte = c;

#endif
#endif
} /* end dispchr */
