#include <stdlib.h>
#include <string.h>
#include "zedit.h"

void  copylin(
              union both_scr  *posptr,
              register struct lineptrs  *place,
              int  maxlrecl)
/**********************************************************************/
/*                                                                    */
/* Copy line(s) from one place to another.                            */
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
register struct bufline  *last;
register struct bufline  *hold;
register struct bufline  *curr;
unsigned int  len_bufline;


len_bufline = sizeof(struct bufline_hdr) + maxlrecl;

last = place -> after -> next;

for (curr = place -> copyfn; curr != place -> copyst -> prev;
    curr = curr -> prev)
    {
    hold = place -> after -> next;
    place -> after -> next = (struct bufline *) malloc(len_bufline);
    if (!(place -> after -> next))
        zfinish(posptr, no_storage);
    memset(place -> after -> next, 0x00, len_bufline);
    place -> after -> next -> prev = place -> after;
    place -> after -> next -> script = curr -> script;
    place -> after -> next -> status = curr -> status;
    place -> after -> next -> next = hold;
    strcpy(place -> after -> next -> bline, curr -> bline);
    hold -> prev = place -> after -> next;
    } /* end for */

srpbufr(posptr, maxlrecl, place -> after -> next);
srpbufr(posptr, maxlrecl, last);

renbufr(place -> after);

place -> copyst = NULL;
place -> copyfn = NULL;
place -> after = NULL;

} /* end copylin */
