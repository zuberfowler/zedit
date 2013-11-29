#include <stdlib.h>
#include <string.h>
#include "zedit.h"

int  cmdparm(
              unsigned int  cmd,
              int  toright,
              int  line_no,
              int  col_no,
              char  scrfield[5],
              int  nfield,
              int  rowcol[] [5],
              char  cmdln[],
              char  prm1[],
              char  prm2[])
/**********************************************************************/
/*                                                                    */
/* Determine scroll value, columns or lines to move.  As a byproduct  */
/* get command line parms if any.                                     */
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
register int  n;
char  amt[CMDLEN];


prm1[0] = '\0';
prm2[0] = '\0';

if (cmd & SRCHCMD)
    {
    /* check for leading blanks */
    if (cmdln[0] == PRECDR)
        if (cmdln[2] == ' ')
            leftjust(&cmdln[2]);
        else if (cmdln[2] == PRECDR)
            leftjust(&cmdln[4]);
    } /* end then */
else
    for (n = 0; cmdln[n] == PRECDR; n = n + 2)
        {
        cmdln[n] = ' ';
        cmdln[n + 1] = ' ';
        } /* end for, else */

if (leftjust(cmdln))
    {
    cmdprse(amt, cmdln);
    if (numeric(amt))
        return(atoi(amt));
    else
        {
        strcpy(prm1, amt);
        if (leftjust(cmdln))
            cmdprse(prm2, cmdln);
        } /* end else */
    } /* end then */
else if (leftfld(scrfield, 4))
    {
    if (numeric(scrfield))
        return(atoi(scrfield));
    strcpy(amt, scrfield);
    } /* end then, else */
else return(0);

lower(amt);
n = 0;

if (cmd == UP  ||  cmd == DOWN)
    switch(amt[0])
        {
        case 'd':
            n = rowcol[nfield] [BOTTOM_MAR] - 2;
            break;
        case 'h':
            n = rowcol[nfield] [BOTTOM_MAR] / 2;
            break;
        case 'm':
            n = -1;
            break;
        case 'p':
            n = rowcol[nfield] [BOTTOM_MAR] - 1;
            break;
        case 'c':
            if (cmd == DOWN)
                n = line_no - 2;
            else
                n = rowcol[nfield] [BOTTOM_MAR] - line_no;
            break;
        } /* end switch */
else if (cmd == LEFT  ||  cmd == RIGHT)
    switch(amt[0])
        {
        case 'd':
            n = rowcol[nfield] [RIGHT_MAR] -
                rowcol[nfield] [LEFT_MAR];
            break;
        case 'h':
            n = (rowcol[nfield] [RIGHT_MAR] -
                rowcol[nfield] [LEFT_MAR]) / 2;
            break;
        case 'm':
            n = -1;
            break;
        case 'p':
            n = (rowcol[nfield] [RIGHT_MAR] -
                rowcol[nfield] [LEFT_MAR]) + 1;
            break;
        case 'c':
            if (cmd == LEFT)
                toright = !toright;
            if (toright)
                n = col_no - rowcol[nfield] [LEFT_MAR];
            else
                n = rowcol[nfield] [RIGHT_MAR] - col_no;
            break;
        } /* end switch */
else if (cmd == LOCATE)
    n = 1;

return(n);
} /* end cmdparm */
