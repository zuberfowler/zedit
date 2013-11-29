#include "zedit.h"

void  txtonly(
              int  amode,
              char  bline[],
              char  txtline[],
              int  map[])
/**********************************************************************/
/*                                                                    */
/* Move the data from the input buffer linear format to the triplex   */
/* format in order to be able to have the data in consonant TXT       */
/* format without any diacritics.  Also build a map between bline     */
/* and txtline while building txtline.  Map and txtline do not need   */
/* to be initialized (except see following).                          */
/*                                                                    */
/* Txtonly is also used in some routines with a two character bline   */
/* for the purpose of testing whether the second character is a       */
/* diacritic or not.  When used in this way test map[1] after the     */
/* call for non-zero.  It will be 1 if the second character was not   */
/* a diacritic.                                                       */
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
static int  dummy = 0;
register int  where = 0;
register int  t = -1;

int  column = 0;
int  last_col = 0;
int  rc[1] [5];
char  scratch[3] [25] [80];


/**********************************************************************/
/* The field is 3 characters wide.  The subscript (column) determines */
/* the logic for taking txt off of a position of the field.  It is    */
/* delayed until the subscript has moved sufficiently far enough to   */
/* indicate that there can be no more diacritics.                     */
/**********************************************************************/
rc[0] [0] = 0;
rc[0] [1] = 0;
rc[0] [2] = 2;
rc[0] [3] = 0;
rc[0] [4] = RC_ENTRY;

while (bline[where]  &&  (bline[where] != '\n'))
    {
    while (bline[where] == PRECDR)
        {
        map[where] = 0;
        ++where;
        amode = bline[where];
        map[where] = 0;
        ++where;
        } /* end while */

    convinp(NULL, bline[where], 0x00, amode, YES, &dummy, &column, 0,
        rc, scratch, NO);

    switch(column)
        {
        case 0:
            if (last_col != column)
                {
                if (t != -1)
                    {
                    txtline[t] = scratch[TXT] [0] [1];
                    map[where - 1] = t;
                    } /* end then */
                ++t;
                } /* end then */
            break;
        case 1:
            if (last_col != column)
                {
                if (t != -1)
                    {
                    txtline[t] = scratch[TXT] [0] [2];
                    map[where - 1] = t;
                    } /* end then */
                ++t;
                } /* end then */
            break;
        case 2:
            if (last_col != column)
                {
                if (t != -1)
                    {
                    txtline[t] = scratch[TXT] [0] [0];
                    map[where - 1] = t;
                    } /* end then */
                ++t;
                } /* end then */
            break;
        } /* end switch */

    last_col = column;
    ++where;
    map[where] = 0;
    } /* end while */

map[where - 1] = t;

switch(column)
    {
    case 0:
        txtline[t++] = scratch[TXT] [0] [2];
        break;
    case 1:
        txtline[t++] = scratch[TXT] [0] [0];
        break;
    case 2:
        txtline[t++] = scratch[TXT] [0] [1];
        break;
    } /* end switch */

txtline[t] = '\0';

} /* end txtonly */
