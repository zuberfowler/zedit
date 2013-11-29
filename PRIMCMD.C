#include "zedit.h"

void  primcmd(
              union both_scr  *posptr,
              unsigned int  cmd[],
              struct bufline *first)
/**********************************************************************/
/*                                                                    */
/* Process command values that expand on the stack to more than one   */
/* task.  These come from the primary option menu.                    */
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

if (first)
    {
    dispmsg(posptr, PRIMCMD_MSG1);
    return;
    } /* end then */

switch(cmd[0])
    {
    case BROWSE:
        pshstck(cmd, SEL_BROWPAN);
        break;
    case EDIT:
        pshstck(cmd, SEL_EDITPAN);
        break;
    case CONFIG:
        pshstck(cmd, SEL_CFGFPAN);
        pshstck(cmd, NOP);
        pshstck(cmd, SEL_CFGKPAN);
        return; /* get out */
    case IMPGRK:
        pshstck(cmd, RETURN);
        pshstck(cmd, IGRKPRC);
        break;
    case IMPHEB:
        pshstck(cmd, RETURN);
        pshstck(cmd, IHEBPRC);
        break;
    case EXPGRK:
        pshstck(cmd, RETURN);
        pshstck(cmd, EGRKPRC);
        break;
    case EXPHEB:
        pshstck(cmd, RETURN);
        pshstck(cmd, EHEBPRC);
        break;
    case EXPHHI:
        pshstck(cmd, RETURN);
        pshstck(cmd, EHHIPRC);
        break;
    } /* end switch */

pshstck(cmd, NOP);
pshstck(cmd, SEL_DSENTRY);

} /* end primcmd */
