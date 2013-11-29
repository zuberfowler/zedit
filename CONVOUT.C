#include <string.h>
#include "zedit.h"

void  convout(
              int  len_in,
              char  txt_in[],
              char  srp_in[],
              char  ovr_in[],
              int  prevsrp,
              char  lineout[],
              register int  where,
              char  save[])
/**********************************************************************/
/*                                                                    */
/* Convert one line from triplex to buffer format.                    */
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
static char  bufid[8] = {BUF_ASCII, BUF_ASCII, BUF_ROMCHAR, BUF_GREEK,
    BUF_HEBREW, BUF_LATIN, BUF_UNUSED, BUF_CHGDIR};

register int  i;
int  blankln = YES;
int  hebrew_start = NO;
int  first = YES;
int  force = NO;
int  toright = NO;
int  srp;


srp = prevsrp;

/* scan any of line scrolled off the screen to the left */
for (i = 0; i < where; ++i)
    {
    if (lineout[i] == PRECDR)
        {
        ++i;
        switch(lineout[i])
            {
            case BUF_HEBREW:
                force = YES;
                prevsrp = lineout[i];
                break;
            case BUF_CHGDIR:
                force = NO;
                toright = YES;
                break;
            default:
                toright = YES;
                prevsrp = lineout[i];
                break;
            } /* end switch */
        } /* end then */
    else if (lineout[i] > ' ')
        blankln = NO;
    } /* end for */

if (toright)
    {
    if (blankln)
        toright = NO;
    } /* end then */
else if (force)
    {
    if (blankln)
        force = NO;
    } /* end then, else */
else if (!blankln)
    {
    if (srp == BUF_HEBREW)
        force = YES;
    else
        toright = YES;
    } /* end then, else */

if (!force)
    {
    /* scan the line coming out of the screen buffer */
    for (i = 0; i <= len_in  &&  !toright; ++i)
        {
        if (prevsrp == BUF_HEBREW  &&  first  &&  txt_in[i] > ' ')
            {
            first = NO;
            if ((srp_in[i] & SRP_MASK) == SRP_HEBREW)
                hebrew_start = YES;
            } /* end then */

        if (txt_in[i] > ' ')
            {
            blankln = NO;
            if ((srp_in[i] & SRP_MASK) != SRP_HEBREW)
                toright = YES;
            } /* end then */
        } /* end for */

    /* scan any of line in the save area (right, off of screen) */
    for (i = 0; !toright  &&  save[i]; ++i)
        {
        if (save[i] == PRECDR)
            {
            ++i;
            switch(save[i])
                {
                case BUF_HEBREW:
                    /* ignore this */
                    break;
                case BUF_CHGDIR:
                    /* keep its direction since it not on screen */
                    toright = YES;
                    break;
                default:
                    toright = YES;
                    break;
                } /* end switch */
            } /* end then */
        else if (save[i] > ' ')
            blankln = NO;
        } /* end for */

    if (!toright)
        if (blankln)
            toright = YES;
        else
            {
            srp = lastsrp(BUF_HEBREW, lineout);
            if (srp != BUF_HEBREW  &&  save[0])
                /* text was found in save which is not Hebrew */
                /* the screen buffer contains only Hebrew, however */
                toright = YES;
            } /* end else, then */
    } /* end then */


