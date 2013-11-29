#include <stdio.h>
#include "zedit.h"

#define  HIGH  0x80
#define  LOW   0x00

void  zedpprt(
              FILE  *prn,
              int  rightmar,
              int  toright,
              char  prbuf[],
              int  true_linesize,
              int  q,
              int  last_amode[],
              int  pb[])
/**********************************************************************/
/*                                                                    */
/* Actually print a line of double high characters.                   */
/*                                                                    */
/* The Epson printer has two download areas so this program           */
/* alternates between the two hoping that when it changes script      */
/* the new one might still be in the other area.  For the IBM         */
/* Proprinter this logic is ignored.                                  */
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
extern unsigned int  prtmode;

extern char  zedasct[94] [8];
extern char  zedascb[94] [8];
extern char  zedgrkt[94] [8];
extern char  zedgrkb[94] [8];
extern char  zedhebt[94] [8];
extern char  zedhebb[94] [8];
extern char  zedlatt[94] [8];
extern char  zedlatb[94] [8];

static char  sel = LOW;
static enum zgraph  last_hgraph = none_of;
static enum zgraph  last_lgraph = none_of;

register int  c;
register int  i;

char  high;


/* ONEBUF required for original US Proprinter */
/* also to use imbedded ESC sequences (w/o high order bit on) */
if ((prtmode & ONEBUF)  ||
   ((prtmode & PRDENS)  &&  !(prtmode & ALTCDE)))
    high = LOW;
else
    high = HIGH;

/**********************************************************************/
/* Print the top half of the line.                                    */
/**********************************************************************/
for (i = 1; i <= q; ++i)
    {
    switch(last_amode[i])
        {
        case BUF_ASCII:
            zedpram(prn);
            if (sel)
                {
                sel = LOW;
                if (last_lgraph != asc_top)
                    {
                    last_lgraph = asc_top;
                    zedpfnt(last_lgraph, sel, prn, zedasct);
                    } /* end then */
                } /* end then */
            else
                {
                sel = high;
                if (last_hgraph != asc_top)
                    {
                    last_hgraph = asc_top;
                    zedpfnt(last_hgraph, sel, prn, zedasct);
                    } /* end then */
                } /* end else */
            break;
        case BUF_LATIN:
            zedpram(prn);
            if (sel)
                {
                sel = LOW;
                if (last_lgraph != lat_top)
                    {
                    last_lgraph = lat_top;
                    zedpfnt(last_lgraph, sel, prn, zedlatt);
                    } /* end then */
                } /* end then */
            else
                {
                sel = high;
                if (last_hgraph != lat_top)
                    {
                    last_hgraph = lat_top;
                    zedpfnt(last_hgraph, sel, prn, zedlatt);
                    } /* end then */
                } /* end else */
            break;
        case BUF_GREEK:
            zedpram(prn);
            if (sel)
                {
                sel = LOW;
                if (last_lgraph != grk_top)
                    {
                    last_lgraph = grk_top;
                    zedpfnt(last_lgraph, sel, prn, zedgrkt);
                    } /* end then */
                } /* end then */
            else
                {
                sel = high;
                if (last_hgraph != grk_top)
                    {
                    last_hgraph = grk_top;
                    zedpfnt(last_hgraph, sel, prn, zedgrkt);
                    } /* end then */
                } /* end else */
            break;
        case BUF_ROMCHAR:
            zedprom(prn);
            sel = LOW;
            break;
        case BUF_HEBREW:
            zedpram(prn);
            if (sel)
                {
                sel = LOW;
                if (last_lgraph != heb_top)
                    {
                    last_lgraph = heb_top;
                    zedpfnt(last_lgraph, sel, prn, zedhebt);
                    } /* end then */
                } /* end then */
            else
                {
                sel = high;
                if (last_hgraph != heb_top)
                    {
                    last_hgraph = heb_top;
                    zedpfnt(last_hgraph, sel, prn, zedhebt);
                    } /* end then */
                } /* end else */
            break;
        } /* end switch */

    if (toright)
        for (c = pb[i-1]; c < pb[i]; ++c)
            switch(prbuf[c])
                {
                case ' ':
                    fputc(' ', prn);
                    break;
                case '\n':
                    fputc(0x0D, prn);  /* CR */
                    fputc(0x0A, prn);  /* LF */
                    break;
                default:
                    fputc(prbuf[c] | sel, prn);
                    break;
                } /* end switch */
    else
        {
        /* align by rightmar if enough room */
        for (c = 0; c < rightmar - true_linesize + 1; ++c)
            fputc(' ', prn);
        for (c = pb[i]+2; c <= pb[i-1]; ++c)
            if (prbuf[c] == ' ')
                fputc(' ', prn);
            else
                fputc(prbuf[c] | sel, prn);
        fputc(0x0D, prn);  /* CR */
        fputc(0x0A, prn);  /* LF */
        } /* end else */
    } /* end for */

