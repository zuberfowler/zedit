#include "zedit.h"

struct bufline  *colslin(
              union both_scr  *posptr,
              int  maxlrecl,
              struct bufline  *curr,
              struct lineptrs  *place)
/**********************************************************************/
/*                                                                    */
/* Create the columns text in a protect line.                         */
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
static char  cnt[10] = {'1','2','3','4','5','6','7','8','9','0'};
register struct bufline  *pos;
register int  r;
register int  c;


if (place -> colsb)
    {
    curr = place -> colsb;
    place -> colsb = NULL;
    } /* end then */

pos = protlin(posptr, curr, maxlrecl+2);
pos -> status |= ST_SCRL;

pos -> bline[0] = PRECDR;
if (pos -> next -> bline[0] == PRECDR)
    {
    pos -> bline[1] = pos -> next -> bline[1];
    pos -> next -> script = pos -> bline[1];
    } /* end then */
else
    pos -> bline[1] = pos -> script;

c = 0;
for (r = 2; r < maxlrecl; ++r)
    {
    if ((r - 1) % 10 == 0)
        {
        pos -> bline[r] = cnt[c];
        if (++c > 9)
            c = 0;
        } /* end then */
    else if ((r - 1) % 5 == 0)
        pos -> bline[r] = '+';
    else
        pos -> bline[r] = '-';
    } /* end for */

pos -> bline[r++] = '\n';
pos -> bline[r] = '\0';

return(pos);
} /* end colslin */
