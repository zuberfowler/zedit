#include <string.h>
#include "zedit.h"

struct bufline  *letslin(
              union both_scr  *posptr,
              int  maxlrecl,
              struct bufline  *curr,
              struct lineptrs  *place)
/**********************************************************************/
/*                                                                    */
/* Create the letter help protect lines.                              */
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
register struct bufline  *pos1;
register struct bufline  *pos2;
register struct bufline  *pos3;
register int  i;
int  g;
int  h;
int  len;


/* g and h are count of extra letters for Greek and Hebrew */
g = 0;
h = 2;
len = (maxlrecl > 134) ? maxlrecl : 134;

if (place -> colsb)
    {
    curr = place -> colsb;
    place -> colsb = NULL;
    } /* end then */

pos3 = protlin(posptr, curr, len);
pos3 -> status |= ST_SCRL;
pos2 = protlin(posptr, pos3, len);
pos2 -> status |= ST_SCRL;
pos1 = protlin(posptr, pos2, len);
pos1 -> status |= ST_SCRL;

pos1 -> bline[0] = PRECDR;
pos1 -> bline[1] = BUF_ASCII;

pos2 -> script = BUF_ASCII;
pos2 -> bline[0] = PRECDR;
pos2 -> bline[1] = BUF_GREEK;

pos3 -> script = BUF_GREEK;
pos3 -> bline[0] = PRECDR;
pos3 -> bline[1] = BUF_HEBREW;
pos3 -> bline[2] = PRECDR;
pos3 -> bline[3] = BUF_CHGDIR;

strncpy(&(pos1 -> bline[2]), "abcdefghijklmnopqrstuvwxyz {|}~ ", 32);
for (i = 97; i < 123; ++i)
    {
    g = letsgrk(i, g, -95, pos2 -> bline);
    h = letsheb(i, h, -95, pos3 -> bline);
    } /* end for */
pos2 -> bline[28+g] = ' ';
pos3 -> bline[28+h] = ' ';
for (i = 123; i < 127; ++i)
    {
    g = letsgrk(i, g, -94, pos2 -> bline);
    h = letsheb(i, h, -94, pos3 -> bline);
    } /* end for */
pos2 -> bline[33+g] = ' ';
pos3 -> bline[33+h] = ' ';

strncpy(&(pos1-> bline[34]), "ABCDEFGHIJKLMNOPQRSTUVWXYZ [\\]^_` ", 34);
for (i = 65;  i < 91;  ++i)
    {
    g = letsgrk(i, g, -31, pos2 -> bline);
    h = letsheb(i, h, -31, pos3 -> bline);
    } /* end for */
pos2 -> bline[60+g] = ' ';
pos3 -> bline[60+h] = ' ';
for (i = 91; i < 97; ++i)
    {
    g = letsgrk(i, g, -30, pos2 -> bline);
    h = letsheb(i, h, -30, pos3 -> bline);
    } /* end for */

strncpy(&(pos1 -> bline[68]), "!\"#$%&'()*+,-./0123456789:;<=>?@", 32);
for (i = 32;  i < 65;  ++i)
    {
    g = letsgrk(i, g, 35, pos2 -> bline);
    h = letsheb(i, h, 35, pos3 -> bline);
    } /* end for */

pos1 -> bline[100] = '\n';
pos1 -> bline[101] = '\0';

pos2 -> bline[100+g] = '\n';
pos2 -> bline[101+g] = '\0';

pos3 -> bline[100+h] = PRECDR;
if (pos3 -> next -> bline[0] == PRECDR)
    {
    pos3 -> bline[101+h] = pos3 -> next -> bline[1];
    pos3 -> next -> script = pos3 -> next -> bline[1];
    } /* end then */
else
    pos3 -> bline[101+h] = pos3 -> next -> script;

pos3 -> bline[102+h] = ' ';
pos3 -> bline[103+h] = '\n';
pos3 -> bline[104+h] = '\0';

return(pos1);
} /* end letslin */
