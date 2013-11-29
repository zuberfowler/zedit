#include "zedit.h"

void  stckcmd(
              unsigned int  cmd[])
/**********************************************************************/
/*                                                                    */
/* Process command values that expand on the stack to more than one   */
/* task.  These are internal cmds.                                    */
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


pshstck(cmd, VIDEO);

switch(cmd[0])
    {
    case SEL_PRIMARY:
        pshstck(cmd, PRIMARY);
        break;
    case SEL_DSENTRY:
        pshstck(cmd, DSENTRY);
        break;
    case SEL_BROWPAN:
        pshstck(cmd, BROWPAN);
        break;
    case SEL_EDITPAN:
        pshstck(cmd, EDITPAN);
        break;
    case SEL_COPYDSN:
        pshstck(cmd, COPYDSN);
        break;
    case SEL_CFGKPAN:
        pshstck(cmd, CFGKPAN);
        break;
    case SEL_CFGFPAN:
        pshstck(cmd, CFGFPAN);
        break;
    } /* end switch */

pshstck(cmd, CLRSCR);
pshstck(cmd, NVIDEO);
cmd[0] = CLRINPT;

} /* end stckcmd */
