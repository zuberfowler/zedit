#include <string.h>
#include "zedit.h"

void  findprm(
              union both_scr  *posptr,
              int  *line_no,
              int  *col_no,
              int  nfield,
              int  rowcol[][5],
              int  maxlrecl,
              unsigned int  cmd,
              int  *coloffset,
              struct bufline  *first,
              struct bufline  **curr,
              int  *dschanged,
              char  new_prm1[],
              char  new_prm2[],
              char  text[],
              int  map[])
/**********************************************************************/
/*                                                                    */
/* Perform find and change commands.                                  */
/*                                                                    */
/* For Greek and Hebrew:                                              */
/*     If the find parameter is entered with diacritics then the find */
/* must be a complete match (including diacritics).  If the parameter */
/* is consonants only then the search will match by consonants        */
/* (ignoring diacritics).                                             */
/*                                                                    */
/* For Regular/Special:                                               */
/*     The find processes as expected except underlined strings if    */
/* used in the text will not be matched unless the find parameter     */
/* specifically includes the underlining.                             */
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
/* pindex note:  for PINIT 3nd arg is ignored,
                 for PFIND 4th arg is ignored */
static int  (*f)[] = NULL;
static int  (*r)[] = NULL;

static struct bufline  *lptr = NULL;
/* prm is output format, pat is TXT format */
static int  revheb1 = NO;
static int  hitbottom = NO;
static int  reinit = NO;
static int  scr1 = BUF_ASCII;
static char  prm1[CMDLEN] = {'\0'};
static char  prm2[CMDLEN] = {'\0'};
static char  pat1[CMDLEN] = {'\0'};
static char  pat2[CMDLEN] = {'\0'};
static char  rprm1[CMDLEN] = {'\0'};
static char  rprm2[CMDLEN] = {'\0'};
static char  rpat1[CMDLEN] = {'\0'};
static char  rpat2[CMDLEN] = {'\0'};

register int  stprm = 0;
int  next;
int  onscr;
int  stpat = 0;
int  rfind = YES;
int  srpchg = NO;
int  revheb2;
int  scr2;
char  *found;


/**********************************************************************/
/* set up environment for multiple searches                           */
/**********************************************************************/
if ((cmd == CHANGE)  ||  (hitbottom  &&  !new_prm1[0]))
    next = 0;
else
    next = 1;

if (new_prm1[0])
    {
    hitbottom = NO;

    if (new_prm1[0] == PRECDR)
        {
        if ((char) scr1 != new_prm1[1])
            srpchg = YES;
        scr1 = new_prm1[1];
        new_prm1[0] = ' ';
        new_prm1[1] = ' ';
        if (new_prm1[2] == PRECDR)
            {
            revheb1 = YES;
            new_prm1[2] = ' ';
            new_prm1[3] = ' ';
            } /* end then */
        else
            revheb1 = NO;
        leftjust(new_prm1);
        } /* end then */
    else
        {
        revheb1 = NO;
        scr1 = BUF_ASCII;
        } /* end else */

    if (srpchg  ||  strcmp(prm1, new_prm1))
        {
        /* create pat1 from prm1 */
        strcpy(prm1, new_prm1);
        txtonly(scr1, prm1, pat1, map);
        if (revheb1)
            rhebrew(prm1, pat1, rprm1, rpat1);
        reinit = YES;

        /* use lptr/rfind to keep one copy start-search code */
        lptr = NULL;
        rfind = NO;
        } /* end then */
    } /* end then */
else
    if (!pat1[0])
        {
        dispmsg(posptr, FINDPRM_MSG1);
        return;
        } /* end then, else */

/* determine where to start the search */
if (!lptr)
    {
    lptr = *curr;
    txtonly(lptr -> script, lptr -> bline, text, map);

    if ((*line_no >= rowcol[nfield] [TOP_MAR])  &&
      (*col_no >= rowcol[nfield] [LEFT_MAR]))
        if (revheb1 &&  (lptr -> bline[3] != BUF_CHGDIR)  &&
        ((lptr ->  script  == BUF_HEBREW)  ||
         (lptr -> bline[1] == BUF_HEBREW)))
            stpat = *coloffset + rowcol[nfield] [RIGHT_MAR] - *col_no;
        else
            stpat = *coloffset + *col_no - rowcol[nfield] [LEFT_MAR];
    else
        stpat = 0;

    for (stprm = 0; map[stprm] != stpat; ++stprm)
        {;}; /* end for */
    } /* end then */

if (rfind)
    {
    stprm += next;
    stpat += next;
    } /* end then */

/**********************************************************************/
/* set up parameter for a change command                              */
/**********************************************************************/
if (new_prm2[0])
    {
    if (new_prm2[0] == PRECDR)
        {
        scr2 = new_prm2[1];
        new_prm2[0] = ' ';
        new_prm2[1] = ' ';
        if (new_prm2[2] == PRECDR)
            {
            revheb2 = YES;
            new_prm2[2] = ' ';
            new_prm2[3] = ' ';
            } /* end then */
        else
            revheb2 = NO;
        leftjust(new_prm2);
        } /* end then */
    else
        {
        revheb2 = revheb1;
        scr2 = scr1;
        } /* end else */

    strcpy(prm2, new_prm2);
    txtonly(scr2, prm2, pat2, map);
    if (revheb2)
        rhebrew(prm2, pat2, rprm2, rpat2);
    } /* end then */

