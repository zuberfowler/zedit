#include "zedit.h"

void  ov8cxga(
              register union both_scr  *posptr,
              char  c,
              int  line_no,
              int  col_no)
/**********************************************************************/
/*                                                                    */
/* Overlay into screen position one character using 8x8 rom character */
/* - XGA.                                                             */
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
extern union both_scr  *posxga[2];
extern int  p;

register int  d;
register int  e;
register int  f;
int  tab;


if (line_no > 15)
    {
    line_no = line_no - 16;
    posptr = posxga[p];
    } /* end then */

tab = col_no / 2;

for (d = 0, e = 8, f = 9;  d < 8;  ++d, e += 2, f += 2)
    if (col_no % 2)
        {
        posptr -> xs.xl[line_no] [e].xp[tab].sx |=
            (char) (romptr -> rchr[c] [d] >> 4u);
        posptr -> xs.xl[line_no] [f].xp[tab].sx |=
            (char) (romptr -> rchr[c] [d] >> 4u);

        posptr -> xs.xl[line_no] [e].xp[tab].xs |=
            (char) (romptr -> rchr[c] [d] << 4u);
        posptr -> xs.xl[line_no] [f].xp[tab].xs |=
            (char) (romptr -> rchr[c] [d] << 4u);
        } /* end then */
    else
        {
        posptr -> xs.xl[line_no] [e].xp[tab].xb |=
            romptr -> rchr[c] [d];
        posptr -> xs.xl[line_no] [f].xp[tab].xb |=
            romptr -> rchr[c] [d];
        } /* end else */

} /* end ov8cxga */
