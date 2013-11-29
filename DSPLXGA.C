#include "zedit.h"

void  dsplxga(
              union both_scr  *posptr,
              char  ln[],
              int  line_no,
              char  dots[] [14])
/**********************************************************************/
/*                                                                    */
/* Copy into screen position a line of text - XGA.                    */
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

register int  c; /* col   */
register int  d; /* down  */
register int  e; /* down+ */
register int  f; /* field */
register int  tab;


if (line_no > 15)
    {
    line_no = line_no - 16;
    posptr = posxga[p];
    } /* end then */

for (e = 0; e < 2; ++e)
    for (tab = 0; tab < 40; ++tab)
        {
        posptr -> xs.xl[line_no] [e].xp[tab].xb = 0x00u;
        posptr -> xs.xl[line_no] [e].xp[tab].sx = 0x00u;
        posptr -> xs.xl[line_no] [e].xp[tab].xs = 0x00u;
        } /* end for, for */

for (d = 0, e = 2, f = 3;  d < 14;  ++d, e += 2, f += 2)
    for (c = 0; c < 80; ++c)
        {
        tab = c / 2;
        if (c % 2)
            {
            posptr -> xs.xl[line_no] [e].xp[tab].sx =
                (char) (dots[ln[c]] [d] >> 4u);
            posptr -> xs.xl[line_no] [f].xp[tab].sx =
                (char) (dots[ln[c]] [d] >> 4u);

            posptr -> xs.xl[line_no] [e].xp[tab].xs =
                (char) (dots[ln[c]] [d] << 4u);
            posptr -> xs.xl[line_no] [f].xp[tab].xs =
                (char) (dots[ln[c]] [d] << 4u);
            } /* end then */
        else
            {
            posptr -> xs.xl[line_no] [e].xp[tab].xb =
                dots[ln[c]] [d];
            posptr -> xs.xl[line_no] [f].xp[tab].xb =
                dots[ln[c]] [d];
            } /* end else */
        } /* end for */

} /* end dsplxga */
