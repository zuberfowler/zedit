#include "zedit.h"

void  excrdsp(
              union both_scr  *posptr,
              register struct bufline  *ptr)
/**********************************************************************/
/*                                                                    */
/* Redisplay an excluded line whose pointer is passed as a parameter. */
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
register struct bufline  *oldbot;
struct bufline  *oldtop;
int  n;


n = 0;
for (pos = ptr -> prev; pos -> status != ST_BYPS; pos = pos -> prev)
    ++n;

oldtop = pos;
oldbot = pos -> eblk;

if (n)
    /* lines still to be excluded above redisplay line */
    if (ptr -> next != oldbot)
        {
        /* create new XBLK record for exclude above redisplay */
        pos = protlin(posptr, ptr, sizeof(struct bufline));
        pos -> status |= ST_XBLK;
        pos -> rcnt = n;
        pos -> bblk = oldtop;
        excxblk(pos);
        oldtop -> eblk = pos;
        /* create new BYPS record for exclude below redisplay */
        pos = protlin(posptr, ptr -> next, sizeof(struct bufline_hdr) +
            sizeof(char [2]) + sizeof(struct bufline *));
        pos -> status |= ST_BYPS;
        pos -> bline[0] = '\n';
        pos -> bline[1] = '\0';
        pos -> eblk = oldbot;
        oldbot -> bblk = pos;
        oldbot -> rcnt -= (n + 1);
        excxblk(oldbot);
        } /* end then */
    else
        {
        /* move the XBLK record above redisplay line */
        ptr -> prev -> next = oldbot;
        oldbot -> prev = ptr -> prev;
        ptr -> next = oldbot -> next;
        oldbot -> next -> prev = ptr;
        oldbot -> next = ptr;
        ptr -> prev = oldbot;
        --(oldbot -> rcnt);
        excxblk(oldbot);
        } /* end else, then */
else
    /* BYPS is immediately above redisplay line */
    if (ptr -> next != oldbot)
        {
        /* move the BYPS record after redisplay line */
        pos -> prev -> next = ptr;
        pos -> next = ptr -> next;
        ptr -> next -> prev = pos;
        ptr -> prev = pos -> prev;
        pos -> prev = ptr;
        ptr -> next = pos;
        --(oldbot -> rcnt);
        excxblk(oldbot);
        } /* end then */
    else
        /* no lines remain to be excluded */
        excremv(pos, &n);

ptr -> status ^= ST_EXCL;

} /* end excrdsp */
