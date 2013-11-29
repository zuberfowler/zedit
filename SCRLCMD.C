#include <stdlib.h>
#include "zedit.h"

struct bufline  *scrlcmd(
              union both_scr  *posptr,
              unsigned int  panel,
              int  nfield,
              int  rowcol[][5],
              char  inptext[] [25] [80],
              int  amount,
              int  maxlrecl,
              unsigned int  cmd[],
              int  *coloffset,
              struct bufline  *first,
              register struct bufline  *curr,
              int  wherest[25],
              int  wherend[25],
              int  *dschanged,
              register struct lineptrs  *place)
/**********************************************************************/
/*                                                                    */
/* Execute scroll commands.                                           */
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
register int  r;


if (!(panel & EDBRPAN))
    {
    dispmsg(posptr, SCRLCMD_MSG1);
    return(curr);
    } /* end then */

scrtbuf(posptr, nfield, rowcol, inptext, curr, maxlrecl, wherest,
    wherend, dschanged);

/* process cmd either outstanding or from input */
switch(cmd[0])
    {
    case DOWN:
        if (amount < 0)
            for (r = 1; ; ++r)
                {
                if (!(curr -> next))
                    break;
                curr = curr -> next;
                } /* end for */
        else
            for (r = 1; r <= amount; ++r)
                {
                if (!(curr -> next))
                    break;
                curr = curr -> next;
                } /* end for */
        if (!(curr -> next))
            for (r = 1; r <= 12; ++ r)
                {
                if (!(curr -> prev))
                    break;
                curr = curr -> prev;
                } /* end for */
        break;
    case UP:
        if (amount < 0)
            curr = first;
        else
            for (r = 1; r <= amount; ++r)
                {
                if (!(curr -> prev))
                    break;
                curr = curr -> prev;
                } /* end for */
        break;
    case LEFT:
        if (amount < 0)
            *coloffset = 0;
        else
            {
            *coloffset -= amount;
            if (*coloffset < 0)
                *coloffset = 0;
            } /* end else */
        break;
    case RIGHT:
        *coloffset += amount;
        if ((*coloffset > (maxlrecl - (rowcol[nfield] [RIGHT_MAR]
            - rowcol[nfield] [LEFT_MAR] + 3))) || (amount < 0))
            *coloffset = maxlrecl - (rowcol[nfield] [RIGHT_MAR] -
                rowcol[nfield] [LEFT_MAR] + 3);
        break;
    case LOCATE:
        for (curr = first;
            curr  &&  atoi(curr -> lineno) != amount;
            curr = curr -> next)
            {;}; /* end for */
        if (!curr)
            {
            curr = first;
            dispmsg(posptr, SCRLCMD_MSG2);
            } /* end then */
        break;
    case COLMS:
        curr = colslin(posptr, maxlrecl, curr, place);
        break;
    case LETS:
        curr = letslin(posptr, maxlrecl, curr, place);
        break;
    case KEYS:
        curr = keyslin(posptr, curr, place);
        break;
    } /* end switch */

buftscr(posptr, nfield, rowcol, inptext, curr, maxlrecl, *coloffset,
    wherest, wherend, place, YES);

return(curr);

} /* end scrlcmd */
