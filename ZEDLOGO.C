#include "zedit.h"

void  zedlogo(
              register union both_scr  *posptr)
/**********************************************************************/
/*                                                                    */
/* Produce the ZEDIT logo on the primary option menu panel.           */
/*                                                                    */
/* Hercules mono-graphic screen:                                      */
/* The screen size is 720h X 348v, text is 80 X 25.                   */
/* The screen has four fields (0:3) of rows with each having a range  */
/* of 0:86.  Adjacent rows from the same field are displayed four     */
/* lines apart on the screen.                                         */
/* The character patterns are 7 X 9 (columns X rows) and are framed   */
/* by a 9 X (12 + 2) box (the 2 does not occur on row 25).            */
/* Each char code is translated to an index into the array "zedlchr". */
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
#ifndef S370
#ifndef VMS
extern unsigned int  graphic;
extern char  zedlchr[] [14];

register int  d;  /* down  */
register int  e;  /* range */
register int  f;  /* field */
#ifdef DOS
int  start;
#endif


/**********************************************************************/
if (graphic & IBM1)
    {
    for (d = 0; d < 14; ++d)
        {
        posptr -> is.iscr[7] [d] [72] = zedlchr[0] [d];
        posptr -> is.iscr[7] [d] [73] = zedlchr[1] [d];
        posptr -> is.iscr[7] [d] [74] = zedlchr[2] [d];
        posptr -> is.iscr[7] [d] [75] = zedlchr[2] [d];
        posptr -> is.iscr[7] [d] [76] = zedlchr[2] [d];
        posptr -> is.iscr[7] [d] [77] = zedlchr[2] [d];
        posptr -> is.iscr[7] [d] [78] = zedlchr[2] [d];
        posptr -> is.iscr[7] [d] [79] = zedlchr[3] [d];
        posptr -> is.iscr[7] [d] [80] = zedlchr[4] [d];

        posptr -> is.iscr[8] [d] [73] = zedlchr[5] [d];
        posptr -> is.iscr[8] [d] [74] = zedlchr[6] [d];
        posptr -> is.iscr[8] [d] [75] = zedlchr[7] [d];
        posptr -> is.iscr[8] [d] [76] = zedlchr[7] [d];
        posptr -> is.iscr[8] [d] [77] = zedlchr[8] [d];
        posptr -> is.iscr[8] [d] [78] = zedlchr[9] [d];
        posptr -> is.iscr[8] [d] [79] = zedlchr[10] [d];

        posptr -> is.iscr[9] [d] [75] = zedlchr[11] [d];
        posptr -> is.iscr[9] [d] [76] = zedlchr[12] [d];
        posptr -> is.iscr[9] [d] [77] = zedlchr[13] [d];
        } /* end for */
    } /* end then */


/**********************************************************************/
else if (graphic & EGA)
    {
    for (d = 0; d < 14; ++d)
        {
        posptr -> es.escr[7] [d] [63] = zedlchr[0] [d];
        posptr -> es.escr[7] [d] [64] = zedlchr[1] [d];
        posptr -> es.escr[7] [d] [65] = zedlchr[2] [d];
        posptr -> es.escr[7] [d] [66] = zedlchr[2] [d];
        posptr -> es.escr[7] [d] [67] = zedlchr[2] [d];
        posptr -> es.escr[7] [d] [68] = zedlchr[2] [d];
        posptr -> es.escr[7] [d] [69] = zedlchr[2] [d];
        posptr -> es.escr[7] [d] [70] = zedlchr[3] [d];
        posptr -> es.escr[7] [d] [71] = zedlchr[4] [d];

        posptr -> es.escr[8] [d] [64] = zedlchr[5] [d];
        posptr -> es.escr[8] [d] [65] = zedlchr[6] [d];
        posptr -> es.escr[8] [d] [66] = zedlchr[7] [d];
        posptr -> es.escr[8] [d] [67] = zedlchr[7] [d];
        posptr -> es.escr[8] [d] [68] = zedlchr[8] [d];
        posptr -> es.escr[8] [d] [69] = zedlchr[9] [d];
        posptr -> es.escr[8] [d] [70] = zedlchr[10] [d];

        posptr -> es.escr[9] [d] [66] = zedlchr[11] [d];
        posptr -> es.escr[9] [d] [67] = zedlchr[12] [d];
        posptr -> es.escr[9] [d] [68] = zedlchr[13] [d];
        } /* end for */
    } /* end then */


