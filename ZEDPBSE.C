#include <stdio.h>
#include "zedit.h"

void  zedpbse(
              char  dsn[],
              int  maxlrecl,
              int  rightmar)
/**********************************************************************/
/*                                                                    */
/* Zedit print driver program for non-display mode.                   */
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
extern unsigned int  prtmode;
struct bufline  *first;
FILE  *in;

if (!rightmar)
    rightmar = 72;

in = fopen(dsn, OLD_INPUT);
if (!in)
    zfinish(NULL, open_in);

first = readbuf(NULL, in, maxlrecl);
fclose(in);

if (prtmode & PRPPDS)
    zedpimg(NULL, maxlrecl, first, rightmar);
else
    zedpbuf(NULL, maxlrecl, first, rightmar);

} /* end main zedprt */
