#include <string.h>
#include "zedit.h"

void  cfgkpan(
              union both_scr  *posptr,
              int  *line_no,
              int  *col_no,
              int  *nfield,
              int  **rowcol_ptr,
              char  inptext[] [25] [80])
/**********************************************************************/
/*                                                                    */
/* Change configuration values for keyboard panel.                    */
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
extern char  ascchar[128] [14];
extern char  grkexch[256];
extern char  hebexch[256];

static int  rowcol[191] [5] =
   {{1, 13, 60,  1, RC_ENTRY},            /* cmd line */
    {3,  9,  9,  3, RC_NORMAL},           /*   */
    {3, 10, 10,  3, RC_NORMAL},           /* ! */
    {3, 11, 11,  3, RC_NORMAL},           /* " */
    {3, 12, 12,  3, RC_NORMAL},           /* # */
    {3, 13, 13,  3, RC_NORMAL},           /* $ */
    {3, 14, 14,  3, RC_NORMAL},           /* % */
    {3, 15, 15,  3, RC_NORMAL},           /* & */
    {3, 16, 16,  3, RC_NORMAL},           /* ' */
    {3, 17, 17,  3, RC_NORMAL},           /* ( */
    {3, 18, 18,  3, RC_NORMAL},           /* ) */
    {3, 19, 19,  3, RC_NORMAL},           /* * */
    {3, 20, 20,  3, RC_NORMAL},           /* + */
    {3, 21, 21,  3, RC_NORMAL},           /* , */
    {3, 22, 22,  3, RC_NORMAL},           /* - */
    {3, 23, 23,  3, RC_NORMAL},           /* . */
    {3, 24, 24,  3, RC_NORMAL},           /* / */
    {3, 25, 25,  3, RC_NORMAL},           /* 0 */
    {3, 26, 26,  3, RC_NORMAL},           /* 1 */
    {3, 27, 27,  3, RC_NORMAL},           /* 2 */
    {3, 28, 28,  3, RC_NORMAL},           /* 3 */
    {3, 29, 29,  3, RC_NORMAL},           /* 4 */
    {3, 30, 30,  3, RC_NORMAL},           /* 5 */
    {3, 31, 31,  3, RC_NORMAL},           /* 6 */
    {3, 32, 32,  3, RC_NORMAL},           /* 7 */
    {3, 33, 33,  3, RC_NORMAL},           /* 8 */
    {3, 34, 34,  3, RC_NORMAL},           /* 9 */
    {3, 35, 35,  3, RC_NORMAL},           /* : */
    {3, 36, 36,  3, RC_NORMAL},           /* ; */
    {3, 37, 37,  3, RC_NORMAL},           /* < */
    {3, 38, 38,  3, RC_NORMAL},           /* = */
    {3, 39, 39,  3, RC_NORMAL},           /* > */
    {3, 40, 40,  3, RC_NORMAL},           /* ? */
    {3, 41, 41,  3, RC_NORMAL},           /* @ */
    {5,  0,  0,  5, RC_NORMAL},           /* A */
    {5,  1,  1,  5, RC_NORMAL},           /* B */
    {5,  2,  2,  5, RC_NORMAL},           /* C */
    {5,  3,  3,  5, RC_NORMAL},           /* D */
    {5,  4,  4,  5, RC_NORMAL},           /* E */
    {5,  5,  5,  5, RC_NORMAL},           /* F */
    {5,  6,  6,  5, RC_NORMAL},           /* G */
    {5,  7,  7,  5, RC_NORMAL},           /* H */
    {5,  8,  8,  5, RC_NORMAL},           /* I */
    {5,  9,  9,  5, RC_NORMAL},           /* J */
    {5, 10, 10,  5, RC_NORMAL},           /* K */
    {5, 11, 11,  5, RC_NORMAL},           /* L */
    {5, 12, 12,  5, RC_NORMAL},           /* M */
    {5, 13, 13,  5, RC_NORMAL},           /* N */
    {5, 14, 14,  5, RC_NORMAL},           /* O */
    {5, 15, 15,  5, RC_NORMAL},           /* P */
    {5, 16, 16,  5, RC_NORMAL},           /* Q */
    {5, 17, 17,  5, RC_NORMAL},           /* R */
    {5, 18, 18,  5, RC_NORMAL},           /* S */
    {5, 19, 19,  5, RC_NORMAL},           /* T */
    {5, 20, 20,  5, RC_NORMAL},           /* U */
    {5, 21, 21,  5, RC_NORMAL},           /* V */
    {5, 22, 22,  5, RC_NORMAL},           /* W */
    {5, 23, 23,  5, RC_NORMAL},           /* X */
    {5, 24, 24,  5, RC_NORMAL},           /* Y */
    {5, 25, 25,  5, RC_NORMAL},           /* Z */
    {5, 27, 27,  5, RC_NORMAL},           /* [ */
    {5, 28, 28,  5, RC_NORMAL},           /* \ */
    {5, 29, 29,  5, RC_NORMAL},           /* ] */
    {5, 30, 30,  5, RC_NORMAL},           /* ^ */
    {5, 31, 31,  5, RC_NORMAL},           /* _ */
    {5, 32, 32,  5, RC_NORMAL},           /* ` */
    {5, 34, 34,  5, RC_NORMAL},           /* a */
    {5, 35, 35,  5, RC_NORMAL},           /* b */
    {5, 36, 36,  5, RC_NORMAL},           /* c */
    {5, 37, 37,  5, RC_NORMAL},           /* d */
    {5, 38, 38,  5, RC_NORMAL},           /* e */
    {5, 39, 39,  5, RC_NORMAL},           /* f */
    {5, 40, 40,  5, RC_NORMAL},           /* g */
    {5, 41, 41,  5, RC_NORMAL},           /* h */
    {5, 42, 42,  5, RC_NORMAL},           /* i */
    {5, 43, 43,  5, RC_NORMAL},           /* j */
    {5, 44, 44,  5, RC_NORMAL},           /* k */
    {5, 45, 45,  5, RC_NORMAL},           /* l */
    {5, 46, 46,  5, RC_NORMAL},           /* m */
    {5, 47, 47,  5, RC_NORMAL},           /* n */
    {5, 48, 48,  5, RC_NORMAL},           /* o */
    {5, 49, 49,  5, RC_NORMAL},           /* p */
    {5, 50, 50,  5, RC_NORMAL},           /* q */
    {5, 51, 51,  5, RC_NORMAL},           /* r */
    {5, 52, 52,  5, RC_NORMAL},           /* s */
    {5, 53, 53,  5, RC_NORMAL},           /* t */
    {5, 54, 54,  5, RC_NORMAL},           /* u */
    {5, 55, 55,  5, RC_NORMAL},           /* v */
    {5, 56, 56,  5, RC_NORMAL},           /* w */
    {5, 57, 57,  5, RC_NORMAL},           /* x */
    {5, 58, 58,  5, RC_NORMAL},           /* y */
    {5, 59, 59,  5, RC_NORMAL},           /* z */
    {5, 61, 61,  5, RC_NORMAL},           /* { */
    {5, 62, 62,  5, RC_NORMAL},           /* | */
    {5, 63, 63,  5, RC_NORMAL},           /* } */
    {5, 64, 64,  5, RC_NORMAL},           /* ~ */
    {8,  9,  9,  8, RC_NORMAL},           /*   */
    {8, 10, 10,  8, RC_NORMAL},           /* ! */
    {8, 11, 11,  8, RC_NORMAL},           /* " */
    {8, 12, 12,  8, RC_NORMAL},           /* # */
    {8, 13, 13,  8, RC_NORMAL},           /* $ */
    {8, 14, 14,  8, RC_NORMAL},           /* % */
    {8, 15, 15,  8, RC_NORMAL},           /* & */
    {8, 16, 16,  8, RC_NORMAL},           /* ' */
    {8, 17, 17,  8, RC_NORMAL},           /* ( */
    {8, 18, 18,  8, RC_NORMAL},           /* ) */
    {8, 19, 19,  8, RC_NORMAL},           /* * */
    {8, 20, 20,  8, RC_NORMAL},           /* + */
    {8, 21, 21,  8, RC_NORMAL},           /* , */
    {8, 22, 22,  8, RC_NORMAL},           /* - */
    {8, 23, 23,  8, RC_NORMAL},           /* . */
    {8, 24, 24,  8, RC_NORMAL},           /* / */
    {8, 25, 25,  8, RC_NORMAL},           /* 0 */
    {8, 26, 26,  8, RC_NORMAL},           /* 1 */
    {8, 27, 27,  8, RC_NORMAL},           /* 2 */
    {8, 28, 28,  8, RC_NORMAL},           /* 3 */
    {8, 29, 29,  8, RC_NORMAL},           /* 4 */
    {8, 30, 30,  8, RC_NORMAL},           /* 5 */
    {8, 31, 31,  8, RC_NORMAL},           /* 6 */
    {8, 32, 32,  8, RC_NORMAL},           /* 7 */
    {8, 33, 33,  8, RC_NORMAL},           /* 8 */
    {8, 34, 34,  8, RC_NORMAL},           /* 9 */
    {8, 35, 35,  8, RC_NORMAL},           /* : */
    {8, 36, 36,  8, RC_NORMAL},           /* ; */
    {8, 37, 37,  8, RC_NORMAL},           /* < */
    {8, 38, 38,  8, RC_NORMAL},           /* = */
    {8, 39, 39,  8, RC_NORMAL},           /* > */
    {8, 40, 40,  8, RC_NORMAL},           /* ? */
    {8, 41, 41,  8, RC_NORMAL},           /* @ */
   {10,  0,  0, 10, RC_NORMAL},           /* A */
   {10,  1,  1, 10, RC_NORMAL},           /* B */
   {10,  2,  2, 10, RC_NORMAL},           /* C */
   {10,  3,  3, 10, RC_NORMAL},           /* D */
   {10,  4,  4, 10, RC_NORMAL},           /* E */
   {10,  5,  5, 10, RC_NORMAL},           /* F */
   {10,  6,  6, 10, RC_NORMAL},           /* G */
   {10,  7,  7, 10, RC_NORMAL},           /* H */
   {10,  8,  8, 10, RC_NORMAL},           /* I */
   {10,  9,  9, 10, RC_NORMAL},           /* J */
   {10, 10, 10, 10, RC_NORMAL},           /* K */
   {10, 11, 11, 10, RC_NORMAL},           /* L */
   {10, 12, 12, 10, RC_NORMAL},           /* M */
   {10, 13, 13, 10, RC_NORMAL},           /* N */
   {10, 14, 14, 10, RC_NORMAL},           /* O */
   {10, 15, 15, 10, RC_NORMAL},           /* P */
   {10, 16, 16, 10, RC_NORMAL},           /* Q */
   {10, 17, 17, 10, RC_NORMAL},           /* R */
   {10, 18, 18, 10, RC_NORMAL},           /* S */
   {10, 19, 19, 10, RC_NORMAL},           /* T */
   {10, 20, 20, 10, RC_NORMAL},           /* U */
   {10, 21, 21, 10, RC_NORMAL},           /* V */
   {10, 22, 22, 10, RC_NORMAL},           /* W */
   {10, 23, 23, 10, RC_NORMAL},           /* X */
   {10, 24, 24, 10, RC_NORMAL},           /* Y */
   {10, 25, 25, 10, RC_NORMAL},           /* Z */
   {10, 27, 27, 10, RC_NORMAL},           /* [ */
   {10, 28, 28, 10, RC_NORMAL},           /* \ */
   {10, 29, 29, 10, RC_NORMAL},           /* ] */
   {10, 30, 30, 10, RC_NORMAL},           /* ^ */
   {10, 31, 31, 10, RC_NORMAL},           /* _ */
   {10, 32, 32, 10, RC_NORMAL},           /* ` */
   {10, 34, 34, 10, RC_NORMAL},           /* a */
   {10, 35, 35, 10, RC_NORMAL},           /* b */
   {10, 36, 36, 10, RC_NORMAL},           /* c */
   {10, 37, 37, 10, RC_NORMAL},           /* d */
   {10, 38, 38, 10, RC_NORMAL},           /* e */
   {10, 39, 39, 10, RC_NORMAL},           /* f */
   {10, 40, 40, 10, RC_NORMAL},           /* g */
   {10, 41, 41, 10, RC_NORMAL},           /* h */
   {10, 42, 42, 10, RC_NORMAL},           /* i */
   {10, 43, 43, 10, RC_NORMAL},           /* j */
   {10, 44, 44, 10, RC_NORMAL},           /* k */
   {10, 45, 45, 10, RC_NORMAL},           /* l */
   {10, 46, 46, 10, RC_NORMAL},           /* m */
   {10, 47, 47, 10, RC_NORMAL},           /* n */
   {10, 48, 48, 10, RC_NORMAL},           /* o */
   {10, 49, 49, 10, RC_NORMAL},           /* p */
   {10, 50, 50, 10, RC_NORMAL},           /* q */
   {10, 51, 51, 10, RC_NORMAL},           /* r */
   {10, 52, 52, 10, RC_NORMAL},           /* s */
   {10, 53, 53, 10, RC_NORMAL},           /* t */
   {10, 54, 54, 10, RC_NORMAL},           /* u */
   {10, 55, 55, 10, RC_NORMAL},           /* v */
   {10, 56, 56, 10, RC_NORMAL},           /* w */
   {10, 57, 57, 10, RC_NORMAL},           /* x */
   {10, 58, 58, 10, RC_NORMAL},           /* y */
   {10, 59, 59, 10, RC_NORMAL},           /* z */
   {10, 61, 61, 10, RC_NORMAL},           /* { */
   {10, 62, 62, 10, RC_NORMAL},           /* | */
   {10, 63, 63, 10, RC_NORMAL},           /* } */
   {10, 64, 64, 10, RC_NORMAL}};          /* ~ */