/**********************************************************************/
else if (graphic & IBM2)
    {
    for (d = 0; d < 14; ++d)
        {
        posptr -> i2.i2scr[7] [d+5] [72] = zedlchr[0] [d];
        posptr -> i2.i2scr[7] [d+5] [73] = zedlchr[1] [d];
        posptr -> i2.i2scr[7] [d+5] [74] = zedlchr[2] [d];
        posptr -> i2.i2scr[7] [d+5] [75] = zedlchr[2] [d];
        posptr -> i2.i2scr[7] [d+5] [76] = zedlchr[2] [d];
        posptr -> i2.i2scr[7] [d+5] [77] = zedlchr[2] [d];
        posptr -> i2.i2scr[7] [d+5] [78] = zedlchr[2] [d];
        posptr -> i2.i2scr[7] [d+5] [79] = zedlchr[3] [d];
        posptr -> i2.i2scr[7] [d+5] [80] = zedlchr[4] [d];

        posptr -> i2.i2scr[8] [d] [73] = zedlchr[5] [d];
        posptr -> i2.i2scr[8] [d] [74] = zedlchr[6] [d];
        posptr -> i2.i2scr[8] [d] [75] = zedlchr[7] [d];
        posptr -> i2.i2scr[8] [d] [76] = zedlchr[7] [d];
        posptr -> i2.i2scr[8] [d] [77] = zedlchr[8] [d];
        posptr -> i2.i2scr[8] [d] [78] = zedlchr[9] [d];
        posptr -> i2.i2scr[8] [d] [79] = zedlchr[10] [d];
        } /* end for */

    for (d = 0; d < 5; ++d)
        {
        posptr -> i2.i2scr[8] [d+14] [75] = zedlchr[11] [d];
        posptr -> i2.i2scr[8] [d+14] [76] = zedlchr[12] [d];
        posptr -> i2.i2scr[8] [d+14] [77] = zedlchr[13] [d];
        } /* end for */

    for (d = 5; d < 14; ++d)
        {
        posptr -> i2.i2scr[9] [d-5] [75] = zedlchr[11] [d];
        posptr -> i2.i2scr[9] [d-5] [76] = zedlchr[12] [d];
        posptr -> i2.i2scr[9] [d-5] [77] = zedlchr[13] [d];
        } /* end for */
    } /* end then */


/**********************************************************************/
else if (graphic & VGA)
    {
    for (d = 0; d < 14; ++d)
        {
        posptr -> vs.vscr[7] [d+5] [63] = zedlchr[0] [d];
        posptr -> vs.vscr[7] [d+5] [64] = zedlchr[1] [d];
        posptr -> vs.vscr[7] [d+5] [65] = zedlchr[2] [d];
        posptr -> vs.vscr[7] [d+5] [66] = zedlchr[2] [d];
        posptr -> vs.vscr[7] [d+5] [67] = zedlchr[2] [d];
        posptr -> vs.vscr[7] [d+5] [68] = zedlchr[2] [d];
        posptr -> vs.vscr[7] [d+5] [69] = zedlchr[2] [d];
        posptr -> vs.vscr[7] [d+5] [70] = zedlchr[3] [d];
        posptr -> vs.vscr[7] [d+5] [71] = zedlchr[4] [d];

        posptr -> vs.vscr[8] [d] [64] = zedlchr[5] [d];
        posptr -> vs.vscr[8] [d] [65] = zedlchr[6] [d];
        posptr -> vs.vscr[8] [d] [66] = zedlchr[7] [d];
        posptr -> vs.vscr[8] [d] [67] = zedlchr[7] [d];
        posptr -> vs.vscr[8] [d] [68] = zedlchr[8] [d];
        posptr -> vs.vscr[8] [d] [69] = zedlchr[9] [d];
        posptr -> vs.vscr[8] [d] [70] = zedlchr[10] [d];
        } /* end then */

    for (d = 0; d < 5; ++d)
        {
        posptr -> vs.vscr[8] [d+14] [66] = zedlchr[11] [d];
        posptr -> vs.vscr[8] [d+14] [67] = zedlchr[12] [d];
        posptr -> vs.vscr[8] [d+14] [68] = zedlchr[13] [d];
        } /* end then */

    for (d = 5; d < 11; ++d)
        {
        posptr -> vs.vscr[9] [d-5] [66] = zedlchr[11] [d];
        posptr -> vs.vscr[9] [d-5] [67] = zedlchr[12] [d];
        posptr -> vs.vscr[9] [d-5] [68] = zedlchr[13] [d];
        } /* end then */
    } /* end then */


