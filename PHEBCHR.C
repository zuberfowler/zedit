#include <ctype.h>
#include <string.h>
#include "zedit.h"

void  phebchr(
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
/* Process character by character changes to the screen for Hebrew    */
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
/* ineligible is initialized in keyboard order */
static char  ineligible[] = {'!', '@', '*', '(', ')',
    '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', MAQQEPH, '=',
    PASEQ, '[', ']', '\\', SOPH_PASUQ, '"', '?', ',', '.', '/', '\0'};

static char  trope[] = {MAHPAKATUM, SEGHOLTA, GERES, GARSAYIM,
    SILLUQ, REBIA, ZAQEF, ZAQEF_MAG, KEPULA, MEREKA, TIPHA, MUNAH,
    GALGAL, ILLUJ, TEBIR, DEHI, SALSELET, DARGA, PAZER_MAG, PAZER,
    MAHPAK, YETIB, ATNAH, TELISA_PAR, TELISA_MAG, SINNORIT};

int  f;
enum csrfunc  dirforw;


/* checks done on preceding letter */
if (toright)
    if (shift & INS_LOCK)
        dirforw = nopcsr;
    else
        {
        entfield(leftcsr, toright, nfield, rowcol, line_no, col_no);
        dirforw = rightcsr;
        } /* end else, then */
else
    {
    entfield(rightcsr, toright, nfield, rowcol, line_no, col_no);
    dirforw = leftcsr;
    } /* end else */


if ((inptext[SRP] [*line_no] [*col_no] & SRP_MASK) == SRP_HEBREW  &&
    !strchr(ineligible, inptext[TXT] [*line_no] [*col_no]))
    {
    if (shift & INS_LOCK)
        {
        for (f = 0; *line_no > rowcol[f] [BOTTOM_MAR]; ++f)
            {;}; /* end for */
        for ( ; *col_no > rowcol[f] [RIGHT_MAR]; ++f)
            {;}; /* end for */
        } /* end then */
    switch(inpt)
        {
        /* symbols */
        case PATHAH:
            inptext[OVR] [*line_no] [*col_no] &= OVR_RHTMASK;
            inptext[OVR] [*line_no] [*col_no] |= OVR_PATHAH;
            break;
        case SEGHOL:
            inptext[OVR] [*line_no] [*col_no] &= OVR_RHTMASK;
            inptext[OVR] [*line_no] [*col_no] |= OVR_SEGHOL;
            break;
        case HIREQ:
            inptext[OVR] [*line_no] [*col_no] &= OVR_RHTMASK;
            inptext[OVR] [*line_no] [*col_no] |= OVR_HIREQ;
            break;
        case QIBBUS:
            inptext[OVR] [*line_no] [*col_no] &= OVR_RHTMASK;
            inptext[OVR] [*line_no] [*col_no] |= OVR_QIBBUS;
            break;
        case QAMES:
            inptext[OVR] [*line_no] [*col_no] &= OVR_RHTMASK;
            inptext[OVR] [*line_no] [*col_no] |= OVR_QAMES;
            break;
        case SERE:
            inptext[OVR] [*line_no] [*col_no] &= OVR_RHTMASK;
            inptext[OVR] [*line_no] [*col_no] |= OVR_SERE;
            break;
        case HOLEM:
            inptext[OVR] [*line_no] [*col_no] &= OVR_RHTMASK;
            inptext[OVR] [*line_no] [*col_no] |= OVR_HOLEM;
            break;
        case SHEWA:
            inptext[OVR] [*line_no] [*col_no] |= OVR_SHEWA;
            break;
        case DAGESH:
            if (inptext[TXT] [*line_no] [*col_no] != ALEPH  &&
                inptext[TXT] [*line_no] [*col_no] != HETH   &&
                inptext[TXT] [*line_no] [*col_no] != AYIN)
                {
                inptext[OVR] [*line_no] [*col_no] &= (~OVR_RAPHE);
                inptext[OVR] [*line_no] [*col_no] |= OVR_DAGESH;
                } /* end then */
            else
                { /* Dagesh not used with this letter */
                dispmsg(posptr, PHEBCHR_MSG1);
                return;
                } /* end else */
            break;
        case RAPHE:
            if (inptext[TXT] [*line_no] [*col_no] != ALEPH  &&
                inptext[TXT] [*line_no] [*col_no] != HE     &&
                inptext[TXT] [*line_no] [*col_no] != HETH   &&
                inptext[TXT] [*line_no] [*col_no] != AYIN   &&
                inptext[TXT] [*line_no] [*col_no] != RESH)
                {
                inptext[OVR] [*line_no] [*col_no] &= (~OVR_DAGESH);
                inptext[OVR] [*line_no] [*col_no] |= OVR_RAPHE;
                } /* end then */
            else
                { /* Raphe not used with this letter */
                dispmsg(posptr, PHEBCHR_MSG2);
                return;
                } /* end else */
            break;
        case QAMES_KATUPH:
            inptext[OVR] [*line_no] [*col_no] &= OVR_RHTMASK;
            inptext[OVR] [*line_no] [*col_no] |= OVR_KATUPH;
            break;
        /* tropes */
        case MAHPAKATUM:
            inptext[SRP] [*line_no] [*col_no] = TRP_MAHPAKATUM;
            break;
        case SEGHOLTA:
            inptext[SRP] [*line_no] [*col_no] = TRP_SEGHOLTA;
            break;
        case GERES:
            inptext[SRP] [*line_no] [*col_no] = TRP_GERES;
            break;
        case GARSAYIM:
            inptext[SRP] [*line_no] [*col_no] = TRP_GARSAYIM;
            break;
        case SILLUQ:
            inptext[SRP] [*line_no] [*col_no] = TRP_SILLUQ;
            break;
        case REBIA:
            inptext[SRP] [*line_no] [*col_no] = TRP_REBIA;
            break;
        case ZAQEF:
            inptext[SRP] [*line_no] [*col_no] = TRP_ZAQEF;
            break;
        case ZAQEF_MAG:
            inptext[SRP] [*line_no] [*col_no] = TRP_ZAQEFMAG;
            break;
        case KEPULA:
            inptext[SRP] [*line_no] [*col_no] = TRP_KEPULA;
            break;
        case MEREKA:
            inptext[SRP] [*line_no] [*col_no] = TRP_MEREKA;
            break;
        case TIPHA:
            inptext[SRP] [*line_no] [*col_no] = TRP_TIPHA;
            break;
        case MUNAH:
            inptext[SRP] [*line_no] [*col_no] = TRP_MUNAH;
            break;
        case GALGAL:
            inptext[SRP] [*line_no] [*col_no] = TRP_GALGAL;
            break;
        case ILLUJ:
            inptext[SRP] [*line_no] [*col_no] = TRP_ILLUJ;
            break;
        case TEBIR:
            inptext[SRP] [*line_no] [*col_no] = TRP_TEBIR;
            break;
        case DEHI:
            inptext[SRP] [*line_no] [*col_no] = TRP_DEHI;
            break;
        case SALSELET:
            inptext[SRP] [*line_no] [*col_no] = TRP_SALSELET;
            break;
        case DARGA:
            inptext[SRP] [*line_no] [*col_no] = TRP_DARGA;
            break;
        case PAZER_MAG:
            inptext[SRP] [*line_no] [*col_no] = TRP_PAZERMAG;
            break;
        case PAZER:
            inptext[SRP] [*line_no] [*col_no] = TRP_PAZER;
            break;
        case MAHPAK:
            inptext[SRP] [*line_no] [*col_no] = TRP_MAHPAK;
            break;
        case YETIB:
            inptext[SRP] [*line_no] [*col_no] = TRP_YETIB;
            break;
        case ATNAH:
            inptext[SRP] [*line_no] [*col_no] = TRP_ATNAH;
            break;
        case TELISA_PAR:
            inptext[SRP] [*line_no] [*col_no] = TRP_TELISAPAR;
            break;
        case TELISA_MAG:
            inptext[SRP] [*line_no] [*col_no] = TRP_TELISAMAG;
            break;
        case SINNORIT:
            inptext[SRP] [*line_no] [*col_no] = TRP_SINNORIT;
            break;
        default:
            /* if term combination stay at present position */
            if ((inptext[OVR] [*line_no] [*col_no] == 0x00)  &&
               ((inptext[TXT] [*line_no] [*col_no] == KAPH  &&
                inpt == KAPH_TERM) || (inpt == MEM_TERM  &&
                inptext[TXT] [*line_no] [*col_no] == MEM) ||
                (inptext[TXT] [*line_no] [*col_no] == NUN  &&
                inpt == NUN_TERM) || (inpt == PE_TERM  &&
                inptext[TXT] [*line_no] [*col_no] == PE) ||
                (inptext[TXT] [*line_no] [*col_no] == SADHE  &&
                inpt == SADHE_TERM)))
                break;
            if (!toright  &&  shift != EXCLMSG)
                if (inptext[OVR] [*line_no] [*col_no] & OVR_TERM  &&
                  isalpha(inpt)  &&
                  !(*col_no == rowcol[nfield][LEFT_MAR]))
                    { /* terminal char inside of word */
                    dispmsg(posptr, PHEBCHR_MSG3);
                    return;
                    } /* end then */
                else if ((inpt == BLANK  ||
                  inpt == SOPH_PASUQ  ||  inpt == MAQQEPH)  &&
                 (inptext[TXT] [*line_no] [*col_no] == KAPH  ||
                  inptext[TXT] [*line_no] [*col_no] == MEM   ||
                  inptext[TXT] [*line_no] [*col_no] == NUN   ||
                  inptext[TXT] [*line_no] [*col_no] == PE    ||
                  inptext[TXT] [*line_no] [*col_no] == SADHE)  &&
                  !(inptext[OVR] [*line_no] [*col_no] & OVR_TERM)  &&
                  !(*col_no == rowcol[nfield][LEFT_MAR]))
                    { /* non terminal used at end of word */
                    dispmsg(posptr, PHEBCHR_MSG4);
                    return;
                    } /* end then, else */
            entfield(dirforw, toright, nfield, rowcol, line_no, col_no);
            if (shift & INS_LOCK)
                if ((f = inschar(posptr, toright, rowcol, *line_no,
                    *col_no, inptext)) < 0)
                    return;
            inptext[OVR] [*line_no] [*col_no] = 0x00;
            break;
        } /* end switch */
    } /* end then */
else
    {
    entfield(dirforw, toright, nfield, rowcol, line_no, col_no);
    if (shift & INS_LOCK)
        if ((f = inschar(posptr, toright, rowcol, *line_no, *col_no,
            inptext)) < 0)
            return;
    inptext[OVR] [*line_no] [*col_no] = 0x00;
    } /* end else */

if ((inptext[OVR] [*line_no] [*col_no] == 0x00)  &&
    !strchr(trope, inpt))
    switch(inpt)
        {
        case KAPH_TERM:
            inptext[TXT] [*line_no] [*col_no] = KAPH;
            inptext[OVR] [*line_no] [*col_no] |= OVR_TERM;
            break;
        case MEM_TERM:
            inptext[TXT] [*line_no] [*col_no] = MEM;
            inptext[OVR] [*line_no] [*col_no] |= OVR_TERM;
            break;
        case NUN_TERM:
            inptext[TXT] [*line_no] [*col_no] = NUN;
            inptext[OVR] [*line_no] [*col_no] |= OVR_TERM;
            break;
        case PE_TERM:
            inptext[TXT] [*line_no] [*col_no] = PE;
            inptext[OVR] [*line_no] [*col_no] |= OVR_TERM;
            break;
        case SADHE_TERM:
            inptext[TXT] [*line_no] [*col_no] = SADHE;
            inptext[OVR] [*line_no] [*col_no] |= OVR_TERM;
            break;
        default:
            inptext[TXT] [*line_no] [*col_no] = (char) inpt;
            break;
        } /* end switch */

inptext[SRP] [*line_no] [*col_no] = (char) (SRP_HEBREW  |
    (inptext[SRP] [*line_no] [*col_no] & TRP_MASK));

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
        rdspheb(posptr, *line_no, *col_no, inptext);
        if (display == YESXGA)
            xga8514(posptr, *line_no, *col_no);
        } /* end else, then */


entfield(dirforw, toright, nfield, rowcol, line_no, col_no);

} /* end phebchr */
