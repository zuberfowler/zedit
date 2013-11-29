#include "zedit.h"

void  dsp8lin(
              union both_scr  *posptr,
              char  ln[],
              int  line_no)
/**********************************************************************/
/*                                                                    */
/* Copy into screen position a line of text using 8x8 chars in rom.   */
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
extern struct rombios  *romptr;
extern unsigned int  graphic;

register int  c; /* col   */
register int  d; /* down  */
register int  e; /* down+ */
register int  f; /* field */


#ifdef VMS
extern char  ascchar[128] [14];

if (line_no == 24)
    line_no = 0;

if (graphic & DISPL)
    displin(posptr, ln, line_no, ascchar);
else
    {
    wmove(posptr, line_no, 0);
    waddstr(posptr, ln);
    } /* end else */

#else


if (graphic & IBM1)
    ds8libm(posptr, ln, line_no);

else if (graphic & IBM2)
    ds8lib2(posptr, ln, line_no);

#ifdef DOS
else if (graphic & HMONO)
    ds8lhmn(posptr, ln, line_no);
#endif

else if (graphic & XGA)
    ds8lxga(posptr, ln, line_no);

else if (graphic & CGA)
    for (d = -3, e = line_no * 7;  d < 11;  ++e)
        for (f = 0;  f < 2;  ++f, ++d)
            for (c = 0; c < 80; ++c)
                if (d < 0  ||  d > 7)
                    posptr -> cs.cpos[f].cscr[e] [c] = 0x00u;
                else
                    posptr -> cs.cpos[f].cscr[e] [c] =
                        romptr -> rchr[ln[c]] [d];

else if (graphic & EGA)
    for (d = 0, e = -3;  d < 14;  ++d, ++e)
        for (c = 0; c < 80; ++c)
            if (e < 0  ||  e > 7)
                posptr -> es.escr[line_no] [d] [c] = 0x00u;
            else
                posptr -> es.escr[line_no] [d] [c] =
                    romptr -> rchr[ln[c]] [e];

else if (graphic & VGA)
    for (d = -5, e = 0;  e < 19;  ++d, ++e)
        for (c = 0; c < 80; ++c)
            if (d < 0  ||  d > 7)
                posptr -> vs.vscr[line_no] [e] [c] = 0x00u;
            else
                posptr -> vs.vscr[line_no] [e] [c] =
                    romptr -> rchr[ln[c]] [d];

else
    for (c = 0; c < 80; ++c)
        posptr -> ns.nline[line_no].ncol[c].char_byte = ln[c];

#endif
#endif
} /* end dsp8lin */
