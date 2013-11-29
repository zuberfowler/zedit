#include <stdlib.h>
#include "zedit.h"
#include "hdafi.h"

void  zepilog(
              union both_scr  *posptr,
              enum fintype  code)
/**********************************************************************/
/*                                                                    */
/* Termination code.  Reset the terminal screen.                      */
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
extern unsigned int  graphic;
static struct hclose_parm  xc = {sizeof(xc)-2, 0};


if (graphic & XGA  &&  code != video_fail)
    HCLOSE(&xc);

#ifdef DOS
if (graphic & HMONO)
    {
    prtcntl(DISP_MODE, GRAPH0_NVIDEO);
    fillscr(posptr);
    } /* end then */
#endif

textreg();

if (graphic & TEXT)
    fillscr(posptr);

#ifdef DOS
else if (graphic & HMONO)
    {
    prtcntl(DISP_MODE, TEXT0_NVIDEO);
    prtcntl(DISP_MODE, TEXT0_VIDEO);
    graphic = NO;
    fillscr(posptr);
    } /* end then */
#endif

#ifdef S370
clrscr();
#endif

} /* end zepilog */
