#include "zedit.h"

int  entpanl(
              union both_scr  *posptr,
              int  inpt,
              int  scan,
              unsigned int  shift,
              int  amode,
              int  toright,
              int  *line_no,
              int  *col_no,
              int  f,
              int  nfield,
              int  rowcol[] [5],
              char  inptext[] [25] [80])
/**********************************************************************/
/*                                                                    */
/* Process panel scroll type scan codes.                              */
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
static int  prtset = NO;
int  finished = YES;


switch(scan)
    {
    case FLEFT_ARROW:
        entfield(leftcsr, toright, nfield, rowcol, line_no, col_no);
    case LEFT_ARROW:
        entfield(leftcsr, toright, nfield, rowcol, line_no, col_no);
        prtset = NO;
        break;
    case FRIGHT_ARROW:
        entfield(rightcsr, toright, nfield, rowcol, line_no, col_no);
    case RIGHT_ARROW:
        entfield(rightcsr, toright, nfield, rowcol, line_no, col_no);
        prtset = NO;
        break;
    case FDOWN_ARROW:
        entfield(downcsr, toright, nfield, rowcol, line_no, col_no);
    case DOWN_ARROW:
        entfield(downcsr, toright, nfield, rowcol, line_no, col_no);
        prtset = NO;
        break;
    case FUP_ARROW:
        entfield(upcsr, toright, nfield, rowcol, line_no, col_no);
    case UP_ARROW:
        entfield(upcsr, toright, nfield, rowcol, line_no, col_no);
        prtset = NO;
        break;
    case RETURN_KEY:
        entfield(retcsr, toright, nfield, rowcol, line_no, col_no);
        prtset = NO;
        break;
    case TAB_KEY:
        if (inpt == 0x00  ||  inpt == CNTL_U)
            entfield(lefttab, toright, nfield, rowcol, line_no, col_no);
        else
            entfield(righttab, toright, nfield, rowcol, line_no,
                col_no);
        prtset = NO;
        break;
    case HOME:
        entfield(homecsr, toright, nfield, rowcol, line_no, col_no);
        prtset = NO;
        break;
    case END_KEY:
        entfield(endcsr, toright, nfield, rowcol, line_no, col_no);
        prtset = NO;
        break;
    case PRTSC:
        if (!prtset)
            scrprnt(posptr);
        else
            dispmsg(posptr, ENTPANL_MSG1);
        prtset = YES;
        break;
    case INS:
        statlin(posptr, amode, shift, toright, inptext);
        prtset = NO;
        break;
    case BACKSPACE:
        if (toright)
            entfield(leftcsr, toright, nfield, rowcol, line_no, col_no);
        else
            entfield(rightcsr, toright, nfield, rowcol, line_no,
                col_no);
        for (f = 0; *line_no > rowcol[f] [BOTTOM_MAR];  ++f)
            {;}; /* end for */
        for ( ; *col_no > rowcol[f] [RIGHT_MAR]; ++f)
            {;}; /* end for */
        if ((rowcol[f] [ATTRIB] >= RC_PROTECT) ||
            ((inptext[ATR] [*line_no] [*col_no] & ATR_PROTECT) ==
                ATR_PROTECT))
            {
            if (toright)
                entfield(rightcsr, toright, nfield, rowcol, line_no,
                    col_no);
            else
                entfield(leftcsr, toright, nfield, rowcol, line_no,
                    col_no);
            dispmsg(posptr, ENTPANL_MSG2);
            } /* end then */
        else
            {
            if (rowcol[f] [ATTRIB] == RC_NORMAL)
                /* then flag as changed */
                ++rowcol[f] [ATTRIB];
            delchar(toright, f, rowcol, *line_no, *col_no, inptext);
            rdsplin(posptr, *line_no, rowcol[f] [LEFT_MAR],
                rowcol[f] [RIGHT_MAR], inptext);
            if (graphic & XGA)
                xga8514(posptr, *line_no, RDSPLIN);
            } /* end else */
        prtset = NO;
        break;
    case DEL:
        if ((rowcol[f] [ATTRIB] >= RC_PROTECT) ||
            ((inptext[ATR] [*line_no] [*col_no] & ATR_PROTECT) ==
                ATR_PROTECT))
            dispmsg(posptr, ENTPANL_MSG2);
        else
            {
            if (rowcol[f] [ATTRIB] == RC_NORMAL)
                /* then flag as changed */
                ++rowcol[f] [ATTRIB];
            delchar(toright, f, rowcol, *line_no, *col_no, inptext);
            rdsplin(posptr, *line_no, rowcol[f] [LEFT_MAR],
                rowcol[f] [RIGHT_MAR], inptext);
            if (graphic & XGA)
                xga8514(posptr, *line_no, RDSPLIN);
            } /* end else */
        prtset = NO;
        break;
    default:
        finished = NO;
        prtset = NO;
        break;
    } /* end switch */

return(finished);
} /* end entpanl */
