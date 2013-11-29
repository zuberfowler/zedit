#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zedit.h"

#ifdef OS2
#define INCL_DOS
#define INCL_NOPMAPI
#include <os2.h>
#endif

void LINKMSC  zedpbuf(
              union both_scr  *posptr,
              int  maxlrecl,
              register struct bufline  *ptr,
              int  rightmar)
/**********************************************************************/
/*                                                                    */
/* Print routine for double high character set data.                  */
/*                                                                    */
/* This routine is the start of the zedit print command.  The print   */
/* command comes via the misccmd routine.                             */
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
extern char  outfile[];
extern unsigned int  prtmode;
#ifdef OS2
extern long  sem_pr;
#endif

static char  grkover[] = {ACUTE, CIRCUMFLEX, GRAVE, SMOOTH, ROUGH,
    IOTASUB, UMLAUT, '\0'};

static char  latover[] = {ACUTE, CIRCUMFLEX, LGRAVE, UNDERLINE, TILDE,
    DOT, CEDILLA, UMLAUT, BREVE, SLASH, '\0'};
static char  c_dacute[]  = " oOuU";

static char  hebover[] = {PATHAH, SEGHOL, HIREQ, QIBBUS, QAMES, SERE,
    HOLEM, SHEWA, DAGESH, RAPHE, '\0'};
static char  hebterm[] = {KAPH_TERM, MEM_TERM, NUN_TERM, PE_TERM,
    SADHE_TERM, '\0'};
static char  hebd72[] = {GIMEL, ZAYIN, SADHE_TERM, '\0'};
static char  hebd74[] = {HE, MEM, MEM_TERM, SAMEKH, QOPH, TAW, '\0'};
static char  hebd75[] = {TETH, PE, PE_TERM, '\0'};
static char  hebd76[] = {SHIN, SIN, '\0'};

FILE  *prn;

register int  where;
int  toright;
int  amode;
char  *prbuf;
char  lastpr;
char  tchar;


prbuf = (char *) malloc(maxlrecl);
if (!prbuf)
    zfinish(posptr, no_storage);

if (prtmode & PSCRPT)
    {
    prn = fopen(outfile, NEW_OUTPUT);
    if (!prn)
        zfinish(posptr, open_out);
    zedppsf(prn);
    } /* end then */
else
    {
    prn = fopen(outfile, NEW_OUTBIN);
    if (!prn)
        zfinish(posptr, open_out);
    /* switch printer to 24/216 (8/72) line spacing (no gap) */
    zedplsp(prn);
    if ((prtmode & PRDENS)  &&  !(prtmode & ALTCDE))
        zedpx24(prn);
    } /* end else */

toright = YES;
amode = BUF_ASCII;
lastpr = BLANK;

