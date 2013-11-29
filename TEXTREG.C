#include "zedit.h"

#ifdef OS2
#define INCL_SUB
#define INCL_NOPMAPI
#include <os2.h>
#endif

void  textreg(void)
/**********************************************************************/
/*                                                                    */
/* Set the registers to text mode values.                             */
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
#ifndef AIX
#ifndef S370
#ifndef OS2
extern unsigned int  graphic;

union  regs_both  regs;


#ifdef VMS
#include <stdio.h>


if (graphic & DISPL)
    printf("S(E)%c\\", 0x1B);
else
    endwin();


#else


if (graphic & HMONO)
    {
    /* reg 0 */
    prtcntl(ADDR_REG, 0x0000);
    prtcntl(DATA_REG, 0x0061);

    /* reg 1 */
    prtcntl(ADDR_REG, 0x0001);
    prtcntl(DATA_REG, 0x0050);

    /* reg 2 */
    prtcntl(ADDR_REG, 0x0002);
    prtcntl(DATA_REG, 0x0052);

    /* reg 3 */
    prtcntl(ADDR_REG, 0x0003);
    prtcntl(DATA_REG, 0x000F);

    /* reg 4 */
    prtcntl(ADDR_REG, 0x0004);
    prtcntl(DATA_REG, 0x0019);

    /* reg 5 */
    prtcntl(ADDR_REG, 0x0005);
    prtcntl(DATA_REG, 0x0006);

    /* reg 6 */
    prtcntl(ADDR_REG, 0x0006);
    prtcntl(DATA_REG, 0x0019);

    /* reg 7 */
    prtcntl(ADDR_REG, 0x0007);
    prtcntl(DATA_REG, 0x0019);

    /* reg 9 */
    prtcntl(ADDR_REG, 0x0009);
    prtcntl(DATA_REG, 0x000D);

    /* reg 10 */
    prtcntl(ADDR_REG, 0x000A);
    prtcntl(DATA_REG, 0x000B);

    /* reg 11 */
    prtcntl(ADDR_REG, 0x000B);
    prtcntl(DATA_REG, 0x000C);
    } /* end then */

else if (graphic & NOT_H)  /* ie. CGA, EGA, IBM, etc. */
    {
    regs.h.ah = 0;
    regs.h.al = 3;
    sysint(0x10, &regs, &regs);
    } /* end then */

#endif
#else
/**********************************************************************/
/*                                                                    */
/* OS2 compile code.                                                  */
/*                                                                    */
/**********************************************************************/

VIOMODEINFO  sel;


sel.cb = 12;
sel.fbType = VGMT_OTHER;
sel.col = 80;
sel.row = 25;
sel.color = 1;
sel.hres = 720;
sel.vres = 350;
while (VioSetMode(&sel, 0) == 438)
    {;}; /* end while */

#endif
#endif
#endif
} /* end textreg */
