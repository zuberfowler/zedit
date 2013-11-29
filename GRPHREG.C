#include <stdlib.h>
#include "zedit.h"
#include "hdafi.h"

#ifdef OS2
#define INCL_DOS
#define INCL_SUB
#define INCL_NOPMAPI
#include <os2.h>
#endif

void  grphreg(void)
/**********************************************************************/
/*                                                                    */
/* Set the registers to graphic mode values.                          */
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
static unsigned short S16  tstate = NULL;

static struct hqdps_parm  xq = {6, 0, 0, 0};
static struct hopen_parm  xo = {3, 0, 0, 0};
static struct hinit_parm  xi = {2, 0};
static struct hsmx_parm   xx = {2, MIX_NOC, MIX_OVER};
static struct hscol_parm  xc = {4, HD_CYAN};


#ifndef AIX
#ifndef S370
#ifndef OS2

union regs_both  regs;


#ifdef VMS
#include <stdio.h>


if (graphic & DISPL)
    printf("%cPpS(E)", 0x1B);


#else


if (graphic & HMONO)
    {
    /* reg 0 */
    prtcntl(ADDR_REG, 0x0000);
    prtcntl(DATA_REG, 0x0035);

    /* reg 1 */
    prtcntl(ADDR_REG, 0x0001);
    prtcntl(DATA_REG, 0x002D);

    /* reg 2 */
    prtcntl(ADDR_REG, 0x0002);
    prtcntl(DATA_REG, 0x002E);

    /* reg 3 */
    prtcntl(ADDR_REG, 0x0003);
    prtcntl(DATA_REG, 0x0007);

    /* reg 4 */
    prtcntl(ADDR_REG, 0x0004);
    prtcntl(DATA_REG, 0x005B);

    /* reg 5 */
    prtcntl(ADDR_REG, 0x0005);
    prtcntl(DATA_REG, 0x0002);

    /* reg 6 */
    prtcntl(ADDR_REG, 0x0006);
    prtcntl(DATA_REG, 0x0057);

    /* reg 7 */
    prtcntl(ADDR_REG, 0x0007);
    prtcntl(DATA_REG, 0x0057);

    /* reg 9 */
    prtcntl(ADDR_REG, 0x0009);
    prtcntl(DATA_REG, 0x0003);

    /* reg 10 */
    prtcntl(ADDR_REG, 0x000A);
    prtcntl(DATA_REG, 0x0000);

    /* reg 11 */
    prtcntl(ADDR_REG, 0x000B);
    prtcntl(DATA_REG, 0x0000);
    } /* end then */

/* 640 x 480 (sixteen possible) color graphics VGA */
/* 640 x 480 two color graphics MCGA */
else if (graphic & HIRES)
    {
    regs.h.ah = 0;
    if (graphic & UCOLOR)
        regs.h.al = 18;  /* VGA */
    else
        regs.h.al = 17;  /* MCGA */
    sysint(0x10, &regs, &regs);

    /* 720 x 480 (sixteen possible) color graphics VGA */
    if (graphic & IBM2)
        {
        ibmmode();
        if (graphic & UCOLOR)
            {
            /* set the ibm color (cyan) */
            prtcntl(0x03CE, 0x0001);
            prtcntl(0x03CF, 0x0004);
            } /* end then */
        } /* end then */
    else
        if (graphic & UCOLOR)
            {
            /* set the vga color (purple) */
            prtcntl(0x03CE, 0x0001);
            prtcntl(0x03CF, 0x0002);
            } /* end else */
    } /* end then */

/* 640 x 350 (sixteen possible) color graphics EGA */
else if (graphic & LORES)
    {
    regs.h.ah = 0;
    regs.h.al = 16;
    sysint(0x10, &regs, &regs);

    /* 720 x 350 (sixteen possible) color graphics EGA */
    if (graphic & IBM1)
        {
        ibmmode();
        if (graphic & UCOLOR)
            {
            /* set the ibm color (cyan) */
            prtcntl(0x03CE, 0x0001);
            prtcntl(0x03CF, 0x0004);
            } /* end then */
        } /* end then */
    else
        if (graphic & UCOLOR)
            {
            /* set the ega color (purple) */
            prtcntl(0x03CE, 0x0001);
            prtcntl(0x03CF, 0x0002);
            } /* end else */
    } /* end then */

