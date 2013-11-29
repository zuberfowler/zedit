#include "zedit.h"

void  dspcxga(
              register union both_scr  *posptr,
              char  c,
              int  line_no,
              int  col_no,
              char  dots[] [14])
/**********************************************************************/
/*                                                                    */
/* Copy into screen position one character - XGA.                     */
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

register int  d; /* down   */
register int  e; /* down2  */
register int  f; /* down2+ */
int  tab;


if (line_no > 15)
    {
    line_no = line_no - 16;
    posptr = posxga[p];
    } /* end then */

tab = col_no / 2;

if (col_no % 2)
    {
    posptr -> xs.xl[line_no] [0].xp[tab].sx = 0x00u;
    posptr -> xs.xl[line_no] [1].xp[tab].sx = 0x00u;

    posptr -> xs.xl[line_no] [0].xp[tab].xs = 0x00u;
    posptr -> xs.xl[line_no] [1].xp[tab].xs = 0x00u;
    } /* end then */
else
    {
    posptr -> xs.xl[line_no] [0].xp[tab].xb = 0x00u;
    posptr -> xs.xl[line_no] [1].xp[tab].xb = 0x00u;
    } /* end else */

for (d = 0, e = 2, f = 3; d < 14; ++d, e += 2, f += 2)
    if (col_no % 2)
        {
        posptr -> xs.xl[line_no] [e].xp[tab].sx =
            (char) (dots[c] [d] >> 4u);
        posptr -> xs.xl[line_no] [f].xp[tab].sx =
            (char) (dots[c] [d] >> 4u);

        posptr -> xs.xl[line_no] [e].xp[tab].xs =
            (char) (dots[c] [d] << 4u);
        posptr -> xs.xl[line_no] [f].xp[tab].xs =
            (char) (dots[c] [d] << 4u);
        } /* end then */
    else
        {
        posptr -> xs.xl[line_no] [e].xp[tab].xb = dots[c] [d];
        posptr -> xs.xl[line_no] [f].xp[tab].xb = dots[c] [d];
        } /* end else */

} /* end dspcxga */
