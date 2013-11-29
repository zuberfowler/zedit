#include "zedit.h"

void  ovr8chr(
              register union both_scr  *posptr,
              char  c,
              int  line_no,
              int  col_no)
/**********************************************************************/
/*                                                                    */
/* Overlay into screen position one character using 8x8 rom character.*/
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
extern char  ascchar[128] [14];

if (graphic & DISPL)
    overchr(posptr, c, line_no, col_no, ascchar);

#else


if (graphic & IBM1)
    ov8cibm(posptr, c, line_no, col_no);

else if (graphic & IBM2)
    ov8cib2(posptr, c, line_no, col_no);

#ifdef DOS
else if (graphic & HMONO)
    ov8chmn(posptr, c, line_no, col_no);
#endif

else if (graphic & XGA)
    ov8cxga(posptr, c, line_no, col_no);

else if (graphic & CGA)
    for (d = -3, e = line_no * 7;  d < 11;  ++e)
        for (f = 0; f < 2; ++f)
            {
            if (d >= 0  &&  d <= 7)
                posptr -> cs.cpos[f].cscr[e] [col_no] |=
                    romptr -> rchr[c] [d];
            ++d;
            } /* end for */

else if (graphic & EGA)
    {
    for (d = 0, e = 3;  d < 8;  ++d, ++e)
        posptr -> es.escr[line_no] [e] [col_no] |=
            romptr -> rchr[c] [d];
    } /* end then */

else if (graphic & VGA)
    {
    for (d = 0, e = 5;  d < 8;  ++d, ++e)
        posptr -> vs.vscr[line_no] [e] [col_no] |=
            romptr -> rchr[c] [d];
    } /* end then */

#endif
#endif
} /* end ovr8chr */
