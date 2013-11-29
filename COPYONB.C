#include "zedit.h"

void  copyonb(
              register struct lineptrs  *place)
/**********************************************************************/
/*                                                                    */
/* Copy a block of lines onto another block of lines.  If the source  */
/* is less lines than the destination, then the source will repeat    */
/* from the begining.  Either the source or the destination may be    */
/* only one or a block.                                               */
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


frln = place -> copyst;
toln = place -> onst;

while (toln != place -> onfn -> next)
    {
    if (frln == place -> copyfn -> next)
        frln = place -> copyst;

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
    } /* end while */

place -> copyst = NULL;
place -> copyfn = NULL;
place -> onst = NULL;
place -> onfn = NULL;

} /* end copyonb */