/**********************************************************************/
else if (graphic & XGA)
    {
    /* line one */
    for (d = 0, e = 2, f = 3; d < 14; ++d, e += 2, f += 2)
        {
        posptr -> xs.xl[7] [e].xp[32].xb = zedlchr[0] [d];
        posptr -> xs.xl[7] [e].xp[32].sx = zedlchr[1] [d];
        posptr -> xs.xl[7] [e].xp[32].xs = zedlchr[2] [d];
        posptr -> xs.xl[7] [e].xp[33].xb = zedlchr[2] [d];
        posptr -> xs.xl[7] [e].xp[33].sx = zedlchr[2] [d];
        posptr -> xs.xl[7] [e].xp[33].xs = zedlchr[2] [d];
        posptr -> xs.xl[7] [e].xp[34].xb = zedlchr[2] [d];
        posptr -> xs.xl[7] [e].xp[34].sx = zedlchr[3] [d];
        posptr -> xs.xl[7] [e].xp[34].xs = zedlchr[4] [d];

        posptr -> xs.xl[7] [f].xp[32].xb = zedlchr[0] [d];
        posptr -> xs.xl[7] [f].xp[32].sx = zedlchr[1] [d];
        posptr -> xs.xl[7] [f].xp[32].xs = zedlchr[2] [d];
        posptr -> xs.xl[7] [f].xp[33].xb = zedlchr[2] [d];
        posptr -> xs.xl[7] [f].xp[33].sx = zedlchr[2] [d];
        posptr -> xs.xl[7] [f].xp[33].xs = zedlchr[2] [d];
        posptr -> xs.xl[7] [f].xp[34].xb = zedlchr[2] [d];
        posptr -> xs.xl[7] [f].xp[34].sx = zedlchr[3] [d];
        posptr -> xs.xl[7] [f].xp[34].xs = zedlchr[4] [d];
        } /* end for */

    /* line two */
    for (d = 0, e = 0, f = 1; d < 14; ++d, e += 2, f += 2)
        {
        posptr -> xs.xl[8] [e].xp[32].sx = zedlchr[5] [d];
        posptr -> xs.xl[8] [e].xp[32].xs = zedlchr[6] [d];
        posptr -> xs.xl[8] [e].xp[33].xb = zedlchr[7] [d];
        posptr -> xs.xl[8] [e].xp[33].sx = zedlchr[7] [d];
        posptr -> xs.xl[8] [e].xp[33].xs = zedlchr[8] [d];
        posptr -> xs.xl[8] [e].xp[34].xb = zedlchr[9] [d];
        posptr -> xs.xl[8] [e].xp[34].sx = zedlchr[10] [d];

        posptr -> xs.xl[8] [f].xp[32].sx = zedlchr[5] [d];
        posptr -> xs.xl[8] [f].xp[32].xs = zedlchr[6] [d];
        posptr -> xs.xl[8] [f].xp[33].xb = zedlchr[7] [d];
        posptr -> xs.xl[8] [f].xp[33].sx = zedlchr[7] [d];
        posptr -> xs.xl[8] [f].xp[33].xs = zedlchr[8] [d];
        posptr -> xs.xl[8] [f].xp[34].xb = zedlchr[9] [d];
        posptr -> xs.xl[8] [f].xp[34].sx = zedlchr[10] [d];
        } /* end for */

    /* gap */
    posptr -> xs.xl[8] [28].xp[33].xb = zedlchr[11] [0];
    posptr -> xs.xl[8] [28].xp[33].sx = zedlchr[12] [0];
    posptr -> xs.xl[8] [28].xp[33].xs = zedlchr[13] [0];

    posptr -> xs.xl[8] [29].xp[33].xb = zedlchr[11] [0];
    posptr -> xs.xl[8] [29].xp[33].sx = zedlchr[12] [0];
    posptr -> xs.xl[8] [29].xp[33].xs = zedlchr[13] [0];

    /* line three */
    for (d = 1, e = 0, f = 1; d < 14; ++d, e += 2, f += 2)
        {
        posptr -> xs.xl[9] [e].xp[33].xb = zedlchr[11] [d];
        posptr -> xs.xl[9] [e].xp[33].sx = zedlchr[12] [d];
        posptr -> xs.xl[9] [e].xp[33].xs = zedlchr[13] [d];

        posptr -> xs.xl[9] [f].xp[33].xb = zedlchr[11] [d];
        posptr -> xs.xl[9] [f].xp[33].sx = zedlchr[12] [d];
        posptr -> xs.xl[9] [f].xp[33].xs = zedlchr[13] [d];
        } /* end for */
    } /* end then */


