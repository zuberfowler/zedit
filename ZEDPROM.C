#include <stdio.h>
#include "zedit.h"

void  zedprom(
              FILE  *prn)
/**********************************************************************/
/*                                                                    */
/* This subroutine causes the printer to switch to its builtin        */
/* character set in rom.                                              */
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


if (prtmode & PROPRT  ||
  ((prtmode & PRDENS)  &&  !(prtmode & ALTCDE)))
    {
    fputc(0x1B, prn);   /* ESC */
    fputc(0x49, prn);   /* select rom NLQ */
    if (prtmode & PRONLQ)
        fputc(0x02, prn);   /* select rom NLQ */
    else
        fputc(0x00, prn);   /* select rom draft */
    } /* end then */
else
    {
    fputc(0x1B, prn);   /* ESC */
    fputc(0x25, prn);   /* select rom */
    fputc(0x00, prn);   /* select rom */
    } /* end else */

} /* end zedprom */
