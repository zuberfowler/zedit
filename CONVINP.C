#include "zedit.h"

void  convinp(
              union both_scr  *posptr,
              unsigned int  inpt,
              unsigned int  shift,
              int  amode,
              int  toright,
              int  *line_no,
              int  *col_no,
              int  nfield,
              int  rowcol[] [5],
              char  inptext[] [25] [80],
              unsigned int  display)
/**********************************************************************/
/*                                                                    */
/* Call the correct char processor according to the amode.            */
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
extern char  grkexch[256];
extern char  hebexch[256];


switch(amode)
    {
    case BUF_ASCII:
        inpt &= 0x7Fu;
        pascchr(posptr, inpt, shift, toright, nfield, rowcol, line_no,
            col_no, inptext, display);
        break;
    case BUF_ROMCHAR:
        inpt &= 0x7Fu;
        promchr(posptr, inpt, shift, toright, nfield, rowcol, line_no,
            col_no, inptext, display);
        break;
    case BUF_GREEK:
        if (grkexch[0]  &&  display & NOMAYBE)
            inpt = grkexch[inpt];
        inpt &= 0x7Fu;
        pgrkchr(posptr, inpt, shift, toright, nfield, rowcol, line_no,
            col_no, inptext, display);
        break;
    case BUF_HEBREW:
        if (hebexch[0]  &&  display & NOMAYBE)
            inpt = hebexch[inpt];
        inpt &= 0x7Fu;
        phebchr(posptr, inpt, shift, toright, nfield, rowcol, line_no,
            col_no, inptext, display);
        break;
    case BUF_LATIN:
        inpt &= 0x7Fu;
        platchr(posptr, inpt, shift, toright, nfield, rowcol, line_no,
            col_no, inptext, display);
        break;
    } /* end switch */

} /* end convinp */