register int  i;
register char  *line;


/* pass field assignments to other routines */
*nfield = 190;
*rowcol_ptr = (int *) rowcol;

line = &inptext[TXT] [0] [0];
memset(line, '-', 80);
strncpy(line + 27, " KEYBOARD CONFIGURATION ", 24);
displin(posptr, line, 0, ascchar);

line = &inptext[TXT] [1] [0];
strncpy(line, "COMMAND ===>", 12);
memset(line + 12, ' ', 49);
strncpy(line + 61, "*** USE TAB KEY ***", 19);
displin(posptr, line, 1, ascchar);

line = &inptext[TXT] [2] [0];
strncpy(line, " Greek:   !\"#$%&'()*+,-./0123456789:;<=>?@", 42);
dsp8lin(posptr, line, 2);

*line_no = 3;
for (i = 32, *col_no = 9;  i < 65;  ++i, ++(*col_no))
    pgrkchr(posptr, grkexch[i], 0x00, YES, *nfield, rowcol,
        line_no, col_no, inptext, YES);

line = &inptext[TXT] [4] [0];
strncpy(line, "ABCDEFGHIJKLMNOPQRSTUVWXYZ [\\]^_`", 33);
strncpy(line+34, "abcdefghijklmnopqrstuvwxyz {|}~", 32);
dsp8lin(posptr, line, 4);

