#include <stdio.h>
#include "zedit.h"

#ifdef OS2
#define INCL_DOS
#define INCL_NOPMAPI
#include <os2.h>
#endif

void  dispmsg(
              union both_scr  *posptr,
              int  msgno)
/**********************************************************************/
/*                                                                    */
/* Display a message on the message line and optionally ring the      */
/* bell.  Error messages starting with ! ring the bell.               */
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
extern unsigned int  graphic;
extern char  msgtext[MSGMAX][80];

int  ln;


if (!posptr)
    return;

if (msgtext[msgno][0] == '!')
#ifdef OS2
    DosBeep(500, 75);
#else
    printf("%c", BELL);
#endif

if (graphic & CGA)
    ln = 0;
else
    ln = 24;

dsp8lin(posptr, &msgtext[msgno][0], ln);
revline(posptr, ln);
if (graphic & XGA)
    xga8514(posptr, ln, RDSPLIN);

} /* end dispmsg */
