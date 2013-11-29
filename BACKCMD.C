#include <string.h>
#include "zedit.h"

void  backcmd(
              union both_scr  *posptr,
              unsigned int  *panel,
              int  nfield,
              int  rowcol[][5],
              char  inptext[] [25] [80],
              char  dsn[56],
              int  maxlrecl,
              unsigned int  cmd[],
              int  coloffset,
              struct bufline  **first,
              struct bufline  *curr,
              int  wherest[25],
              int  wherend[25],
              int  *dschanged,
              struct lineptrs  *place,
              char  prm[])
/**********************************************************************/
/*                                                                    */
/* Return back down the panel structure.                              */
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
register  l;
int  changed = YES;


if (cmd[2] == SEL_COPYDSN)
    {
    cmd[0] = NOP;
    cmd[1] = ENTER;
    return;
    } /* end then */

/* if in help display all back commands are treated the same */
if (place -> oldcurr)
    {
    cmd[0] = NOP;
    if (place -> oldpanel  &  EDBRPAN)
        {
        *panel = place -> oldpanel;
        *first = place -> newcurr;
        for (l  = rowcol[nfield] [TOP_MAR];
             l <= rowcol[nfield] [BOTTOM_MAR]; ++l)
            {
            memset(&inptext[ATR] [l] [0], 0x00, 80);
            memset(&inptext[TXT] [l] [0], 0x00, 80);
            memset(&inptext[SRP] [l] [0], 0x00, 80);
            memset(&inptext[OVR] [l] [0], 0x00, 80);
            } /* end for */
        buftscr(posptr, nfield, rowcol, inptext, curr, maxlrecl,
            coloffset, wherest, wherend, place, YES);
        } /* end then */
    else
        {
        *first = NULL;
        cmd[1] = SEL_PRIMARY;
        clrline(posptr, 24);
        } /* end else */
    place -> newcurr = NULL;
    place -> oldcurr = NULL;
    place -> oldpanel = NOPANEL;
    return;
    } /* end then */

/* allow X only on primary panel */
if (cmd[0] == XXITSYS  &&  *panel == PRIMARY)
    cmd[0] = EXITSYS;

/* process cmd either outstanding or from input */
switch(cmd[0])
    {
    case CANCEL:
        optback(posptr, *panel, nfield, rowcol, inptext, dsn, maxlrecl,
            cmd, first, curr, wherest, wherend, dschanged, PANLBACK);
        clrline(posptr, 24);
        break;
    case EXITSYS:
        optback(posptr, *panel, nfield, rowcol, inptext, dsn, maxlrecl,
            cmd, first, curr, wherest, wherend, dschanged, EDITBACK);
        cmd[1] = SEL_PRIMARY;
        *panel = PRIMARY;
        cmd[0] = END;
        break;
    case RETURN:
        optback(posptr, *panel, nfield, rowcol, inptext, dsn, maxlrecl,
            cmd, first, curr, wherest, wherend, dschanged, EDITBACK);
        if (cmd[1] == ENTER)
            cmd[1] = SEL_PRIMARY;
        break;
    case END:
        cmd[0] = NOP;
        optback(posptr, *panel, nfield, rowcol, inptext, dsn, maxlrecl,
            cmd, first, curr, wherest, wherend, dschanged, PNEDBACK);
        break;
    case SAVE:
        optback(posptr, *panel, nfield, rowcol, inptext, dsn, maxlrecl,
            cmd, first, curr, wherest, wherend, &changed, SVEDBACK);
        if (*panel & EDEDPAN)
            buftscr(posptr, nfield, rowcol, inptext, curr, maxlrecl,
                coloffset, wherest, wherend, place, NO);
        break;
    case REPLACE:
        optback(posptr, *panel, nfield, rowcol, inptext, prm, maxlrecl,
            cmd, first, curr, wherest, wherend, &changed, SVEDBACK);
        if (*panel & EDEDPAN)
            buftscr(posptr, nfield, rowcol, inptext, curr, maxlrecl,
                coloffset, wherest, wherend, place, NO);
        break;
    } /* end switch */

} /* end backcmd */
