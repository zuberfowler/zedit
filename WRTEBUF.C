#include <stdio.h>
#include "zedit.h"

int  wrtebuf(
              char  dsn[56],
              register struct bufline  *ptr)
/**********************************************************************/
/*                                                                    */
/* Output the new edited version of the processed file.               */
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
FILE  *wds;

#ifdef VMS
#include <string.h>

register char  *pos;


pos = strchr(dsn, ';');
if (pos)
    *pos = '\0';
#endif

wds = fopen(dsn, NEW_OUTPUT);
if (!wds)
    return(YES);

while (ptr)
    {
    if (ptr -> status & ST_TEXT)
        fputs(ptr -> bline, wds);
    ptr = ptr -> next;
    } /* end while */

fclose(wds);
return(NO);

} /* end wrtebuf */
