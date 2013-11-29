#include <stdlib.h>
#include "zedit.h"

void  delnexc(
              union both_scr  *posptr,
              int  maxlrecl,
              register struct bufline  *ptr,
              struct bufline  **curr)
/**********************************************************************/
/*                                                                    */
/* Process a DELETE ALL NX command.                                   */
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
register struct bufline  *top;
register struct bufline  *temp;


/* ptr is set to first on entry */
*curr = ptr;
top = ptr;
ptr = ptr -> next;

while (ptr -> next)
    {
    if (ptr -> status == ST_BYPS)
        {
        top -> next = ptr;
        ptr -> prev = top;
        srpbufr(posptr, maxlrecl, ptr);
        top = ptr -> eblk;
        ptr = top -> next;
        } /* end then */
    else
        {
        temp = ptr;
        ptr = ptr -> next;
        free(temp);
        } /* end else */
    } /* end while */

top -> next = ptr;
ptr -> prev = top;
renbufr(*curr);

} /* end delnexc */