/**********************************************************************/
/* Print the bottom half of the line.  Only ram printing for the      */
/* bottom half.                                                       */
/**********************************************************************/
zedpram(prn);

for (i = 1; i <= q; ++i)
    {
    switch(last_amode[i])
        {
        case BUF_ASCII:
            if (sel)
                {
                sel = LOW;
                if (last_lgraph != asc_bot)
                    {
                    last_lgraph = asc_bot;
                    zedpfnt(last_lgraph, sel, prn, zedascb);
                    } /* end then */
                } /* end then */
            else
                {
                sel = high;
                if (last_hgraph != asc_bot)
                    {
                    last_hgraph = asc_bot;
                    zedpfnt(last_hgraph, sel, prn, zedascb);
                    } /* end then */
                } /* end else */
            break;
        case BUF_LATIN:
            if (sel)
                {
                sel = LOW;
                if (last_lgraph != lat_bot)
                    {
                    last_lgraph = lat_bot;
                    zedpfnt(last_lgraph, sel, prn, zedlatb);
                    } /* end then */
                } /* end then */
            else
                {
                sel = high;
                if (last_hgraph != lat_bot)
                    {
                    last_hgraph = lat_bot;
                    zedpfnt(last_hgraph, sel, prn, zedlatb);
                    } /* end then */
                } /* end else */
            break;
        case BUF_GREEK:
            if (sel)
                {
                sel = LOW;
                if (last_lgraph != grk_bot)
                    {
                    last_lgraph = grk_bot;
                    zedpfnt(last_lgraph, sel, prn, zedgrkb);
                    } /* end then */
                } /* end then */
            else
                {
                sel = high;
                if (last_hgraph != grk_bot)
                    {
                    last_hgraph = grk_bot;
                    zedpfnt(last_hgraph, sel, prn, zedgrkb);
                    } /* end then */
                } /* end else */
            break;
        case BUF_ROMCHAR:
            /* romchar has no bottom half, so blank out string */
            for (c = pb[i-1]; c < pb[i]-1; ++c)
                prbuf[c] = ' ';
            if (prbuf[pb[i]-1] != '\n')
                prbuf[c] = ' ';
            sel = LOW;
            break;
        case BUF_HEBREW:
            if (sel)
                {
                sel = LOW;
                if (last_lgraph != heb_bot)
                    {
                    last_lgraph = heb_bot;
                    zedpfnt(last_lgraph, sel, prn, zedhebb);
                    } /* end then */
                } /* end then */
            else
                {
                sel = high;
                if (last_hgraph != heb_bot)
                    {
                    last_hgraph = heb_bot;
                    zedpfnt(last_hgraph, sel, prn, zedhebb);
                    } /* end then */
                } /* end else */
            break;
        } /* end switch */

    if (toright)
        for (c = pb[i-1]; c < pb[i]; ++c)
            switch(prbuf[c])
                {
                case ' ':
                    fputc(' ', prn);
                    break;
                case '\n':
                    fputc(0x0D, prn);  /* CR */
                    fputc(0x0A, prn);  /* LF */
                    break;
                default:
                    fputc(prbuf[c] | sel, prn);
                    break;
                } /* end switch */
    else
        {
        /* align by rightmar if enough room */
        for (c = 0; c < rightmar - true_linesize + 1; ++c)
            fputc(' ', prn);
        for (c = pb[i]+2; c <= pb[i-1]; ++c)
            if (prbuf[c] == ' ')
                fputc(' ', prn);
            else
                fputc(prbuf[c] | sel, prn);
        fputc(0x0D, prn);  /* CR */
        fputc(0x0A, prn);  /* LF */
        } /* end else */
    } /* end for */

} /* end zedpprt */
