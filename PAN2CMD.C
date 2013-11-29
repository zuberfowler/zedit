#include <stdio.h>
#include <string.h>
#include "zedit.h"

void  pan2cmd(
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
              struct bufline  *curr,
              int  wherest[25],
              int  wherend[25],
              int  *dschanged,
              register struct lineptrs  *place,
              int  rightmar)
/**********************************************************************/
/*                                                                    */
/* Execute panel/major commands.  Module structure is based on        */
/* panlcmd.c.                                                         */
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
extern char  grkexch[256];
extern char  hebexch[256];

static char  savedsn[56];
static unsigned int  savepanel;
static char  exp[5] = {'.', 'E', 'X', 'P', '\0'};
static char  heb[5] = {'.', 'H', 'E', 'B', '\0'};
static char  zed[5] = {'.', 'Z', 'E', 'D', '\0'};

register struct bufline  *last;
register struct bufline  *strt;
register struct bufline  *top;

register int  c;
FILE  *ds;
char  *loc;
unsigned int  pcmd;
int  msgno;


/* turn off cmd grouping */
pcmd = cmd[0] & WHCHPAN;

if (pcmd & IMEXPRC)
    {
    ds = fopen(dsn, OLD_INPUT);
    if (ds)
        {
        strt = readbuf(posptr, ds, maxlrecl);
        fclose(ds);

        /* create .zed extension */
        loc = strrchr(dsn, '.');
        if (loc)
            {
            c = loc - dsn + 1;
            if (c + 3 < strlen(dsn))
                loc = NULL;
            } /* end then */

        if (loc)
            if (cmd[0] == EHHIPRC)
                {
                dsn[c++] = heb[1];
                dsn[c++] = heb[2];
                dsn[c] = heb[3];
                } /* end then */
            else if (cmd[0] & IMPPROC)
                {
                dsn[c++] = zed[1];
                dsn[c++] = zed[2];
                dsn[c] = zed[3];
                } /* end then, else */
            else
                {
                dsn[c++] = exp[1];
                dsn[c++] = exp[2];
                dsn[c] = exp[3];
                } /* end else */
        else
            if (cmd[0] == EHHIPRC)
                strcat(dsn, heb);
            else if (cmd[0] & IMPPROC)
                strcat(dsn, zed);
            else
                strcat(dsn, exp);

        switch(cmd[0])
            {
            case IGRKPRC:
                transcr(posptr, dsn, maxlrecl, BUF_GREEK, grkexch,
                    strt);
                break;
            case IHEBPRC:
                transcr(posptr, dsn, maxlrecl, BUF_HEBREW, hebexch,
                    strt);
                break;
            case EGRKPRC:
                transcr(posptr, dsn, maxlrecl, 0x00, grkexch, strt);
                break;
            case EHEBPRC:
                transcr(posptr, dsn, maxlrecl, 0x00, hebexch, strt);
                break;
            case EHHIPRC:
                tranheb(dsn, maxlrecl, strt);
                break;
            } /* end switch */

        freebuf(strt);
        } /* end then */
    else
        {
        /* clean off the stack */
        for (c = 2; c < STACKMAX; ++c)
            cmd[c] = NOP;

        switch(cmd[0])
            {
            case IGRKPRC:
                cmd[1] = IMPGRK;
                break;
            case IHEBPRC:
                cmd[1] = IMPHEB;
                break;
            case EGRKPRC:
                cmd[1] = EXPGRK;
                break;
            case EHEBPRC:
                cmd[1] = EXPHEB;
                break;
            case EHHIPRC:
                cmd[1] = EXPHHI;
                break;
            } /* end switch */
        dispmsg(posptr, PAN2CMD_MSG1);
        } /* end else */
    } /* end then */
else
    /* copy command processing */
    switch(cmd[0])
        {
        case COPY:
            if (*panel & EDEDPAN)
                {
                savepanel = *panel;
                strcpy(savedsn, dsn);
                dsn[0] = '\0';
                scrtbuf(posptr, *nfield, (int (*)[5]) *rowcol, inptext,
                    curr, maxlrecl, wherest, wherend, dschanged);
                pshstck(cmd, SEL_COPYDSN);
                pshstck(cmd, NOP);
                pshstck(cmd, SEL_DSENTRY);
                } /* end then */
            else
                dispmsg(posptr, PAN2CMD_MSG2);
            break;
        case COPYDSN:
            msgno = 0;
            if (dsn[0])
                {
                ds = fopen(dsn, OLD_INPUT);
                if (ds)
                    {
                    if (place -> after)
                        {
                        top = place -> after;
                        place -> after = NULL;
                        } /* end then */
                    else
                        top = curr;
                    strt = top -> next;
                    last = getfile(posptr, top, ds, maxlrecl);
                    fclose(ds);
                    last -> next = strt;
                    strt -> prev = last;
                    srpbufr(posptr, maxlrecl, top -> next);
                    srpbufr(posptr, maxlrecl, strt);
                    renbufr(top);
                    } /* end then */
                else
                    msgno = PAN2CMD_MSG1;
                } /* end then */
            else
                msgno = PAN2CMD_MSG3;

            *panel = savepanel;
            strcpy(dsn, savedsn);

            editpan(posptr, line_no, col_no, nfield, rowcol,
                inptext, dsn, rightmar);

            buftscr(posptr, *nfield, (int (*)[5]) *rowcol, inptext,
                curr, maxlrecl, *coloffset, wherest, wherend, place,
                YES);

            if (msgno)
                dispmsg(posptr, msgno);
            break;
        } /* end switch, else */

} /* end pan2cmd */
