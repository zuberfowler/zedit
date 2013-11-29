#include <stdio.h>
#include "zedit.h"

void  zedppre(
              int  maxlrecl,
              FILE  *prn,
              int  rightmar,
              int  amode,
              int  toright,
              char  prchar,
              char  prbuf[])
/**********************************************************************/
/*                                                                    */
/* Prepare buffer for bidirectional printing double high characters.  */
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

static int  q = 0;
static int  last_amode[20] = {-1};
static int  pb[20] = {-1};

static int  true_linesize = 0;


/**********************************************************************/
/* PostScript routine can be called instead of this routine           */
/**********************************************************************/
if (prtmode & PSCRPT)
    {
    zedppsp(maxlrecl, prn, rightmar, amode, toright, prchar);
    return;
    } /* end then */
/**********************************************************************/

/* buffer backspace, replace previous char */
if (!maxlrecl)
    {
    --true_linesize;
    if (toright)
        --pb[q];
    else
        ++pb[q];
    return;
    } /* end then */

/* initialize first time through for a line */
if (pb[q] == -1)
    {
    true_linesize = 0;
    if (toright)
        pb[q] = 0;
    else
        pb[q] = maxlrecl - 1;
    } /* end then */

if (amode != last_amode[q])
    {
    ++q;
    pb[q] = pb[q-1];
    last_amode[q] = amode;
    } /* end then */

prbuf[pb[q]] = prchar;

if (toright)
    ++pb[q];
else
    --pb[q];

if (prchar == '\b')
    --true_linesize;
else
    ++true_linesize;

/* actually print out the line */
if (prchar == '\n')
    {
    zedpprt(prn, rightmar, toright, prbuf, true_linesize, q, last_amode,
        pb);

    /* reset for next line */
    q = 0;
    pb[q] = -1;
    } /* end then */

} /* end zedppre */
