#include <string.h>
#include "zedit.h"

void  cmdrest(
              union both_scr  *posptr,
              int  toright,
              int  rowcol[] [5],
              int  *line_no,
              int  *col_no,
              char  inptext[] [25] [80])
/**********************************************************************/
/*                                                                    */
/* Restore the command line to its original state.                    */
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
register int  i;


for (i = ATR; i <= OVR; ++i)
    memset(&inptext[i] [rowcol[0][TOP_MAR]] [rowcol[0][LEFT_MAR]],
        0x00, (rowcol[0][RIGHT_MAR] - rowcol[0][LEFT_MAR]) + 1);

displin(posptr, &inptext[TXT] [1] [0], 1, ascchar);
if (graphic & XGA)
    xga8514(posptr, 1, RDSPLIN);

if (toright)
    {
    *line_no = rowcol[0] [TOP_MAR];
    *col_no = rowcol[0] [LEFT_MAR];
    } /* end then */
else
    {
    *line_no = rowcol[0] [TOP_MAR];
    *col_no = rowcol[0] [RIGHT_MAR];
    } /* end then */

} /* end cmdrest */
