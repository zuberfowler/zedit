#include "zedit.h"

int  procscn(
              union both_scr  *posptr,
              int  inpt,
              int  scan,
              unsigned int  shift,
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
              char  prm2[],
              char  cmdln[])
/**********************************************************************/
/*                                                                    */
/* Process command level scan characters.                             */
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
int  finished = YES;


if (((scan >= F1)  &&  (scan <= F10))  ||
    ((scan >= SHIFT_F1)  &&  (scan <= ALT_F10)) ||
    ((scan >= F11)  &&  (scan <= ALT_F12)) ||
    (scan == CNTL_END)  ||  (scan == CNTL_DEL))
    {
    cmd[0] = funckey(scan, shift);
    if (cmd[0] == ERASEEOF)
        eraseof(posptr, toright, rowcol, inptext, *line_no, *col_no);
    else if (cmd[0] == RETURN)
        cmd[1] = ENTER;
    procedt(posptr, panel, nfield, rowcol, coloffset, curr, wherest,
        wherend, dschanged, inptext, cmd, *maxlrecl, place, cmdln);
    cmddone(posptr, toright, panel, nfield, rowcol, line_no, col_no,
        inptext, cmd, dsn, maxlrecl, amount, cmdln, prm1, prm2);
    } /* end then */

else switch(scan)
    {
    case PGUP:
        procedt(posptr, panel, nfield, rowcol, coloffset, curr, wherest,
            wherend, dschanged, inptext, cmd, *maxlrecl, place, cmdln);
        cmd[0] = UP;
        cmddone(posptr, toright, panel, nfield, rowcol, line_no, col_no,
            inptext, cmd, dsn, maxlrecl, amount, cmdln, prm1, prm2);
        break;

    case PGDOWN:
        procedt(posptr, panel, nfield, rowcol, coloffset, curr, wherest,
            wherend, dschanged, inptext, cmd, *maxlrecl, place, cmdln);
        cmd[0] = DOWN;
        cmddone(posptr, toright, panel, nfield, rowcol, line_no, col_no,
            inptext, cmd, dsn, maxlrecl, amount, cmdln, prm1, prm2);
        break;

    case ESCAPE:
        procedt(posptr, panel, nfield, rowcol, coloffset, curr, wherest,
            wherend, dschanged, inptext, cmd, *maxlrecl, place, cmdln);
        cmd[0] = END;
        cmddone(posptr, toright, panel, nfield, rowcol, line_no, col_no,
            inptext, cmd, dsn, maxlrecl, amount, cmdln, prm1, prm2);
        break;

    case CNTL_PGUP:
        procedt(posptr, panel, nfield, rowcol, coloffset, curr, wherest,
            wherend, dschanged, inptext, cmd, *maxlrecl, place, cmdln);
        cmd[0] = UP;
        cmdln[0] = 'm';
        cmddone(posptr, toright, panel, nfield, rowcol, line_no, col_no,
            inptext, cmd, dsn, maxlrecl, amount, cmdln, prm1, prm2);
        break;

    case CNTL_PGDOWN:
        procedt(posptr, panel, nfield, rowcol, coloffset, curr, wherest,
            wherend, dschanged, inptext, cmd, *maxlrecl, place, cmdln);
        cmd[0] = DOWN;
        cmdln[0] = 'm';
        cmddone(posptr, toright, panel, nfield, rowcol, line_no, col_no,
            inptext, cmd, dsn, maxlrecl, amount, cmdln, prm1, prm2);
        break;

    default:
        if ((inpt == LINE_FEED) || (scan == KEYPAD_RETURN))
            {
            procedt(posptr, panel, nfield, rowcol, coloffset, curr,
                wherest, wherend, dschanged, inptext, cmd, *maxlrecl,
                place, cmdln);
            cmdline(posptr, cmd, cmdln);
            if (cmd[1] == NOP)
                cmd[1] = ENTER;
            cmddone(posptr, toright, panel, nfield, rowcol, line_no,
                col_no, inptext, cmd, dsn, maxlrecl, amount, cmdln,
                prm1, prm2);
            } /* end then */
        else
            finished = NO;
        break;
    } /* end switch */

return(finished);
} /* end procscn */
