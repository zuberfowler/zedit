#include <stdlib.h>
#include <string.h>
#include "zedit.h"

void   excxblk(
              register struct bufline  *ptr)
/**********************************************************************/
/*                                                                    */
/* Fill in the text of the ST_XBLK protect line that displays the     */
/* exclude count.                                                     */
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
register int  c;


ptr -> bline[0] = PRECDR;
ptr -> bline[1] = BUF_ROMCHAR;

memset(ptr -> bline + 2, '-', 23);
ptr -> bline[25] = ' ';
itoa(ptr -> rcnt, ptr -> bline + 26, 10);
for (c = 26; ptr -> bline[c]; ++c)
    {;}; /* end for */
strncpy(ptr -> bline + c, " LINE(S) NOT DISPLAYED ", 23);
c += 23;
memset(ptr -> bline + c, '-', 24);
c += 24;

ptr -> bline[c++] = PRECDR;
if (ptr -> next -> bline[0] == PRECDR)
    {
    ptr -> bline[c++] = ptr -> next -> bline[1];
    ptr -> next -> script = ptr -> next -> bline[1];
    } /* end then */
else
    ptr -> bline[c++] = ptr -> next -> script;

ptr -> bline[c++] = '\n';
ptr -> bline[c++] = '\0';

} /* end excxblk */
