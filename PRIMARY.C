#include <string.h>
#include "zedit.h"

void  primary(
              union both_scr  *posptr,
              int  *line_no,
              int  *col_no,
              int  *nfield,
              int  **rowcol_ptr,
              char  inptext[] [25] [80])
/**********************************************************************/
/*                                                                    */
/* Primary option menu panel definition.                              */
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

static int  rowcol[1] [5] = {{1, 13, 60,  1, RC_ENTRY}};
static int  rclogo[1] [5] = {{7, 70, 79,  9, RC_ENTRY}};
static char *hebstr = "sEqEj";
static char *grkstr = "ha'natov";

register char  *line;
char  time[6];
char  date[9];


whenow(time, date);

/* pass field assignments to other routines */
*nfield = 0;
*rowcol_ptr = (int *) rowcol;

line = &inptext[TXT] [0] [0];
memset(line, '-', 29);
strncpy(line + 29, " PRIMARY OPTION MENU ", 21);
memset(line + 50, '-', 30);
displin(posptr, line, 0, ascchar);

line = &inptext[TXT] [1] [0];
strncpy(line, "COMMAND ===>", 12);
memset(line + 12, ' ', 50);
displin(posptr, line, 1, ascchar);

line = &inptext[TXT] [3] [0];
strncpy(line, "         0  CONFIG  - Create optional configuration", 51);
memset(line + 51, ' ', 8);
strncpy(line + 59, "VERSION  - ZEDIT ", 17);
strncpy(line + 76, ZEDIT_VERSION, 4);
dsp8lin(posptr, line, 3);

line = &inptext[TXT] [4] [0];
strncpy(line, "         1  BROWSE  - Display existing data set", 47);
memset(line + 47, ' ', 12);
strncpy(line + 59, "TIME     - ", 11);
strncpy(line + 70, time, 5);
dsp8lin(posptr, line, 4);

line = &inptext[TXT] [5] [0];
strncpy(line, "         2  EDIT    - Create or change data set", 47);
memset(line + 47, ' ', 12);
strncpy(line + 59, "DATE     - ", 11);
strncpy(line + 70, date, 8);
dsp8lin(posptr, line, 5);

*line_no = 7;
*col_no = 76;
for (line = hebstr; *line; ++line)
    phebchr(posptr, *line, 0x00, NO, *nfield, rclogo, line_no, col_no,
        inptext, YES);

line = &inptext[TXT] [8] [0];
strncpy(line, "     51,52  IMPGRK,IMPHEB - Convert to ZEDIT codes", 50);
inptext[TXT] [8] [75] = '=';
dsp8lin(posptr, line, 8);

line = &inptext[TXT] [9] [0];
strncpy(line,
    "  53,54,56  EXPGRK,EXPHEB,EXPHHI - Convert from ZEDIT codes", 59);
dsp8lin(posptr, line, 9);
*line_no = 9;
*col_no = 72;
for (line = grkstr; *line; ++line)
    pgrkchr(posptr, *line, 0x00, YES, *nfield, rclogo, line_no, col_no,
        inptext, YES);
zedlogo(posptr);

line = &inptext[TXT] [10] [0];
strncpy(line, "         X  EXITSYS - Terminate session", 44);
dsp8lin(posptr, line, 10);

line = &inptext[TXT] [12] [0];
#ifdef VMS
strncpy(line, "PRESS [Ctrl J] OR [Do] TO PROCESS PANEL", 39);
#else
#ifdef S370
strncpy(line, "PRESS <Enter> TO PROCESS PANEL", 30);
#else
strncpy(line, "PRESS [Ctrl J] OR [Ctrl Enter] TO PROCESS PANEL", 47);
#endif
#endif
dsp8lin(posptr, line, 12);

line = &inptext[TXT] [13] [0];
strncpy(line, "ENTER 'end' COMMAND TO RETURN TO PRIOR PANEL", 44);
dsp8lin(posptr, line, 13);

*line_no = rowcol[0] [TOP_MAR];
*col_no = rowcol[0] [LEFT_MAR];

} /* end primary */
