#include <stdlib.h>
#include "zedit.h"

struct bufline  *excremv(
              register struct bufline  *pos,
              int  *n)
/**********************************************************************/
/*                                                                    */
/* Remove the ST_BYPS and ST_XBLK lines around an exclude block.      */
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
struct bufline  *temp;


pos -> prev -> next = pos -> next;
pos -> next -> prev = pos -> prev;
temp = pos;
pos = pos -> eblk;
free(temp);
*n += pos -> rcnt;
pos -> prev -> next = pos -> next;
pos -> next -> prev = pos -> prev;
temp = pos;
pos = pos -> next;
free(temp);
return(pos);

} /* end excremv */