*line_no = 5;
for (i = 65, *col_no = 0;  i < 91;  ++i, ++(*col_no))
    pgrkchr(posptr, grkexch[i], 0x00, YES, *nfield, rowcol, line_no,
        col_no, inptext, YES);
++(*col_no);
for (i = 91; i < 97; ++i, ++(*col_no))
    pgrkchr(posptr, grkexch[i], 0x00, YES, *nfield, rowcol, line_no,
        col_no, inptext, YES);
++(*col_no);
for (i = 97; i < 123; ++i, ++(*col_no))
    pgrkchr(posptr, grkexch[i], 0x00, YES, *nfield, rowcol, line_no,
        col_no, inptext, YES);
++(*col_no);
for (i = 123; i < 127; ++i, ++(*col_no))
    pgrkchr(posptr, grkexch[i], 0x00, YES, *nfield, rowcol, line_no,
        col_no, inptext, YES);

line = &inptext[TXT] [7] [0];
strncpy(line, "Hebrew:   !\"#$%&'()*+,-./0123456789:;<=>?@", 42);
dsp8lin(posptr, line, 7);

*line_no = 8;
for (i = 32, *col_no = 9;  i < 65;  ++i, ++(*col_no))
    phebchr(posptr, hebexch[i], 0x00, YES, *nfield, rowcol, line_no,
        col_no, inptext, YES);

