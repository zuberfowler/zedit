#include <stdlib.h>
#include <string.h>
#include "zedit.h"

void  rhebrew(
              char  prm[],
              char  con[],
              char  rev[],
              char  bkc[])
/**********************************************************************/
/*                                                                    */
/* Reverse Hebrew string that was written out in a mixed line.        */
/* Con is assumed to have the txtonly version of prm.  Rev is the     */
/* reversed prm.  Bkc is the reversed con.                            */
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
register char  *hld;
register int  i;
register int  p;
register int  r;

int  b;
int  c;
int  h;


b = 0;
c = strlen(con) - 1;
h = 0;
p = strlen(prm) - 1;
r = 0;
hld = (char *) malloc(p);

while (p >= 0)
    if (prm[p] == con[c])
        {
        bkc[b++] = con[c];
        rev[r++] = prm[p];
        for (i = 0; i < h; ++i)
            rev[r++] = *(hld + i);
        h = 0;
        --c;
        --p;
        } /* end then */
    else
        {
        *(hld + h) = prm[p];
        ++h;
        --p;
        } /* end else, while */

bkc[b] = '\0';
rev[r] = '\0';

free(hld);

} /* end rhebrew */
