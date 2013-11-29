#include "zedit.h"

char  *mergeon(
              register char  *frstr,
              register char  *tostr)
/**********************************************************************/
/*                                                                    */
/* This function merges one string upon another.  The receiving       */
/* string must have enough area of memory to hold the entire from     */
/* string length.  A position in the receiving string is valid for    */
/* the merge if it is blank or null, otherwise it is left as is.      */
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
int  longer;
char  *hold;


hold = tostr;
longer = NO;

for ( ; *frstr; ++frstr, ++tostr)
    if (*tostr == ' '  &&  *tostr != '\n'  &&  *frstr != '\n')
        *tostr = *frstr;
    else if (!(*tostr)  ||  *tostr == '\n')
        {
        *tostr = *frstr;
        longer = YES;
        } /* end then, else */
    else if (longer)
        *tostr = *frstr;

if (longer)
    *tostr = '\0';

return(hold);

} /* end mergeon */
