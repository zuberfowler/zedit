#include <string.h>
#include "zedit.h"

void  rdspheb(
              union both_scr  *posptr,
              int  line_no,
              int  col_no,
              char  inptext[] [25] [80])
/**********************************************************************/
/*                                                                    */
/* Redisplay Hebrew character on screen including any overlays.       */
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
extern char  hebchar[128] [14];

char  conflict[] = {TRP_DARGA, TRP_MAHPAK, TRP_SILLUQ, TRP_KEPULA,
    TRP_MEREKA, TRP_TIPHA, TRP_MUNAH, TRP_GALGAL, TRP_TEBIR,
    TRP_ATNAH};
int  adjust;
char  upcase;
char  accent;
char  over;


/* display base character */
if (inptext[OVR] [line_no] [col_no] & OVR_TERM)
    upcase = (char) ('A' - 'a');
else
    upcase = '\0';

dispchr(posptr, (char) (inptext[TXT] [line_no] [col_no] + upcase),
    line_no, col_no, hebchar);

/* determine if accented and if possible conflict with vowel */
accent = (char) (inptext[SRP] [line_no] [col_no] & TRP_MASK);
if (strchr(conflict, accent))
    adjust = YES;
else
    adjust = NO;

/* display overlay vowel character */
over = '\0';
switch(inptext[OVR] [line_no] [col_no] & OVR_LFTMASK)
    {
    case OVR_PATHAH:
        if (adjust)
            over = PATHAH_RT;
        else
            over = PATHAH;
        break;
    case OVR_SEGHOL:
        if (adjust)
            over = SEGHOL_RT;
        else
            over = SEGHOL;
        break;
    case OVR_HIREQ:
        if (adjust)
            over = HIREQ_RT;
        else
            over = HIREQ;
        break;
    case OVR_QIBBUS:
        if (adjust)
            over = QIBBUS_RT;
        else
            over = QIBBUS;
        break;
    case OVR_QAMES:
        if (inptext[TXT] [line_no] [col_no] == KAPH  &&
           (inptext[OVR] [line_no] [col_no] & OVR_TERM))
            over = QAMES_UP;
        else if (adjust)
            over = QAMES_RT;
        else
            over = QAMES;
        break;
    case OVR_SERE:
        if (adjust)
            over = SERE_RT;
        else
            over = SERE;
        break;
    case OVR_HOLEM:
        if (inptext[TXT] [line_no] [col_no] == WAW)
            over = HOLEM26;
        else
            over = HOLEM;
        break;
    case OVR_KATUPH:
        if (inptext[TXT] [line_no] [col_no] == KAPH  &&
           (inptext[OVR] [line_no] [col_no] & OVR_TERM))
            over = QAMES_UP;
        else if (adjust)
            over = QAMES_KRT;
        else
            over = QAMES_KATUPH;
        break;
    } /* end switch */

if (over)
    overchr(posptr, over, line_no, col_no, hebchar, NO);

/* display overlay symbol character */
if (inptext[OVR] [line_no] [col_no] & OVR_SHEWA)
    {
    if (inptext[TXT] [line_no] [col_no] == KAPH  &&
        (inptext[OVR] [line_no] [col_no] & OVR_TERM))
        over = SHEWA_UP;
    else
        over = SHEWA;

    overchr(posptr, over, line_no, col_no, hebchar, NO);
    } /* end then */

if (inptext[OVR] [line_no] [col_no] & OVR_DAGESH)
    {
    if (inptext[TXT] [line_no] [col_no] == GIMEL  ||
        inptext[TXT] [line_no] [col_no] == ZAYIN  ||
        (inptext[TXT] [line_no] [col_no] == SADHE  &&
        (inptext[OVR] [line_no] [col_no] & OVR_TERM)))
        over = DAGESH72;
    else if (inptext[TXT] [line_no] [col_no] == HE  ||
        inptext[TXT] [line_no] [col_no] == MEM  ||
        /* also MEM_TERM implied */
        inptext[TXT] [line_no] [col_no] == SAMEKH  ||
        inptext[TXT] [line_no] [col_no] == QOPH  ||
        inptext[TXT] [line_no] [col_no] == TAW)
        over = DAGESH74;
    else if (inptext[TXT] [line_no] [col_no] == TETH  ||
        inptext[TXT] [line_no] [col_no] == PE)
        /* also PE_TERM implied */
        over = DAGESH75;
    else if (inptext[TXT] [line_no] [col_no] == SHIN  ||
        inptext[TXT] [line_no] [col_no] == SIN)
        over = DAGESH76;
    else if (inptext[TXT] [line_no] [col_no] == SADHE  &&
        !(inptext[OVR] [line_no] [col_no] & OVR_TERM))
        over = DAGESH71;
    else over = DAGESH;

    overchr(posptr, over, line_no, col_no, hebchar, NO);
    } /* end then */

if (inptext[OVR] [line_no] [col_no] & OVR_RAPHE)
    overchr(posptr, RAPHE, line_no, col_no, hebchar, NO);

/* display overlay trope character */
switch(accent)
    {
    case '\0':
        over = '\0';
        break;
    case TRP_MAHPAKATUM:
        over = MAHPAKATUM;
        break;
    case TRP_SEGHOLTA:
        over = SEGHOLTA;
        break;
    case TRP_GERES:
        over = GERES;
        break;
    case TRP_GARSAYIM:
        over = GARSAYIM;
        break;
    case TRP_SILLUQ:
        over = SILLUQ;
        break;
    case TRP_REBIA:
        over = REBIA;
        break;
    case TRP_ZAQEF:
        over = ZAQEF;
        break;
    case TRP_ZAQEFMAG:
        over = ZAQEF_MAG;
        break;
    case TRP_KEPULA:
        over = KEPULA;
        break;
    case TRP_MEREKA:
        over = MEREKA;
        break;
    case TRP_TIPHA:
        over = TIPHA;
        break;
    case TRP_MUNAH:
        over = MUNAH;
        break;
    case TRP_GALGAL:
        over = GALGAL;
        break;
    case TRP_ILLUJ:
        over = ILLUJ;
        break;
    case TRP_TEBIR:
        over = TEBIR;
        break;
    case TRP_DEHI:
        over = DEHI;
        break;
    case TRP_SALSELET:
        over = SALSELET;
        break;
    case TRP_DARGA:
        over = DARGA;
        break;
    case TRP_PAZERMAG:
        over = PAZER_MAG;
        break;
    case TRP_PASTA:
        over = PASTA;
        break;
    case TRP_PAZER:
        over = PAZER;
        break;
    case TRP_MAHPAK:
        over = MAHPAK;
        break;
    case TRP_YETIB:
        over = YETIB;
        break;
    case TRP_ATNAH:
        over = ATNAH;
        break;
    case TRP_TELISAPAR:
        over = TELISA_PAR;
        break;
    case TRP_TELISAMAG:
        over = TELISA_MAG;
        break;
    case TRP_SINNORIT:
        over = SINNORIT;
        break;
    } /* end switch */

if (over)
    overchr(posptr, over, line_no, col_no, hebchar, NO);

} /* end rdspheb */