line = &inptext[TXT] [9] [0];
strncpy(line, "ABCDEFGHIJKLMNOPQRSTUVWXYZ [\\]^_`", 33);
strncpy(line+34, "abcdefghijklmnopqrstuvwxyz {|}~", 32);
dsp8lin(posptr, line, 9);

*line_no = 10;
for (i = 65, *col_no = 0;  i < 91;  ++i, ++(*col_no))
    phebchr(posptr, hebexch[i], 0x00, YES, *nfield, rowcol, line_no,
        col_no, inptext, YES);
++(*col_no);
for (i = 91; i < 97; ++i, ++(*col_no))
    phebchr(posptr, hebexch[i], 0x00, YES, *nfield, rowcol, line_no,
        col_no, inptext, YES);
++(*col_no);
for (i = 97; i < 123; ++i, ++(*col_no))
    phebchr(posptr, hebexch[i], 0x00, YES, *nfield, rowcol, line_no,
        col_no, inptext, YES);
++(*col_no);
for (i = 123; i < 127; ++i, ++(*col_no))
    phebchr(posptr, hebexch[i], 0x00, YES, *nfield, rowcol, line_no,
        col_no, inptext, YES);

line = &inptext[TXT] [12] [0];
#ifdef VMS
strncpy(line, "PRESS [Ctrl J] OR [Do] TO CONTINUE", 34);
#else
#ifdef S370
strncpy(line, "PRESS <Enter> TO CONTINUE", 25);
#else
strncpy(line, "PRESS [Ctrl J] OR [Ctrl Enter] TO CONTINUE", 42);
#endif
#endif
dsp8lin(posptr, line, 12);

line = &inptext[TXT] [13] [0];
strncpy(line, "ENTER 'end' COMMAND TO RETURN TO PRIOR PANEL", 44);
dsp8lin(posptr, line, 13);

*line_no = rowcol[0] [TOP_MAR];
*col_no = rowcol[0] [LEFT_MAR];

} /* end cfgkpan */