for ( ; ptr -> next; ptr = ptr -> next)
    {
    if (ptr -> status & ST_PROT)
        continue;

    amode = ptr -> script;
    if (amode == BUF_HEBREW)
        toright = NO;
    else
        toright = YES;
    where = 0;

    while(ptr -> bline[where])
        {
        while(ptr -> bline[where] == PRECDR)
            {
            ++where;
            switch(ptr -> bline[where])
                {
                case BUF_HEBREW:
                    amode = ptr -> bline[where];
                    toright = NO;
                    break;
                case BUF_CHGDIR:
                    toright = !toright;
                    break;
                default:
                    amode = ptr -> bline[where];
                    toright = YES;
                    break;
                } /* end switch */
            ++where;
            } /* end while */

        switch(amode)
            {
            case BUF_ASCII:
                if (ptr -> bline[where] == CNTL_UNDERLINE)
                    {
                    zedppre(maxlrecl, prn, rightmar, amode, toright,
                        '\b', prbuf);
                    zedppre(maxlrecl, prn, rightmar, amode, toright,
                        UNDERLINE, prbuf);
                    } /* end then */
                else
                    zedppre(maxlrecl, prn, rightmar, amode, toright,
                        ptr -> bline[where], prbuf);
                break;
            case BUF_LATIN:
                if (strchr(latover, ptr -> bline[where]))
                    {
                    switch(ptr -> bline[where])
                        {
                        case SLASH:
                            if (prtmode & PSCRPT)
                                tchar = SLASH_CH;
                            else
                                tchar = SLASH;
                            break;
                        case DOT:
                            if (prtmode & PSCRPT)
                                switch(lastpr)
                                    {
                                    case ' ':
                                    case 'a':
                                    case 'A':
                                    case 'u':
                                    case 'U':
                                        tchar = OVERCIR_CH;
                                        break;
                                    case 'c':
                                    case 'C':
                                    case 'g':
                                    case 'G':
                                    case 'z':
                                    case 'Z':
                                    case 'I':
                                        tchar = OVERDOT_CH;
                                        break;
                                    case 'L':
                                    case 'l':
                                        tchar = MIDDOT_CH;
                                        break;
                                    } /* end switch, then */
                            else
                                /* cannot handle middle dot on l */
                                if (lastpr == 'l'  ||  lastpr == 'L')
                                    tchar = ' ';
                                else
                                    tchar = ptr -> bline[where];
                            break;
                        case CEDILLA:
                            if (prtmode & PSCRPT)
                                {
                                if (strchr(c_dacute, lastpr))
                                    tchar = DOUBLEAC_CH;
                                else
                                    tchar = CEDILLA_CH;
                                } /* end then */
                            else
                            /* substitute the regular double quote */
                            /* for the double acute; overcircle is */
                            /* the same as the overdot in here     */
                                if (strchr(c_dacute, lastpr))
                                    tchar = '"';
                                else
                                    tchar = ptr -> bline[where];
                            break;
                        case UMLAUT:
                            if (prtmode & PSCRPT)
                                tchar = UMLAUT_CH;
                            else
                                tchar = ptr -> bline[where];
                            break;
                        case BREVE:
                            if (prtmode & PSCRPT)
                                tchar = BREVE_CH;
                            else
                                tchar = ptr -> bline[where];
                            break;
                        default:
                            tchar = ptr -> bline[where];
                            break;
                        } /* end switch */
                    zedppre(maxlrecl, prn, rightmar, amode, toright,
                        '\b', prbuf);
                    zedppre(maxlrecl, prn, rightmar, amode, toright,
                        tchar, prbuf);
                    } /* end then */
                else
                    {
                    if (prtmode & PSCRPT)
                        {
                        /* make character substitutions (PSCRPT) */
                        switch(ptr -> bline[where])
                            {
                            case C_AE:
                                tchar = C_AE_CH;
                                break;
                            case S_AE:
                                tchar = S_AE_CH;
                                break;
                            case C_OE:
                                tchar = C_OE_CH;
                                break;
                            case S_OE:
                                tchar = S_OE_CH;
                                break;
                            case C_THORN:
                                tchar = C_THORN_CH;
                                break;
                            case S_THORN:
                                tchar = S_THORN_CH;
                                break;
                            case ETH:
                                tchar = ETH_CH;
                                break;
                            default:
                                tchar = ptr -> bline[where];
                                break;
                            } /* end switch */
                        } /* end then (PSCRPT) */
                    else
                        tchar = ptr -> bline[where];
                    lastpr = ptr -> bline[where];
                    zedppre(maxlrecl, prn, rightmar, amode, toright,
                        tchar, prbuf);
                    } /* end else */
                break;
            case BUF_ROMCHAR:
                if (ptr -> bline[where] == CNTL_UNDERLINE)
                    {
                    zedppre(maxlrecl, prn, rightmar, amode, toright,
                        '\b', prbuf);
                    zedppre(maxlrecl, prn, rightmar, amode, toright,
                        UNDERLINE, prbuf);
                    } /* end then */
                else
                    zedppre(maxlrecl, prn, rightmar, amode, toright,
                        ptr -> bline[where], prbuf);
                break;
            case BUF_GREEK:
                if (strchr(grkover, ptr -> bline[where]))
                    {
                    zedppre(maxlrecl, prn, rightmar, amode, toright,
                        '\b', prbuf);
                    zedppre(maxlrecl, prn, rightmar, amode, toright,
                        ptr -> bline[where], prbuf);
                    } /* end then */
                else if (ptr -> bline[where] == SIGMATERM)
                    {
                    zedppre(0, prn, rightmar, amode, toright,
                        '\b', prbuf);
                    zedppre(maxlrecl, prn, rightmar, amode, toright,
                        ptr -> bline[where], prbuf);
                    } /* end then */
                else
                    zedppre(maxlrecl, prn, rightmar, amode, toright,
                        ptr -> bline[where], prbuf);
                break;
            case BUF_HEBREW:
                if (strchr(hebover, ptr -> bline[where]))
                    {
                    switch(ptr -> bline[where])
                        {
                        case HOLEM:
                            if (lastpr == WAW)
                                tchar = HOLEM26;
                            else
                                tchar = ptr -> bline[where];
                            break;
                        case QAMES:
                            if (lastpr == KAPH_TERM)
                                tchar = QAMES_UP;
                            else
                                {
                                if (ptr -> bline[where+1] ==
                                    QAMES_KATUPH)
                                    ++where;
                                tchar = ptr -> bline[where];
                                } /* end else */
                            break;
                        case SHEWA:
                            if (lastpr == KAPH_TERM)
                                tchar = SHEWA_UP;
                            else
                                tchar = ptr -> bline[where];
                            break;
                        case DAGESH:
                            if (strchr(hebd72, lastpr))
                                tchar = DAGESH72;
                            else if (strchr(hebd74, lastpr))
                                tchar = DAGESH74;
                            else if (strchr(hebd75, lastpr))
                                tchar = DAGESH75;
                            else if (strchr(hebd76, lastpr))
                                tchar = DAGESH76;
                            else if (lastpr == SADHE)
                                tchar = DAGESH71;
                            else
                                tchar = ptr -> bline[where];
                            break;
                        default:
                            tchar = ptr -> bline[where];
                            break;
                        } /* end switch */
                    zedppre(maxlrecl, prn, rightmar, amode, toright,
                        '\b', prbuf);
                    zedppre(maxlrecl, prn, rightmar, amode, toright,
                        tchar, prbuf);
                    } /* end then */
                else if (strchr(hebterm, ptr -> bline[where]))
                    {
                    lastpr = ptr -> bline[where];
                    zedppre(0, prn, rightmar, amode, toright,
                        '\b', prbuf);
                    zedppre(maxlrecl, prn, rightmar, amode, toright,
                        ptr -> bline[where], prbuf);
                    } /* end then */
                else
                    {
                    lastpr = ptr -> bline[where];
                    zedppre(maxlrecl, prn, rightmar, amode, toright,
                        ptr -> bline[where], prbuf);
                    } /* end else */
                break;
            } /* end switch */

        ++where;
        } /* end while */
    } /* end for */

/* reset printer to its builtin character set */

if (prtmode & PSCRPT)
    /* flush buffer and produce final "showpage" */
    zedppre(maxlrecl, prn, rightmar, amode, toright, 0x1A, prbuf);
else
    zedprom(prn);

free(prbuf);
fputc('\f', prn);
fclose(prn);

#ifdef OS2
DosSemClear(&sem_pr);
#endif

} /* end zedpbuf */
