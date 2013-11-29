#include <stdlib.h>
#include <string.h>
#include "zedit.h"

struct bufline  *excshow(
              union both_scr  *posptr,
              register struct lineptrs  *place,
              int  maxlrecl)
/**********************************************************************/
/*                                                                    */
/* Process exclude show/first/last line commands.                     */
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
register struct bufline  *pos;
struct bufline  *top;
struct bufline  *bot;
register int  s;
int  forw;
int  snum;


if (place -> excst)
    {
    forw = YES;
    pos = place -> excst;
    place -> excst = NULL;
    } /* end then */
else
    {
    forw = NO;
    pos = place -> excfn;
    place -> excfn = NULL;
    } /* end else */

top = pos -> bblk;
bot = pos;

if (pos -> rcnt  <  place -> count)
    snum = pos -> rcnt;
else
    snum = place -> count;
place -> count = 0;

/* calculate the number of lines remaining excluded */
pos -> rcnt -= snum;

if (!(pos -> rcnt))
    {
    /* show the whole thing and exit */
    for (pos = top -> next; pos != bot; pos = pos -> next)
        pos -> status ^= ST_EXCL;
    return(excremv(top, &snum));
    } /* end then */

if (forw)
    {
    /* reset first lines and move BYPS line down */
    for (s = 0, pos = top -> next; s < snum; ++s, pos = pos -> next)
        pos -> status ^= ST_EXCL;
    place -> movest = top;
    place -> movefn = top;
    place -> after = pos -> prev;
    movelin(posptr, place, maxlrecl);
    } /* end then */
else
    {
    /* reset last lines and move XBLK line up */
    for (s = 0, pos = bot -> prev; s < snum; ++s, pos = pos -> prev)
        pos -> status ^= ST_EXCL;
    place -> movest = bot;
    place -> movefn = bot;
    place -> after = pos;
    movelin(posptr, place, maxlrecl);
    } /* end else */

/* redo the XBLK record */
excxblk(bot);

return(bot);

} /* end excshow */
