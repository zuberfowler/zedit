#include "zedit.h"

void  movecpy(
              union both_scr  *posptr,
              register struct lineptrs  *place,
              int  maxlrecl)
/**********************************************************************/
/*                                                                    */
/* Move or copy line(s) from one place to another.  This routine is   */
/* a driver for the move/copy routines that do the work.              */
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


if (place -> copyst  &&  place -> copyfn)
    {
    if (place -> after)
        if (place -> onfn)
            dispmsg(posptr, MOVECPY_MSG1);
        else
            if (cmpline(place -> after, place -> copyst) > 0  &&
                cmpline(place -> after, place -> copyfn) < 0)
                dispmsg(posptr, MOVECPY_MSG2);
            else
                copylin(posptr, place, maxlrecl);
    else
        if (place -> onfn)
            copyonb(place);
    } /* end then */

else if (place -> movest  &&  place -> movefn)
    {
    if (place -> after)
        if (place -> onfn)
            dispmsg(posptr, MOVECPY_MSG1);
        else
            if (cmpline(place -> after, place -> movest) > 0  &&
                cmpline(place -> after, place -> movefn) < 0)
                dispmsg(posptr, MOVECPY_MSG2);
            else
                movelin(posptr, place, maxlrecl);
    else
        if (place -> onfn)
            moveonb(posptr, place, maxlrecl);
    } /* end else */

} /* end movecpy */
