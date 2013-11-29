#include "zedit.h"

struct bufline  *keyslin(
              union both_scr  *posptr,
              struct bufline  *curr,
              struct lineptrs  *place)
/**********************************************************************/
/*                                                                    */
/* Display the PF key values in a protect line.                       */
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
extern unsigned int  fkeyset[4] [12];
extern unsigned int  cmdvals[CMDMAX];
extern char  cmdtxts[CMDMAX] [6];
static char  key[12][2] =
    {{' ', '1'},
     {' ', '2'},
     {' ', '3'},
     {' ', '4'},
     {' ', '5'},
     {' ', '6'},
     {' ', '7'},
     {' ', '8'},
     {' ', '9'},
     {'1', '0'},
     {'1', '1'},
     {'1', '2'}};
register struct bufline  *pos;
register int  c;
register int  i;
register int  j;


if (place -> colsb)
    {
    curr = place -> colsb;
    place -> colsb = NULL;
    } /* end then */

pos = protlin(posptr, curr, 82);

c = 0;
pos -> bline[c++] = PRECDR;
pos -> bline[c++] = BUF_ASCII;

for (i = 0; i < 12; ++i)
    for (j = 0; j < CMDMAX; ++j)
        if (fkeyset[0] [i] == cmdvals[j])
            {
            pos -> bline[c++] = key[i][0];
            pos -> bline[c++] = key[i][1];
            pos -> bline[c++] = cmdtxts[j] [0];
            pos -> bline[c++] = cmdtxts[j] [1];
            pos -> bline[c++] = cmdtxts[j] [2];
            pos -> bline[c++] = ' ';
            } /* end then */

pos -> bline[c++] = PRECDR;
if (pos -> next -> bline[0] == PRECDR)
    {
    pos -> bline[c++] = pos -> next -> bline[1];
    pos -> next -> script = pos -> next -> bline[1];
    } /* end then */
else
    pos -> bline[c++] = pos -> next -> script;

pos -> bline[c++] = ' ';
pos -> bline[c++] = '\n';
pos -> bline[c++] = '\0';

return(pos);
} /* end keyslin */
