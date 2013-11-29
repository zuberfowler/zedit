#include "zedit.h"

void  delchar(
              int  toright,
              int  f,
              int  rowcol[] [5],
              int  line_no,
              int  col_no,
              char  inptext[] [25] [80])
/**********************************************************************/
/*                                                                    */
/* Delchar a character on a line of the screen.                       */
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


if (toright)
    for (i = ATR; i <= OVR; ++i)
        {
        for (c = col_no; c < rowcol[f] [RIGHT_MAR]; ++c)
            inptext[i] [line_no] [c] = inptext[i] [line_no] [c+1];
        inptext[i] [line_no] [rowcol[f] [RIGHT_MAR]] = 0x00;
        } /* end for, then */
else
    for (i = ATR; i <= OVR; ++i)
        {
        for (c = col_no; c > rowcol[f] [LEFT_MAR]; --c)
            inptext[i] [line_no] [c] = inptext[i] [line_no] [c-1];
        inptext[i] [line_no] [rowcol[f] [LEFT_MAR]] = 0x00;
        } /* end for, else */

} /* end delchar */
