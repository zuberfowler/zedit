#include "zedit.h"

void  ov8cib2(
              register union both_scr  *posptr,
              char  c,
              int  line_no,
              int  col_no)
/**********************************************************************/
/*                                                                    */
/* Overlay into screen position one character using 8x8 rom character */
/* - IBM2.                                                            */
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
extern struct rombios  *romptr;
register int  d; /* down  */
register int  e; /* down+ */
int  tab;
int  tup;
int  colcase;


tab = (col_no * 9) / 8;
tup = tab + 1;
colcase = col_no % 8;

for (d = 0, e = 5; d < 8; ++d, ++e)
    switch(colcase)
        {
        case 0:
            posptr -> i2.i2scr[line_no] [e] [tab] |=
                (char) (romptr -> rchr[c] [d] >> 1u);
            posptr -> i2.i2scr[line_no] [e] [tup] |=
                (char) (romptr -> rchr[c] [d] << 7u);
            break;
        case 1:
            posptr -> i2.i2scr[line_no] [e] [tab] |=
                (char) (romptr -> rchr[c] [d] >> 2u);
            posptr -> i2.i2scr[line_no] [e] [tup] |=
                (char) (romptr -> rchr[c] [d] << 6u);
            break;
        case 2:
            posptr -> i2.i2scr[line_no] [e] [tab] |=
                (char) (romptr -> rchr[c] [d] >> 3u);
            posptr -> i2.i2scr[line_no] [e] [tup] |=
                (char) (romptr -> rchr[c] [d] << 5u);
            break;
        case 3:
            posptr -> i2.i2scr[line_no] [e] [tab] |=
                (char) (romptr -> rchr[c] [d] >> 4u);
            posptr -> i2.i2scr[line_no] [e] [tup] |=
                (char) (romptr -> rchr[c] [d] << 4u);
            break;
        case 4:
            posptr -> i2.i2scr[line_no] [e] [tab] |=
                (char) (romptr -> rchr[c] [d] >> 5u);
            posptr -> i2.i2scr[line_no] [e] [tup] |=
                (char) (romptr -> rchr[c] [d] << 3u);
            break;
        case 5:
            posptr -> i2.i2scr[line_no] [e] [tab] |=
                (char) (romptr -> rchr[c] [d] >> 6u);
            posptr -> i2.i2scr[line_no] [e] [tup] |=
                (char) (romptr -> rchr[c] [d] << 2u);
            break;
        case 6:
            posptr -> i2.i2scr[line_no] [e] [tab] |=
                (char) (romptr -> rchr[c] [d] >> 7u);
            posptr -> i2.i2scr[line_no] [e] [tup] |=
                (char) (romptr -> rchr[c] [d] << 1u);
            break;
        case 7:
            posptr -> i2.i2scr[line_no] [e] [tup] |=
                romptr -> rchr[c] [d];
            break;
        } /* end switch */

} /* end ov8cib2 */
