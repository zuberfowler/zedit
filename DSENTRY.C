#include <string.h>
#include "zedit.h"

void  dsentry(
              union both_scr  *posptr,
              int  *line_no,
              int  *col_no,
              int  *nfield,
              int  **rowcol_ptr,
              char  inptext[] [25] [80],
              char  *selfor)
/**********************************************************************/
/*                                                                    */
/* Data set name entry panel, used by both edit and browse.           */
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

static int  rowcol[10] [5] =
   {{1, 13, 60,  1, RC_ENTRY},            /* cmd line */
#ifdef VMS
    {4, 15, 18,  4, RC_ENTRY},            /* drive */
#else
    {4, 15, 15,  4, RC_ENTRY},            /* drive */
#endif
    {5, 15, 22,  5, RC_ENTRY},            /* path1 */
    {5, 30, 37,  5, RC_ENTRY},            /* path2 */
    {5, 45, 52,  5, RC_ENTRY},            /* path3 */
    {6, 15, 22,  6, RC_ENTRY},            /* name */
#ifdef S370
    {7, 15, 22,  7, RC_ENTRY},            /* ext */
#else
    {7, 15, 17,  7, RC_ENTRY},            /* ext */
#endif
#ifdef VMS
    {8, 15, 17,  8, RC_ENTRY},            /* version */
#else
#ifdef S370
    {8, 15, 22,  8, RC_ENTRY},            /* member */
#else
    {7, 15, 17,  7, RC_PROTECT},          /* dummy */
#endif
#endif
    {9, 27, 78,  9, RC_ENTRY},            /* other dsn */
   {10, 27, 31, 10, RC_ENTRY}};           /* maxlrecl */

register char  *line;


/* pass field assignments to other routines */
*nfield = 9;
*rowcol_ptr = (int *) rowcol;

line = &inptext[TXT] [0] [0];
memset(line, '-', 80);
strcpy(line, selfor);
*(line + strlen(selfor)) = ' ';
strncpy(line + 28, " DATA SET ENTRY PANEL ", 22);
displin(posptr, line, 0, ascchar);

line = &inptext[TXT] [1] [0];
strncpy(line, "COMMAND ===>", 12);
memset(line + 12, ' ', 50);
displin(posptr, line, 1, ascchar);

line = &inptext[TXT] [3] [0];
strncpy(line, "DATA SET DEFINITION:", 20);
dsp8lin(posptr, line, 3);

line = &inptext[TXT] [4] [0];
strncpy(line, "    DRIVE ===>", 14);
dsp8lin(posptr, line, 4);

line = &inptext[TXT] [5] [0];
strncpy(line, "    PATH  ===>           ", 25);
strncpy(line + 25, "===>           ", 15);
strncpy(line + 40, "===>", 4);
dsp8lin(posptr, line, 5);

line = &inptext[TXT] [6] [0];
strncpy(line, "    NAME  ===>", 14);
dsp8lin(posptr, line, 6);

line = &inptext[TXT] [7] [0];
strncpy(line, "    EXT   ===>", 14);
dsp8lin(posptr, line, 7);

#ifdef S370
line = &inptext[TXT] [8] [0];
strncpy(line, "    MEM   ===>", 14);
dsp8lin(posptr, line, 8);
#endif

#ifdef VMS
line = &inptext[TXT] [8] [0];
strncpy(line, "    VER   ===>", 14);
dsp8lin(posptr, line, 8);
#endif

line = &inptext[TXT] [9] [0];
strncpy(line, "Free Format DSN Entry ===> ", 27);
dsp8lin(posptr, line, 9);

line = &inptext[TXT] [10] [0];
strncpy(line, "MAXIMUM RECORD LENGTH ===>         ", 35);
strncpy(line + 35, "<Default = 258 (256 screen columns)>", 36);
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

} /* end dsentry */