/**********************************************************************/
else if (graphic & CGA)
    {
    for (d = 0, e = (7 * 14) / 2; d < 14; ++e)
        for (f = 0; f < 2; ++f)
            {
            posptr -> cs.cpos[f].cscr[e] [63] = zedlchr[0] [d];
            posptr -> cs.cpos[f].cscr[e] [64] = zedlchr[1] [d];
            posptr -> cs.cpos[f].cscr[e] [65] = zedlchr[2] [d];
            posptr -> cs.cpos[f].cscr[e] [66] = zedlchr[2] [d];
            posptr -> cs.cpos[f].cscr[e] [67] = zedlchr[2] [d];
            posptr -> cs.cpos[f].cscr[e] [68] = zedlchr[2] [d];
            posptr -> cs.cpos[f].cscr[e] [69] = zedlchr[2] [d];
            posptr -> cs.cpos[f].cscr[e] [70] = zedlchr[3] [d];
            posptr -> cs.cpos[f].cscr[e] [71] = zedlchr[4] [d];
            ++d;
            } /* end for */

    for (d = 0, e = (8 * 14) / 2; d < 14; ++e)
        for (f = 0; f < 2; ++f)
            {
            posptr -> cs.cpos[f].cscr[e] [64] = zedlchr[5] [d];
            posptr -> cs.cpos[f].cscr[e] [65] = zedlchr[6] [d];
            posptr -> cs.cpos[f].cscr[e] [66] = zedlchr[7] [d];
            posptr -> cs.cpos[f].cscr[e] [67] = zedlchr[7] [d];
            posptr -> cs.cpos[f].cscr[e] [68] = zedlchr[8] [d];
            posptr -> cs.cpos[f].cscr[e] [69] = zedlchr[9] [d];
            posptr -> cs.cpos[f].cscr[e] [70] = zedlchr[10] [d];
            ++d;
            } /* end for */

    for (d = 0, e = (9 * 14) / 2; d < 14; ++e)
        for (f = 0; f < 2; ++f)
            {
            posptr -> cs.cpos[f].cscr[e] [66] = zedlchr[11] [d];
            posptr -> cs.cpos[f].cscr[e] [67] = zedlchr[12] [d];
            posptr -> cs.cpos[f].cscr[e] [68] = zedlchr[13] [d];
            ++d;
            } /* end for */
    } /* end then */


/**********************************************************************/
#ifdef DOS
else if (graphic & HMONO)
    {
    start = (7 * 14) % 4;
    for (d = 0, e = (7 * 14) / 4; d < 14; ++e)
        {
        for (f = start; f < 4  &&  d < 14; ++f)
            {
            posptr -> sa.pos[f].scr[e] [72] = zedlchr[0] [d];
            posptr -> sa.pos[f].scr[e] [73] = zedlchr[1] [d];
            posptr -> sa.pos[f].scr[e] [74] = zedlchr[2] [d];
            posptr -> sa.pos[f].scr[e] [75] = zedlchr[2] [d];
            posptr -> sa.pos[f].scr[e] [76] = zedlchr[2] [d];
            posptr -> sa.pos[f].scr[e] [77] = zedlchr[2] [d];
            posptr -> sa.pos[f].scr[e] [78] = zedlchr[2] [d];
            posptr -> sa.pos[f].scr[e] [79] = zedlchr[3] [d];
            posptr -> sa.pos[f].scr[e] [80] = zedlchr[4] [d];
            ++d;
            } /* end for */
        start = 0;
        } /* end for */

    start = (8 * 14) % 4;
    for (d = 0, e = (8 * 14) / 4; d < 14; ++e)
        {
        for (f = start; f < 4  &&  d < 14; ++f)
            {
            posptr -> sa.pos[f].scr[e] [73] = zedlchr[5] [d];
            posptr -> sa.pos[f].scr[e] [74] = zedlchr[6] [d];
            posptr -> sa.pos[f].scr[e] [75] = zedlchr[7] [d];
            posptr -> sa.pos[f].scr[e] [76] = zedlchr[7] [d];
            posptr -> sa.pos[f].scr[e] [77] = zedlchr[8] [d];
            posptr -> sa.pos[f].scr[e] [78] = zedlchr[9] [d];
            posptr -> sa.pos[f].scr[e] [79] = zedlchr[10] [d];
            ++d;
            } /* end for */
        start = 0;
        } /* end for */

    start = (9 * 14) % 4;
    for (d = 0, e = (9 * 14) / 4; d < 14; ++e)
        {
        for (f = start; f < 4  &&  d < 14; ++f)
            {
            posptr -> sa.pos[f].scr[e] [75] = zedlchr[11] [d];
            posptr -> sa.pos[f].scr[e] [76] = zedlchr[12] [d];
            posptr -> sa.pos[f].scr[e] [77] = zedlchr[13] [d];
            ++d;
            } /* end for */
        start = 0;
        } /* end for */
    } /* end then */
#endif


#endif
#endif
} /* end zedlogo */
