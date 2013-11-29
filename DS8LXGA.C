#include "zedit.h"

void  ds8lxga(
              union both_scr  *posptr,
              char  ln[],
              int  line_no)
/**********************************************************************/
/*                                                                    */
/* Copy into screen position a line of text using 8x8 chars in rom -  */
/* XGA.                                                               */
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

register int  tab;
register int  c; /* col   */
register int  d; /* down  */
register int  e; /* down+ */
register int  f; /* field */


if (line_no > 15)
    {
    line_no = line_no - 16;
    posptr = posxga[p];
    } /* end then */

for (d = -4, e = 0, f = 1;  e < 30;  ++d, e += 2, f += 2)
    for (c = 0; c < 80; ++c)
        {
        tab = c / 2;
        if (c % 2)
            if (d < 0  ||  d > 7)
                {
                posptr -> xs.xl[line_no] [e].xp[tab].sx = 0x00u;
                posptr -> xs.xl[line_no] [f].xp[tab].sx = 0x00u;

                posptr -> xs.xl[line_no] [e].xp[tab].xs = 0x00u;
                posptr -> xs.xl[line_no] [f].xp[tab].xs = 0x00u;
                } /* end then */
            else
                {
                posptr -> xs.xl[line_no] [e].xp[tab].sx =
                    (char) (romptr -> rchr[ln[c]] [d] >> 4u);
                posptr -> xs.xl[line_no] [f].xp[tab].sx =
                    (char) (romptr -> rchr[ln[c]] [d] >> 4u);

                posptr -> xs.xl[line_no] [e].xp[tab].xs =
                    (char) (romptr -> rchr[ln[c]] [d] << 4u);
                posptr -> xs.xl[line_no] [f].xp[tab].xs =
                    (char) (romptr -> rchr[ln[c]] [d] << 4u);
                } /* end else, then */
        else
            if (d < 0  ||  d > 7)
                {
                posptr -> xs.xl[line_no] [e].xp[tab].xb = 0x00u;
                posptr -> xs.xl[line_no] [f].xp[tab].xb = 0x00u;
                } /* end then */
            else
                {
                posptr -> xs.xl[line_no] [e].xp[tab].xb =
                    romptr -> rchr[ln[c]] [d];
                posptr -> xs.xl[line_no] [f].xp[tab].xb =
                    romptr -> rchr[ln[c]] [d];
                } /* end else, else */
        } /* end for */

} /* end ds8lxga */
