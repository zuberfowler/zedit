#include "zedit.h"

void  revcxga(
              register union both_scr  *posptr,
              int  line_no,
              int  col_no)
/**********************************************************************/
/*                                                                    */
/* Turn a character position to the oposite display of its present    */
/* display (normal/reverse) - XGA.                                    */
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
extern union both_scr  *posxga[2];
extern int  p;

register int  d; /* down */
int  l;
int  tab;
int  colcase;


if (line_no > 15)
    {
    l = line_no - 16;
    posptr = posxga[p];
    } /* end then */
else
    l = line_no;

colcase = col_no % 2;
tab = col_no / 2;

for (d = 0; d < 30; ++d)
    /* @-bug, condition must be reversed due to MSC 6.0a bug */
    if (!colcase)
        posptr -> xs.xl[l] [d].xp[tab].xb = (char)
            ~(posptr -> xs.xl[l] [d].xp[tab].xb);
    else
        {
        posptr -> xs.xl[l] [d].xp[tab].sx ^= 0x0F;
        posptr -> xs.xl[l] [d].xp[tab].xs ^= 0xF0;
        } /* end else */

/* copy the reverse character to the physical display screen */
xga8514(posptr, line_no, col_no);

} /* end revcxga */
