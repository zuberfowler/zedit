#include <string.h>
#include "zedit.h"

int  cfgkget(
              union both_scr  *posptr,
              int  rowcol[] [5],
              char  inptext[] [25] [80])
/**********************************************************************/
/*                                                                    */
/* Process the config keyboard panel.                                 */
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
extern char  grkexch[256];
extern char  hebexch[256];

register int  i;
register int  r;
char  grkhold[128];
char  hebhold[128];
char  work[3];


/* Greek character set */
grkhold[127] = '\0';

for (i = 0;  i < 32;  ++i)
    grkhold[i] = ' ';

for (r = 1;  i < 127;  ++i, ++r)
    {
    convout(0, &inptext[TXT] [rowcol[r][TOP_MAR]] [rowcol[r][LEFT_MAR]],
        &inptext[SRP] [rowcol[r][TOP_MAR]] [rowcol[r][LEFT_MAR]],
        &inptext[OVR] [rowcol[r][TOP_MAR]] [rowcol[r][LEFT_MAR]],
        BUF_GREEK, work, 0, "");
    grkhold[i] = work[strlen(work) - 1];
    } /* end for */

for (i = 32; i < 127; ++i)
    if (strchr(&grkhold[i+1], grkhold[i]))
       {
       dispmsg(posptr, CFGKGET_MSG1);
       return(YES);
       } /* end then */


/* Hebrew character set */
hebhold[127] = '\0';

for (i = 0;  i < 32;  ++i)
    hebhold[i] = ' ';

for ( ;  i < 127;  ++i, ++r)
    {
    convout(0, &inptext[TXT] [rowcol[r][TOP_MAR]] [rowcol[r][LEFT_MAR]],
        &inptext[SRP] [rowcol[r][TOP_MAR]] [rowcol[r][LEFT_MAR]],
        &inptext[OVR] [rowcol[r][TOP_MAR]] [rowcol[r][LEFT_MAR]],
        BUF_HEBREW, work, 0, "");
    hebhold[i] = work[strlen(work) - 1];
    } /* end for */

for (i = 32; i < 127; ++i)
    if (strchr(&hebhold[i+1], hebhold[i]))
       {
       dispmsg(posptr, CFGKGET_MSG2);
       return(YES);
       } /* end then */


/* both character sets verified */
strcpy(grkexch, grkhold);
strcpy(hebexch, hebhold);
return(NO);

} /* end cfgkget */
