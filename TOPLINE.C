#include <stdlib.h>
#include <string.h>
#include "zedit.h"

void  topline(
              union both_scr  *posptr,
              int  nfield,
              int  rowcol[] [5],
              char  inptext[] [25] [80],
              struct bufline  *curr,
              int  maxlrecl,
              int  coloffset,
              int  clrmsg)
/**********************************************************************/
/*                                                                    */
/* (Re)Display top line right hand side of BROWSE/EDIT panels.        */
/* Reset message area on top line and on line 25 (some terminals).    */
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
extern unsigned int  graphic;
extern char  ascchar[128] [14];

static int  rc_topline[1] [5] = {{0, 56, 79, 0, RC_PROTECT}};
register char  *line;
int  right_col;
int  num;
char  cwrk[8];


if (rowcol[nfield - 1] [TOP_MAR] == rowcol[nfield] [TOP_MAR]  &&
    rowcol[nfield - 1] [BOTTOM_MAR] == rowcol[nfield] [BOTTOM_MAR])
    num = YES;
else
    num = NO;

line = &inptext[TXT] [0] [0];

if (!num)
    {
    strncpy(line + 50, " LINE ", 6);
    if (curr -> lineno[0] == '*')
        dispnum(posptr, 0, rc_topline, NO, 0, rc_topline[0] [LEFT_MAR],
            "0000000", 0, inptext);
    else
        dispnum(posptr, 0, rc_topline, NO, 0, rc_topline[0] [LEFT_MAR],
            curr -> lineno, 0, inptext);
    strncpy(line + 63, " COL ", 5);
    } /* end then */
else
    strncpy(line + 59, " COLUMNS ", 9);

right_col = coloffset + (rowcol[nfield] [RIGHT_MAR] -
    rowcol[nfield] [LEFT_MAR]) + 1;
if (right_col > maxlrecl)
   right_col = maxlrecl - 2;

memset(cwrk, '\0', 8);
itoa(coloffset + 1, cwrk, 10);
rightjst(cwrk, 7);
dispnum(posptr, 0, rc_topline, NO, 0, 68, cwrk, 2, inptext);
*(line + 73) = ' ';

memset(cwrk, '\0', 8);
itoa(right_col, cwrk, 10);
rightjst(cwrk, 7);
dispnum(posptr, 0, rc_topline, NO, 0, 74, cwrk, 2, inptext);
*(line + 79) = ' ';

displin(posptr, line, 0, ascchar);
if (graphic & XGA)
    xga8514(posptr, 0, RDSPLIN);

if (clrmsg)
    clrline(posptr, 24);

} /* end topline */
