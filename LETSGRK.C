#include <string.h>
#include "zedit.h"

int  letsgrk(
              int  i,  /* main index */
              int  e,  /* extra char count, return value */
              int  d,  /* displacement */
              char  bline[])
/**********************************************************************/
/*                                                                    */
/* Insert required extra primary letter before an overlay letter.     */
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
static char  overs[] = {ACUTE, CIRCUMFLEX, GRAVE, IOTASUB, ROUGH,
                       SIGMATERM, SMOOTH, UMLAUT, '\0'};
extern char  grkexch[256];
char  *pos;


pos = strchr(overs, grkexch[i]);
if (pos)
    {
    if (*pos == SIGMATERM)
        bline[i+e+d] = SIGMA;
    else
        bline[i+e+d] = BLANK;
    ++e;
    } /* end then */

bline[i+e+d] = grkexch[i];

return(e);
} /* end letsgrk */
