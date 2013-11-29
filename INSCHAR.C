#include "zedit.h"

int  inschar(
              union both_scr  *posptr,
              int  toright,
              int  rowcol[] [5],
              int  line_no,
              int  col_no,
              char  inptext[] [25] [80])
/**********************************************************************/
/*                                                                    */
/* Inschar a character on a line of the screen.                       */
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
register int  i;
register int  r;
int  check;


check = NO;
for (r = 0; line_no > rowcol[r] [BOTTOM_MAR]; ++r)
    {;}; /* end for */
for ( ; col_no > rowcol[r] [RIGHT_MAR]; ++r)
    check = YES;

if (toright)
    {
    if (check  &&  inptext[TXT] [line_no] [rowcol[r] [RIGHT_MAR]] > ' ')
        {
        dispmsg(posptr, INSCHAR_MSG1);
        return(-1);
        } /* end then */
    for (i = ATR; i <= OVR; ++i)
        for (c = rowcol[r] [RIGHT_MAR]; c > col_no; --c)
            inptext[i] [line_no] [c] = inptext[i] [line_no] [c-1];
    } /* end then */
else
    {
    if (check  &&  inptext[TXT] [line_no] [rowcol[r] [LEFT_MAR]] > ' ')
        {
        dispmsg(posptr, INSCHAR_MSG1);
        return(-1);
        } /* end then */
    for (i = ATR; i <= OVR; ++i)
        for (c = rowcol[r] [LEFT_MAR]; c < col_no; ++c)
            inptext[i] [line_no] [c] = inptext[i] [line_no] [c+1];
    } /* end else */

return(r);

} /* end inschar */
