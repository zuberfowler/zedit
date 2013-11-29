#include "zedit.h"

void  revline(
              register union both_scr  *posptr,
              int  line_no)
/**********************************************************************/
/*                                                                    */
/* Change a screen line to the oposite of its current display type    */
/* (normal/reverse).                                                  */
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


if (line_no == 24)
    line_no = 0;

if (graphic & DISPL)
    printf("P[0,%d]W(C,S1)P[,%d]V[719]W(V,S0)",
        (line_no + 1) * 28 - 1, line_no * 28);


#else



if (graphic & IBM1)
    for (d = 0; d < 14; ++d)
        for (c = 0; c < 90; ++c)
            posptr -> is.iscr[line_no] [d] [c] = (char)
                ~(posptr -> is.iscr[line_no] [d] [c]);

else if (graphic & IBM2)
    for (d = 0; d < 19; ++d)
        for (c = 0; c < 90; ++c)
            posptr -> i2.i2scr[line_no] [d] [c] = (char)
                ~(posptr -> i2.i2scr[line_no] [d] [c]);

#ifdef DOS
else if (graphic & HMONO)
    revlhmn(posptr, line_no);
#endif

else if (graphic & XGA)
    revlxga(posptr, line_no);

else if (graphic & CGA)
    for (d = 0, e = line_no * 7;  d < 14;  ++e)
        for (f = 0;  f < 2;  ++f, ++d)
            for (c = 0; c < 80; ++c)
                posptr -> cs.cpos[f].cscr[e] [c] = (char)
                    ~(posptr -> cs.cpos[f].cscr[e] [c]);

else if (graphic & EGA)
    for (d = 0; d < 14; ++d)
        for (c = 0; c < 80; ++c)
            posptr -> es.escr[line_no] [d] [c] = (char)
                ~(posptr -> es.escr[line_no] [d] [c]);

else if (graphic & VGA)
    for (d = 0; d < 19; ++d)
        for (c = 0; c < 80; ++c)
            posptr -> vs.vscr[line_no] [d] [c] = (char)
                ~(posptr -> vs.vscr[line_no] [d] [c]);

else
    for (c = 0; c < 80; ++c)
        posptr -> ns.nline[line_no].ncol[c].attr_byte = M_REV;

#endif
#endif
} /* end revline */
