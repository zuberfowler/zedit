#include <stdlib.h>
#include <string.h>
#include "zedit.h"

void  scrtbuf(
              union both_scr  *posptr,
              int  nfield,
              int  rowcol[] [5],
              char  inptext[] [25] [80],
              register struct bufline  *curr,
              int  maxlrecl,
              int  wherest[25],
              int  wherend[25],
              int  *dschanged)
/**********************************************************************/
/*                                                                    */
/* Copy the text out of the triplex screen area into the data buffer. */
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
register int  line_no;
register int  i;
register char  *save;
register char  *work;
register char  *pos;

int  prevsrp;
int  offset;


if (rowcol[nfield] [ATTRIB] != RC_CHANGED)
    return;

*dschanged = YES;

/* reset attribute field for window */
--rowcol[nfield] [ATTRIB];

work = (char *) malloc(7 * maxlrecl);
if (!work)
    zfinish(posptr, no_storage);
save = (char *) malloc(maxlrecl);
if (!save)
    zfinish(posptr, no_storage);
prevsrp =  curr -> script;

for (line_no = rowcol[nfield] [TOP_MAR];
    curr  &&  line_no <= rowcol[nfield] [BOTTOM_MAR];
    ++line_no, curr = curr -> next)
    {
    if (curr -> status & ST_TEXT)
        {
        offset = strlen(curr -> bline) - 1;

        if (wherend[line_no] <= offset)
            {
            strcpy(save, &(curr -> bline[wherend[line_no]]));
            /* blank out what was copied to save */
            for (i = wherend[line_no]; curr -> bline[i]; ++i)
                curr -> bline[i] = ' ';
            } /* end then */
        else
            *save = '\0';

        /* must occur after test with wherend */
        if (offset < 0)
            offset = 0;

        /* copy to work area */
        strcpy(work, curr -> bline);
        /* may need filler if it used to be short and now long */
        memset(work + offset, ' ', maxlrecl);
        work[offset + maxlrecl] = '\0';

        convout(rowcol[nfield] [RIGHT_MAR] - rowcol[nfield] [LEFT_MAR],
            &inptext[TXT] [line_no] [rowcol[nfield] [LEFT_MAR]],
            &inptext[SRP] [line_no] [rowcol[nfield] [LEFT_MAR]],
            &inptext[OVR] [line_no] [rowcol[nfield] [LEFT_MAR]],
            prevsrp, work, wherest[line_no], save);

        strcat(work, save);

        /* backscan */
        pos = work + strlen(work);
        while(pos - work)
            {
            --pos;
            if (*pos == ' '  ||  *pos == '\n')
                *pos = '\0';
            else
                break;
            } /* end while */

        /* prevent overrun */
        offset = (maxlrecl - strlen(work)) - 2;
        if (offset < 0)
            {
            /* overflow error message */
            dispmsg(posptr, SCRTBUF_MSG1);
            *(work + (maxlrecl - 2)) = '\0';
            } /* end then */

        /* set terminators */
        pos = work + strlen(work);
        *pos = '\n';
        *(++pos) = '\0';

        /* move to buffer */
        strcpy(curr -> bline, work);

        /* see if need to change line's script */
        if (prevsrp != (int) curr -> script)
            {
            for (i = 0; i < wherest[line_no]; ++i)
                if (curr -> bline[i] > ' ')
                    {
                    srpbufr(posptr, maxlrecl, curr);
                    break; /* for */
                    } /* end then */
            curr -> script = (char) prevsrp;
            } /* end then */

        prevsrp = lastsrp(prevsrp, curr -> bline);
        } /* end then */

    } /* end for */

/* make sure buffer srp in order */
srpbufr(posptr, maxlrecl, curr);

free(save);
free(work);

} /* end scrtbuf */
