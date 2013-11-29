#include <string.h>
#include "zedit.h"

#ifdef OS2
#define INCL_DOS
#define INCL_SUB
#define INCL_NOPMAPI
#include <os2.h>
#endif

void  misccmd(
              union both_scr  *posptr,
              int  toright,
              int  *line_no,
              int  *col_no,
              unsigned int  *panel,
              int  *nfield,
              int  rowcol[][5],
              char  inptext[] [25] [80],
              int  maxlrecl,
              unsigned int  cmd,
              int  coloffset,
              struct bufline  **first,
              struct bufline  **curr,
              int  wherest[25],
              int  wherend[25],
              int  *dschanged,
              struct lineptrs  *place,
              int  rightmar,
              int  **rcptr)
/**********************************************************************/
/*                                                                    */
/* Miscellaneous commands that kind of go together.                   */
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
extern unsigned int  prtmode;
extern char  ascchar[128] [14];
extern struct bufhelp  helpedt[];
extern struct bufhelp  helpgen[];


#ifdef OS2
/* OS/2 specific identifiers */
extern long  sem_pr;
union both_scr  **stck1;
short  *stck2;
struct bufline  **stck3;
short  *stck4;
unsigned char  cc;

unsigned int  zedpbuf_thread;
static unsigned char  zedpbuf_stack[4096];
#endif


switch(cmd)
    {
    case CURSOR:
        entfield(homecsr, toright, *nfield, rowcol, line_no, col_no);
        break;
    case RTAB:
        entfield(lefttab, toright, *nfield, rowcol, line_no, col_no);
        break;
    case RESET:
        if (*panel & EDBRPAN)
            {
            scrtbuf(posptr, *nfield, rowcol, inptext, *curr, maxlrecl,
                wherest, wherend, dschanged);
            memset(place, 0x00, sizeof(*place));
            delprot(*first, curr);
            buftscr(posptr, *nfield, rowcol, inptext, *curr, maxlrecl,
                coloffset, wherest, wherend, place, YES);
            } /* end then */
        else if (graphic & CGA)
                 displin(posptr, &inptext[TXT] [0] [0], 0, ascchar);
             else
                 clrline(posptr, 24);
        break;
    case HELP:
        if (*panel & HELPPAN)
            break;
        memset(place, 0x00, sizeof(*place));
        if (*panel & EDEDPAN)
            {
            place -> newcurr = *first;
            place -> oldpanel = *panel;
            *panel = HEDTPAN;
            scrtbuf(posptr, *nfield, rowcol, inptext, *curr, maxlrecl,
                wherest, wherend, dschanged);
            place -> oldcurr = *curr;
            if (*line_no > 1)
                *curr = (struct bufline *) helpedt;
            else
                *curr = (struct bufline *) helpgen;
            buftscr(posptr, *nfield, rowcol, inptext, *curr, 72, 0,
                wherest, wherend, place, YES);
            } /* end then */
        else
            {
            place -> oldpanel = *panel;
            if (*curr)
                {
                place -> newcurr = *first;
                place -> oldcurr = *curr;
                } /* end then */
            else
                {
                place -> oldcurr = (struct bufline *) YES;
                browpan(posptr, line_no, col_no, nfield, rcptr,
                    inptext, "General Help Information", 80);
                } /* end else */
            *curr = (struct bufline *) helpgen;
            *panel = HBROPAN;
            buftscr(posptr, *nfield, (int (*)[5]) *rcptr, inptext,
                *curr, 72, 0, wherest, wherend, place, YES);
            } /* end else */
        *first = *curr;
        break;
    case DELNX:
        if (*panel & EDBRPAN)
            {
            scrtbuf(posptr, *nfield, rowcol, inptext, *curr, maxlrecl,
                wherest, wherend, dschanged);
            delnexc(posptr, maxlrecl, *first, curr);
            buftscr(posptr, *nfield, rowcol, inptext, *curr, maxlrecl,
                coloffset, wherest, wherend, place, YES);
            } /* end then */
        else
            dispmsg(posptr, MISCCMD_MSG1);
        break;
    case DELX:
        if (*panel & EDBRPAN)
            {
            scrtbuf(posptr, *nfield, rowcol, inptext, *curr, maxlrecl,
                wherest, wherend, dschanged);
            delxblk(posptr, maxlrecl, *first, curr);
            buftscr(posptr, *nfield, rowcol, inptext, *curr, maxlrecl,
                coloffset, wherest, wherend, place, YES);
            } /* end then */
        else
            dispmsg(posptr, MISCCMD_MSG1);
        break;
    case PRINT:
        if (*panel & EDBRPAN)
            {
            scrtbuf(posptr, *nfield, rowcol, inptext, *curr, maxlrecl,
                wherest, wherend, dschanged);
            if (!rightmar)
                {
                /* see if num is on or off */
                if (rowcol[*nfield - 1] [TOP_MAR] ==
                       rowcol[*nfield] [TOP_MAR]
                  &&   rowcol[*nfield - 1] [BOTTOM_MAR] ==
                       rowcol[*nfield] [BOTTOM_MAR])
                    rightmar = 72;
                else
                    rightmar = 80;
                } /* end then */
            if (prtmode & PRPPDS)
                zedpimg(posptr, maxlrecl, *first, rightmar);
            else
                {
#ifdef OS2
#ifndef DEBUG
                /* unlock the screen for possible wait */
                VioScrUnLock(0);
                DosSemRequest(&sem_pr, -1L);
                while (VioScrLock(LOCKIO_WAIT, &cc, 0))
                    DosSleep(1000L);

                /* set up stack for parameter passing */
                stck4 = (short *) &zedpbuf_stack[4094];
                *stck4 = (short) rightmar;
                stck3 = (struct bufline **) &zedpbuf_stack[4090];
                *stck3 = *first;
                stck2 = (short *) &zedpbuf_stack[4088];
                *stck2 = (short) maxlrecl;
                stck1 = (union both_scr **) &zedpbuf_stack[4084];
                *stck1 = posptr;

                /* Call zedpbuf using a separate thread. */
#ifdef M_I386
                DosCreateThread((unsigned long (*)) &zedpbuf_thread,
                    zedpprm, (unsigned long) (zedpbuf_stack + 4084),
                    0L, 8192L);
#else
                DosCreateThread((PFNTHREAD) zedpbuf,
                    (PTID) &zedpbuf_thread, zedpbuf_stack + 4084);
#endif
#else
                zedpbuf(posptr, maxlrecl, *first, rightmar);
#endif
#else
                zedpbuf(posptr, maxlrecl, *first, rightmar);
#endif
                } /* end else */
            } /* end then */
        else
            dispmsg(posptr, MISCCMD_MSG2);
        break;
    } /* end switch */

} /* end misccmd */
