#include <string.h>
#include "zedit.h"

int  cmpline(
              struct bufline  *lo,
              struct bufline  *hi)
/**********************************************************************/
/*                                                                    */
/* Compare two lines and determine which comes first in the buffer.   */
/* The return result is similar to strcmp, return(lo - hi).           */
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


if (lo -> lineno[0] == '*'  ||  hi -> lineno[0] == '*')
    {
    if (lo == hi)
       return(0);
    while (lo)
        {
        if (lo == hi)
           return(-1);
        lo = lo -> next;
        } /* end while */
    return(1);
    } /* end then */

return(strcmp(lo -> lineno, hi -> lineno));

} /* end cmpline */
