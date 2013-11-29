#include <string.h>
#include "zedit.h"

void  shiftlf(
              union both_scr  *posptr,
              register struct lineptrs  *place,
              int  maxlrecl)
/**********************************************************************/
/*                                                                    */
/* Process a shift left line command "(n" or "((n".                   */
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


for (lptr = place -> slst;  lptr != place -> slfn -> next;
    lptr = lptr -> next)
    {
    if (lptr -> status & ST_PROT)
        continue;

    for (n = 0; lptr -> bline[n] == PRECDR; n = n + 2)
        {;}; /* end for */

    strcpy(&(lptr -> bline[n]), &(lptr -> bline[place -> count]));

    srpbufr(posptr, maxlrecl, lptr);
    srpbufr(posptr, maxlrecl, lptr -> next);

    if (!strlen(lptr -> bline))
        {
        lptr -> bline[0] = '\n';
        lptr -> bline[1] = '\0';
        } /* end then */
    } /* end for */

place -> slst = NULL;
place -> slfn = NULL;
place -> count = 0;

} /* end shiftlf */