else if (graphic & CGA)
    {
    regs.h.ah = 0;
    regs.h.al = 6;
    sysint(0x10, &regs, &regs);
    } /* end then */

else if (graphic & XGA)
    {
    if (!tstate)
        {
        if (!getafi())
            zfinish(NULL, video_fail);

        HQDPS(&xq);
        tstate = (unsigned short S16) malloc(xq.bufsize + 15);
        xi.tstate_seg = SELPTR(tstate) + ((OFFPTR(tstate) + 15u) >> 4u);
        } /* end then */

    HOPEN(&xo);
    if (xo.rc != 0)
        zfinish(NULL, video_fail);

    HINIT(&xi);
    HSMX(&xx);
    if (graphic & UCOLOR)
        HSCOL(&xc);
    HEGS();
    } /* end then */


#endif
#else
/**********************************************************************/
/*                                                                    */
/* OS2 compile code.                                                  */
/*                                                                    */
/**********************************************************************/

VIOMODEINFO  sel;


/* 640 x 480 (sixteen possible) color graphics VGA */
/* 640 x 480 two color graphics MCGA */
if (graphic & HIRES)
    {
    sel.cb = 12;
    sel.fbType = VGMT_OTHER | VGMT_GRAPHICS;
    if (graphic & UCOLOR)
        sel.color = 4;
    else
        sel.color = 1;
    sel.col = 80;
    sel.row = 50;
    sel.hres = 640;
    sel.vres = 480;
    while (VioSetMode(&sel, 0) == 438)
        {;}; /* end while */

    if (graphic & IBM2)
        {
        /* 720 x 480 (sixteen possible) color graphics VGA */
        IOPLibm();
        if (graphic & UCOLOR)
            IOPLcya();
        } /* end then */
    else
        if (graphic & UCOLOR)
            IOPLpur();
    } /* end then */

else if (graphic & LORES)
    {
    /* 640 x 350 (sixteen possible) color graphics EGA */
    sel.cb = 12;
    sel.fbType = VGMT_OTHER | VGMT_GRAPHICS;
    sel.color = 4;
    sel.col = 80;
    sel.row = 25;
    sel.hres = 640;
    sel.vres = 350;
    while (VioSetMode(&sel, 0) == 438)
        {;}; /* end while */

    if (graphic & IBM1)
        {
        /* 720 x 350 (sixteen possible) color graphics EGA */
        IOPLibm();
        if (graphic & UCOLOR)
            IOPLcya();
        } /* end then */
    else
        if (graphic & UCOLOR)
            IOPLpur();
    } /* end then */

else if (graphic & XGA)
    {
    /* 1024 x 768 XGA graphics */
    if (!tstate)
        {
        if (makeafi())
            zfinish(NULL, video_fail);
        HQDPS(&xq);
        HOPEN(&xo);
        if (xo.rc != 0)
            zfinish(NULL, video_fail);

        tstate = (unsigned short S16) &xi.tstate_seg;
        if (DosAllocSeg(xq.bufsize, tstate, 0u))
            zfinish(NULL, no_storage);

        HINIT(&xi);
        HSMX(&xx);
        if (graphic & UCOLOR)
            HSCOL(&xc);
        HEGS();
        } /* end then */
    else
        {
        HOPEN(&xo);
        if (xo.rc != 0)
            zfinish(NULL, video_fail);

        HSYNC(&xi);
        HSMX(&xx);
        if (graphic & UCOLOR)
            HSCOL(&xc);
        HEGS();
        } /* end else */
    } /* end then */

else if (graphic & CGA)
    {
    /* 640 x 200 CGA graphics */
    sel.cb = 12;
    sel.fbType = VGMT_OTHER | VGMT_GRAPHICS;
    sel.color = 1;
    sel.col = 80;
    sel.row = 25;
    sel.hres = 640;
    sel.vres = 200;
    while (VioSetMode(&sel, 0) == 438)
        {;}; /* end while */
    } /* end then */

#endif
#endif
#endif
} /* end grphreg */