if (toright)
    {
    srp = lastsrp(srp, lineout);
    if (hebrew_start)
        {
        /* mixed line following pure Hebrew line */
        lineout[where++] = PRECDR;
        lineout[where++] = BUF_HEBREW;
        lineout[where++] = PRECDR;
        lineout[where++] = BUF_CHGDIR;
        } /* end then */

    for (i = 0; i <= len_in; ++i)
        {
        if ((srp_in[i] & SRP_MASK) != ((char) prevsrp & SRP_MASK)  &&
            (txt_in[i] > ' '  ||  ovr_in[i] != 0x00))
            {
            lineout[where++] = PRECDR;
            lineout[where++] = bufid[srp_in[i] & SRP_MASK];
            prevsrp = bufid[srp_in[i] & SRP_MASK];
            if (prevsrp == BUF_HEBREW)
                {
                lineout[where++] = PRECDR;
                lineout[where++] = BUF_CHGDIR;
                } /* end then */
            } /* end then */

        if (txt_in[i])
            lineout[where++] = txt_in[i];
        else
            lineout[where++] = ' ';

        if (ovr_in[i])
            switch(prevsrp)
                {
                case BUF_ASCII:
                    lineout[where++] = CNTL_UNDERLINE;
                    break;
                case BUF_ROMCHAR:
                    lineout[where++] = CNTL_UNDERLINE;
                    break;
                case BUF_GREEK:
                    if (ovr_in[i] == OVR_SIGMATERM)
                        lineout[where++] = SIGMATERM;
                    else
                        {
                        if (ovr_in[i] & OVR_ACUTE)
                            lineout[where++] = ACUTE;
                        else if (ovr_in[i] & OVR_CIRCUMFLEX)
                            lineout[where++] = CIRCUMFLEX;
                        else if (ovr_in[i] & OVR_GRAVE)
                            lineout[where++] = GRAVE;

                        if (ovr_in[i] & OVR_SMOOTH)
                            lineout[where++] = SMOOTH;
                        else if (ovr_in[i] & OVR_ROUGH)
                            lineout[where++] = ROUGH;

                        if (ovr_in[i] & OVR_UMLAUT)
                            lineout[where++] = UMLAUT;

                        if (ovr_in[i] & OVR_IOTASUB)
                            lineout[where++] = IOTASUB;
                        } /* end else */
                    break;
                case BUF_HEBREW:
                    if (ovr_in[i] & OVR_TERM)
                        lineout[where++] = txt_in[i] + (char)('A'-'a');

                    switch(ovr_in[i] & OVR_LFTMASK)
                        {
                        case OVR_PATHAH:
                            lineout[where++] = PATHAH;
                            break;
                        case OVR_SEGHOL:
                            lineout[where++] = SEGHOL;
                            break;
                        case OVR_HIREQ:
                            lineout[where++] = HIREQ;
                            break;
                        case OVR_QIBBUS:
                            lineout[where++] = QIBBUS;
                            break;
                        case OVR_QAMES:
                            lineout[where++] = QAMES;
                            break;
                        case OVR_SERE:
                            lineout[where++] = SERE;
                            break;
                        case OVR_HOLEM:
                            lineout[where++] = HOLEM;
                            break;
                        case OVR_KATUPH:
                            lineout[where++] = QAMES;
                            lineout[where++] = QAMES_KATUPH;
                            break;
                        } /* end switch */

                    if (ovr_in[i] & OVR_SHEWA)
                        lineout[where++] = SHEWA;

                    if (ovr_in[i] & OVR_DAGESH)
                        lineout[where++] = DAGESH;

                    if (ovr_in[i] & OVR_RAPHE)
                        lineout[where++] = RAPHE;
                    break;
                case BUF_LATIN:
                    /* masked values must come first */
                    if ((ovr_in[i] & OVR_LFTMASK) == OVR_SLASH)
                        lineout[where++] = SLASH;
                    else if ((ovr_in[i] & OVR_LFTMASK) == OVR_DOT)
                        lineout[where++] = DOT;
                    else if (ovr_in[i] & OVR_ACUTE)
                        lineout[where++] = ACUTE;
                    else if (ovr_in[i] & OVR_CIRCUMFLEX)
                        lineout[where++] = CIRCUMFLEX;
                    else if (ovr_in[i] & OVR_GRAVE)
                        lineout[where++] = LGRAVE;
                    else if (ovr_in[i] & OVR_TILDE)
                        lineout[where++] = TILDE;
                    else if (ovr_in[i] & OVR_BREVE)
                        lineout[where++] = BREVE;
                    else if (ovr_in[i] & OVR_UMLAUT)
                        lineout[where++] = UMLAUT;

                    if (ovr_in[i] & OVR_CEDILLA)
                        lineout[where++] = CEDILLA;

                    if (ovr_in[i] & OVR_UNDERLINE)
                        lineout[where++] = UNDERLINE;
                    break;
                } /* end switch */
        } /* end for */

    /* fix srp for save if necessary */
    if (save[0]  &&  srp != prevsrp  &&  save[0] != PRECDR)
        {
        if (srp != BUF_HEBREW)
            {
            i = strlen(save) + 2;
            for ( ; i >= 2; --i)
                save[i] = save[i - 2];
            } /* end then */
        else
            {
            i = strlen(save) + 4;
            for ( ; i >= 4; --i)
                save[i] = save[i - 4];
            save[3] = BUF_CHGDIR;
            save[2] = PRECDR;
            } /* end else */
        save[1] = (char) srp;
        save[0] = PRECDR;
        } /* end then */
    } /* end then */
else
    /* right to left Hebrew only */
    {
    if (prevsrp != BUF_HEBREW)
        {
        lineout[where++] = PRECDR;
        lineout[where++] = BUF_HEBREW;
        } /* end then */
    for (i = len_in; i >= 0; --i)
        {
        if (txt_in[i])
            lineout[where++] = txt_in[i];
        else
            lineout[where++] = ' ';

        if (ovr_in[i] & OVR_TERM)
            lineout[where++] = txt_in[i] + (char)('A'-'a');

        switch(ovr_in[i] & OVR_LFTMASK)
            {
            case OVR_PATHAH:
                lineout[where++] = PATHAH;
                break;
            case OVR_SEGHOL:
                lineout[where++] = SEGHOL;
                break;
            case OVR_HIREQ:
                lineout[where++] = HIREQ;
                break;
            case OVR_QIBBUS:
                lineout[where++] = QIBBUS;
                break;
            case OVR_QAMES:
                lineout[where++] = QAMES;
                break;
            case OVR_SERE:
                lineout[where++] = SERE;
                break;
            case OVR_HOLEM:
                lineout[where++] = HOLEM;
                break;
            case OVR_KATUPH:
                lineout[where++] = QAMES;
                lineout[where++] = QAMES_KATUPH;
                break;
            } /* end switch */

        if (ovr_in[i] & OVR_SHEWA)
            lineout[where++] = SHEWA;

        if (ovr_in[i] & OVR_DAGESH)
            lineout[where++] = DAGESH;

        if (ovr_in[i] & OVR_RAPHE)
            lineout[where++] = RAPHE;
        } /* end for */
    } /* end else */

/* null for end of string */
lineout[where] = '\0';

/* correct dual language line caused by leading blanks */
for (i = 0; lineout[i] == ' '; ++i)
    {;}; /* end for */
if (i != 0  &&  lineout[i] == PRECDR)
    {
    lineout[0] = lineout[i];
    lineout[1] = lineout[i+1];
    if (i != 1)
        lineout[i] = ' ';
    lineout[i+1] = ' ';
    if (lineout[i+2] == PRECDR)
        {
        lineout[2] = lineout[i+2];
        lineout[3] = lineout[i+3];
        if (i != 1)
            lineout[i+2] = ' ';
        lineout[i+3] = ' ';
        } /* end then */
    } /* end then */

} /* end convout */
