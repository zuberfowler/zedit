#include <string.h>
#include "zedit.h"

void  procedt(
              union both_scr  *posptr,
              unsigned int  panel,
              int  nfield,
              int  rowcol[][5],
              int  coloffset,
              struct bufline  **curr,
              int  wherest[25],
              int  wherend[25],
              int  *dschanged,
              char  inptext[] [25] [80],
              unsigned int  cmd[],
              int  maxlrecl,
              register struct lineptrs  *place,
              char  cmdln[])
/**********************************************************************/
/*                                                                    */
/* This routine is called if a command event has taken place (ie. a   */
/* function key, return key, etc.)                                    */
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


/* convert out command line to output file format */
convout(rowcol[0][RIGHT_MAR] - rowcol[0][LEFT_MAR],
    &inptext[TXT] [rowcol[0][TOP_MAR]] [rowcol[0][LEFT_MAR]],
    &inptext[SRP] [rowcol[0][TOP_MAR]] [rowcol[0][LEFT_MAR]],
    &inptext[OVR] [rowcol[0][TOP_MAR]] [rowcol[0][LEFT_MAR]],
    SRP_MASK, cmdln, 0, "");

/* remove new line char */
cmdln[strlen(cmdln)] = '\0';

/* process line commands if in numbered edit */
if (panel == EDITPAN)
    if (rowcol[nfield - 1] [ATTRIB] > RC_NORMAL)
        {
        scrtbuf(posptr, nfield, rowcol, inptext, *curr, maxlrecl,
            wherest, wherend, dschanged);
        linecmd(posptr, nfield, rowcol, inptext, cmd, maxlrecl, *curr,
            place, dschanged);
        if ((place -> newcurr)  &&  !(place -> oldcurr))
            {
            *curr = place -> newcurr;
            place -> newcurr = NULL;
            } /* end then*/
        if (cmd[1] < COLMS  ||  cmd[1] > LETS)
            buftscr(posptr, nfield, rowcol, inptext, *curr, maxlrecl,
                coloffset, wherest, wherend, place, NO);
        } /* end then */

} /* end procedt */
