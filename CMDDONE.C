#include <stdlib.h>
#include "zedit.h"

void  cmddone(
              union both_scr  *posptr,
              int  toright,
              unsigned int  panel,
              int  nfield,
              int  rowcol[] [5],
              int  *line_no,
              int  *col_no,
              char  inptext[] [25] [80],
              unsigned int  cmd[],
              char  dsn[56],
              int  *maxlrecl,
              int  *amount,
              char  cmdln[],
              char  prm1[],
              char  prm2[])
/**********************************************************************/
/*                                                                    */
/* Processing which is done between command interpretation and        */
/* implementation.  One of the main functions is to clean up          */
/* (redisplay) the command line.                                      */
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
int  newlrecl;


if ((cmd[0] >= EXITSYS  &&  cmd[0] <= CANCEL)  ||
    (cmd[0] >= CURSOR  &&  cmd[0] <= HELP)  ||
    cmd[0] == ERASEEOF)
    return;

switch(panel)
    {
    case CFGKPAN:
        if (cmd[1] == ENTER)
            if (cfgkget(posptr, rowcol, inptext))
                cmd[1] = NOP;
            else
                clrline(posptr, 24);
        else
            cmdrest(posptr, toright, rowcol, line_no, col_no, inptext);
        break;
    case CFGFPAN:
        if (cmd[1] == ENTER)
            {
            cfgfget(posptr, rowcol, inptext);
            cmd[0] = RETURN;
            } /* end then */
        else
            cmdrest(posptr, toright, rowcol, line_no, col_no, inptext);
        break;
    case PRIMARY:
        cmdrest(posptr, toright, rowcol, line_no, col_no, inptext);
        clrline(posptr, 24);
        break;
    case DSENTRY:
        if (cmd[1] == ENTER)
            {
            formdsn(&inptext[TXT] [rowcol[1] [TOP_MAR]]
                    [rowcol[1] [LEFT_MAR]],
                &inptext[TXT] [rowcol[2] [TOP_MAR]]
                    [rowcol[2] [LEFT_MAR]],
                &inptext[TXT] [rowcol[3] [TOP_MAR]]
                    [rowcol[3] [LEFT_MAR]],
                &inptext[TXT] [rowcol[4] [TOP_MAR]]
                    [rowcol[4] [LEFT_MAR]],
                &inptext[TXT] [rowcol[5] [TOP_MAR]]
                    [rowcol[5] [LEFT_MAR]],
                &inptext[TXT] [rowcol[6] [TOP_MAR]]
                    [rowcol[6] [LEFT_MAR]],
                &inptext[TXT] [rowcol[7] [TOP_MAR]]
                    [rowcol[7] [LEFT_MAR]],
                &inptext[TXT] [rowcol[8] [TOP_MAR]]
                    [rowcol[8] [LEFT_MAR]], dsn);
            upper(dsn);
            newlrecl = atoi(rightjst(&inptext[TXT]
                [rowcol[9] [TOP_MAR]] [rowcol[9] [LEFT_MAR]], 5));
            if (newlrecl > 2  &&  newlrecl != MAXLREC)
                *maxlrecl = newlrecl;
            } /* end then */
        else
            cmdrest(posptr, toright, rowcol, line_no, col_no, inptext);
        break;
    default:
        *amount = cmdparm(cmd[0], toright, *line_no, *col_no,
            &inptext[TXT] [rowcol[1] [TOP_MAR]] [rowcol[1] [LEFT_MAR]],
            nfield, rowcol, cmdln, prm1, prm2);

        if (*amount  ||  cmd[1] == ENTER)
            cmdrest(posptr, toright, rowcol, line_no, col_no, inptext);

        break;
    } /* end switch */

} /* end cmddone */
