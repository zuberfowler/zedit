#include "zedit.h"

void  ibmmode(void)
/**********************************************************************/
/*                                                                    */
/* Set the registers to custom IBM graphic mode values.               */
/* IBM1 - 720 x 350 (sixteen possible) color graphics EGA             */
/* IBM2 - 720 x 480 (sixteen possible) color graphics VGA             */
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
register int  value;


/* before - reset sequencer register */
prtcntl(0x03C4, 0x0000);
prtcntl(0x03C5, 0x0001);

/* change dot clock frequency */
value = prtinpt(0x03CC);
value |= 0x0004;
prtcntl(0x03C2, value);

/* after - reset sequencer register */
prtcntl(0x03C4, 0x0000);
prtcntl(0x03C5, 0x0003);

/* unlock registers */
prtcntl(0x03D4, 0x0011);
value = prtinpt(0x03D5);
value &= 0x007F;
prtcntl(0x03D5, value);

/* controler registers */
prtcntl(0x03D4, 0x0000);
prtcntl(0x03D5, 0x006B);
prtcntl(0x03D4, 0x0001);
prtcntl(0x03D5, 0x0059);
prtcntl(0x03D4, 0x0002);
prtcntl(0x03D5, 0x005A);
prtcntl(0x03D4, 0x0004);
prtcntl(0x03D5, 0x005E);
prtcntl(0x03D4, 0x0005);
prtcntl(0x03D5, 0x008C);

/* ninety bytes of input buffer */
prtcntl(0x03D4, 0x0013);
prtcntl(0x03D5, 0x002D);

/* lock registers */
prtcntl(0x03D4, 0x0011);
value = prtinpt(0x03D5);
value |= 0x0080;
prtcntl(0x03D5, value);

} /* end ibmmode */
