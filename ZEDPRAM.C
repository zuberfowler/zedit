#include <stdio.h>
#include "zedit.h"

void  zedpram(
              FILE  *prn)
/**********************************************************************/
/*                                                                    */
/* Cause printer to select down loaded characters for printing.       */
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
    fputc(0x49, prn);   /* select ram */
    if (prtmode & PRONLQ)
        fputc(0x06, prn);   /* NLQ download */
    else
        fputc(0x04, prn);   /* draft download */
    } /* end then */
else
    {
    fputc(0x1B, prn);   /* ESC */
    fputc(0x25, prn);   /* select ram */
    fputc(0x01, prn);   /* select ram */
    fputc(0x00, prn);   /* select ram */
    } /* end else */

} /* end zedpram */
