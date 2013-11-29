#include "zedit.h"

void  dispnum(
              union both_scr  *posptr,
              int  nfield,
              int  rowcol[] [5],
              char  stat,
              int  num_line,
              int  num_col,
              char  numdigit[],
              register int  nd_col,
              char  inptext[] [25] [80])
/**********************************************************************/
/*                                                                    */
/* Put a line number on the screen.                                   */
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


for ( ; numdigit[nd_col]; ++nd_col)
    {
    if (stat & ST_HELP)
        inptext[ATR] [num_line] [num_col] |= ATR_PROTECT;
    else
        inptext[ATR] [num_line] [num_col] &= ~ATR_PROTECT;
    convinp(posptr, numdigit[nd_col], 0x00, BUF_ROMCHAR, YES,
        &num_line, &num_col, nfield, rowcol, inptext, YESMAYBE);
    } /* end for */

} /* end dispnum */
