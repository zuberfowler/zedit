#include <stdlib.h>
#include <string.h>
#include "zedit.h"

void  renbufr(
              register struct bufline  *ptr)
/**********************************************************************/
/*                                                                    */
/* Renumber the records in the buffer.  Call excmerg to merge exclude */
/* block as necessary.                                                */
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
register int  ln;


/* get the begining line number */
if (!(ptr -> prev))
    ln = 1;
else
    {
    while (ptr  &&  ptr -> status & ST_PROT)
        {
        if (ptr -> prev -> status == ST_XBLK  &&
            ptr -> status == ST_BYPS)
            ptr = excmerg(ptr);
        else
            ptr = ptr -> next;
        } /* end while */
    if (ptr)
        ln = atoi(ptr -> lineno) + 1;
    else
        return;
    } /* end else */

/* renumber the remainder of the buffer */
ptr = ptr -> next;
while (ptr -> next)
    {
    if (ptr -> status & ST_PROT)
        {
        if (ptr -> prev -> status == ST_XBLK  &&
            ptr -> status == ST_BYPS)
            ptr = excmerg(ptr);
        } /* end then */
    else
        {
        itoa(ln++, ptr -> lineno, 10);
        rightjst(ptr -> lineno, 7);
        } /* end else */
    ptr = ptr -> next;
    } /* end while */

} /* end renbufr */
