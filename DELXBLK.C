#include <stdlib.h>
#include "zedit.h"

void  delxblk(
              union both_scr  *posptr,
              int  maxlrecl,
              register struct bufline  *ptr,
              struct bufline  **curr)
/**********************************************************************/
/*                                                                    */
/* Process a DELETE ALL X command.                                    */
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
ptr = ptr -> next;

while (ptr -> next)
    {
    if (ptr -> status & ST_EXCL)
        {
        if (ptr -> status == ST_BYPS)
            top = ptr -> prev;
        temp = ptr;
        ptr = ptr -> next;
        free(temp);
        } /* end then */
    else if (ptr -> status == ST_XBLK)
        {
        temp = ptr;
        ptr = ptr -> next;
        free(temp);
        top -> next = ptr;
        ptr -> prev = top;
        srpbufr(posptr, maxlrecl, ptr);
        } /* end then, else */
    else
        ptr = ptr -> next;
    } /* end while */

renbufr(*curr);

} /* end delxblk */
