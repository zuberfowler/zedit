#include <stdlib.h>
#include "zedit.h"

int  vrepcnt(
              union both_scr  *posptr,
              char  charcnt[8])
/**********************************************************************/
/*                                                                    */
/* Convert and verify the count given on a line command.  If no count */
/* is given return a count of 1.  If something invalid is given       */
/* return 0.                                                          */
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
register int  cnt;


if (!numeric(charcnt))
    {
    dispmsg(posptr, VREPCNT_MSG1);
    return(0);
    } /* end then */

cnt = atoi(charcnt);

if (cnt < 1)
    cnt = 1;

return(cnt);

} /* end vrepcnt */
