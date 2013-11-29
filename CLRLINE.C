#include "zedit.h"

void  clrline(
              register union both_scr  *posptr,
              int  line_no)
/**********************************************************************/
/*                                                                    */
/* Clear a screen line to blank/null.                                 */
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
#ifndef S370
extern unsigned int  graphic;

register int  tab;
register int  d; /* down */
register int  e; /* down+ */
register int  f; /* field */


#ifdef VMS
#include <stdio.h>


if (graphic & DISPL)
    printf("P[0,%d]W(E,S1)P[,%d]V[719]W(V,S0)",
        (line_no + 1) * 28 - 1, line_no * 28);
else
    {
    wmove(posptr, line_no, 0);
    wclrtoeol(posptr);
    } /* end else */

#else


if (graphic & IBM1)
    for (d = 0; d < 14; ++d)
        for (tab = 0; tab < 90; ++tab)
            posptr -> is.iscr[line_no] [d] [tab] = 0x00u;

else if (graphic & IBM2)
    for (d = 0; d < 19; ++d)
        for (tab = 0; tab < 90; ++tab)
            posptr -> i2.i2scr[line_no] [d] [tab] = 0x00u;

#ifdef DOS
else if (graphic & HMONO)
    clrlhmn(posptr, line_no);
#endif

else if (graphic & XGA)
    {
    clrlxga(posptr, line_no);
    if (line_no == 24)
        xga8514(posptr, line_no, RDSPLIN);
    } /* end then */

else if (graphic & CGA)
    {
    if (line_no < 14)
        for (d = 0, e = line_no * 7;  d < 14;  ++e)
            for (f = 0;  f < 2;  ++f, ++d)
                for (tab = 0; tab < 80; ++tab)
                    posptr -> cs.cpos[f].cscr[e] [tab] = 0x00u;
    } /* end then */

else if (graphic & EGA)
    for (d = 0; d < 14; ++d)
        for (tab = 0; tab < 80; ++tab)
            posptr -> es.escr[line_no] [d] [tab] = 0x00u;

else if (graphic & VGA)
    for (d = 0; d < 19; ++d)
        for (tab = 0; tab < 80; ++tab)
            posptr -> vs.vscr[line_no] [d] [tab] = 0x00u;

else
    for (tab = 0; tab < 80; ++tab)
        {
        posptr -> ns.nline[line_no].ncol[tab].char_byte = ' ';
        posptr -> ns.nline[line_no].ncol[tab].attr_byte = M_NORM;
        } /* end then */

#endif
#endif
} /* end clrline */
