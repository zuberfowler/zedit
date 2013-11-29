#include <string.h>
#include "zedit.h"

#ifdef VMS
#include <iodef.h>
#include <descrip.h>
#include <curses.h>
#else
#ifdef OS2
#define INCL_DOS
#define INCL_SUB
#define INCL_NOPMAPI
#include <os2.h>
#endif
#endif

unsigned short  zedinit(
              int argc,
              char  *argv[],
              union both_scr  *posptr[],
              char  inptext[2] [4] [25] [80],
              char  dsn[2] [56],
              int  maxlrecl[2],
              struct lineptrs  place[2],
              unsigned int  cmd[],
              int  *rightmar)
/**********************************************************************/
/*                                                                    */
/* Zedit initialization code.                                         */
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
extern struct rombios  *romptr;

#ifdef OS2
/* OS/2 specific identifiers */

/* get virtual screen address */
void S16  bufptr;

/* get physical screen address */
static unsigned char  savevio_stack[4096];
char  **stck;
VIOPHYSBUF  buf;
unsigned int  savevio_thread;
unsigned char  cc;

/* get rom font address */
VIOFONTINFO  f;
#endif

/* uninitialialized values */
#ifdef VMS
static int  channel = 1;    /* will be changed by SYS$ASSIGN */
static readonly  $DESCRIPTOR(d_default, "TT");
#endif

unsigned short  buflen = 44032;


/**********************************************************************/
/* Initialize options, work areas.                                    */
/**********************************************************************/
invcopt(posptr, dsn, argc, argv, cmd, maxlrecl, rightmar);

if (graphic & CGA)
    buflen = 32768;

#ifdef PTRINIT
ptrinit();
#endif

cfginit();

memset(inptext, 0x00, 16000);
memset(place, 0x00, 2 * sizeof(place[0]));

/**********************************************************************/
/* Initialize screen area - VMS                                       */
/**********************************************************************/
#ifdef VMS
if (!(graphic & DISPL))
    {
    initscr();
    posptr[0] = stdscr;
    posptr[1] = stdscr;
    } /* end then */
SYS$ASSIGN(&d_default, &channel, 0, 0);
grphreg();
#else

#ifdef OS2
/**********************************************************************/
/* get rom font address - OS/2                                        */
/**********************************************************************/
f.cb = sizeof(f);             /* size of data structure */
f.type = 1;                   /* font in rom */
f.cxCell = 8;                 /* horizontal size */
f.cyCell = 8;                 /* vertical size */
f.pbData = NULL;              /* pointer to font data area */
f.cbData = 0;                 /* length of data area */
while (VioGetFont(&f, 0) == 438)
    {;}; /* end while */

#ifdef PTRCONV
romptr = (struct rombios  *) EXPPTR(HISECT(f.pbData),
    LOSECT(f.pbData));
#else
romptr = (struct rombios  *) f.pbData;
#endif

/**********************************************************************/
/* get physical screen address - OS/2                                 */
/**********************************************************************/
if (graphic & DISPL)
    {
#ifndef DEBUG
    while (VioScrLock(LOCKIO_WAIT, &cc, 0))
        DosSleep(5000L);
#endif

    grphreg();

    if (graphic & CGA)
        {
        buf.cb = 0x08000;
        buf.pBuf = (PBYTE) 0x000B8000;
        } /* end else */
    else
        {
        buf.cb = 0x10000;
        buf.pBuf = (PBYTE) 0x000A0000;
        } /* end else */

    if (graphic & XGA)
        {
        fillscr(posptr[0]);
        fillscr(posptr[1]);
        } /* end then */
    else
        {
        VioGetPhysBuf(&buf, 0);

        posptr[0] = (union both_scr  *) EXPPTR(buf.asel[0], 0);
        fillscr(posptr[0]);

        if (graphic & TWOSCR)
            {
            posptr[1] = (union both_scr *)((char *)posptr[0] + 0x08000);
            fillscr(posptr[1]);
            } /* end then */
        } /* end else */

#ifndef DEBUG
    VioScrUnLock(0);

    /* save and restore the video screen for process switch */
    if (!(graphic & CGA))
        {
        stck = (char **) &savevio_stack[2044];
        *stck = (char *) posptr;
#ifdef M_I386
        DosCreateThread((unsigned long (*)) &savevio_thread, savevio,
            (unsigned long) posptr, 0L, 8192L);
#else
        DosCreateThread((PFNTHREAD) savevio, (PTID) &savevio_thread,
            savevio_stack + 2044);
#endif
        } /* end then */
#endif
    } /* end then */
else
    {
    /* text mode only needs a logical screen */
    buflen = 0;
    VioGetBuf((unsigned long *) &bufptr, &buflen, 0);
#ifdef PTRCONV
    posptr[0] = (union both_scr  *) EXPPTR(HISECT(bufptr),
        LOSECT(bufptr));
#else
    posptr[0] = (union both_scr  *) bufptr;
#endif
    posptr[1] = posptr[0];
    fillscr(posptr[0]);
    } /* end else */
#else
#ifdef AIX
/**********************************************************************/
/* initialize screen areas - AIX   @@@                                */
/**********************************************************************/

#else
/**********************************************************************/
/* initialize screen areas - DOS                                      */
/**********************************************************************/

if (graphic & HMONO)
    prtcntl(DISP_MODE, TEXT0_NVIDEO);
if (!(graphic & XGA))
    {
    fillscr(posptr[0]);
    fillscr(posptr[1]);
    } /* end then */

grphreg();

if (graphic & XGA)
    {
    fillscr(posptr[0]);
    fillscr(posptr[1]);
    } /* end then */

if (graphic & HMONO)
    prtcntl(DISP_MODE, GRAPH0_NVIDEO);

if (!(graphic & DISPL))
    prtcntl(DISP_MODE, TEXT0_VIDEO);

#endif
#endif
#endif

return(buflen);

} /* end zedinit */
