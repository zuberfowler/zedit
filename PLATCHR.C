#include <string.h>
#include "zedit.h"

void  platchr(
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
/* Process character by character changes to the screen for Latin     */
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
extern char  ascchar[128] [14];

static char  c_slash[]   = " dDhHlLoO";
static char  c_acute[]   = " aAeEiIoOuUcClLnNrRsSyYzZ";
static char  c_circ[]    = " aAeEiIoOuUcCgGhHjJsS";
static char  c_grave[]   = " aAeEiIoOuU";
static char  c_tilde[]   = " aAoOnN";
static char  c_breve[]   = " aAeEuUcCdDgGlLnNrRsStTzZ";
static char  c_umlaut[]  = " aAeEiIoOuUyY";
static char  c_cedilla[] = "aAeEcCsStT";
static char  c_dacute[]  = " oOuU";

char  saveovr;
enum csrfunc  dirforw;
int  f;


/* checks are done on preceding character */
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


/* if inpt is found here then the display will be done in rdsplat */
if ((inptext[SRP] [*line_no] [*col_no] & SRP_MASK) == SRP_LATIN)
    {  /* is a Latin letter */
    switch(inpt)
        {
        case UNDERLINE:
            inptext[OVR] [*line_no] [*col_no] |= OVR_UNDERLINE;
            break;
        case SLASH:
            if (strchr(c_slash, inptext[TXT] [*line_no] [*col_no]))
                {
                inptext[OVR] [*line_no] [*col_no] &= OVR_UNDERLINE;
                inptext[OVR] [*line_no] [*col_no] |= OVR_SLASH;
                } /* end then */
            break;
        case DOT:
            switch(inptext[TXT] [*line_no] [*col_no])
                {
                case 'L':
                case 'l':
                    /* middle dot */
                    inptext[OVR] [*line_no] [*col_no] &= OVR_UNDERLINE;
                    inptext[OVR] [*line_no] [*col_no] |= OVR_DOT;
                    break;
                case 'A':
                case 'a':
                    /* over circle */
                    inptext[OVR] [*line_no] [*col_no] &=
                        (OVR_UNDERLINE | OVR_CEDILLA);
                    inptext[OVR] [*line_no] [*col_no] |= OVR_DOT;
                    break;
                case ' ':
                case 'U':
                case 'u':
                    /* over circle */
                    inptext[OVR] [*line_no] [*col_no] &= OVR_UNDERLINE;
                    inptext[OVR] [*line_no] [*col_no] |= OVR_DOT;
                    break;
                case 'C':
                case 'c':
                case 'G':
                case 'g':
                case 'I':
                case 'Z':
                case 'z':
                    /* over dot */
                    inptext[OVR] [*line_no] [*col_no] &=
                        (OVR_UNDERLINE | OVR_CEDILLA);
                    inptext[OVR] [*line_no] [*col_no] |= OVR_DOT;
                    break;
                } /* end switch */
            break;
        case ACUTE:
            if (strchr(c_acute, inptext[TXT] [*line_no] [*col_no]))
                {
                inptext[OVR] [*line_no] [*col_no] &= (OVR_UNDERLINE  |
                    OVR_CEDILLA);
                inptext[OVR] [*line_no] [*col_no] |= OVR_ACUTE;
                } /* end then */
            break;
        case CIRCUMFLEX:
            if (strchr(c_circ, inptext[TXT] [*line_no] [*col_no]))
                {
                inptext[OVR] [*line_no] [*col_no] &= (OVR_UNDERLINE  |
                    OVR_CEDILLA);
                inptext[OVR] [*line_no] [*col_no] |= OVR_CIRCUMFLEX;
                } /* end then */
            break;
        case LGRAVE:
            if (strchr(c_grave, inptext[TXT] [*line_no] [*col_no]))
                {
                inptext[OVR] [*line_no] [*col_no] &= (OVR_UNDERLINE  |
                    OVR_CEDILLA);
                inptext[OVR] [*line_no] [*col_no] |= OVR_GRAVE;
                } /* end then */
            break;
        case TILDE:
            if (strchr(c_tilde, inptext[TXT] [*line_no] [*col_no]))
                {
                inptext[OVR] [*line_no] [*col_no] &= (OVR_UNDERLINE  |
                    OVR_CEDILLA);
                inptext[OVR] [*line_no] [*col_no] |= OVR_TILDE;
                } /* end then */
            break;
        case BREVE:
            if (strchr(c_breve, inptext[TXT] [*line_no] [*col_no]))
                {
                inptext[OVR] [*line_no] [*col_no] &= (OVR_UNDERLINE  |
                    OVR_CEDILLA);
                inptext[OVR] [*line_no] [*col_no] |= OVR_BREVE;
                } /* end then */
            break;
        case UMLAUT:
            if (strchr(c_umlaut, inptext[TXT] [*line_no] [*col_no]))
                {
                inptext[OVR] [*line_no] [*col_no] &= (OVR_UNDERLINE  |
                    OVR_CEDILLA);
                inptext[OVR] [*line_no] [*col_no] |= OVR_UMLAUT;
                } /* end then */
            break;
        case CEDILLA:
            if (strchr(c_cedilla, inptext[TXT] [*line_no] [*col_no]))
                {
                inptext[OVR] [*line_no] [*col_no] |= OVR_CEDILLA;
                } /* end then */
            else if (strchr(c_dacute, inptext[TXT][*line_no][*col_no]))
                {
                inptext[OVR] [*line_no] [*col_no] &= OVR_UNDERLINE;
                inptext[OVR] [*line_no] [*col_no] |= OVR_CEDILLA;
                } /* end then, else */
            break;
        } /* end switch */
    }  /* end then, is a Latin letter */


if (saveovr == inptext[OVR] [*line_no] [*col_no])
    {
    entfield(dirforw, toright, nfield, rowcol, line_no, col_no);

    if (shift & INS_LOCK)
        if ((f = inschar(posptr, toright, rowcol, *line_no, *col_no,
            inptext)) < 0)
            return;

    inptext[SRP] [*line_no] [*col_no] = SRP_LATIN;

    switch(inpt)
        {
        case UNDERLINE:
            inptext[TXT] [*line_no] [*col_no] = BLANK;
            inptext[OVR] [*line_no] [*col_no] = OVR_UNDERLINE;
            break;
        case SLASH:
            inptext[TXT] [*line_no] [*col_no] = BLANK;
            inptext[OVR] [*line_no] [*col_no] = OVR_SLASH;
            inpt = SLASH_CH;
            break;
        case DOT:
            inptext[TXT] [*line_no] [*col_no] = BLANK;
            inptext[OVR] [*line_no] [*col_no] = OVR_DOT;
            inpt = OVERCIR_CH;
            break;
        case ACUTE:
            inptext[TXT] [*line_no] [*col_no] = BLANK;
            inptext[OVR] [*line_no] [*col_no] = OVR_ACUTE;
            break;
        case CIRCUMFLEX:
            inptext[TXT] [*line_no] [*col_no] = BLANK;
            inptext[OVR] [*line_no] [*col_no] = OVR_CIRCUMFLEX;
            break;
        case LGRAVE:
            inptext[TXT] [*line_no] [*col_no] = BLANK;
            inptext[OVR] [*line_no] [*col_no] = OVR_GRAVE;
            break;
        case TILDE:
            inptext[TXT] [*line_no] [*col_no] = BLANK;
            inptext[OVR] [*line_no] [*col_no] = OVR_TILDE;
            break;
        case BREVE:
            inptext[TXT] [*line_no] [*col_no] = BLANK;
            inptext[OVR] [*line_no] [*col_no] = OVR_BREVE;
            inpt = BREVE_CH;
            break;
        case UMLAUT:
            inptext[TXT] [*line_no] [*col_no] = BLANK;
            inptext[OVR] [*line_no] [*col_no] = OVR_UMLAUT;
            inpt = UMLAUT_CH;
            break;
        case CEDILLA:
            inptext[TXT] [*line_no] [*col_no] = BLANK;
            inptext[OVR] [*line_no] [*col_no] = OVR_CEDILLA;
            inpt = DOUBLEAC_CH;
            break;
        case C_AE:
            inptext[TXT] [*line_no] [*col_no] = (char) inpt;
            inptext[OVR] [*line_no] [*col_no] = 0x00;
            inpt = C_AE_CH;
            break;
        case S_AE:
            inptext[TXT] [*line_no] [*col_no] = (char) inpt;
            inptext[OVR] [*line_no] [*col_no] = 0x00;
            inpt = S_AE_CH;
            break;
        case C_OE:
            inptext[TXT] [*line_no] [*col_no] = (char) inpt;
            inptext[OVR] [*line_no] [*col_no] = 0x00;
            inpt = C_OE_CH;
            break;
        case S_OE:
            inptext[TXT] [*line_no] [*col_no] = (char) inpt;
            inptext[OVR] [*line_no] [*col_no] = 0x00;
            inpt = S_OE_CH;
            break;
        case C_THORN:
            inptext[TXT] [*line_no] [*col_no] = (char) inpt;
            inptext[OVR] [*line_no] [*col_no] = 0x00;
            inpt = C_THORN_CH;
            break;
        case S_THORN:
            inptext[TXT] [*line_no] [*col_no] = (char) inpt;
            inptext[OVR] [*line_no] [*col_no] = 0x00;
            inpt = S_THORN_CH;
            break;
        case ETH:
            inptext[TXT] [*line_no] [*col_no] = (char) inpt;
            inptext[OVR] [*line_no] [*col_no] = 0x00;
            inpt = ETH_CH;
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
            dispchr(posptr, (char) inpt, *line_no, *col_no, ascchar);
            if (display == YESXGA)
                xga8514(posptr, *line_no, *col_no);
            } /* end else, then */
    } /* end then */
else
    {
    if (display)
        {
        rdsplat(posptr, *line_no, *col_no, inptext);
        if (display == YESXGA)
            xga8514(posptr, *line_no, *col_no);
        } /* end then */
    if (inpt == UNDERLINE)
        entfield(dirforw, toright, nfield, rowcol, line_no, col_no);
    } /* end else */


if (inpt != UNDERLINE)
    entfield(dirforw, toright, nfield, rowcol, line_no, col_no);
else if ((inptext[SRP] [*line_no] [*col_no] & SRP_MASK) == SRP_LATIN)
    entfield(dirforw, toright, nfield, rowcol, line_no, col_no);

} /* end platchr */
