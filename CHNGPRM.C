#include <string.h>
#include "zedit.h"

void  chngprm(
              union both_scr  *posptr,
              int  maxlrecl,
              char  pat[],
              char  prm2[],
              int  map[],
              int  onscr,
              register struct bufline  *ptr,
              int  *dschanged)
/**********************************************************************/
/*                                                                    */
/* Change the string value of prm1 to prm2.                           */
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
register int  b;
register int  e;
register int  j;
int  cnt;
int  lenprm1;
int  lenprm2;


*dschanged = YES;

/* find the beginning location of prm1, b, in bline */
for (b = 0; map[b] != onscr; ++b)
    {;}; /* end for */

/* compute onscr for the ending character of pat */
onscr = onscr + strlen(pat) - 1;

/* find the ending location, e, of prm1 in bline */
for (e = b; map[e] != onscr; ++e)
    {;}; /* end for */

lenprm1 = e - b + 1;
lenprm2 = strlen(prm2);

if (lenprm2 < lenprm1)
    {
    for (j = 0; b <= e; ++b)
        if (prm2[j])
            {
            ptr -> bline[b] = prm2[j];
            ++j;
            } /* end then */
        else
            ptr -> bline[b] = ' ';

    /* scan existing blanks */
    for (++e; ptr -> bline[e] == ' '; ++e)
        {;}; /* end for */

    /* remove just the difference in the parms */
    e -= (lenprm1 - lenprm2);
    leftjust(&(ptr -> bline[e]));
    } /* end then */
else
    {
    cnt = lenprm2 - lenprm1;
    if (cnt)
    /* ie. lenprm2 > lenprm1 */
        {
        /* shift right end of bline for a count of cnt */
        j = strlen(ptr -> bline) + cnt;

        if (j >= maxlrecl)
            {
            dispmsg(posptr, CHNGPRM_MSG1);
            return;
            } /* end then */

        ptr -> bline[j--] = '\0';

        for ( ; j > e + cnt; --j)
            ptr -> bline[j] = ptr -> bline[j - cnt];
        } /* end then */

    /* lenprm1 (is now) == lenprm2 */
    for (j = 0; prm2[j]; ++j, ++b)
        ptr -> bline[b] = prm2[j];
    } /* end else */

/* prm2 could have introduced a new PRECDR-charset */
srpbufr(posptr, maxlrecl, ptr -> next);

} /* end chngprm */
