#include "zedit.h"

void  procinp(
              union both_scr  *posptr,
              int  inpt,
              int  scan,
              unsigned int  shift,
              int  amode,
              int  toright,
              unsigned int  panel,
              int  nfield,
              int  rowcol[][5],
              int  coloffset,
              struct bufline  **curr,
              int  wherest[25],
              int  wherend[25],
              int  *dschanged,
              char  inptext[] [25] [80],
              char  dsn[56],
              int  *amount,
              int  *maxlrecl,
              int  *line_no,
              int  *col_no,
              unsigned int  cmd[],
              struct lineptrs  *place,
              char  prm1[],
              char  prm2[])
/**********************************************************************/
/*                                                                    */
/* Process input characters (inpt, scan, shift) by determining what   */
/* type/class of input it is.                                         */
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
register int  f;
char  cmdln[CMDLEN];


if (scan)
    if (procscn(posptr, inpt, scan, shift, toright, panel, nfield,
            rowcol, coloffset, curr, wherest, wherend, dschanged,
            inptext, dsn, amount, maxlrecl, line_no, col_no, cmd, place,
            prm1, prm2, cmdln))
        return;

for (f = 0; *line_no > rowcol[f] [BOTTOM_MAR]; ++f)
    {;}; /* end for */
for ( ; *col_no > rowcol[f] [RIGHT_MAR]; ++f)
    {;}; /* end for */

if (scan == RETURN_KEY)
    {
    procedt(posptr, panel, nfield, rowcol, coloffset, curr, wherest,
        wherend, dschanged, inptext, cmd, *maxlrecl, place, cmdln);
    if (f == 0)
        {
        cmdline(posptr, cmd, cmdln);
        if (!(panel & PROCPAN)  &&  cmd[1] == NOP)
            cmd[1] = ENTER;
        cmddone(posptr, toright, panel, nfield, rowcol, line_no, col_no,
            inptext, cmd, dsn, maxlrecl, amount, cmdln, prm1, prm2);
        } /* end then */
    } /* end then */

if (panel & PRDSPAN)
    {
    amode = BUF_ASCII;
    toright = YES;
    } /* end then */

if (scan)
    if (entpanl(posptr, inpt, scan, shift, amode, toright, line_no,
            col_no, f, nfield, rowcol, inptext))
        return;

if (!inpt)
    dispmsg(posptr, PROCINP_MSG1);
else if ((rowcol[f] [ATTRIB] >= RC_PROTECT)  ||
      ((inptext[ATR] [*line_no] [*col_no] & ATR_PROTECT) ==
      ATR_PROTECT))
    dispmsg(posptr, PROCINP_MSG2);
else
    {
    if (rowcol[f] [ATTRIB] == RC_NORMAL)
        ++rowcol[f] [ATTRIB];  /* flag as changed */
    convinp(posptr, inpt, shift, amode, toright, line_no, col_no,
        nfield, rowcol, inptext, YES | (graphic & XGA));
    } /* end else */

} /* end procinp */
