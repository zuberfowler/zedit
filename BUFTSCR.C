#include <stdlib.h>
#include <string.h>
#include "zedit.h"

void  buftscr(
              union both_scr  *posptr,
              int  nfield,
              int  rowcol[] [5],
              char  inptext[] [25] [80],
              register struct bufline  *curr,
              int  maxlrecl,
              int  coloffset,
              int  wherest[25],
              int  wherend[25],
              register struct lineptrs  *place,
              int  clrmsg)
/**********************************************************************/
/*                                                                    */
/* Move the data from the input buffer linear format to the inptext   */
/* triplex format and display to the screen one line at a time        */
/* using buftsln.                                                     */
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
register int  line_no;
int  col_no;
int  rc[1] [5];
int  amode;
int  num;
int  eol;
int  toright = YES;
char  *scratch;
char  cwrk[8];


rc[0] [0] = 0;
rc[0] [1] = 0;
rc[0] [2] = maxlrecl;
rc[0] [3] = 0;
rc[0] [4] = RC_ENTRY;

topline(posptr, nfield, rowcol, inptext, curr, maxlrecl, coloffset,
    clrmsg);

if (rowcol[nfield - 1] [TOP_MAR] == rowcol[nfield] [TOP_MAR]  &&
    rowcol[nfield - 1] [BOTTOM_MAR] == rowcol[nfield] [BOTTOM_MAR])
    num = YES;
else
    num = NO;

line_no = rowcol[nfield] [TOP_MAR];

/**********************************************************************/
/* Since the starting offset for each high level index are 2000 bytes */
/* apart the minimum and maximum needed is 4000 + maxlrecl.           */
/**********************************************************************/
if (coloffset)
    {
    scratch = (char *) malloc(4000 + maxlrecl);
    if (!scratch)
        zfinish(posptr, no_storage);
    } /* end then */

while (curr  &&  line_no <= rowcol[nfield] [BOTTOM_MAR])
    {
    if (curr -> status & ST_EXCL)
        {
        curr = curr -> next;
        continue;
        } /* end then */
    if (num)
        if (curr == place -> slst)
            {
            dispnum(posptr, nfield, rowcol, NO, line_no,
                rowcol[nfield - 1] [LEFT_MAR], "#((    ", 0, inptext);
            itoa(place -> count, cwrk, 10);
            dispnum(posptr, nfield, rowcol, NO, line_no,
                rowcol[nfield - 1] [LEFT_MAR] + 3, cwrk, 0, inptext);
            } /* end then */
        else if (curr == place -> srst)
            {
            dispnum(posptr, nfield, rowcol, NO, line_no,
                rowcol[nfield - 1] [LEFT_MAR], "#))    ", 0, inptext);
            itoa(place -> count, cwrk, 10);
            dispnum(posptr, nfield, rowcol, NO, line_no,
                rowcol[nfield - 1] [LEFT_MAR] + 3, cwrk, 0, inptext);
            } /* end then, else */
        else if (curr == place -> after)
            dispnum(posptr, nfield, rowcol, NO, line_no,
                rowcol[nfield - 1] [LEFT_MAR], "#A     ", 0, inptext);
        else if (curr == place -> copyst)
            if (place -> copyst == place -> copyfn)
                dispnum(posptr, nfield, rowcol, NO, line_no,
                    rowcol[nfield - 1] [LEFT_MAR], "#C     ", 0,
                    inptext);
            else
                dispnum(posptr, nfield, rowcol, NO, line_no,
                    rowcol[nfield - 1] [LEFT_MAR], "#CC    ", 0,
                    inptext);
        else if (curr == place -> copyfn)
            dispnum(posptr, nfield, rowcol, NO, line_no,
                rowcol[nfield - 1] [LEFT_MAR], "#CC    ", 0,
                inptext);
        else if (curr == place -> delst)
            dispnum(posptr, nfield, rowcol, NO, line_no,
                rowcol[nfield - 1] [LEFT_MAR], "#DD    ", 0, inptext);
        else if (curr == place -> movest)
            if (place -> movest == place -> movefn)
                dispnum(posptr, nfield, rowcol, NO, line_no,
                    rowcol[nfield - 1] [LEFT_MAR], "#M     ", 0,
                    inptext);
            else
                dispnum(posptr, nfield, rowcol, NO, line_no,
                    rowcol[nfield - 1] [LEFT_MAR], "#MM    ", 0,
                    inptext);
        else if (curr == place -> movefn)
            dispnum(posptr, nfield, rowcol, NO, line_no,
                rowcol[nfield - 1] [LEFT_MAR], "#MM    ", 0,
                inptext);
        else if (curr == place -> onst)
            dispnum(posptr, nfield, rowcol, NO, line_no,
                rowcol[nfield - 1] [LEFT_MAR], "#OO    ", 0,
                inptext);
        else if (curr == place -> onfn)
            dispnum(posptr, nfield, rowcol, NO, line_no,
                rowcol[nfield - 1] [LEFT_MAR], "#OO    ", 0,
                inptext);
        else if (curr == place -> repst)
            {
            dispnum(posptr, nfield, rowcol, NO, line_no,
                rowcol[nfield - 1] [LEFT_MAR], "#RR    ", 0, inptext);
            itoa(place -> count, cwrk, 10);
            dispnum(posptr, nfield, rowcol, NO, line_no,
                rowcol[nfield - 1] [LEFT_MAR] + 3, cwrk, 0, inptext);
            } /* end then, else */
        else if (curr == place -> excst)
            dispnum(posptr, nfield, rowcol, NO, line_no,
                rowcol[nfield - 1] [LEFT_MAR], "#XX    ", 0, inptext);
        else dispnum(posptr, nfield, rowcol, curr -> status, line_no,
            rowcol[nfield - 1] [LEFT_MAR], curr -> lineno, 0, inptext);

    /* zedpimg and zedpbuf have parallel logic */
    amode = curr -> script;
    if (curr -> script == BUF_HEBREW)
        toright = NO;
    else
        toright = YES;

    wherest[line_no] = 0;
    eol = NO;
    if (coloffset  &&  (curr -> status & ST_SCRL))
        getstrt(coloffset, curr -> bline, rc, scratch,
            &wherest[line_no], &amode, &eol, &toright);

    wherend[line_no] = wherest[line_no];
    if (toright)
        col_no = rowcol[nfield] [LEFT_MAR];
    else
        col_no = rowcol[nfield] [RIGHT_MAR];
    buftsln(posptr, nfield, rowcol, curr, line_no, maxlrecl,
        inptext, &wherend[line_no], &amode, &eol, &toright, &col_no);

    curr = curr -> next;
    ++line_no;
    } /* end lineloop */

/* clear out bottom of window */
while (line_no <= rowcol[nfield] [BOTTOM_MAR])
    {
    clrline(posptr, line_no);
    memset(&inptext[ATR] [line_no] [0], ATR_PROTECT, 80);
    memset(&inptext[TXT] [line_no] [0], 0x00, 80);
    memset(&inptext[SRP] [line_no] [0], 0x00, 80);
    memset(&inptext[OVR] [line_no] [0], 0x00, 80);
    ++line_no;
    } /* end while */

if (coloffset)
    free(scratch);

if (graphic & XGA)
    xga8514(posptr, FULLSCR, NO);

} /* end buftscr */
