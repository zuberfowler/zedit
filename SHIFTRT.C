#include <string.h>
#include "zedit.h"

void  shiftrt(
              union both_scr  *posptr,
              register struct lineptrs  *place,
              int  maxlrecl)
/**********************************************************************/
/*                                                                    */
/* Process a shift right line command ")n" or "))n".                  */
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
register int  n;
int  cnt;


if (place -> count  >  maxlrecl - 2)
    cnt = maxlrecl - 2;
else
    cnt = place -> count;

for (lptr = place -> srst;  lptr != place -> srfn -> next;
    lptr = lptr -> next)
    {
    if (lptr -> status & ST_PROT)
        continue;

    n = strlen(lptr -> bline) + cnt;

    if (n < 2)
        n = 2;
    else if (n >= maxlrecl)
        {
        dispmsg(posptr, SHIFTRT_MSG1);
        n = maxlrecl - 1;
        } /* end then, else */

    lptr -> bline[n--] = '\0';
    lptr -> bline[n--] = '\n';

    for ( ; n >= cnt; --n)
        lptr -> bline[n] = lptr -> bline[n - cnt];

    for (n = 0; n < cnt; ++n)
        lptr -> bline[n] = ' ';

    srpbufr(posptr, maxlrecl, lptr);
    srpbufr(posptr, maxlrecl, lptr -> next);

    /* correct dual language line caused by leading blanks */
    for (n = 0; lptr -> bline[n] == ' '; ++n)
        {;}; /* end for */
    if (n != 0  &&  lptr -> bline[n] == PRECDR)
        {
        lptr -> bline[0] = lptr -> bline[n];
        lptr -> bline[1] = lptr -> bline[n+1];
        if (n != 1)
            lptr -> bline[n] = ' ';
        lptr -> bline[n+1] = ' ';
        if (lptr -> bline[n+2] == PRECDR)
            {
            lptr -> bline[2] = lptr -> bline[n+2];
            lptr -> bline[3] = lptr -> bline[n+3];
            if (n != 1)
                lptr -> bline[n+2] = ' ';
            lptr -> bline[n+3] = ' ';
            } /* end then */
        } /* end then */

    } /* end for */

place -> srst = NULL;
place -> srfn = NULL;
place -> count = 0;

} /* end shiftrt */