/**********************************************************************/
/* If prm1 contains diacritics or it is regular or special characters */
/*     then search the buffer first before doing txtonly processing.  */
/* This will cause underlined regular/special text to be processed    */
/* differently than Greek or Hebrew diacritics.                       */
/**********************************************************************/
found = NULL;
if (strcmp(prm1, pat1) ||
   (scr1 == BUF_ASCII)  ||  (scr1 == BUF_ROMCHAR))
    {
    if (strcmp(prm1, pat1) ||  reinit)
        {
        pindex(PINIT, &f, text, prm1);
        if (revheb1)
            pindex(PINIT, &r, text, rprm1);
        reinit = NO;
        } /* end then */

    if (revheb1 &&  (lptr -> bline[3] != BUF_CHGDIR)  &&
    ((lptr ->  script  == BUF_HEBREW)  ||
     (lptr -> bline[1] == BUF_HEBREW)))
        found = pindex(PFIND, &r, &(lptr -> bline[stprm]), rprm1);
    else
        found = pindex(PFIND, &f, &(lptr -> bline[stprm]), prm1);

    if (!found)
        {
        lptr = lptr -> next;
        stpat = 0;
        while (lptr  &&  !found)
            {
            if (revheb1 &&  (lptr -> bline[3] != BUF_CHGDIR)  &&
            ((lptr ->  script  == BUF_HEBREW)  ||
             (lptr -> bline[1] == BUF_HEBREW)))
                found = pindex(PFIND, &r, lptr -> bline, rprm1);
            else
                found = pindex(PFIND, &f, lptr -> bline, prm1);
            if (!found)
                lptr = lptr -> next;
            } /* end while */
        } /* end then */

    if (strcmp(prm1, pat1))
        {
        pindex(PINIT, &f, text, pat1);
        if (revheb1)
            pindex(PINIT, &r, text, rpat1);
        } /* end then */
    } /* end then */
else
    if (reinit)
        {
        pindex(PINIT, &f, text, pat1);
        if (revheb1)
            pindex(PINIT, &r, text, rpat1);
        reinit = NO;
        } /* end then, else */

/**********************************************************************/
/* This is the actual screen find.                                    */
/**********************************************************************/
found = NULL;
if (lptr)
    {
    txtonly(lptr -> script, lptr -> bline, text, map);

    if (revheb1 &&  (lptr -> bline[3] != BUF_CHGDIR)  &&
    ((lptr ->  script  == BUF_HEBREW)  ||
     (lptr -> bline[1] == BUF_HEBREW)))
        found = pindex(PFIND, &r, &text[stpat], rpat1);
    else
        found = pindex(PFIND, &f, &text[stpat], pat1);

    if (!found)
        {
        lptr = lptr -> next;
        while (lptr  &&  !found)
            {
            txtonly(lptr -> script, lptr -> bline, text, map);
            if (revheb1 &&  (lptr -> bline[3] != BUF_CHGDIR)  &&
            ((lptr ->  script  == BUF_HEBREW)  ||
             (lptr -> bline[1] == BUF_HEBREW)))
                found = pindex(PFIND, &r, text, rpat1);
            else
                found = pindex(PFIND, &f, text, pat1);
            if (!found)
                lptr = lptr -> next;
            } /* end while */
        } /* end then */
    } /* end then */

/**********************************************************************/
/* post search processing                                             */
/**********************************************************************/
if (found)
    {
    /* compute offset */
    onscr = found - text;

    if (revheb1 &&  (lptr -> bline[3] != BUF_CHGDIR)  &&
    ((lptr ->  script  == BUF_HEBREW)  ||
     (lptr -> bline[1] == BUF_HEBREW)))
        if (onscr < rowcol[nfield][RIGHT_MAR] -rowcol[nfield][LEFT_MAR])
            {
            *coloffset = 0;
            *col_no = rowcol[nfield][RIGHT_MAR] - onscr;
            } /* end then */
        else
            {
            *coloffset = (strlen(pat1) + onscr) -
                (rowcol[nfield][RIGHT_MAR] - rowcol[nfield][LEFT_MAR]);
            *col_no = rowcol[nfield][RIGHT_MAR] - (onscr - *coloffset);
            } /* end else */
    else
        if (onscr < rowcol[nfield][RIGHT_MAR] -rowcol[nfield][LEFT_MAR])
            {
            *coloffset = 0;
            *col_no = onscr + rowcol[nfield][LEFT_MAR];
            } /* end then */
        else
            {
            *coloffset = (strlen(pat1) + onscr) -
                (rowcol[nfield][RIGHT_MAR] - rowcol[nfield][LEFT_MAR]);
            *col_no = rowcol[nfield][LEFT_MAR] + (onscr - *coloffset);
            } /* end else */

    /* execute change command */
    if (cmd == CHANGE)
        if (revheb1 &&  (lptr -> bline[3] != BUF_CHGDIR)  &&
        ((lptr ->  script  == BUF_HEBREW)  ||
         (lptr -> bline[1] == BUF_HEBREW)))
            chngprm(posptr, maxlrecl, rpat1, rprm2, map, onscr, lptr,
                dschanged);
        else
            chngprm(posptr, maxlrecl, pat1, prm2, map, onscr, lptr,
                dschanged);

    /* finish up */
    if (lptr -> status & ST_EXCL)
        excrdsp(posptr, lptr);
    *curr = lptr;
    *line_no = rowcol[nfield] [TOP_MAR];
    dispmsg(posptr, FINDPRM_MSG2);
    hitbottom = NO;
    lptr = NULL;
    } /* end then */
else
    {
    if (hitbottom)
        dispmsg(posptr, FINDPRM_MSG3);
    else
        dispmsg(posptr, FINDPRM_MSG4);
    lptr = first;
    hitbottom = YES;
    } /* end else */

} /* end findprm */
