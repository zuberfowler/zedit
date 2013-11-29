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
#include <stdio.h>
#endif

/****************************/
/* zedmain global variables */
/****************************/
#ifdef OS2
long  sem_pr = 0;
#endif

/* global graphics mode, print mode */
unsigned int  graphic = NO;
unsigned int  prtmode = NO;

/* global print file */
char  outfile[PRTMAX] = {'p', 'r', 'n', '\0'};

/* ptr to last 8 lines of 17/8 XGA/8514 screen build buffer */
union both_scr  *posxga[2];

/* global reference used in savevio (OS/2) and with posxga */
int  p = 1;

/* init value for DOS, OS/2 obtains by function call */
struct rombios  *romptr = (struct rombios *) 0xF000FA6E;

int LINKMSC  main(
              int  argc,
              char  *argv[])
/**********************************************************************/
/*                                                                    */
/* Zedit program initialization and base command processing.  This    */
/* module along with the driver procedure are the main control point. */
/* This procedure knows that there are two different screens.         */
/*     Everything above ZDRIVER only knows of one.  Consequently all  */
/*     data which is duplicated is declared at this level.            */
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
/***************************/
/* initialialized values   */
/***************************/
static struct bufline  *first[2] = {NULL, NULL};
/* The last position of each stack must always remain empty. */
static unsigned int  cmdstack[2][STACKMAX + 1] =
    {{NOP, PRIMARY, VIDEO, NOP, NOP, NOP, NOP, NOP,
      NOP, NOP, NOP, NOP, NOP, NOP, NOP, NOP,
      NOP, NOP, NOP, NOP, NOP, NOP, NOP, NOP,
      NOP, NOP, NOP, NOP, NOP, NOP, NOP, NOP,
      NOP, NOP, NOP, NOP, NOP, NOP, NOP, NOP},
     {NOP, PRIMARY, SPLIT, NOP, NOP, NOP, NOP, NOP,
      NOP, NOP, NOP, NOP, NOP, NOP, NOP, NOP,
      NOP, NOP, NOP, NOP, NOP, NOP, NOP, NOP,
      NOP, NOP, NOP, NOP, NOP, NOP, NOP, NOP,
      NOP, NOP, NOP, NOP, NOP, NOP, NOP, NOP}};
static unsigned int  cmd = NOP;
static int  rightmar = 0;
static unsigned int  panel[2] = {PRIMARY, PRIMARY};
static int  maxlrecl[2] = {MAXLREC, MAXLREC};
static int  line_no[2] = {0, 0};
static int  col_no[2] = {0, 0};

static int  amode[2] = {BUF_ASCII, BUF_ASCII};
static int  toright[2] = {YES, YES};
static int  inpt = 0x00;
static int  scan = 0x00;
static unsigned int  shift = 0x00;

/***************************/
/* uninitialialized values */
/***************************/
#ifdef OS2
unsigned char  cc;
#else
union regs_both  regs;
#endif

#ifdef VMS
WINDOW  *posptr[2];
#else
union both_scr  *posptr[3];
char  *real;
int  l;
int  n;
int  s;
#endif

struct lineptrs  place[2];
struct bufline  *curr[2];

int  wherest[2] [25];
int  wherend[2] [25];
int  coloffset[2];
int  nfield[2];
int  dschanged[2];
int  *rowcol[2];
unsigned short  buflen;

char  inptext[2] [4] [25] [80];
char  dsn[2] [56];


/**********************************************************************/
/* Call initialization code.                                          */
/**********************************************************************/
buflen = zedinit(argc, argv, posptr, inptext, dsn, maxlrecl, place,
    &cmdstack[0] [0], &rightmar);

/**********************************************************************/
/* Check for print only invocation.                                   */
/**********************************************************************/
if (!(graphic & ADISPL))
    {
    zedpbse(&dsn[0] [0], maxlrecl[0], rightmar);
    cmd = END;
    } /* end then */

/**********************************************************************/
/*                                                                    */
/* Process input, cmd values.                                         */
/*                                                                    */
/**********************************************************************/

