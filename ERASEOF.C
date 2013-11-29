#include <string.h>
#include "zedit.h"

void  eraseof(
              union both_scr  *posptr,
              int  toright,
              int  rowcol[][5],
              char  inptext[] [25] [80],
              int  line_no,
              int  col_no)
/**********************************************************************/
/*                                                                    */
/* Perform the ERASEEOF command.  This command is only valid from a   */
/* function key.                                                      */
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
register int  i;
register int  f;


for (f = 0; line_no > rowcol[f] [BOTTOM_MAR]; ++f)
    {;}; /* end for */
for ( ; col_no > rowcol[f] [RIGHT_MAR]; ++f)
    {;}; /* end for */

if (rowcol[f] [ATTRIB] < RC_PROTECT)
    {
    if (rowcol[f] [ATTRIB] == RC_NORMAL)
        /* flag as changed */
        ++rowcol[f] [ATTRIB];
    if (toright)
        for (i = ATR; i <= OVR; ++i)
            memset(&inptext[i] [line_no] [col_no], 0x00,
                (rowcol[f] [RIGHT_MAR] - col_no) + 1);
    else
        for (i = ATR; i <= OVR; ++i)
            memset(&inptext[i] [line_no] [rowcol[f] [LEFT_MAR]], 0x00,
                (col_no - rowcol[f] [LEFT_MAR]) + 1);
    rdsplin(posptr, line_no, rowcol[f] [LEFT_MAR],
        rowcol[f] [RIGHT_MAR], inptext);
    } /* end then */
else
    dispmsg(posptr, ERASEOF_MSG1);

} /* end eraseof */
