#include "zedit.h"
#include "hdafi.h"
#include <stdlib.h>
#include <string.h>

#define INCL_SUB
#define INCL_NOPMAPI
#include <os2.h>

void LINKAGE  savevio(
              unsigned long  posprm)
/**********************************************************************/
/*                                                                    */
/* OS/2 Only.                                                         */
/* Function runs as a separate OS/2 thread to save the video screen   */
/* before a process switch and to restore it afterward.  Function is  */
/* terminated by main thread with VioSavRedrawUndo or by program end. */
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
extern int  p;

static struct hclose_parm  xc = {sizeof(xc)-2, 0};
unsigned short int  notify;
unsigned int  size;
char  **posptr;
char  *buf0;
char  *buf1;


posptr = (char  **) posprm;

if (graphic & IBM2  ||  graphic & VGA)
    size = 44032u;
else
    size = 32768u;

if (!(graphic & XGA))
    {
    buf0 = (char *) malloc(size);
    if (!buf0)
        zfinish((union both_scr  *) *posptr, no_storage);
    buf1 = (char *) malloc(size);
    if (!buf1)
        zfinish((union both_scr  *) *posptr, no_storage);
    } /* end then */

while(graphic)
    {
    VioSavRedrawWait(0, &notify, 0);
    if (notify)
        {
        grphreg();
        if (graphic & XGA)
            xga8514((union both_scr  *) *(posptr + p), FULLSCR, NO);
        else
            {
            memcpy(*posptr, buf0, size);
            memcpy(*(posptr + 1), buf1, size);
            if (p  &&  (graphic & TWOSCR))
                IOPLpg1();
            } /* end else */
        } /* end then */
    else
        if (graphic & XGA)
            HCLOSE(&xc);
        else
            {
            /* save display */
            memcpy(buf0, *posptr, size);
            memcpy(buf1, *(posptr + 1), size);
            } /* end else */
    } /* end while */

} /* end savevio */
