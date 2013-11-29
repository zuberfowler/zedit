#include "zedit.h"

void  revlhmn(
              register union both_scr  *posptr,
              int  line_no)
/**********************************************************************/
/*                                                                    */
/* Change a screen line to the oposite of its current display type    */
/* (normal/reverse).                                                  */
/*                                                                    */
/* Hercules mono-graphic screen:                                      */
/* The screen size is 720h X 348v, text is 80 X 25.                   */
/* The screen has four fields (0:3) of rows with each having a range  */
/* of 0:86.  Adjacent rows from the same field are displayed four     */
/* lines apart on the screen.                                         */
/* The character patterns are 7 X 9 (columns X rows) and are framed   */
/* by a 9 X (12 + 2) box (the 2 does not occur on row 25).            */
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
register int  tab;
register int  f; /* field */
register int  r; /* range */
register int  d; /* down  */
int  start_field;


start_field = (line_no * 14) % 4;
for (r = (line_no * 14) / 4; ; ++r)
    {
    for (f = start_field; f < 4; ++f)
        {
        d = (r * 4 + f) % 14;
        for (tab = 0; tab < 90; ++tab)
            posptr -> sa.pos[f].scr[r] [tab] = (char)
                ~(posptr -> sa.pos[f].scr[r] [tab]);
        if (d == 13)
            return;
        } /* end for */
    start_field = 0;
    } /* end for */

} /* end revlhmn */
