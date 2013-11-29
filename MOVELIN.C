#include "zedit.h"

void  movelin(
              union both_scr  *posptr,
              register struct lineptrs  *place,
              int  maxlrecl)
/**********************************************************************/
/*                                                                    */
/* Move line(s) from one place to another.                            */
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
struct bufline  *lptr;


lptr = place -> movest -> prev;

place -> movest -> prev -> next = place -> movefn -> next;
place -> movefn -> next -> prev = place -> movest -> prev;

srpbufr(posptr, maxlrecl, place -> movefn -> next);

place -> movest -> prev = place -> after;
place -> movefn -> next = place -> after -> next;
place -> after -> next -> prev = place -> movefn;
place -> after -> next = place -> movest;

srpbufr(posptr, maxlrecl, place -> movest);

srpbufr(posptr, maxlrecl, place -> movefn -> next);

if (cmpline(place -> after, lptr) >= 0)
    renbufr(lptr);
else
    renbufr(place -> after);

place -> movest = NULL;
place -> movefn = NULL;
place -> after = NULL;

} /* end movelin */
