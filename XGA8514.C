#include "zedit.h"
#include "hdafi.h"

void  xga8514(
              register union both_scr  *posptr,
              int  line_no,
              int  col_no)
/**********************************************************************/
/*                                                                    */
/* Invoke hdafi calls to move screen data to physical display.        */
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
extern union both_scr  *posxga[2];
extern int  p;

/* these should not be static to maintain reentrancy */
struct hbbw_parm  xw =
    {sizeof(xw)-2, 0, 1024, 768, 0, 0, 0, 0, 12, 30};
struct hbbchn_parm  xb = {sizeof(xb)-2, 0, 61440};


if (line_no == FULLSCR)
    {
    /* first 16 lines of screen */
    xw.wsub = 1024;
    xw.hsub = 480;
    xb.sdat = (char S16) posptr;
    HBBW(&xw);
    HBBCHN(&xb);

    /* last 9 lines of screen */
    xw.hsub = 270;
    xw.ycord = 480;
    xb.sdat = (char S16) posxga[p];
    xb.ldat = 34560;
    } /* end then */
else if (col_no == RDSPLIN)
    {
    /* move one display line of screen */
    xw.wsub = 1024;
    xw.ycord = (short) (line_no * 30);
    if (line_no < 16)
        xb.sdat = (char S16) posptr;
    else
        {
        line_no -= 16;
        posptr = posxga[p];
        xb.ldat = 34560;
        xb.sdat = (char S16) posxga[p];
        } /* end else */
    xw.tmar  = (short) (line_no * 30);
    } /* end else */
else
    {
    /* move one character position of screen */
    xw.xcord = (short) (col_no * 12 + 32);
    xw.ycord = (short) (line_no * 30);
    if (line_no < 16)
        xb.sdat = (char S16) posptr;
    else
        {
        line_no -= 16;
        posptr = posxga[p];
        xb.ldat = 34560;
        xb.sdat = (char S16) posxga[p];
        } /* end else */
    xw.lmar  = xw.xcord;
    xw.tmar  = (short) (line_no * 30);
    } /* end else */

HBBW(&xw);
HBBCHN(&xb);

} /* end xga8514 */
