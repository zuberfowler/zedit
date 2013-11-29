#include <stdio.h>
#include <string.h>
#include "zedit.h"

void  cfginit(void)
/**********************************************************************/
/*                                                                    */
/* Open config file if file exists and obtain overrides.              */
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

/* if used last position holds null */
extern char  grkexch[256];
extern char  hebexch[256];
extern unsigned int  fkeyset[4] [12];

register int  i;
register int  j;
FILE  *ds;
char  dsn[256];


/* find directory of zedit program and use its path */
dsn[0] = '\0';
i = strrchr(_pgmptr, '\\') - _pgmptr + 1;
if (i > 0)
    strncpy(dsn, _pgmptr, i);

/* @-bug in strncpy in DOS version of MS 5.1, 6.0a compiler library */
dsn[i] = '\0';

strcat(dsn, "zedit.cfg");

/* open zedit.cfg and obtain overrides */
ds = fopen(dsn, OLD_INPUT);
if (ds)
    {
    fgets(grkexch, 128, ds);
    fgets(hebexch, 128, ds);
    for (i = 0; i < 4; ++i)
        for (j = 0; j < 12; ++j)
            fscanf(ds, " %d", &fkeyset[i] [j]);
    fclose(ds);
    } /* end then */

} /* end cfginit */
