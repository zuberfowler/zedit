#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zedit.h"

struct bufline  *readbuf(
              union both_scr  *posptr,
              FILE  *ds,
              int  maxlrecl)
/**********************************************************************/
/*                                                                    */
/* Creates the file buffer by forming the beginning and end of data   */
/* lines and calling getfile to fill in the data.                     */
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
register struct bufline  *curr;
struct bufline  *first;
unsigned int  len_trmline;


len_trmline = sizeof(struct bufline_hdr) + 84;

curr = (struct bufline *) malloc(len_trmline);
if (!curr)
    zfinish(posptr, no_storage);
first = curr;
curr -> prev = NULL;
memset(curr -> lineno, '0', 7);
curr -> lineno[7] = '\0';
curr -> script = BUF_ASCII;
curr -> status = ST_PROT;
curr -> bline[0] = PRECDR;
curr -> bline[1] = BUF_ASCII;
memset(curr -> bline + 2, '*', 80);
strncpy(curr -> bline + 33, " TOP OF DATA ", 13);
curr -> bline[82] = '\n';
curr -> bline[83] = '\0';

curr = getfile(posptr, curr, ds, maxlrecl);

curr -> next = (struct bufline *) malloc(len_trmline);
if (!(curr -> next))
    zfinish(posptr, no_storage);
curr -> next -> prev = curr;
curr = curr -> next;
curr -> script = BUF_ASCII;
curr -> status = ST_PROT;
curr -> next = NULL;
memset(curr -> lineno, '*', 7);
curr -> lineno[7] = '\0';
curr -> bline[0] = PRECDR;
curr -> bline[1] = BUF_ASCII;
memset(curr -> bline + 2, '*', 80);
strncpy(curr -> bline + 32, " BOTTOM OF DATA ", 16);
curr -> bline[82] = '\n';
curr -> bline[83] = '\0';

memset(first -> lineno, '*', 7);
curr -> lineno[7] = '\0';

return(first);

} /* end readbuf */
