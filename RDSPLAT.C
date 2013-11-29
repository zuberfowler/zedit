#include <string.h>
#include "zedit.h"

void  rdsplat(
              union both_scr  *posptr,
              int  line_no,
              int  col_no,
              char  inptext[] [25] [80])
/**********************************************************************/
/*                                                                    */
/* Redisplay a Latin character on the screen including any overlays.  */
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

static char  c_cedilla[] = "aAeEcCsStT";
static char  c_dacute[]  = " oOuU";

int  stretch;
char  dchar;


/* make special character substitutions */
switch(inptext[TXT] [line_no] [col_no])
    {
    case C_AE:
        dchar = C_AE_CH;
        break;
    case S_AE:
        dchar = S_AE_CH;
        break;
    case C_OE:
        dchar = C_OE_CH;
        break;
    case S_OE:
        dchar = S_OE_CH;
        break;
    case C_THORN:
        dchar = C_THORN_CH;
        break;
    case S_THORN:
        dchar = S_THORN_CH;
        break;
    case ETH:
        dchar = ETH_CH;
        break;
    default:
        dchar = inptext[TXT] [line_no] [col_no];
        break;
    } /* end switch */

/* display the base character */
dispchr(posptr, dchar, line_no, col_no, ascchar);

stretch = NO;
dchar = 0x00;

/* masked values must come first */
if ((inptext[OVR] [line_no ] [col_no] & OVR_LFTMASK) == OVR_SLASH)
    dchar = SLASH_CH;
else if ((inptext[OVR] [line_no ] [col_no] & OVR_LFTMASK) == OVR_DOT)
    switch(inptext[TXT] [line_no] [col_no])
        {
        case 'A':
        case 'U':
        case ' ':
        case 'a':
        case 'u':
            stretch = YES;
            dchar = OVERCIR_CH;
            break;
        case 'C':
        case 'G':
        case 'I':
        case 'Z':
        case 'c':
        case 'g':
        case 'z':
            stretch = YES;
            dchar = OVERDOT_CH;
            break;
        case 'L':
        case 'l':
            dchar = MIDDOT_CH;
            break;
        } /* end switch */
else
    {
    if (inptext[OVR] [line_no ] [col_no] & OVR_ACUTE)
        dchar = ACUTE;
    else if (inptext[OVR] [line_no ] [col_no] & OVR_CIRCUMFLEX)
        dchar = CIRCUMFLEX;
    else if (inptext[OVR] [line_no ] [col_no] & OVR_GRAVE)
        dchar = LGRAVE;
    else if (inptext[OVR] [line_no ] [col_no] & OVR_TILDE)
        dchar = TILDE;
    else if (inptext[OVR] [line_no ] [col_no] & OVR_BREVE)
        dchar = BREVE_CH;
    else if (inptext[OVR] [line_no ] [col_no] & OVR_UMLAUT)
        dchar = UMLAUT_CH;

    stretch = YES;  /* only used, if (dchar) */
    } /* end else */

if (dchar)
    overchr(posptr, dchar, line_no, col_no, ascchar, stretch);


if (inptext[OVR] [line_no ] [col_no] & OVR_CEDILLA)
    if (strchr(c_cedilla, inptext[TXT] [line_no] [col_no]))
        overchr(posptr, CEDILLA_CH, line_no, col_no, ascchar, NO);
    else if (strchr(c_dacute, inptext[TXT] [line_no] [col_no]))
        overchr(posptr, DOUBLEAC_CH, line_no, col_no, ascchar, YES);

if (inptext[OVR] [line_no ] [col_no] & OVR_UNDERLINE)
    overchr(posptr, UNDERLINE, line_no, col_no, ascchar, NO);

} /* end rdsplat */
