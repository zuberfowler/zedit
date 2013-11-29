#include "zedit.h"

unsigned int  funckey(
              int  scan,
              unsigned int  shift)
/**********************************************************************/
/*                                                                    */
/* Determine function key command value.                              */
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
/* function key values */
extern unsigned int  fkeyset[4] [12];


if (scan < 0x0080)
    if (shift & BOTH_SHIFT)
        return(fkeyset[1] [scan - SHIFT_F1]);
    else if (shift & CNTL_KEY)
        if (scan == CNTL_END)
            return(ERASEEOF);
        else
            return(fkeyset[2] [scan - CNTL_F1]);
    else if (shift & ALT_KEY)
        return(fkeyset[3] [scan - ALT_F1]);
    else
        return(fkeyset[0] [scan - F1]);
else
    if (shift & BOTH_SHIFT)
        return(fkeyset[1] [10 + scan - SHIFT_F11]);
    else if (shift & CNTL_KEY)
        if (scan == CNTL_DEL)
            return(ERASEEOF);
        else
            return(fkeyset[2] [10 + scan - CNTL_F11]);
    else if (shift & ALT_KEY)
        return(fkeyset[3] [10 + scan - ALT_F11]);
 /* else */
        return(fkeyset[0] [10 + scan - F11]);

} /* end funckey */
