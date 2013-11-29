#include <string.h>
#include "zedit.h"

void  srpbufr(
              union both_scr  *posptr,
              int  maxlrecl,
              register struct bufline  *ptr)
/**********************************************************************/
/*                                                                    */
/* Rework script values after changing individual lines.  Call twice, */
/* once for the line in question and once for the line following it.  */
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
register int  n;
int  len;
int  prevsrp;


if (!ptr  ||  !(ptr -> prev))
    return;

prevsrp = lastsrp(ptr -> prev -> script, ptr -> prev -> bline);

/* can only happen on first ptr */
if ((char) prevsrp == ptr -> script)
    return;

while (ptr)
    {
    len = strlen(ptr -> bline);
    for (n = 0; n < len; ++n)
        if (ptr -> bline[n] > ' ')
            {
            if (ptr -> bline[0] != PRECDR)
                {
                /* can discard for-loop "n" because of return */
                n = len + 2;
                if (n >= maxlrecl)
                    {
                    dispmsg(posptr, SRPBUFR_MSG1);
                    n = maxlrecl - 1;
                    } /* end then */
                ptr -> bline[n--] = '\0';
                ptr -> bline[n--] = '\n';
                for ( ; n >= 2; --n)
                    ptr -> bline[n] = ptr -> bline[n - 2];
                ptr -> bline[1] = ptr -> script;
                ptr -> bline[0] = PRECDR;
                } /* end then */

            ptr -> script = (char) prevsrp;
            return;
            } /* end then, for */

    ptr -> script = (char) prevsrp;
    ptr = ptr -> next;
    } /* end while */

} /* end srpbufr */
