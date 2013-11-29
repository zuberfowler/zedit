#include <stdlib.h>
#include "zedit.h"

struct bufline  *excmerg(
              register struct bufline  *ptr)
/**********************************************************************/
/*                                                                    */
/* This routine expects to be passed the pointer to ST_BYPS record    */
/* which is preceded by a ST_XBLK record.  It merges the two          */
/* control blocks.  The return value is the next pointer down the     */
/* chain after the freed control record pointers.                     */
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
register struct bufline  *ptrprev;
register struct bufline  *ptreblk;
register struct bufline  *ptrnext;

/* get frequently used pointers */
ptrnext = ptr -> next;
ptrprev = ptr -> prev;
ptreblk = ptr -> eblk;

/* merge the outer control records to make one block */
ptreblk -> rcnt += ptrprev -> rcnt;
ptrprev -> bblk -> eblk = ptreblk;
ptreblk -> bblk = ptrprev -> bblk;

/* delete the obsolete control records */
free(ptr);
ptr = ptrprev -> prev;
free(ptrprev);

/* remove the adjacent control records from the chain */
ptr -> next = ptrnext;
ptrnext -> prev = ptr;

/* redo the final XBLK record */
excxblk(ptreblk);

return(ptr);
} /* end excmerg */
