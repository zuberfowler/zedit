#include <stdlib.h>
#include "zedit.h"

void  delprot(
              register struct bufline  *ptr,
              register struct bufline  **curr)
/**********************************************************************/
/*                                                                    */
/* Remove editor protected informational lines, reset to initial      */
/* state.                                                             */
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
register struct bufline  *temp;


/* don't do first and last lines */
ptr = ptr -> next;

while (ptr -> next)
    {
    if (ptr -> status & ST_PROT)
        {
        if (ptr == *curr)
            *curr = (*curr) -> prev;
        ptr -> prev -> next = ptr -> next;
        ptr -> next -> prev = ptr -> prev;
        temp = ptr;
        ptr = ptr -> next;
        free(temp);
        } /* end then */
    else
        {
        ptr -> status = ST_NORM;
        ptr = ptr -> next;
        } /* end else */
    } /* end while */

} /* end delprot */
