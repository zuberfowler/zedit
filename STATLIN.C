#include <string.h>
#include "zedit.h"

void  statlin(
              union both_scr  *posptr,
              int  amode,
              unsigned int  shift,
              int  toright,
              char  inptext[] [25] [80])
/**********************************************************************/
/*                                                                    */
/* Display the current settings of options in the message area.       */
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
extern unsigned int  graphic;
static char  *mdetxt[5] =
    {"  REG ", "  SPC ", "  GRK ", "  HEB ", "  LAT "};
static char  *dirtxt[2] = {"TORIGHT ", "TOLEFT  "};
static char  *instxt[2] = {"INS ", "OVR "};

register int  t;
register char  *line;


line = &inptext[TXT] [0] [0];

memset(line + 50, '-', 12);

strncpy(line + 62, mdetxt[amode - BUF_ASCII], 6);

if (toright)
    t = 0;
else
    t = 1;
strncpy(line + 68, dirtxt[t], 8);

if (shift & INS_LOCK)
    t = 0;
else
    t = 1;
strncpy(line + 76, instxt[t], 4);

for (t = 50; t < 80; ++t)
    dsp8chr(posptr, inptext[TXT] [0] [t], 0, t);
if (graphic & XGA)
    xga8514(posptr, 0, RDSPLIN);

} /* end statlin */
