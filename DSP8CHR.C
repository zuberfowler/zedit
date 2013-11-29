#include "zedit.h"

void  dsp8chr(
              register union both_scr  *posptr,
              char  c,
              int  line_no,
              int  col_no)
/**********************************************************************/
/*                                                                    */
/* Copy into screen position one character using 8x8 rom character.   */
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
extern struct rombios  *romptr;

register int  d; /* down  */
register int  e; /* down+ */
register int  f; /* field */


#ifdef VMS
extern unsigned char  ascchar[128] [14];


if (graphic & DISPL)
    dispchr(posptr, c, line_no, col_no, ascchar);
else
    {
    wmove(posptr, line_no, col_no);
    if (c == 0x00u)
        waddch(posptr, ' ');
    else
        waddch(posptr, c);
    } /* end else */


#else


if (graphic & IBM1)
    ds8cibm(posptr, c, line_no, col_no);

else if (graphic & IBM2)
    ds8cib2(posptr, c, line_no, col_no);

#ifdef DOS
else if (graphic & HMONO)
    ds8chmn(posptr, c, line_no, col_no);
#endif

else if (graphic & XGA)
    ds8cxga(posptr, c, line_no, col_no);

else if (graphic & CGA)
    for (d = -3, e = line_no * 7;  d < 11;  ++e)
        for (f = 0; f < 2; ++f)
            {
            if (d < 0  ||  d > 7)
                posptr -> cs.cpos[f].cscr[e] [col_no] = 0x00u;
            else
                posptr -> cs.cpos[f].cscr[e] [col_no] =
                    romptr -> rchr[c] [d];
            ++d;
            } /* end for */

else if (graphic & EGA)
    for (d = -3, e = 0;  e < 14;  ++d, ++e)
        if (d < 0  ||  d > 7)
            posptr -> es.escr[line_no] [e] [col_no] = 0x00u;
        else
            posptr -> es.escr[line_no] [e] [col_no] =
                romptr -> rchr[c] [d];

else if (graphic & VGA)
    for (d = -5, e = 0;  e < 19;  ++d, ++e)
        if (d < 0  ||  d > 7)
            posptr -> vs.vscr[line_no] [e] [col_no] = 0x00u;
        else
            posptr -> vs.vscr[line_no] [e] [col_no] =
                romptr -> rchr[c] [d];

else posptr -> ns.nline[line_no].ncol[col_no].char_byte = c;

#endif
#endif
} /* end dsp8chr */
