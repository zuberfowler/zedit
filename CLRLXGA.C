#include "zedit.h"

void  clrlxga(
              register union both_scr  *posptr,
              int  line_no)
/**********************************************************************/
/*                                                                    */
/* Clear a screen line to blank/null - XGA.                           */
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
register int  d; /* down */


if (line_no > 15)
    {
    line_no = line_no - 16;
    posptr = posxga[p];
    } /* end then */

for (d = 0; d < 30; ++d)
    for (tab = 0; tab < 40; ++tab)
        {
        posptr -> xs.xl[line_no] [d].xp[tab].xb = 0x00u;
        posptr -> xs.xl[line_no] [d].xp[tab].sx = 0x00u;
        posptr -> xs.xl[line_no] [d].xp[tab].xs = 0x00u;
        } /* end for */

} /* end clrlxga */
