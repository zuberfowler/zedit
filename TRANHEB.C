#include <stdlib.h>
#include <string.h>
#include "zedit.h"

void  tranheb(
              char  dsn[],
              int  maxlrecl,
              struct bufline  *first)
/**********************************************************************/
/*                                                                    */
/* Perform Hebrew high export command.                                */
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
extern char  hebhiex[128];
static char  extra[] = {PATHAH, SEGHOL, HIREQ, QIBBUS, QAMES, SERE,
    HOLEM, SHEWA, DAGESH, '\n', '\0'};
static char  term[] = {KAPH_TERM, MEM_TERM, NUN_TERM, PE_TERM,
    SADHE_TERM, '\0'};
register struct bufline  *ptr;
register int  b;
register int  n;
char  *map;


map = (char *) malloc(maxlrecl);

/* loop through the data set buffer */
for (ptr = first -> next;  ptr -> next;  ptr = ptr -> next)
    {
    /* flag diacritics and base terminals in map */
    for (b = 0; ptr -> bline[b]; ++b)
        if (ptr -> bline[b] == PRECDR)
            {
            *(map + b++) = NO;
            *(map + b) = NO;
            } /* end then */
        else if (strchr(extra, ptr -> bline[b]))
            *(map + b) = NO;
        else
            {
            *(map + b) = YES;
            if (strchr(term, ptr -> bline[b]))
                *(map + b - 1) = NO;
            } /* end else */

    /* remove diacritics, base terminals and translate characters */
    for (b = 0, n = 0; ptr -> bline[b]; ++b)
        if (map[b])
            ptr -> bline[n++] = hebhiex[ptr -> bline[b]  &  0x007F];

    /* finish up the line */
    ptr -> bline[n++] = '\n';
    ptr -> bline[n] = '\0';
    } /* end for */

/* write the data set back out */
wrtebuf(dsn, first);

} /* end tranheb */
