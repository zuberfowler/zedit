#include "zedit.h"

void  rdspasc(
              union both_scr  *posptr,
              int  line_no,
              int  col_no,
              char  inptext[] [25] [80])
/**********************************************************************/
/*                                                                    */
/* Redisplay ascii character to the screen including any overlays.    */
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
extern char  ascchar[128] [14];


dispchr(posptr, inptext[TXT] [line_no] [col_no], line_no, col_no,
    ascchar);
if (inptext[OVR] [line_no] [col_no] == OVR_UNDERLINE)
    overchr(posptr, UNDERLINE, line_no, col_no, ascchar, NO);

} /* end rdspasc */