while((cmd != END) || (panel[0] != PRIMARY) || (panel[1] != PRIMARY))
    {
    if (cmd == END)
        cmd = SWAP;

    /******************************************************************/
    /* get next input value                                           */
    /******************************************************************/
    if (cmd == NEXTINPT)
        {
        /* put cursor in current location */
        revchar(posptr[p], line_no[p], col_no[p]);

#ifdef S370
        getinpt(&line_no[p], &col_no[p], nfield[p], rowcol[p],
            &inptext[p] [0] [0] [0], &inpt, &scan, &shift);
#else
#ifdef VMS
        if (graphic & TEXT)
            {
            wmove(posptr[p], line_no[p], col_no[p]);
            winch(posptr[p]);
            wrefresh(posptr[p]);
            } /* end then */

        getinpt(channel, &inpt, &scan, &shift);
#else
#ifdef OS2
        if (graphic & TEXT)
            VioShowBuf(0, buflen, 0);
#ifndef DEBUG
        else
            VioScrUnLock(0);
#endif

        getinpt(&inpt, &scan, &shift, graphic);

#ifndef DEBUG
        if (graphic & DISPL)
            while (VioScrLock(LOCKIO_WAIT, &cc, 0))
                DosSleep(1000L);
#endif
#else

        getinpt(&inpt, &scan, &shift, graphic);

#endif
#endif
#endif

        /* remove cursor from last location */
        revchar(posptr[p], line_no[p], col_no[p]);
        } /* end then */
    /******************************************************************/
    /* process first level commands                                   */
    /******************************************************************/
    else if (cmd < FRSTLVL)
        switch(cmd)
            {
            case CLRSCR:
                clrpanl(posptr[p]);
                break;
            case CLRINPT:
                memset(&inptext[p] [0] [0] [0], 0x00, 8000);
                break;
            case NVIDEO:
#ifdef DOS
                if (graphic & HMONO)
                    if (p)
                        prtcntl(DISP_MODE, GRAPH1_NVIDEO);
                    else
                        prtcntl(DISP_MODE, GRAPH0_NVIDEO);
                else if (graphic & TEXT)
                    if (p)
                        prtcntl(DISP_MODE, TEXT1_NVIDEO);
                    else
                        prtcntl(DISP_MODE, TEXT0_NVIDEO);
#endif
                break;
            case REFRESH:
                if (graphic & DISPL)
                    grphreg();
                else
                    textreg();
                pshstck(&(cmdstack[p] [0]), HELP);
                if (!(graphic & XGA))
                    break;
                /* else fall through */
            case VIDEO:
                if (graphic & XGA)
                    xga8514(posptr[p], FULLSCR, NO);
#ifdef DOS
                else if (graphic & HMONO)
                    if (p)
                        prtcntl(DISP_MODE, GRAPH1_VIDEO);
                    else
                        prtcntl(DISP_MODE, GRAPH0_VIDEO);
                else if (graphic & TEXT)
                    if (p)
                        prtcntl(DISP_MODE, TEXT1_VIDEO);
                    else
                        prtcntl(DISP_MODE, TEXT0_VIDEO);
#endif
                break;
            case SPLIT:
                if (p)
                    p = 0;
                else
                    p = 1;
                break;
            case SWAP:
                if (graphic & ONESCR)
                    { /* l=last, s=save, n=new */
                    l = p;
                    real = (char *) posptr[l];
                    if (p)
                        {
                        p = 0;
                        s = 0;
                        n = 2;
                        } /* end then */
                    else
                        {
                        p = 1;
                        s = 2;
                        n = 1;
                        } /* end else */
                    if (graphic & XGA)
                        xga8514(posptr[p], FULLSCR, NO);
                    else
                        {
                        memcpy((char *) posptr[s], real, buflen);
                        memcpy(real, (char *) posptr[n], buflen);
                        posptr[l] = posptr[p];
                        posptr[p] = (union both_scr *) real;
                        } /* end else */
                    break;
                    } /* end then */
#ifdef OS2
                if (graphic & TEXT)
                    {
                    dispmsg(posptr[p], ZEDMAIN_MSG1);
                    break;
                    } /* end then */
#endif
                if (p)
                    {
                    p = 0;
#ifdef DOS
                    if (graphic & HMONO)
                        prtcntl(DISP_MODE, GRAPH0_VIDEO);
#endif
#ifdef OS2
                    IOPLpg0();
#endif
                    } /* end then */
                else
                    {
                    p = 1;
#ifdef DOS
                    if (graphic & HMONO)
                        prtcntl(DISP_MODE, GRAPH1_VIDEO);
#endif
#ifdef OS2
                    IOPLpg1();
#endif
                    } /* end else */
#ifdef DOS
                if (graphic & LORES)
                    {
                    regs.h.ah = 5;
                    regs.h.al = (char) p;
                    sysint(0x10, &regs, &regs);
                    } /* end then */
#endif
                break;
            case REVERSE:
                toright[p] = !toright[p];
                statlin(posptr[p], amode[p], shift, toright[p],
                    (char (*) [25][80]) &inptext[p] [0] [0] [0]);
                break;
            case REGULAR:
                amode[p] = BUF_ASCII;
                statlin(posptr[p], amode[p], shift, toright[p],
                    (char (*) [25][80]) &inptext[p] [0] [0] [0]);
                break;
            case SPECIAL:
                amode[p] = BUF_ROMCHAR;
                statlin(posptr[p], amode[p], shift, toright[p],
                    (char (*) [25][80]) &inptext[p] [0] [0] [0]);
                break;
            case GREEK:
                amode[p] = BUF_GREEK;
                statlin(posptr[p], amode[p], shift, toright[p],
                    (char (*) [25][80]) &inptext[p] [0] [0] [0]);
                break;
            case HEBREW:
                amode[p] = BUF_HEBREW;
                statlin(posptr[p], amode[p], shift, toright[p],
                    (char (*) [25][80]) &inptext[p] [0] [0] [0]);
                break;
            case LATIN:
                amode[p] = BUF_LATIN;
                statlin(posptr[p], amode[p], shift, toright[p],
                    (char (*) [25][80]) &inptext[p] [0] [0] [0]);
                break;
            } /* end switch, then, else */

    /******************************************************************/
    /* call second level command processor                            */
    /******************************************************************/
    cmd = zdriver(posptr[p], inpt, scan, shift, amode[p], toright[p],
        &line_no[p], &col_no[p], &panel[p], &nfield[p], &rowcol[p],
        (char (*) [25][80]) &inptext[p] [0] [0] [0], &dsn[p] [0],
        &maxlrecl[p], &coloffset[p], &first[p], &curr[p],
        &wherest[p] [0], &wherend[p] [0], &dschanged[p], &place[p],
        &cmdstack[p] [0], rightmar);

    } /* end while */

zepilog(posptr[0], normal_end);

return(normal_end);

} /* end zedmain (main zedit) */
