#include "zedit.h"

void  ds8lhmn(
              union both_scr  *posptr,
              char  ln[],
              int  line_no)
/**********************************************************************/
/*                                                                    */
/* Copy into screen position a line of text using 8x8 chars in rom.   */
/*                                                                    */
/* Hercules mono-graphic screen:                                      */
/* The screen size is 720h X 348v, text is 80 X 25.                   */
/* The screen has four fields (0:3) of rows with each having a range  */
/* of 0:86.  Adjacent rows from the same field are displayed four     */
/* lines apart on the screen.                                         */
/* The character patterns are 7 X 9 (columns X rows) and are framed   */
/* by a 9 X (12 + 2) box (the 2 does not occur on row 25).            */
/* Each char code is translated to an index into the array in rom.    */
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
extern struct rombios  *romptr;

register int  tab;
register int  c; /* col   */
register int  f; /* field */
register int  r; /* range */
register int  d; /* down  */
int  start_field;


start_field = (line_no * 14) % 4;
for (r = (line_no * 14) / 4; ; ++r)
    {
    for (f = start_field; f < 4; ++f)
        {
        d = ((r * 4 + f) % 14) - 3;
        c = 0;
        for (tab = 0; tab < 90; ++tab)
          {
          if (d < 0  ||  d > 7)
              posptr -> sa.pos[f].scr[r] [tab] = 0x00u;
          else
              switch(tab % 9)
                  {
                  case 0:
                      posptr -> sa.pos[f].scr[r] [tab] =
                          (char) (romptr -> rchr[ln[c]] [d] >> 1u);
                      ++c;
                      break;
                  case 1:
                      posptr -> sa.pos[f].scr[r] [tab] =
                          (char) (romptr -> rchr[ln[c-1]] [d] << 7u) |
                          (char) (romptr -> rchr[ln[c]] [d] >> 2u);
                      ++c;
                      break;
                  case 2:
                      posptr -> sa.pos[f].scr[r] [tab] =
                          (char) (romptr -> rchr[ln[c-1]] [d] << 6u) |
                          (char) (romptr -> rchr[ln[c]] [d] >> 3u);
                      ++c;
                      break;
                  case 3:
                      posptr -> sa.pos[f].scr[r] [tab] =
                          (char) (romptr -> rchr[ln[c-1]] [d] << 5u) |
                          (char) (romptr -> rchr[ln[c]] [d] >> 4u);
                      ++c;
                      break;
                  case 4:
                      posptr -> sa.pos[f].scr[r] [tab] =
                          (char) (romptr -> rchr[ln[c-1]] [d] << 4u) |
                          (char) (romptr -> rchr[ln[c]] [d] >> 5u);
                      ++c;
                      break;
                  case 5:
                      posptr -> sa.pos[f].scr[r] [tab] =
                          (char) (romptr -> rchr[ln[c-1]] [d] << 3u) |
                          (char) (romptr -> rchr[ln[c]] [d] >> 6u);
                      ++c;
                      break;
                  case 6:
                      posptr -> sa.pos[f].scr[r] [tab] =
                          (char) (romptr -> rchr[ln[c-1]] [d] << 2u) |
                          (char) (romptr -> rchr[ln[c]] [d] >> 7u);
                      break;
                  case 7:
                      posptr -> sa.pos[f].scr[r] [tab] =
                          (char) (romptr -> rchr[ln[c]] [d] << 1u);
                      ++c;
                      break;
                  case 8:
                      posptr -> sa.pos[f].scr[r] [tab] =
                          romptr -> rchr[ln[c]] [d];
                      ++c;
                      break;
                  } /* end switch */
          } /* end for */
        if (d == 10)
            return;
        } /* end for */
    start_field = 0;
    } /* end for */

} /* end ds8lhmn */
