#include "zedit.h"

void  rdspgrk(
              union both_scr  *posptr,
              int  line_no,
              int  col_no,
              char  inptext[] [25] [80])
/**********************************************************************/
/*                                                                    */
/* Redisplay a Greek character on the screen including any overlays.  */
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
extern char  grkchar[128] [14];


if (inptext[OVR] [line_no] [col_no] == OVR_SIGMATERM)
    dispchr(posptr, SIGMATERM, line_no, col_no, grkchar);
else
    {
    dispchr(posptr, inptext[TXT] [line_no ] [col_no], line_no, col_no,
        grkchar);

    if (inptext[OVR] [line_no ] [col_no] & OVR_ACUTE)
        overchr(posptr, ACUTE, line_no, col_no, grkchar, NO);
    else if (inptext[OVR] [line_no ] [col_no] & OVR_CIRCUMFLEX)
        overchr(posptr, CIRCUMFLEX, line_no, col_no, grkchar, NO);
    else if (inptext[OVR] [line_no ] [col_no] & OVR_GRAVE)
        overchr(posptr, GRAVE, line_no, col_no, grkchar, NO);

    if (inptext[OVR] [line_no ] [col_no] & OVR_SMOOTH)
        overchr(posptr, SMOOTH, line_no, col_no, grkchar, NO);
    else if (inptext[OVR] [line_no ] [col_no] & OVR_ROUGH)
        overchr(posptr, ROUGH, line_no, col_no, grkchar, NO);

    if (inptext[OVR] [line_no ] [col_no] & OVR_IOTASUB)
        overchr(posptr, IOTASUB, line_no, col_no, grkchar, NO);

    if (inptext[OVR] [line_no ] [col_no] & OVR_UMLAUT)
        overchr(posptr, UMLAUT, line_no, col_no, grkchar, NO);
    } /* end else */

} /* end rdspgrk */
