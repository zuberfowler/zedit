#include <stdlib.h>
#include <string.h>
#include "zedit.h"

struct bufline  *protlin(
              union both_scr  *posptr,
              register struct bufline  *curr,
              int  len)
/**********************************************************************/
/*                                                                    */
/* Allocate a protected line for COLS, LETS, KEYS, or eXclude line    */
/* command.                                                           */
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
register struct bufline  *pos;


if (!(curr -> prev))
    curr = curr -> next;

pos = (struct bufline *) malloc(sizeof(struct bufline_hdr) + len);
if (!pos)
    zfinish(posptr, no_storage);

memset(pos -> lineno, '*', 7);
pos -> lineno[7] = '\0';
pos -> script = curr -> script;
pos -> status = ST_PROT;
pos -> prev = curr -> prev;
pos -> next = curr;
curr -> prev -> next = pos;
curr -> prev = pos;

return(pos);
} /* end protlin */
