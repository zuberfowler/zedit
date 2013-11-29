#include "zedit.h"

void  dspcibm(
              register union both_scr  *posptr,
              char  c,
              int  line_no,
              int  col_no,
              char  dots[] [14])
/**********************************************************************/
/*                                                                    */
/* Copy into screen position one character - IBM1.                    */
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

for (d = 0; d < 14; ++d)
    switch(colcase)
        {
        case 0:
            posptr -> is.iscr[line_no] [d] [tab] =
                (char) (dots[c] [d] >> 1u);
            posptr -> is.iscr[line_no] [d] [tup] &= 0x3Fu;
            posptr -> is.iscr[line_no] [d] [tup] |=
                (char) (dots[c] [d] << 7u);
            break;
        case 1:
            posptr -> is.iscr[line_no] [d] [tab] &= 0xC0u;
            posptr -> is.iscr[line_no] [d] [tab] |=
                (char) (dots[c] [d] >> 2u);
            posptr -> is.iscr[line_no] [d] [tup] &= 0x1Fu;
            posptr -> is.iscr[line_no] [d] [tup] |=
                (char) (dots[c] [d] << 6u);
            break;
        case 2:
            posptr -> is.iscr[line_no] [d] [tab] &= 0xE0u;
            posptr -> is.iscr[line_no] [d] [tab] |=
                (char) (dots[c] [d] >> 3u);
            posptr -> is.iscr[line_no] [d] [tup] &= 0x0Fu;
            posptr -> is.iscr[line_no] [d] [tup] |=
                (char) (dots[c] [d] << 5u);
            break;
        case 3:
            posptr -> is.iscr[line_no] [d] [tab] &= 0xF0u;
            posptr -> is.iscr[line_no] [d] [tab] |=
                (char) (dots[c] [d] >> 4u);
            posptr -> is.iscr[line_no] [d] [tup] &= 0x07u;
            posptr -> is.iscr[line_no] [d] [tup] |=
                (char) (dots[c] [d] << 4u);
            break;
        case 4:
            posptr -> is.iscr[line_no] [d] [tab] &= 0xF8u;
            posptr -> is.iscr[line_no] [d] [tab] |=
                (char) (dots[c] [d] >> 5u);
            posptr -> is.iscr[line_no] [d] [tup] &= 0x03u;
            posptr -> is.iscr[line_no] [d] [tup] |=
                (char) (dots[c] [d] << 3u);
            break;
        case 5:
            posptr -> is.iscr[line_no] [d] [tab] &= 0xFCu;
            posptr -> is.iscr[line_no] [d] [tab] |=
                (char) (dots[c] [d] >> 6u);
            posptr -> is.iscr[line_no] [d] [tup] &= 0x01u;
            posptr -> is.iscr[line_no] [d] [tup] |=
                (char) (dots[c] [d] << 2u);
            break;
        case 6:
            posptr -> is.iscr[line_no] [d] [tab] &= 0xFEu;
            posptr -> is.iscr[line_no] [d] [tab] |=
                (char) (dots[c] [d] >> 7u);
            posptr -> is.iscr[line_no] [d] [tup] =
                (char) (dots[c] [d] << 1u);
            break;
        case 7:
            posptr -> is.iscr[line_no] [d] [tup] = dots[c] [d];
            break;
        } /* end switch */

} /* end dspcibm */
