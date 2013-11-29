#include "zedit.h"

void  promchr(
              union both_scr  *posptr,
              int  inpt,
              unsigned int  shift,
              int  toright,
              int  nfield,
              int  rowcol[] [5],
              int  *line_no,
              int  *col_no,
              char  inptext[] [25] [80],
              unsigned int  display)
/**********************************************************************/
/*                                                                    */
/* Process character by character changes to the screen for ROM       */
/* graphic charset.                                                   */
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
enum csrfunc  dirforw;
int  f;


/* checks are done on preceding character */
if (toright)
    {
    entfield(leftcsr, toright, nfield, rowcol, line_no, col_no);
    if (inpt == CNTL_UNDERLINE  &&
        inptext[OVR] [*line_no] [*col_no] == OVR_UNDERLINE)
        entfield(rightcsr, toright, nfield, rowcol, line_no, col_no);
    dirforw = rightcsr;
    } /* end then */
else
    if (shift & INS_LOCK)
        dirforw = nopcsr;
    else
        {
        entfield(rightcsr, toright, nfield, rowcol, line_no, col_no);
        dirforw = leftcsr;
        } /* end else */

if (inpt == CNTL_UNDERLINE  &&
    (inptext[SRP] [*line_no] [*col_no] & SRP_MASK) == SRP_ROMCHAR)
    {
    if (display)
        {
        ovr8chr(posptr, UNDERLINE, *line_no, *col_no);
        if (display == YESXGA)
            xga8514(posptr, *line_no, *col_no);
        } /* end then */
    inptext[OVR] [*line_no] [*col_no] = OVR_UNDERLINE;
    } /* end then */
else
    {
    entfield(dirforw, toright, nfield, rowcol, line_no, col_no);

    if (shift & INS_LOCK)
        if ((f = inschar(posptr, toright, rowcol, *line_no, *col_no,
            inptext)) < 0)
            return;

    inptext[SRP] [*line_no] [*col_no] = SRP_ROMCHAR;
    inptext[TXT] [*line_no] [*col_no] = (char) inpt;
    inptext[OVR] [*line_no] [*col_no] = 0x00;

    if (display)
        if (shift & INS_LOCK)
            {
            rdsplin(posptr, *line_no, rowcol[f] [LEFT_MAR],
                rowcol[f] [RIGHT_MAR], inptext);
            if (display == YESXGA)
                xga8514(posptr, *line_no, RDSPLIN);
            } /* end then */
        else
            {
            dsp8chr(posptr, (char) inpt, *line_no, *col_no);
            if (display == YESXGA)
                xga8514(posptr, *line_no, *col_no);
            } /* end else, then */
    } /* end else */


entfield(dirforw, toright, nfield, rowcol, line_no, col_no);

} /* end promchr */
