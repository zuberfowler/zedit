#include <string.h>
#include "zedit.h"

void  edbrpan(
              union both_scr  *posptr,
              char  inptext[] [25] [80],
              char  dsn[],
              int  edit)
/**********************************************************************/
/*                                                                    */
/* Common code for edit and browse panel displays.                    */
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

register char  *line;
register int  c;


line = &inptext[TXT] [0] [0];
if (edit)
    strncpy(line, "EDIT ---- ", 10);
else
    strncpy(line, "BROWSE -- ", 10);
for (c = 0; c < 56  &&  dsn[c]; ++c)
    inptext[TXT] [0] [c + 10] = dsn[c];
strncpy(line + c + 10, " ", 1);
memset(line + c + 11, '-', 52 - c);
/* display done in topline() */

line = &inptext[TXT] [1] [0];
strncpy(line, "COMMAND ===>", 12);
memset(line + 12, ' ', 51);
strncpy(line + 63, "SCROLL ===> ", 12);
if (edit)
    strncpy(line + 75, "HALF", 4);
else
    strncpy(line + 75, "PAGE", 4);
displin(posptr, line, 1, ascchar);

} /* end edbrpan */
