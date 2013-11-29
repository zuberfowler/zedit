#include "zedit.h"

int  lcinval(
              union both_scr  *posptr,
              enum lctype  type,
              register struct bufline  *curr)
/**********************************************************************/
/*                                                                    */
/* Determine whether line command is valid on this line and if not    */
/* notify user with error message and beep.                           */
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
int  answ;


answ = NO;

switch(type)
    {
    case lc_any:
        if (curr -> status & ST_PROT)
            answ = YES;
        break;
    case lc_top:
        if (!(curr -> prev))
            answ = YES;
        break;
    case lc_bottom:
        if (!(curr -> next))
            answ = YES;
        break;
    case lc_both:
        if (!(curr -> next)  ||  !(curr -> prev))
            answ = YES;
        break;
    } /* end switch */

if (answ)
    dispmsg(posptr, LCINVAL_MSG1);

return(answ);

} /* end lcinval */
