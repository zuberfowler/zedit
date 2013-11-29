#include <stdio.h>
#include <string.h>
#include "zedit.h"

void  panlcmd(
              union both_scr  *posptr,
              int  *line_no,
              int  *col_no,
              unsigned int  *panel,
              int  *nfield,
              int  **rowcol,
              char  inptext[] [25] [80],
              char  dsn[56],
              int  maxlrecl,
              unsigned int  cmd[],
              int  *coloffset,
              struct bufline  **first,
              struct bufline  **curr,
              int  wherest[25],
              int  wherend[25],
              int  *dschanged,
              struct lineptrs  *place,
              int  rightmar)
/**********************************************************************/
/*                                                                    */
/* Execute panel commands.                                            */
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
FILE  *ds;
unsigned int  pcmd;
char  selfor[8];

/* cmd subscript */
register int  c;


/* turn off cmd grouping */
pcmd = cmd[0] & WHCHPAN;

if (pcmd & PRIMARY)
    {
    *panel = PRIMARY;
    primary(posptr, line_no, col_no, nfield, rowcol, inptext);
    } /* end then */
else if (pcmd & DSENTRY)
    {
    *panel = DSENTRY;
    switch(cmd[3])
        {
        case SEL_BROWPAN:
            strcpy(selfor, "BROWSE");
            break;
        case SEL_EDITPAN:
            strcpy(selfor, "EDIT");
            break;
        case SEL_COPYDSN:
            strcpy(selfor, "COPY");
            break;
        case IGRKPRC:
            strcpy(selfor, "IMPGRK");
            break;
        case IHEBPRC:
            strcpy(selfor, "IMPHEB");
            break;
        case EGRKPRC:
            strcpy(selfor, "EXPGRK");
            break;
        case EHEBPRC:
            strcpy(selfor, "EXPHEB");
            break;
        case EHHIPRC:
            strcpy(selfor, "EXPHHI");
            break;
        } /* end switch */
    dsentry(posptr, line_no, col_no, nfield, rowcol, inptext, selfor);
    } /* end then */
else if (pcmd & BROWPAN)
    {
    ds = fopen(dsn, OLD_INPUT);
    if (ds)
        {
        *first = readbuf(posptr, ds, maxlrecl);
        *curr = *first;
        fclose(ds);
        *panel = BROWPAN;
        browpan(posptr, line_no, col_no, nfield, rowcol, inptext,
            dsn, rightmar);
        *coloffset = 0;
        buftscr(posptr, *nfield, (int (*)[5]) *rowcol, inptext, *curr,
            maxlrecl, *coloffset, wherest, wherend, place, YES);
        } /* end then */
    else
        {
        /* clean off the stack */
        for (c = 2; c < STACKMAX; ++c)
            cmd[c] = NOP;
        cmd[1] = BROWSE;
        dispmsg(posptr, PANLCMD_MSG1);
        } /* end else */
    } /* end then */
else if (pcmd & EDITPAN)
    {
    ds = fopen(dsn, MOD_INOUT);
#ifdef S370
    if (ds)
        ds = fopen(dsn, OLD_INPUT);
#endif
    if (ds)
        {
        *dschanged = NO;
        fseek(ds, 0L, SEEK_SET);
        *first = readbuf(posptr, ds, maxlrecl);
        *curr = *first;
        fclose(ds);
        *panel = EDITPAN;
        editpan(posptr, line_no, col_no, nfield, rowcol, inptext,
            dsn, rightmar);
        *coloffset = 0;
        buftscr(posptr, *nfield, (int (*)[5]) *rowcol, inptext, *curr,
            maxlrecl, *coloffset, wherest, wherend, place, NO);
        } /* end then */
    else
        {
        /* clean off the stack */
        for (c = 2; c < STACKMAX; ++c)
            cmd[c] = NOP;
        cmd[1] = EDIT;
        dispmsg(posptr, PANLCMD_MSG2);
        } /* end else */
    } /* end then */
else if (pcmd & CFGKPAN)
    {
    *panel = CFGKPAN;
    cfgkpan(posptr, line_no, col_no, nfield, rowcol, inptext);
    } /* end then */
else if (pcmd & CFGFPAN)
    {
    *panel = CFGFPAN;
    cfgfpan(posptr, line_no, col_no, nfield, rowcol, inptext);
    } /* end then */

} /* end panlcmd */
