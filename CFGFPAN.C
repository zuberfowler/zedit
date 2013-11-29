#include <string.h>
#include "zedit.h"

void  cfgfpan(
              union both_scr  *posptr,
              int  *line_no,
              int  *col_no,
              int  *nfield,
              int  **rowcol_ptr,
              char  inptext[] [25] [80])
/**********************************************************************/
/*                                                                    */
/* Change configuration values for function keys panel.               */
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
extern unsigned int  fkeyset[4] [12];
extern unsigned int  cmdvals[CMDMAX];
extern char  cmdtxts[CMDMAX] [6];

static int  rowcol[49] [5] =
   {{1, 13, 60,  1, RC_ENTRY},            /* cmd line */
    {5,  8, 12,  5, RC_NORMAL},           /* PF1  */
    {5, 14, 18,  5, RC_NORMAL},           /* PF2  */
    {5, 20, 24,  5, RC_NORMAL},           /* PF3  */
    {5, 26, 30,  5, RC_NORMAL},           /* PF4  */
    {5, 32, 36,  5, RC_NORMAL},           /* PF5  */
    {5, 38, 42,  5, RC_NORMAL},           /* PF6  */
    {5, 44, 48,  5, RC_NORMAL},           /* PF7  */
    {5, 50, 54,  5, RC_NORMAL},           /* PF8  */
    {5, 56, 60,  5, RC_NORMAL},           /* PF9  */
    {5, 62, 66,  5, RC_NORMAL},           /* PF10 */
    {5, 68, 72,  5, RC_NORMAL},           /* PF11 */
    {5, 74, 78,  5, RC_NORMAL},           /* PF12 */
    {6,  8, 12,  6, RC_NORMAL},           /* SHIFT PF1  */
    {6, 14, 18,  6, RC_NORMAL},           /* SHIFT PF2  */
    {6, 20, 24,  6, RC_NORMAL},           /* SHIFT PF3  */
    {6, 26, 30,  6, RC_NORMAL},           /* SHIFT PF4  */
    {6, 32, 36,  6, RC_NORMAL},           /* SHIFT PF5  */
    {6, 38, 42,  6, RC_NORMAL},           /* SHIFT PF6  */
    {6, 44, 48,  6, RC_NORMAL},           /* SHIFT PF7  */
    {6, 50, 54,  6, RC_NORMAL},           /* SHIFT PF8  */
    {6, 56, 60,  6, RC_NORMAL},           /* SHIFT PF9  */
    {6, 62, 66,  6, RC_NORMAL},           /* SHIFT PF10 */
    {6, 68, 72,  6, RC_NORMAL},           /* SHIFT PF11 */
    {6, 74, 78,  6, RC_NORMAL},           /* SHIFT PF12 */
    {7,  8, 12,  7, RC_NORMAL},           /* CTRL PF1  */
    {7, 14, 18,  7, RC_NORMAL},           /* CTRL PF2  */
    {7, 20, 24,  7, RC_NORMAL},           /* CTRL PF3  */
    {7, 26, 30,  7, RC_NORMAL},           /* CTRL PF4  */
    {7, 32, 36,  7, RC_NORMAL},           /* CTRL PF5  */
    {7, 38, 42,  7, RC_NORMAL},           /* CTRL PF6  */
    {7, 44, 48,  7, RC_NORMAL},           /* CTRL PF7  */
    {7, 50, 54,  7, RC_NORMAL},           /* CTRL PF8  */
    {7, 56, 60,  7, RC_NORMAL},           /* CTRL PF9  */
    {7, 62, 66,  7, RC_NORMAL},           /* CTRL PF10 */
    {7, 68, 72,  7, RC_NORMAL},           /* CTRL PF11 */
    {7, 74, 78,  7, RC_NORMAL},           /* CTRL PF12 */
    {8,  8, 12,  8, RC_NORMAL},           /* ALT PF1  */
    {8, 14, 18,  8, RC_NORMAL},           /* ALT PF2  */
    {8, 20, 24,  8, RC_NORMAL},           /* ALT PF3  */
    {8, 26, 30,  8, RC_NORMAL},           /* ALT PF4  */
    {8, 32, 36,  8, RC_NORMAL},           /* ALT PF5  */
    {8, 38, 42,  8, RC_NORMAL},           /* ALT PF6  */
    {8, 44, 48,  8, RC_NORMAL},           /* ALT PF7  */
    {8, 50, 54,  8, RC_NORMAL},           /* ALT PF8  */
    {8, 56, 60,  8, RC_NORMAL},           /* ALT PF9  */
    {8, 62, 66,  8, RC_NORMAL},           /* ALT PF10 */
    {8, 68, 72,  8, RC_NORMAL},           /* ALT PF11 */
    {8, 74, 78,  8, RC_NORMAL}};          /* ALT PF12 */

