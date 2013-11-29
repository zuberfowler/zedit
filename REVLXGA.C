#include "zedit.h"

void  revlxga(
              register union both_scr  *posptr,
              int  line_no)
/**********************************************************************/
/*                                                                    */
/* Change a screen line to the oposite of its current display type    */
/* (normal/reverse) - XGA.                                            */
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
register int  tab;
register int  d; /* down  */


if (line_no > 15)
    {
    line_no = line_no - 16;
    posptr = posxga[p];
    } /* end then */

for (d = 0; d < 30; ++d)
    for (tab = 0; tab < 40; ++tab)
        {
        posptr -> xs.xl[line_no] [d].xp[tab].xb = (char)
            ~(posptr -> xs.xl[line_no] [d].xp[tab].xb);
        posptr -> xs.xl[line_no] [d].xp[tab].sx = (char)
            ~(posptr -> xs.xl[line_no] [d].xp[tab].sx);
        posptr -> xs.xl[line_no] [d].xp[tab].xs = (char)
            ~(posptr -> xs.xl[line_no] [d].xp[tab].xs);
        } /* end for, for */

} /* end revlxga */
