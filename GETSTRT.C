#include "zedit.h"

void  getstrt(
              int  coloffset,
              char  bline[],
              int  temp_rowcol[] [5],
              char  *scratch,
              int  *where,
              int  *amode,
              int  *eol,
              int  *toright)
/**********************************************************************/
/*                                                                    */
/* Calculate starting position in buffer record for screen display.   */
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
int  column;
int  tmap[3];
char  tbuf[3];
char  ttxt[3];


column = 0;

/* when scrolled over to the right */
while (column < coloffset  &&  !(*eol))
    {
    if (bline[*where] == '\n')
        {
        *eol = YES;
        *where += (coloffset - column - 1);
        } /* end then */
    else
        while (bline[*where] == PRECDR)
            {
            ++(*where);
            switch(bline[*where])
                {
                case BUF_HEBREW:
                    *amode = bline[*where];
                    *toright = NO;
                    break;
                case BUF_CHGDIR:
                    *toright = !(*toright);
                    break;
                default:
                    *amode = bline[*where];
                    *toright = YES;
                    break;
                } /* end switch */
            ++(*where);
            } /* end while */

    convinp(NULL, bline[*where], 0x00, *amode, YES, &dummy, &column, 0,
        temp_rowcol, (char (*)[25][80]) scratch, NO);
    ++(*where);

    } /* end while */

if (!(*eol))
    {
    tbuf[2] = '\0';
    tmap[1] = 0;
    while (!tmap[1]  &&  bline[*where] != '\n'  &&
      bline[*where] != PRECDR  &&  bline[*where])
        {
        tbuf[0] = bline[(*where) - 1];
        tbuf[1] = bline[*where];
        txtonly(*amode, tbuf, ttxt, tmap);
        if (!tmap[1])
            ++(*where);
        } /* end while */
    } /* end then */

} /* end getstrt */
