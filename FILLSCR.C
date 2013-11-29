#include <string.h>
#include "zedit.h"

#ifdef OS2
#define INCL_SUB
#define INCL_NOPMAPI
#include <os2.h>
#endif

void  fillscr(
              union both_scr  *posptr)
/**********************************************************************/
/*                                                                    */
/* This routine clears the screen display area.  It depends on        */
/* display mode what values actually are written to the display       */
/* memory.                                                            */
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
extern union both_scr  *posxga[2];
static int  first = YES;

#ifdef DOS
union regs_both  regs;
#endif


#ifdef VMS
#include <stdio.h>


if (graphic & DISPL)
    printf("S(E)");
else
    wclear(posptr);


#else


if (graphic & DISPL)
    {
    if (graphic & HIRES)
        memset(posptr, 0x00, 43200u);
    else if (graphic & XGA)
        {
        memset(posptr, 0x00, 61440u);
        if (first)
            {
            first = NO;
            memset(posxga[0], 0x00, 34560u);
            memset(posxga[1], 0x00, 34560u);
            } /* end then */
        } /* end then, else */
    else
        memset(posptr, 0x00, 32768u);
    } /* end then */
else if (graphic & TEXT)
#ifdef OS2
    VioScrollUp(0, 0, -1, -1, -1, " \x07", 0);
#else
#ifdef AIX
/* @@@ */
#else
    {
    regs.h.ah = 6;     /* scroll up function */
    regs.h.al = 0;     /* code to clear screen */
    regs.h.ch = 0;     /* upper left row */
    regs.h.cl = 0;     /* upper left column */
    regs.h.dh = 24;    /* lower right row */
    regs.h.dl = 79;    /* lower right column */
    regs.h.bh = 7;     /* attribute value */
    sysint(0x10, &regs, &regs);
    } /* end else */

#endif
#endif
#endif
#endif
} /* end fillscr */
