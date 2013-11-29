#include "zedit.h"

void  revchmn(
              register union both_scr  *posptr,
              int  line_no,
              int  col_no)
/**********************************************************************/
/*                                                                    */
/* Turn a character position to the oposite display of its present    */
/* display (normal/reverse).                                          */
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
                posptr -> sa.pos[f].scr[r] [tab] ^= 0xFFu;
                posptr -> sa.pos[f].scr[r] [tup] ^= 0x80u;
                break;
            case 1:
                posptr -> sa.pos[f].scr[r] [tab] ^= 0x7Fu;
                posptr -> sa.pos[f].scr[r] [tup] ^= 0xC0u;
                break;
            case 2:
                posptr -> sa.pos[f].scr[r] [tab] ^= 0x3Fu;
                posptr -> sa.pos[f].scr[r] [tup] ^= 0xE0u;
                break;
            case 3:
                posptr -> sa.pos[f].scr[r] [tab] ^= 0x1Fu;
                posptr -> sa.pos[f].scr[r] [tup] ^= 0xF0u;
                break;
            case 4:
                posptr -> sa.pos[f].scr[r] [tab] ^= 0x0Fu;
                posptr -> sa.pos[f].scr[r] [tup] ^= 0xF8u;
                break;
            case 5:
                posptr -> sa.pos[f].scr[r] [tab] ^= 0x07u;
                posptr -> sa.pos[f].scr[r] [tup] ^= 0xFCu;
                break;
            case 6:
                posptr -> sa.pos[f].scr[r] [tab] ^= 0x03u;
                posptr -> sa.pos[f].scr[r] [tup] ^= 0xFEu;
                break;
            case 7:
                posptr -> sa.pos[f].scr[r] [tab] ^= 0x01u;
                posptr -> sa.pos[f].scr[r] [tup] ^= 0xFFu;
                break;
            } /* end switch */
        if (d == 13)
            return;
        } /* end for */
    start_field = 0;
    } /* end for */

} /* end revchmn */
