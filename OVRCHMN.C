#include "zedit.h"

void  ovrchmn(
              register union both_scr  *posptr,
              char  c,
              int  line_no,
              int  col_no,
              char  dots[] [14])
/**********************************************************************/
/*                                                                    */
/* Overlay into screen position one character.                        */
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
register int  f; /* field */
register int  r; /* range */
register int  d; /* down  */

int  tab;
int  tup;
int  colcase;
int  start_field;


tab = (col_no * 9) / 8;
tup = tab + 1;
colcase = col_no % 8;
start_field = (line_no * 14) % 4;

for (r = (line_no * 14) / 4; ; ++r)
    {
    for (f = start_field; f < 4; ++f)
        {
        d = (r * 4 + f) % 14;
        switch(colcase)
            {
            case 0:
                posptr -> sa.pos[f].scr[r] [tab] |=
                    (char) (dots[c] [d] >> 1u);
                posptr -> sa.pos[f].scr[r] [tup] |=
                    (char) (dots[c] [d] << 7u);
                break;
            case 1:
                posptr -> sa.pos[f].scr[r] [tab] |=
                    (char) (dots[c] [d] >> 2u);
                posptr -> sa.pos[f].scr[r] [tup] |=
                    (char) (dots[c] [d] << 6u);
                break;
            case 2:
                posptr -> sa.pos[f].scr[r] [tab] |=
                    (char) (dots[c] [d] >> 3u);
                posptr -> sa.pos[f].scr[r] [tup] |=
                    (char) (dots[c] [d] << 5u);
                break;
            case 3:
                posptr -> sa.pos[f].scr[r] [tab] |=
                    (char) (dots[c] [d] >> 4u);
                posptr -> sa.pos[f].scr[r] [tup] |=
                    (char) (dots[c] [d] << 4u);
                break;
            case 4:
                posptr -> sa.pos[f].scr[r] [tab] |=
                    (char) (dots[c] [d] >> 5u);
                posptr -> sa.pos[f].scr[r] [tup] |=
                    (char) (dots[c] [d] << 3u);
                break;
            case 5:
                posptr -> sa.pos[f].scr[r] [tab] |=
                    (char) (dots[c] [d] >> 6u);
                posptr -> sa.pos[f].scr[r] [tup] |=
                    (char) (dots[c] [d] << 2u);
                break;
            case 6:
                posptr -> sa.pos[f].scr[r] [tab] |=
                    (char) (dots[c] [d] >> 7u);
                posptr -> sa.pos[f].scr[r] [tup] |=
                    (char) (dots[c] [d] << 1u);
                break;
            case 7:
                posptr -> sa.pos[f].scr[r] [tup] |= dots[c] [d];
                break;
            } /* end switch */
        if (d == 13)
            return;
        } /* end for */
    start_field = 0;
    } /* end for */

} /* end ovrchmn */
