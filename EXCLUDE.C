#include <stdlib.h>
#include <string.h>
#include "zedit.h"

struct bufline  *exclude(
              union both_scr  *posptr,
              register struct lineptrs  *place)
/**********************************************************************/
/*                                                                    */
/* Process exclude line commands.                                     */
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
int  n;
int  m;


n = 0;
pos = place -> excst -> prev;

if (pos -> status == ST_XBLK)
    {
    /* merge in any existing, preceding, exclude */
    m = pos -> rcnt;
    top = pos -> bblk;
    pos -> prev -> next = pos -> next;
    pos -> next -> prev = pos -> prev;
    pos = pos -> next;
    free(top -> eblk);
    } /* end then */
else
    {
    /* create BYPS control record for exclude start */
    m = 0;
    pos = pos -> next;
    top = protlin(posptr, pos, sizeof(struct bufline_hdr) +
        sizeof(char [2]) + sizeof(struct bufline *));
    top -> status |= ST_BYPS;
    top -> bline[0] = '\n';
    top -> bline[1] = '\0';
    } /* end else */

/* perform the current exclude */
if (place -> count > 1)
    while (pos -> next  &&  n < place -> count)
        if (pos -> status == ST_BYPS)
            {
            pos = excremv(pos, &m);
            --(place -> count);
            } /* end then */
        else
            {
            pos -> status |= ST_EXCL;
            pos = pos -> next;
            ++n;
            } /* end else */
else
    while (pos != place -> excfn -> next)
        if (pos -> status == ST_BYPS)
            pos = excremv(pos, &n);
        else
            {
            pos -> status |= ST_EXCL;
            pos = pos -> next;
            ++n;
            } /* end else */

/* merge in any existing, following, exclude */
if (pos -> status == ST_BYPS)
    pos = excremv(pos, &n);

/* create XBLK control record for exclude finish */
n += m;
pos = protlin(posptr, pos, sizeof(struct bufline));
pos -> status |= ST_XBLK;

/* fill in the control information */
pos -> rcnt = n;
pos -> bblk = top;
top -> eblk = pos;

/* fill in the text */
excxblk(pos);

/* reinitialize place */
place -> excst = NULL;
place -> excfn = NULL;
place -> count = 0;

return(pos);

} /* end exclude */
