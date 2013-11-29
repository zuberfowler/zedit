#include <stdio.h>
#include "zedit.h"

void  scrprnt(
              register union both_scr  *posptr)
/**********************************************************************/
/*                                                                    */
/* Dump the content of the graphic screen to a graphic printer.       */
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

FILE  *prn;
short llen;
char  bout[3];
char  byte;

register int  r; /* range */
register int  f; /* field */
register int  tab;
register int  i;



prn = fopen(outfile, NEW_OUTBIN);
if (!prn)
    {
    dispmsg(posptr, SCRPRNT_MSG1);
    return;
    } /* end then */

/* switch printer to correct vertical line spacing (no gap) */
zedplsp(prn);

/**********************************************************************/
if (graphic & IBM)
    {
    if ((prtmode & PRDENS)  && !(prtmode & ALTCDE))
        /* round out to multiple of eight * 3 */
        if (graphic & IBM1)
            llen = 1056;
        else
            llen = 1440;
    else
        if (graphic & IBM1)
            llen = 350;
        else
            llen = 475;

    for (tab = 0; tab < 90; ++tab)
        {
        scrpesc(prn, llen);

        for (f = 24; f >= 0; --f)
            if (graphic & IBM1)
                for (r = 13; r >= 0; --r)
                    {
                    byte = posptr -> is.iscr[f] [r] [tab];
#ifdef DOS
                    xepslot(&byte);
#endif
                    if (prtmode & PRDENS)
                        {
                        bytemap(byte, bout);
                        for (i = 0; i < 3; ++i)
                            fputc(bout[i], prn);
                        } /* end then */
                    else
                        fputc(byte, prn);
                    } /* end for */
            else
                for (r = 18; r >= 0; --r)
                    {
                    byte = posptr -> i2.i2scr[f] [r] [tab];
#ifdef DOS
                    xepslot(&byte);
#endif
                    if (prtmode & PRDENS)
                        {
                        bytemap(byte, bout);
                        for (i = 0; i < 3; ++i)
                            fputc(bout[i], prn);
                        } /* end then */
                    else
                        fputc(byte, prn);
                    } /* end for */

        if ((prtmode & PRDENS)  && !(prtmode & ALTCDE))
            if (graphic & IBM1)
                for (i = 0; i < 6; ++i)
                    fputc(0x00, prn);
            else
                for (i = 0; i < 15; ++i)
                    fputc(0x00, prn);
        } /* end for */
    } /* end then */

/**********************************************************************/
#ifdef DOS
else if ((graphic & HMONO)  &&  (!(prtmode & PROPRT)))
    scrphmn(posptr, prn);
#endif

/**********************************************************************/
else if (graphic & XGA)
    scrpxga(posptr, prn);

/**********************************************************************/
else if (graphic & CGA)
    {
    llen = 200;
    if ((prtmode & PRDENS)  && !(prtmode & ALTCDE))
        llen *= 3;
    for (tab = 0; tab < 80; ++tab)
        {
        scrpesc(prn, llen);

        for (r = 99; r >= 0; --r)
            for (f = 1; f >= 0; --f)
                {
                byte = posptr -> cs.cpos[f].cscr[r] [tab];
#ifdef DOS
                xepslot(&byte);
#endif
                if (prtmode & PRDENS)
                    {
                    bytemap(byte, bout);
                    for (i = 0; i < 3; ++i)
                        fputc(bout[i], prn);
                    } /* end then */
                else
                    fputc(byte, prn);
                } /* end for */
        } /* end for */
    } /* end then, else */

/**********************************************************************/
else if (graphic & EGA)
    {
    if ((prtmode & PRDENS)  && !(prtmode & ALTCDE))
        /* round out to multiple of eight * 3 */
        llen = 1056;
    else
        llen = 350;

    for (tab = 0; tab < 80; ++tab)
        {
        scrpesc(prn, llen);

        for (f = 24; f >= 0; --f)
            for (r = 13; r >= 0; --r)
                {
                byte = posptr -> es.escr[f] [r] [tab];
#ifdef DOS
                xepslot(&byte);
#endif
                if (prtmode & PRDENS)
                    {
                    bytemap(byte, bout);
                    for (i = 0; i < 3; ++i)
                        fputc(bout[i], prn);
                    } /* end then */
                else
                    fputc(byte, prn);
                } /* end for */

        if ((prtmode & PRDENS)  && !(prtmode & ALTCDE))
            for (i = 0; i < 6; ++i)
                fputc(0x00, prn);
        } /* end for */
    } /* end then, else */

/**********************************************************************/
else if (graphic & VGA)
    {
    if ((prtmode & PRDENS)  && !(prtmode & ALTCDE))
        /* round out to multiple of eight * 3 */
        llen = 1440;
    else
        llen = 475;

    for (tab = 0; tab < 80; ++tab)
        {
        scrpesc(prn, llen);

        for (f = 24; f >= 0; --f)
            for (r = 18; r >= 0; --r)
                {
                byte = posptr -> vs.vscr[f] [r] [tab];
#ifdef DOS
                xepslot(&byte);
#endif
                if (prtmode & PRDENS)
                    {
                    bytemap(byte, bout);
                    for (i = 0; i < 3; ++i)
                        fputc(bout[i], prn);
                    } /* end then */
                else
                    fputc(byte, prn);
                } /* end for */

        if ((prtmode & PRDENS)  && !(prtmode & ALTCDE))
            for (i = 0; i < 15; ++i)
                fputc(0x00, prn);
        } /* end for */
    } /* end then, else */

/**********************************************************************/
fputc('\f', prn);
fclose(prn);

} /* end scrprnt */