register int  i;
register int  j;
register char  *line;


/* pass field assignments to other routines */
*nfield = 48;
*rowcol_ptr = (int *) rowcol;

line = &inptext[TXT] [0] [0];
memset(line, '-', 80);
strncpy(line + 25, " FUNCTION KEY CONFIGURATION ", 28);
displin(posptr, line, 0, ascchar);

line = &inptext[TXT] [1] [0];
strncpy(line, "COMMAND ===>", 12);
memset(line + 12, ' ', 50);
displin(posptr, line, 1, ascchar);

line = &inptext[TXT] [3] [0];
strncpy(line, "state   PF1   PF2   PF3   PF4   PF5   PF6   PF7   PF8\
   PF9   PF10  PF11  PF12", 78);
dsp8lin(posptr, line, 3);

line = &inptext[TXT] [4] [0];
memset(line, '=', 80);
dsp8lin(posptr, line, 4);


line = &inptext[TXT] [5] [0];
strncpy(line, "<none>", 6);
for (i = 0; i < 12; ++i)
    for (j = 0; j < CMDMAX; ++j)
        if (fkeyset[0] [i] == cmdvals[j])
            strncpy(&inptext[TXT] [5] [rowcol[i+1] [LEFT_MAR]],
                &cmdtxts[j] [0], 5);
dsp8lin(posptr, line, 5);

line = &inptext[TXT] [6] [0];
strncpy(line, "SHIFT", 5);
for (i = 0; i < 12; ++i)
    for (j = 0; j < CMDMAX; ++j)
        if (fkeyset[1] [i] == cmdvals[j])
            strncpy(&inptext[TXT] [6] [rowcol[i+13] [LEFT_MAR]],
                &cmdtxts[j] [0], 5);
dsp8lin(posptr, line, 6);

line = &inptext[TXT] [7] [0];
strncpy(line, "CTRL", 4);
for (i = 0; i < 12; ++i)
    for (j = 0; j < CMDMAX; ++j)
        if (fkeyset[2] [i] == cmdvals[j])
            strncpy(&inptext[TXT] [7] [rowcol[i+25] [LEFT_MAR]],
                &cmdtxts[j] [0], 5);
dsp8lin(posptr, line, 7);

line = &inptext[TXT] [8] [0];
strncpy(line, "ALT", 3);
for (i = 0; i < 12; ++i)
    for (j = 0; j < CMDMAX; ++j)
        if (fkeyset[3] [i] == cmdvals[j])
            strncpy(&inptext[TXT] [8] [rowcol[i+37] [LEFT_MAR]],
                &cmdtxts[j] [0], 5);
dsp8lin(posptr, line, 8);

line = &inptext[TXT] [12] [0];
#ifdef VMS
strncpy(line, "PRESS [Ctrl J] OR [Do] TO SAVE CONFIGURATION", 44);
#else
#ifdef S370
strncpy(line, "PRESS <Enter> TO SAVE CONFIGURATION", 35);
#else
strncpy(line, "PRESS [Ctrl J] OR [Ctrl Enter] TO SAVE CONFIGURATION",
    52);
#endif
#endif
dsp8lin(posptr, line, 12);

line = &inptext[TXT] [13] [0];
strncpy(line, "ENTER 'end' COMMAND TO RETURN TO PRIOR PANEL", 44);
dsp8lin(posptr, line, 13);

*line_no = rowcol[0] [TOP_MAR];
*col_no = rowcol[0] [LEFT_MAR];

} /* end cfgfpan */
