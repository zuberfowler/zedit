#include <stdio.h>
#include <string.h>
#include "zedit.h"

void  cfgfget(
              union both_scr  *posptr,
              int  rowcol[] [5],
              char  inptext[] [25] [80])
/**********************************************************************/
/*                                                                    */
/* Process the config function key panel and write the config file    */
/* to disk.                                                           */
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
extern char  *_pgmptr;
extern char  grkexch[256];
extern char  hebexch[256];
extern unsigned int  fkeyset[4] [12];

register int  c;
register int  i;
register int  j;
register int  r;

char  cmdln[8];
FILE  *wds;
char  dsn[256];
int  col_no;
unsigned int  key[2];


/* find directory of zedit program and use its path */
dsn[0] = '\0';
i = strrchr(_pgmptr, '\\') - _pgmptr + 1;
if (i > 0)
    strncpy(dsn, _pgmptr, i);
dsn[i] = '\0';
strcat(dsn, "zedit.cfg");

wds = fopen(dsn, NEW_OUTPUT);
if (wds)
    {
    cmdln[7] = '\0';
    fprintf(wds, "%s", grkexch);
    fprintf(wds, "%s", hebexch);

    /* interpret function key commands */
    for (i = 0, r = 1;  i < 4;  ++i)
        for (j = 0;  j < 12;  ++j, ++r)
            {
            for (c = 2, col_no = rowcol[r][LEFT_MAR]; c < 7; ++c,
              ++col_no)
                cmdln[c] = inptext[TXT] [rowcol[r] [TOP_MAR]] [col_no];
            cmdline(posptr, key, cmdln);
            fprintf(wds, " %d", key[0]);
            fkeyset[i] [j] = key[0];
            } /* end for, for */

    fprintf(wds, "\n* Optional ZEDIT.CFG customization data set.\n");
    fclose(wds);
    } /* end then */
else
    dispmsg(posptr, CFGFGET_MSG1);

} /* end cfgfget */
