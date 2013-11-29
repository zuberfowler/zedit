#include <stdio.h>
#include "zedit.h"

void  zedppsp(
              int  regular,  /* alias for maxlrecl */
              FILE  *prn,
              int  rightmar,
              int  amode,
              int  toright,
              char  prchar)
/**********************************************************************/
/*                                                                    */
/* Actually print a character to the PostScript file.                 */
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
/* constants */
static double  hsize = (double) (12.0 * .6);
static double  vsize = (double) (12.0);
static double  between = (double) (2.0);
static double  top = (double) (768.0);
static double  bottom = (double) (24.0);
static double  ldead = (double) (18.0);
static double  left = (double) (18.0);

/* kept values */
static int  last_amode = -1;
static int  last_toright = -1;
static int  skip = YES;
static int  stropen = NO;
static double  x = (double) (18.0);
static double  y = (double) (768.0 - 12.0);
static char  keep = '\0';

/* char constants */
static char  lparen = '(';

/* string ptr constants */
static char  *charfmt = "%s %s %1.0f %s ";
static char  *ascchar = "/Ascch";
static char  *findfont = "findfont";
static char  *grkchar = "/Grkch";
static char  *hebchar = "/Hebch";
static char  *rhebchr = "/Rhebc";
static char  *set = "scalefont setfont";
static char  *show = ") show\n";
static char  *showpage = "showpage\n";
static char  *spcchar = "/Spcch";


if (!regular)
    {
    /* buffer backspace, replace previous char */
    skip = YES;
    return;
    } /* end then */

if (skip)
    {
    /* first time through or replace previous char */
    skip = NO;
    keep = prchar;
    return;
    } /* end then */

if (last_amode == -1)
    {
    if (rightmar < 80)
        left = (double) (ldead + (80 - rightmar) / 2.0 * hsize);
    x = left;
    fprintf(prn, "%1.0f %1.0f moveto ", x, y);
    } /* end then */

if (amode != last_amode  ||  toright != last_toright)
    {
    last_amode = amode;
    last_toright = toright;
    if (stropen)
        {
        stropen = NO;
        fputs(show, prn);
        } /* end then */
    x = left;
    switch(amode)
        {
        case BUF_ASCII:
        case BUF_LATIN:
            fprintf(prn, charfmt, ascchar, findfont, vsize, set);
            break;
        case BUF_GREEK:
            fprintf(prn, charfmt, grkchar, findfont, vsize, set);
            break;
        case BUF_HEBREW:
            if (toright)
                fprintf(prn, charfmt, rhebchr, findfont, vsize, set);
            else
                {
                fprintf(prn, charfmt, hebchar, findfont, vsize, set);
                x = left + (rightmar - 1) * hsize;
                } /* end else */
            break;
        case BUF_ROMCHAR:
            fprintf(prn, charfmt, spcchar, findfont, vsize, set);
            break;
        } /* end switch */
    } /* end then */

if (!stropen)
    {
    stropen = YES;
    fputc(lparen, prn);
    } /* end then */

if (keep == '\n')
    {
    stropen = NO;
    fputs(show, prn);
    y -= vsize + between;
    if (y < bottom)
        {
        fputs(showpage, prn);
        y = top - vsize;
        } /* end then */
    fprintf(prn, "%1.0f %1.0f moveto ", x, y);
    } /* end then */
else
    {
    if (keep == '('  ||  keep == ')')
        fputc('\\', prn);
    fputc(keep, prn);
    if (keep == '\\')
        fputc(keep, prn);
    } /* end else */

if (prchar == 0x1A)
    {
    if (stropen)
        fputs(show, prn);
    fputs(showpage, prn);
    } /* end then */

keep = prchar;

} /* end zedppsp */
