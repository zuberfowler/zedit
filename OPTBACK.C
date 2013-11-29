#include "zedit.h"

void  optback(
              union both_scr  *posptr,
              unsigned int  panel,
              int  nfield,
              int  rowcol[][5],
              char  inptext[] [25] [80],
              char  dsn[56],
              int  maxlrecl,
              unsigned int  cmd[],
              struct bufline  **first,
              struct bufline  *curr,
              int  wherest[25],
              int  wherend[25],
              int  *dschanged,
              unsigned int  option)
/**********************************************************************/
/*                                                                    */
/* By option:                                                         */
/* Reset the stack to an initialized condition depending on panel.    */
/* Save out the edit data set.                                        */
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


if (option & PANLBACK)
    switch(panel)
        {
        case PRIMARY:
            cmd[0] = END;
            break;
        case DSENTRY:
            cmd[1] = SEL_PRIMARY;
            break;
        case BROWPAN:
            cmd[1] = BROWSE;
            break;
        case EDITPAN:
            cmd[1] = EDIT;
            break;
        case CFGKPAN:
            cmd[1] = SEL_PRIMARY;
            break;
        case CFGFPAN:
            cmd[1] = CONFIG;
            break;
        } /* end switch */


if (option & EDITBACK)
    if (panel & EDEDPAN)
        {
        scrtbuf(posptr, nfield, rowcol, inptext, curr, maxlrecl,
            wherest, wherend, dschanged);
        if (*dschanged)
            {
            if (wrtebuf(dsn, *first))
                dispmsg(posptr, OPTBACK_MSG1);
            else
                dispmsg(posptr, OPTBACK_MSG2);
            *dschanged = NO;
            } /* end then */
        else
            clrline(posptr, 24);
        } /* end then */
    else if (option & SAVEBACK)
        dispmsg(posptr, OPTBACK_MSG3);
else
    clrline(posptr, 24);


if (!(option & SAVEBACK))
    {
    if (panel & EDBRPAN)
        {
        freebuf(*first);
        dsn[0] = '\0';
        *first = NULL;
        } /* end then */
    for (c = 2; c < STACKMAX; ++c)
        cmd[c] = NOP;
    } /* end then */

} /* end optback */
