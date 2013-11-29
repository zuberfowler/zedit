#include <stdlib.h>
#include <string.h>
#include "zedit.h"

void  rrepblk(
              union both_scr  *posptr,
              register struct lineptrs  *place,
              int  maxlrecl)
/**********************************************************************/
/*                                                                    */
/* Process a repeat block command "RR".                               */
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
register struct bufline  *curr;
register struct bufline  *hold;
register struct bufline  *lptr;
register int  n;
unsigned int  len_bufline;


len_bufline = sizeof(struct bufline_hdr) + maxlrecl;

for (n = 0; n < place -> count; ++n)
    {
    hold = place -> repfn -> next;
    lptr = place -> repfn;
    for (curr = place -> repst; curr != place -> repfn -> next;
        curr = curr -> next)
        {
        lptr -> next = (struct bufline *) malloc(len_bufline);
        if (!(lptr -> next))
            zfinish(posptr, no_storage);
        memset(lptr -> next, 0x00, len_bufline);
        lptr -> next -> prev = lptr;
        lptr = lptr -> next;
        lptr -> script = curr -> script;
        lptr -> status = curr -> status;
        strcpy(lptr -> bline, curr -> bline);
        } /* end for */

    srpbufr(posptr, maxlrecl, place -> repfn -> next);

    lptr -> next = hold;
    hold -> prev = lptr;
    } /* end for */

renbufr(place -> repfn);

place -> repst = NULL;
place -> repfn = NULL;
place -> count = 0;

} /* end rrepblk */
