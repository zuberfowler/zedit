#include <stdlib.h>
#include "zedit.h"

void  ddelblk(
              union both_scr  *posptr,
              register struct lineptrs  *place,
              int  maxlrecl)
/**********************************************************************/
/*                                                                    */
/* Process a delete block command "DD".                               */
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
register struct bufline  *lptr;


place -> newcurr = place -> delst -> prev;

place -> delst -> prev -> next = place -> delfn -> next;
place -> delfn -> next -> prev = place -> delst -> prev;
srpbufr(posptr, maxlrecl, place -> delfn -> next);
renbufr(place -> delst -> prev);

for (lptr = place -> delst -> next; lptr != place -> delfn -> next;
    lptr = lptr -> next)
    free(lptr -> prev);

free(place -> delfn);

place -> delst = NULL;
place -> delfn = NULL;

} /* end ddelblk */
