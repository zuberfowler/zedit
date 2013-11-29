#include "zedit.h"

void  rdsprom(
              union both_scr  *posptr,
              int  line_no,
              int  col_no,
              char  inptext[] [25] [80])
/**********************************************************************/
/*                                                                    */
/* Redisplay a rom character to the screen including any overlays.    */
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


dsp8chr(posptr, inptext[TXT] [line_no] [col_no], line_no, col_no);
if (inptext[OVR] [line_no] [col_no] == OVR_UNDERLINE)
    ovr8chr(posptr, UNDERLINE, line_no, col_no);

} /* end rdsprom */
