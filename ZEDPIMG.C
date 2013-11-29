#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zedit.h"

void  zedpimg(
              union both_scr  *real_posptr,
              int  maxlrecl,
              register struct bufline  *curr,
              int  rightmar)
/**********************************************************************/
/*                                                                    */
/* This routine will print using IBM PPDS graphic mode.               */
/* This mode is a generic graphic mode over a wide range of printers  */
/* from many manufacturers.                                           */
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
extern unsigned int  graphic;
extern unsigned int  prtmode;

/* initialialized values */
static int  rcbrowse[1] [5] =
   {{0,  0, 79, 23, RC_NORMAL}};

static int  rcedit[2] [5] =
   {{0,  0,  6, 23, RC_NORMAL},
    {0,  8, 79, 23, RC_NORMAL}};

static int  toright = YES;

double  scale;
double  down;
unsigned int  hold_graphic;
int  (*rowcol)[] [5];
int  nfield;
int  amode;
int  max_field;
int  start_tab;
int  max_tab;
int  col_no;
int  line_no;
int  where;
int  eol;
FILE  *prn;
unsigned short  llen;
char  inptext[4] [25] [80];
char  mout[8];
char  bout[3];
char  min[8];

register union both_scr  *posptr;
register int  field;
register int  range;
register int  tab;
register int  i;


prn = fopen(outfile, NEW_OUTBIN);
if (!prn)
    zfinish(real_posptr, open_out);

/* switch printer to correct vertical line spacing (no gap) */
zedplsp(prn);

memset(inptext, 0x00, 8000u);

if (rightmar > 80)
    rightmar = 80;

/* save graphic mode for fake screen set up */
hold_graphic = graphic;

/* obtain fake screen area in which to format characters */
if (prtmode & XGABOX)
    {
    posptr = (union both_scr  *) malloc(61440u);
    if (!posptr)
        zfinish(real_posptr, no_storage);
    memset((char *) posptr, 0x00, 61440u);

    rcbrowse[0] [BOTTOM_MAR] = 15;
    rcedit[0] [BOTTOM_MAR] = 15;
    rcedit[1] [BOTTOM_MAR] = 15;

    if (prtmode & PRWIDE)
        start_tab = 12;
    else
        start_tab = 4;

    scale = 1.5;
    down = 30.0;
    graphic = XGA;
    } /* end then */
else
    {
    posptr = (union both_scr  *) malloc(44032u);
    if (!posptr)
        zfinish(real_posptr, no_storage);
    memset((char *) posptr, 0x00, 44032u);

    if (prtmode & BIGBOX)
        {
        down = 19.0;
        graphic = IBM2;
        } /* end then */
    else
        {
        down = 14.0;
        graphic = IBM1;
        } /* end else */

    if (prtmode & PRWIDE)
        start_tab = 9;
    else
        start_tab = 0;

    scale = 9.0 / 8.0;
    } /* end else */

if (rightmar > 72)
    {
    start_tab = 0;
    nfield = 0;
    rowcol = (int (*)[][5]) rcbrowse;
    rcbrowse[0] [RIGHT_MAR] = rightmar - 1;
    } /* end then */
else
    {
    nfield = 1;
    rowcol = (int (*)[][5]) rcedit;
    rightmar += 7;
    rcedit[1] [RIGHT_MAR] = rightmar;
    ++rightmar;
    } /* end else */

max_tab = (int) ((double) rightmar * scale + 0.876);
llen = (unsigned short) ((max_tab - start_tab) * 8);
if ((prtmode & PRDENS)  &&  !(prtmode & ALTCDE))
    llen *= 3;

while(curr)
    {
    for (line_no = 0;
      curr  &&  line_no <= (*rowcol)[nfield] [BOTTOM_MAR];
      curr = curr -> next)
        {
        if (curr -> status & ST_PROT)
            continue;
        amode = curr -> script;
        if (curr -> script == BUF_HEBREW)
            toright = NO;
        else
            toright = YES;
        where = 0;
        eol = NO;
        if (toright)
            col_no = (*rowcol)[nfield] [LEFT_MAR];
        else
            col_no = (*rowcol)[nfield] [RIGHT_MAR];

        buftsln(posptr, nfield, *rowcol, curr, line_no, maxlrecl,
            inptext, &where, &amode, &eol, &toright, &col_no);

        ++line_no;
        } /* end for */

    if (line_no <= (*rowcol)[nfield] [BOTTOM_MAR])
        clrline(posptr, line_no);

    max_field = (int) ((double) line_no * down / 8.0 + 0.876);

    for (field = 0; field < max_field; ++field)
        {
        fputc(0x0D, prn);  /* CR */
        fputc(0x0A, prn);  /* LF */

        /* graphics command required before each output line */
        fputc(0x1B, prn);  /* ESC */
        if (prtmode & PRDENS)
            {
            if (prtmode & ALTCDE)
                {
                fputc(0x2A, prn);      /*  * - 24 pin graphics */
                if (prtmode & PRWIDE)
                    fputc(0x20, prn);  /* SP - single density graphic */
                else
                    fputc(0x21, prn);  /*  ! - dual density graphic */
                } /* end then */
            else
                {
                fputc(0x5B, prn);      /*  [ - 24 pin graphics */
                fputc(0x67, prn);      /*  g - 24 pin graphics */
                } /* end else */
            } /* end then */
        else
            {
            if (prtmode & PRWIDE)
                fputc(0x4B, prn);      /*  K - single density graphic */
            else
                fputc(0x4C, prn);      /*  L - dual density graphic */
            } /* end else */
        fputc(((char *)&llen)[0], prn); /* length low  order byte */
        fputc(((char *)&llen)[1], prn); /* length high order byte */

        if ((prtmode & PRDENS)  &&  !(prtmode & ALTCDE))
            {
            if (prtmode & PRWIDE)
                fputc(0x08, prn);  /* mode 8, high resolution like K */
            else
                fputc(0x09, prn);  /* mode 9, high resolution like L */
            } /* end then */

        for (tab = start_tab; tab < max_tab; ++tab)
            {
            for (range = 0; range < 8; ++range)
                if (graphic & XGA)
                    min[range] = posptr -> xi.xj[field] [range].xk[tab];
                else
                    min[range] = posptr -> pi.pimg[field] [range] [tab];

            invert(min[0], min[1], min[2], min[3], min[4], min[5],
                min[6], min[7], mout);

            for (range = 0; range < 8; ++range)
                {
#ifdef DOS
                xepslot(&mout[range]);
#endif
                if (prtmode & PRDENS)
                    {
                    bytemap(mout[range], bout);
                    for (i = 0; i < 3; ++i)
                        fputc(bout[i], prn);
                    } /* end then */
                else
                    fputc(mout[range], prn);
                } /* end for */
            } /* end for */
        } /* end for */

    } /* end while */

fputc('\f', prn);
/* restore environment */
graphic = hold_graphic;

/* clean up */
free(posptr);
fclose(prn);

} /* end main zedprt */
