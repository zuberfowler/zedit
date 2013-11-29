#include <stdlib.h>
#include "zedit.h"

void  srchcmd(
              union both_scr  *posptr,
              int  *line_no,
              int  *col_no,
              unsigned int  panel,
              int  nfield,
              int  rowcol[] [5],
              char  inptext[] [25] [80],
              int  maxlrecl,
              unsigned int  cmd,
              int  *coloffset,
              struct bufline  *first,
              struct bufline  **curr,
              int  wherest[25],
              int  wherend[25],
              int  *dschanged,
              struct lineptrs  *place,
              char  prm1[],
              char  prm2[])
/**********************************************************************/
/*                                                                    */
/* Verify find and change commands and perform housekeeping for       */
/* their execution.                                                   */
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
struct bufline  *hold;
char  *text;
int  *map;


switch(cmd)
    {
    case FIND:
        if (!(panel & EDBRPAN))
            {
            dispmsg(posptr, SRCHCMD_MSG1);
            return;
            } /* end then */
        break;
    case CHANGE:
        if (!(panel & EDEDPAN))
            {
            dispmsg(posptr, SRCHCMD_MSG2);
            return;
            } /* end then */
        break;
    } /* end switch */

scrtbuf(posptr, nfield, rowcol, inptext, *curr, maxlrecl, wherest,
    wherend, dschanged);

text = (char *) malloc(maxlrecl);
if (!text)
    zfinish(posptr, no_storage);

map = (int *) malloc(maxlrecl * sizeof(int));
if (!map)
    zfinish(posptr, no_storage);

hold = *curr;

findprm(posptr, line_no, col_no, nfield, rowcol, maxlrecl, cmd,
    coloffset, first, curr, dschanged, prm1, prm2, text, map);

free(text);
free(map);

if (hold != *curr  ||  *dschanged)
    buftscr(posptr, nfield, rowcol, inptext, *curr, maxlrecl,
        *coloffset, wherest, wherend, place, NO);

} /* end srchcmd */
