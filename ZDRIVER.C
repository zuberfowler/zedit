#include <stdio.h>
#include "zedit.h"

unsigned int  zdriver(
              union both_scr  *posptr,
              int  inpt,
              int  scan,
              unsigned int  shift,
              int  amode,
              int  toright,
              int  *line_no,
              int  *col_no,
              unsigned int  *panel,
              int  *nfield,
              int  **rowcol,
              char  inptext[] [25] [80],
              char  dsn[56],
              int  *maxlrecl,
              int  *coloffset,
              struct bufline  **first,
              struct bufline  **curr,
              int  wherest[25],
              int  wherend[25],
              int  *dschanged,
              struct lineptrs  *place,
              unsigned int  cmd[],
              int  rightmar)
/**********************************************************************/
/*                                                                    */
/* Screen and cmd control module.                                     */
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
/* cmd subscript */
register int  c;

char  prm1[CMDLEN];
char  prm2[CMDLEN];
int  amount;


/* maintain commands in stack */
if (cmd[1] == NOP)
    {
    if (cmd[0] != NEXTINPT)
        {
        cmd[0] = NEXTINPT;
        return(cmd[0]);
        } /* end then */
    } /* end then */
else
    for (c = 0; c < STACKMAX; ++c)
        cmd[c] = cmd[c + 1];

/* process input if any */
if (cmd[0] == NEXTINPT)
    procinp(posptr, inpt, scan, shift, amode, toright, *panel, *nfield,
        (int (*)[5]) *rowcol, *coloffset, curr, wherest, wherend,
        dschanged, inptext, dsn, &amount, maxlrecl, line_no, col_no,
        cmd, place, prm1, prm2);

/* process command either outstanding or from input */
if (cmd[0] & TODOCMD)
    {
    if (cmd[0] & SCRLCMD)
        *curr = scrlcmd(posptr, *panel, *nfield, (int (*)[5]) *rowcol,
            inptext, amount, *maxlrecl, cmd, coloffset, *first, *curr,
            wherest, wherend, dschanged, place);

    else if (cmd[0] & STCKCMD)
        stckcmd(cmd);

    else if (cmd[0] & MISCCMD)
        misccmd(posptr, toright, line_no, col_no, panel, nfield,
            (int (*)[5]) *rowcol, inptext, *maxlrecl, cmd[0], *coloffset,
            first, curr, wherest, wherend, dschanged, place, rightmar,
            rowcol);

    else if (cmd[0] & SRCHCMD)
        srchcmd(posptr, line_no, col_no, *panel, *nfield,
            (int (*)[5]) *rowcol, inptext, *maxlrecl, cmd[0], coloffset,
            *first, curr, wherest, wherend, dschanged, place, prm1,
            prm2);

    else if (cmd[0] & PANLCMD)
        panlcmd(posptr, line_no, col_no, panel, nfield, rowcol, inptext,
            dsn, *maxlrecl, cmd, coloffset, first, curr, wherest,
            wherend, dschanged, place, rightmar);

    else if (cmd[0] & PAN2CMD)
        pan2cmd(posptr, line_no, col_no, panel, nfield, rowcol, inptext,
            dsn, *maxlrecl, cmd, coloffset, *curr, wherest, wherend,
            dschanged, place, rightmar);

    else if (cmd[0] & BACKCMD)
        {
        if (place -> oldcurr)
            if (place -> oldpanel  &  EDBRPAN)
                *curr = place -> oldcurr;
            else
                *curr = NULL;
        backcmd(posptr, panel, *nfield, (int (*)[5]) *rowcol, inptext,
            dsn, *maxlrecl, cmd, *coloffset, first, *curr, wherest,
            wherend, dschanged, place, prm1);
        } /* end then, else */

    else if (cmd[0] & PRIMCMD)
        primcmd(posptr, cmd, *first);
    } /* end then */

return(cmd[0]);

} /* end zdriver */
