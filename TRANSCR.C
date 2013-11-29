#include <stdlib.h>
#include <string.h>
#include "zedit.h"

void  transcr(
              union both_scr  *posptr,
              char  dsn[],
              int  maxlrecl,
              int  scrinit,
              char  exchange[256],
              struct bufline  *first)
/**********************************************************************/
/*                                                                    */
/* Perform import and export commands.                                */
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
static char  hebterm[] = {KAPH_TERM, MEM_TERM, NUN_TERM, PE_TERM,
    SADHE_TERM, '\0'};

register struct bufline  *ptr;
register int  b;
register int  i;
int  *map;


map = (int *) malloc(maxlrecl * sizeof(int));

/* loop through the data set buffer */
for (ptr = first -> next;  ptr -> next;  ptr = ptr -> next)
    {
    /* if this is an export need to remove diacritics */
    if (!scrinit)
        {
        txtonly(ptr -> script, ptr -> bline, ptr -> bline, map);
        strcat(ptr -> bline, "\n");
        } /* end then */

    /* translate characters */
    for (b = 0; ptr -> bline[b] != '\n'; ++b)
        if (ptr -> bline[b] == PRECDR)
            {
            if (ptr -> bline[b+1] != '\n')
                ++b;
            } /* end then */
        else
            {
            ptr -> bline[b] = exchange[(unsigned char) ptr -> bline[b]];

            /* check for terminal letters */
            if (exchange[255] == 'H')
                {
                if (strchr(hebterm, ptr -> bline[b]))
                    {
                    /* insert its main representation */
                    for (i = strlen(ptr -> bline); i > b; --i)
                        ptr -> bline[i] = ptr -> bline[i - 1];
                    ptr -> bline[b] += 'a' - 'A';
                    ++b;
                    } /* end then */
                } /* end then */
            else
                if (ptr -> bline[b] == SIGMATERM)
                    {
                    /* insert its main representation */
                    for (i = strlen(ptr -> bline); i > b; --i)
                        ptr -> bline[i] = ptr -> bline[i - 1];
                    ptr -> bline[b] = SIGMA;
                    ++b;
                    } /* end then, else */
            } /* end else */

    } /* end for */

/* add a PRECDR if doing import */
if (scrinit)
    {
    ptr = (struct bufline *) malloc(sizeof(struct bufline_hdr) + 4);
    if (!ptr)
        zfinish(posptr, no_storage);
    ptr -> prev = first;
    ptr -> next = first -> next;
    first -> next -> prev = ptr;
    first -> next = ptr;
    ptr -> script = first -> script;
    ptr -> status = ST_NORM;
    ptr -> bline[0] = PRECDR;
    ptr -> bline[1] = (char) scrinit;
    ptr -> bline[2] = '\0';
    } /* end then */

/* write the data set back out */
wrtebuf(dsn, first);

} /* end transcr */
