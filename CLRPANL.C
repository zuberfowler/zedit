#include "zedit.h"

void  clrpanl(
              union both_scr  *posptr)
/**********************************************************************/
/*                                                                    */
/* Clear the panel area but leave the message line alone (line 25).   */
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
extern unsigned int  graphic;

register int  l;
register int  range;


if (graphic & CGA)
    range = 14;
else
    range = 24;

for (l = 0; l < range; ++l)
    clrline(posptr, l);


} /* end clrpanl */
