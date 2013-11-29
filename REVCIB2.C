#include "zedit.h"

void  revcib2(
              register union both_scr  *posptr,
              int  line_no,
              int  col_no)
/**********************************************************************/
/*                                                                    */
/* Turn a character position to the oposite display of its present    */
/* display (normal/reverse) - IBM2.                                   */
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
register int  d; /* down  */
int  tab;
int  tup;
int  colcase;


tab = (col_no * 9) / 8;
tup = tab + 1;
colcase = col_no % 8;

for (d = 0; d < 19; ++d)
    switch(colcase)
        {
        case 0:
            posptr -> i2.i2scr[line_no] [d] [tab] ^= 0xFFu;
            posptr -> i2.i2scr[line_no] [d] [tup] ^= 0x80u;
            break;
        case 1:
            posptr -> i2.i2scr[line_no] [d] [tab] ^= 0x7Fu;
            posptr -> i2.i2scr[line_no] [d] [tup] ^= 0xC0u;
            break;
        case 2:
            posptr -> i2.i2scr[line_no] [d] [tab] ^= 0x3Fu;
            posptr -> i2.i2scr[line_no] [d] [tup] ^= 0xE0u;
            break;
        case 3:
            posptr -> i2.i2scr[line_no] [d] [tab] ^= 0x1Fu;
            posptr -> i2.i2scr[line_no] [d] [tup] ^= 0xF0u;
            break;
        case 4:
            posptr -> i2.i2scr[line_no] [d] [tab] ^= 0x0Fu;
            posptr -> i2.i2scr[line_no] [d] [tup] ^= 0xF8u;
            break;
        case 5:
            posptr -> i2.i2scr[line_no] [d] [tab] ^= 0x07u;
            posptr -> i2.i2scr[line_no] [d] [tup] ^= 0xFCu;
            break;
        case 6:
            posptr -> i2.i2scr[line_no] [d] [tab] ^= 0x03u;
            posptr -> i2.i2scr[line_no] [d] [tup] ^= 0xFEu;
            break;
        case 7:
            posptr -> i2.i2scr[line_no] [d] [tab] ^= 0x01u;
            posptr -> i2.i2scr[line_no] [d] [tup] ^= 0xFFu;
            break;
        } /* end switch */

} /* end revcib2 */
