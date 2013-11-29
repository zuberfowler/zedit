#include "zedit.h"

#ifdef OS2
#define INCL_DOS
#define INCL_SUB
#define INCL_NOPMAPI
#include <os2.h>
#endif

void  linecmd(
              union both_scr  *posptr,
              int  nfield,
              int  rowcol[] [5],
              char  inptext[] [25] [80],
              unsigned int  cmd[],
              int  maxlrecl,
              register struct bufline  *curr,
              struct lineptrs  *place,
              int  *dschanged)
/**********************************************************************/
/*                                                                    */
/* Loop through lines and find line commands and pass on to process.  */
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
#ifdef OS2
extern long  sem_pr;
unsigned char  cc;
#endif

register char  *pos;
int  line_no;
char  ccnt[8];


/* reset attribute byte for window */
--rowcol[nfield - 1] [ATTRIB];

for(line_no = rowcol[nfield - 1] [TOP_MAR];
    curr  &&  line_no <= rowcol[nfield - 1] [BOTTOM_MAR];
    curr = curr -> next)
    {
    if (curr -> status & ST_EXCL)
        continue;

    pos = loclcmd(curr,
        &inptext[TXT] [line_no] [rowcol[nfield - 1] [LEFT_MAR]],
        &inptext[SRP] [line_no] [rowcol[nfield - 1] [LEFT_MAR]],
        ccnt);

    if (!pos)
        {
        ++line_no;
        continue;
        } /* end then */

#ifdef OS2
#ifndef DEBUG
    /* unlock the screen for possible wait */
    VioScrUnLock(0);
    DosSemWait(&sem_pr, -1L);
    while (VioScrLock(LOCKIO_WAIT, &cc, 0))
        DosSleep(1000L);
#endif
#endif

    if (*pos < 'f')
        curr = lnecmd1(posptr, nfield, rowcol, cmd, maxlrecl, curr,
            place, pos, ccnt, &line_no, dschanged);
    else if (*pos > 'o')
        curr = lnecmd3(posptr, maxlrecl, curr, place, pos, ccnt,
            &line_no, dschanged);
    else
        curr = lnecmd2(posptr, cmd, maxlrecl, curr, place, pos, ccnt,
            &line_no, dschanged);

    ++line_no;
    } /* end for */

} /* end linecmd */
