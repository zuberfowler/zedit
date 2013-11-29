#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zedit.h"

struct bufline  *getfile(
              union both_scr  *posptr,
              register struct bufline  *curr,
              FILE  *ds,
              int  maxlrecl)
/**********************************************************************/
/*                                                                    */
/* Read the input data set.                                           */
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
unsigned int  len_bufline;
int  prevsrp;
char  *more;


len_bufline = sizeof(struct bufline_hdr) + maxlrecl;
prevsrp = BUF_ASCII;

curr -> next = (struct bufline *) malloc(len_bufline);
if (!(curr -> next))
    zfinish(posptr, no_storage);
memset(curr -> next, '\0', len_bufline);
more = fgets(curr -> next -> bline, maxlrecl, ds);

while(!feof(ds))
    {
    curr -> next -> prev = curr;
    itoa(atoi(curr -> lineno) + 1, curr -> next -> lineno, 10);
    curr = curr -> next;
    rightjst(curr -> lineno, 7);
    curr -> script = (char) prevsrp;
    prevsrp = lastsrp(prevsrp, curr -> bline);
    curr -> status = ST_NORM;
    curr -> next = (struct bufline *) malloc(len_bufline);
    if (!(curr -> next))
        zfinish(posptr, no_storage);
    memset(curr -> next, '\0', len_bufline);
    more = fgets(curr -> next -> bline, maxlrecl, ds);
    } /* end while */

if (more)
    {
    curr -> next -> prev = curr;
    itoa(atoi(curr -> lineno) + 1, curr -> next -> lineno, 10);
    curr = curr -> next;
    rightjst(curr -> lineno, 7);
    curr -> script = (char) prevsrp;
    curr -> status = ST_NORM;
    curr -> bline[strlen(curr -> bline) - 1] = '\n';
    } /* end then */
else
    free(curr -> next);

return(curr);

} /* end getfile */
