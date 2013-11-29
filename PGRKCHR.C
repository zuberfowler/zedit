#include <ctype.h>
#include "zedit.h"

void  pgrkchr(
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
/* Process character by character changes to the screen for Greek     */
/* charset.                                                           */
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
extern char  grkchar[128] [14];

char  saveovr;
enum csrfunc  dirforw;
int  f;


/* checks done on preceding letter */
if (toright)
    {
    entfield(leftcsr, toright, nfield, rowcol, line_no, col_no);
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

/* save its current status */
saveovr = inptext[OVR] [*line_no] [*col_no];


if ((inptext[SRP] [*line_no] [*col_no] & SRP_MASK) == SRP_GREEK)
{  /* is a Greek letter, no indentation this block */

if (inptext[TXT] [*line_no] [*col_no] == ALPHA   ||
    inptext[TXT] [*line_no] [*col_no] == EPSILON ||
    inptext[TXT] [*line_no] [*col_no] == ETA     ||
    inptext[TXT] [*line_no] [*col_no] == IOTA    ||
    inptext[TXT] [*line_no] [*col_no] == OMICRON ||
    inptext[TXT] [*line_no] [*col_no] == UPSILON ||
    inptext[TXT] [*line_no] [*col_no] == OMEGA   ||
    inptext[TXT] [*line_no] [*col_no] == BLANK)
    /* then */
    switch(inpt)
        {
        case IOTASUB:
            if (inptext[TXT] [*line_no] [*col_no] == ALPHA ||
                inptext[TXT] [*line_no] [*col_no] == ETA   ||
                inptext[TXT] [*line_no] [*col_no] == OMEGA ||
                inptext[TXT] [*line_no] [*col_no] == BLANK)
                /* then */
                inptext[OVR] [*line_no] [*col_no] |= OVR_IOTASUB;
            break;
        case ACUTE:
            inptext[OVR] [*line_no] [*col_no] |= OVR_ACUTE;
            /* turn off the other accent flags if on */
            inptext[OVR] [*line_no] [*col_no] &= ~OVR_CIRCUMFLEX;
            inptext[OVR] [*line_no] [*col_no] &= ~OVR_GRAVE;
            break;
        case CIRCUMFLEX:
            inptext[OVR] [*line_no] [*col_no] |= OVR_CIRCUMFLEX;
            /* turn off the other accent flags if on */
            inptext[OVR] [*line_no] [*col_no] &= ~OVR_ACUTE;
            inptext[OVR] [*line_no] [*col_no] &= ~OVR_GRAVE;
            break;
        case GRAVE:
            inptext[OVR] [*line_no] [*col_no] |= OVR_GRAVE;
            /* turn off the other accent flags if on */
            inptext[OVR] [*line_no] [*col_no] &= ~OVR_ACUTE;
            inptext[OVR] [*line_no] [*col_no] &= ~OVR_CIRCUMFLEX;
            break;
        case UMLAUT:
            if (inptext[TXT] [*line_no] [*col_no] == IOTA    ||
                inptext[TXT] [*line_no] [*col_no] == UPSILON ||
                inptext[TXT] [*line_no] [*col_no] == BLANK)
                /* then */
                inptext[OVR] [*line_no] [*col_no] |= OVR_UMLAUT;
            break;
        case SMOOTH:
            inptext[OVR] [*line_no] [*col_no] |= OVR_SMOOTH;
            /* turn off the other breathing flag if on */
            inptext[OVR] [*line_no] [*col_no] &= ~OVR_GRAVE;
            break;
        case ROUGH:
            inptext[OVR] [*line_no] [*col_no] |= OVR_ROUGH;
            /* turn off the other breathing flag if on */
            inptext[OVR] [*line_no] [*col_no] &= ~OVR_SMOOTH;
            break;
        case SIGMATERM:
            entfield(dirforw, toright, nfield, rowcol, line_no, col_no);
            inptext[SRP] [*line_no] [*col_no] = SRP_GREEK;
            inptext[TXT] [*line_no] [*col_no] = SIGMA;
            inptext[OVR] [*line_no] [*col_no] = OVR_SIGMATERM;
            break;
        } /* end switch */
else
    switch(inpt)
        {
        case ROUGH:
            if (inptext[TXT] [*line_no] [*col_no] == RHO)
                inptext[OVR] [*line_no] [*col_no] = OVR_ROUGH;
            break;
        case SIGMATERM:
            if (inptext[TXT] [*line_no] [*col_no] == SIGMA)
                inptext[OVR] [*line_no] [*col_no] = OVR_SIGMATERM;
            break;
        default:
            if (inptext[TXT] [*line_no] [*col_no] == SIGMA  &&
               !(toright  &&  *col_no == rowcol[nfield] [RIGHT_MAR])  &&
               !(!toright  &&  *col_no == rowcol[nfield] [LEFT_MAR])  &&
               shift != EXCLMSG)
                if (inptext[OVR] [*line_no] [*col_no] == OVR_SIGMATERM)
                    {
                    if (isalpha(inpt))
                        dispmsg(posptr, PGRKCHR_MSG1);
                    } /* end then */
                else
                    if (!isalpha(inpt))
                        dispmsg(posptr, PGRKCHR_MSG2);
            break;
        } /* end switch */

}  /* end then, is a Greek letter, no indentation this block */


if (saveovr == inptext[OVR] [*line_no] [*col_no])
    {
    entfield(dirforw, toright, nfield, rowcol, line_no, col_no);

    if (shift & INS_LOCK)
        if ((f = inschar(posptr, toright, rowcol, *line_no, *col_no,
            inptext)) < 0)
            return;

    inptext[SRP] [*line_no] [*col_no] = SRP_GREEK;

    switch(inpt)
        {
        case ACUTE:
            inptext[TXT] [*line_no] [*col_no] = BLANK;
            inptext[OVR] [*line_no] [*col_no] = OVR_ACUTE;
            break;
        case CIRCUMFLEX:
            inptext[TXT] [*line_no] [*col_no] = BLANK;
            inptext[OVR] [*line_no] [*col_no] = OVR_CIRCUMFLEX;
            break;
        case GRAVE:
            inptext[TXT] [*line_no] [*col_no] = BLANK;
            inptext[OVR] [*line_no] [*col_no] = OVR_GRAVE;
            break;
        case UMLAUT:
            inptext[TXT] [*line_no] [*col_no] = BLANK;
            inptext[OVR] [*line_no] [*col_no] = OVR_UMLAUT;
            break;
        case SMOOTH:
            inptext[TXT] [*line_no] [*col_no] = BLANK;
            inptext[OVR] [*line_no] [*col_no] = OVR_SMOOTH;
            break;
        case ROUGH:
            inptext[TXT] [*line_no] [*col_no] = BLANK;
            inptext[OVR] [*line_no] [*col_no] = OVR_ROUGH;
            break;
        case IOTASUB:
            inptext[TXT] [*line_no] [*col_no] = BLANK;
            inptext[OVR] [*line_no] [*col_no] = OVR_IOTASUB;
            break;
        case SIGMATERM:
            inptext[TXT] [*line_no] [*col_no] = SIGMA;
            inptext[OVR] [*line_no] [*col_no] = OVR_SIGMATERM;
            break;
        default:
            inptext[TXT] [*line_no] [*col_no] = (char) inpt;
            inptext[OVR] [*line_no] [*col_no] = 0x00;
            break;
        } /* end switch */

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
            dispchr(posptr, (char) inpt, *line_no, *col_no, grkchar);
            if (display == YESXGA)
                xga8514(posptr, *line_no, *col_no);
            } /* end else */
    } /* end then */
else
    if (display)
        {
        rdspgrk(posptr, *line_no, *col_no, inptext);
        if (display == YESXGA)
            xga8514(posptr, *line_no, *col_no);
        } /* end then, else */


entfield(dirforw, toright, nfield, rowcol, line_no, col_no);

} /* end pgrkchr */
