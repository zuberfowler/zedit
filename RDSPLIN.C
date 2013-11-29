#include "zedit.h"

void  rdsplin(
              union both_scr  *posptr,
              int  line_no,
              int  startcol,
              int  endcol,
              char  inptext[] [25] [80])
/**********************************************************************/
/*                                                                    */
/* Redisplay an entire line on the screen allowing for all character  */
/* sets.                                                              */
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
register int  c;


for (c = startcol; c <= endcol; ++c)
    switch(inptext[SRP] [line_no] [c] & SRP_MASK)
        {
        case SRP_ROMCHAR:
            rdsprom(posptr, line_no, c, inptext);
            break;
        case SRP_GREEK:
            rdspgrk(posptr, line_no, c, inptext);
            break;
        case SRP_HEBREW:
            rdspheb(posptr, line_no, c, inptext);
            break;
        case SRP_LATIN:
            rdsplat(posptr, line_no, c, inptext);
            break;
        default:
            rdspasc(posptr, line_no, c, inptext);
            break;
        } /* end switch, for, then */

} /* end rdsplin */
