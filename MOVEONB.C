#include "zedit.h"

void  moveonb(
              union both_scr  *posptr,
              register struct lineptrs  *place,
              int  maxlrecl)
/**********************************************************************/
/*                                                                    */
/* Move a block of lines onto another block of lines.  If the source  */
/* is less lines than the destination, then the source will repeat    */
/* from the beggining.  Either the source or the destination may be   */
/* either one line or a block.                                        */
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
register struct bufline  *frln;
register struct bufline  *toln;
int  all;


all = NO;

frln = place -> movest;
toln = place -> onst;

while (toln != place -> onfn -> next)
    {
    if (frln == place -> movefn -> next)
        {
        all = YES;
        frln = place -> movest;
        } /* end then */

    if (frln -> status & ST_PROT)
        frln = frln -> next;
    else if (toln -> status & ST_PROT)
        toln = toln -> next;
    else
        {
        mergeon(frln -> bline, toln -> bline);
        toln = toln -> next;
        frln = frln -> next;
        } /* end else */
    } /* end for */

if (all  ||  frln == place -> movefn -> next)
    {
    place -> delst = place -> movest;
    place -> delfn = place -> movefn;
    ddelblk(posptr, place, maxlrecl);
    } /* end else */
else
    dispmsg(posptr, MOVEONB_MSG1);

place -> movest = NULL;
place -> movefn = NULL;
place -> onst = NULL;
place -> onfn = NULL;

} /* end moveonb */
