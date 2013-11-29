#include "zedit.h"

char  *cmdprse(
              char  cmd[],
              char  cmdln[])
/**********************************************************************/
/*                                                                    */
/* This function moves the first word from cmdln to cmd.  A quoted    */
/* strings is considered one word.  This function returns the         */
/* address of cmd.                                                    */
/*                                                                    */
/* This function assumes that cmd will hold the result and it assumes */
/* that cmdln on input is currently left justified to begin with.     */
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
register int  c;
register int  l;
char  del;


c = 0;

if (cmdln[0] == '\'' ||  cmdln[0] == '"')
    {
    del = cmdln[0];
    cmdln[0] = ' ';
    } /* end then */
else
    {
    del = ' ';
    cmd[c++] = cmdln[0];
    cmdln[0] = ' ';
    } /* end else */

for (l = 1; (cmdln[l] != del)  &&  cmdln[l]; ++c, ++l)
    {
    cmd[c] = cmdln[l];
    cmdln[l] = ' ';
    } /* end for */

if (cmdln[l] == del)
    cmdln[l] = ' ';
cmd[c] = '\0';

return(cmd);

} /* end cmdprse */
