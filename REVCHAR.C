#include "zedit.h"

#ifdef OS2
#define INCL_SUB
#define INCL_NOPMAPI
#include <os2.h>
#endif

void  revchar(
              register union both_scr  *posptr,
              int  line_no,
              int  col_no)
/**********************************************************************/
/*                                                                    */
/* Turn a character position to the oposite display of its present    */
/* display (normal/reverse).                                          */
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

#ifndef OS2
union regs_both  regs;
#endif

register int  d; /* down  */
register int  e; /* range */
register int  f; /* field */


#ifdef VMS
#include <stdio.h>

if (graphic & DISPL)
    printf("P[%d,%d]W(C,S1)P[,%d]V[%d]W(V,S0)",
        col_no * 9 + 1, (line_no+1) * 28, line_no * 28, col_no * 9 + 8);

#else


if (graphic & IBM1)
    revcibm(posptr, line_no, col_no);

else if (graphic & IBM2)
    revcib2(posptr, line_no, col_no);

#ifdef DOS
else if (graphic & HMONO)
    revchmn(posptr, line_no, col_no);
#endif

else if (graphic & XGA)
    revcxga(posptr, line_no, col_no);

else if (graphic & CGA)
    for (d = 0, e = line_no * 7;  d < 14;  ++e)
        for (f = 0;  f < 2;  ++f, ++d)
            posptr -> cs.cpos[f].cscr[e] [col_no] ^= 0xFFu;

else if (graphic & EGA)
    for (d = 0; d < 14; ++d)
        posptr -> es.escr[line_no] [d] [col_no] ^= 0xFFu;

else if (graphic & VGA)
    for (d = 0; d < 19; ++d)
        posptr -> vs.vscr[line_no] [d] [col_no] ^= 0xFFu;

else
    {
#ifdef OS2
    VioSetCurPos((unsigned short) line_no, (unsigned short) col_no, 0);
#else
#ifdef AIX
/* @@@ */
#else
    regs.h.ah = 2;                /* position cursor function */
    regs.h.dh = (char) line_no;
    regs.h.dl = (char) col_no;
    regs.h.bh = 0;                /* current page (for rom) */
    sysint(0x10, &regs, &regs);
#endif
#endif
    posptr -> ns.nline[line_no].ncol[col_no].attr_byte ^= 0x77u;
    } /* end then */

#endif
#endif
} /* end revchar */
