#include <string.h>
#include "zedit.h"

void  buftsln(
              union both_scr  *posptr,
              int  nfield,
              int  rowcol[] [5],
              register struct bufline  *curr,
              int  line_no,
              int  maxlrecl,
              char  inptext[] [25] [80],
              int  *where,
              int  *amode,
              int  *eol,
              int  *toright,
              int  *col_no)
/**********************************************************************/
/*                                                                    */
/* Move the data from the input buffer linear format to the inptext   */
/* triplex format and display one line.                               */
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
int  c;
int  ln;
int  max;
int  tmap[3];
int  line_process;
unsigned int  ashift;
char  tbuf[3];
char  ttxt[3];


line_process = YES;
c = *col_no;
tbuf[2] = '\0';

while (line_process)
    {
    if (curr -> status & ST_PROT)
        {
        inptext[ATR] [line_no] [*col_no] |= ATR_PROTECT;
        max = strlen(curr -> bline);
        } /* end then */
    else
        {
        inptext[ATR] [line_no] [*col_no] &= ~ATR_PROTECT;
        max = maxlrecl;
        } /* end else */

    if (*where < max  &&  !(*eol))
        {
        if (curr -> bline[*where] == '\n')
            {
            *eol = YES;
            ++(*where);
            } /* end then */
        else
            while (curr -> bline[*where] == PRECDR)
                {
                ++(*where);
                switch(curr -> bline[*where])
                    {
                    case BUF_CHGDIR:
                        *toright = !(*toright);
                        *col_no = rowcol[nfield] [RIGHT_MAR] -
                            *col_no + rowcol[nfield] [LEFT_MAR];
                        c = *col_no;
                        break;
                    case BUF_HEBREW:
                        *amode = curr -> bline[*where];
                        if (*toright)
                            {
                            *toright = NO;
                            *col_no = rowcol[nfield] [RIGHT_MAR] -
                                *col_no + rowcol[nfield] [LEFT_MAR];
                            c = *col_no;
                            } /* end then */
                        break;
                    default:
                        *amode = curr -> bline[*where];
                        if (!(*toright))
                            {
                            *toright = YES;
                            *col_no = rowcol[nfield] [RIGHT_MAR] -
                                *col_no + rowcol[nfield] [LEFT_MAR];
                            c = *col_no;
                            } /* end then */
                        break;
                    } /* end switch */
                ++(*where);
                } /* end while, else */

        if (curr -> status == ST_PROTSCRL)
            ashift = EXCLMSG;
        else
            ashift = 0x00;

        convinp(posptr, curr -> bline[*where], ashift, *amode, *toright,
            &line_no, col_no, nfield, rowcol, inptext, YESMAYBE);

        ++(*where);
        } /* end then */
    else
        convinp(posptr, ' ', 0x00, *amode, *toright, &line_no, col_no,
            nfield, rowcol, inptext, YESMAYBE);

    if (c == *col_no)
        if (*toright)
            {
            ln = line_no;
            entfield(leftcsr, *toright, nfield, rowcol, &ln, &c);
            } /* end then */
        else
            {
            ln = line_no;
            entfield(rightcsr, *toright, nfield, rowcol, &ln, &c);
            } /* end then */

    if ((*toright  &&  c == rowcol[nfield] [RIGHT_MAR])  ||
      (!(*toright)  &&  c == rowcol[nfield] [LEFT_MAR]))
        if (*eol  || curr -> bline[*where] == '\n'  ||
              !(curr -> bline[*where])  ||
              curr -> bline[*where] == PRECDR)
            line_process = NO;
        else
            {
            tbuf[0] = curr -> bline[(*where) - 1];
            tbuf[1] = curr -> bline[*where];
            txtonly(*amode, tbuf, ttxt, tmap);
            if (tmap[1])
                line_process = NO;
            } /* end else, then */

    c = *col_no;
    } /* end while */

} /* end buftsln */
