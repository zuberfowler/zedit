#include "zedit.h"

int  ckplace(
              union both_scr  *posptr,
              enum cktype  type,
              register struct lineptrs  *place)
/**********************************************************************/
/*                                                                    */
/* When a block command is begun on a line this routine checks if     */
/* there are any conflicting block commands already outstanding.      */
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

switch(type)
    {
    case sl_cmd:
        if (place -> srst  ||  place -> delst  ||  place -> copyst  ||
            place -> onst  ||  place -> excst  ||  place -> movest  ||
            place -> repst)
            {
            dispmsg(posptr, CKPLACE_MSG1);
            return(YES);
            } /* end then */
        else
            return(NO);
    case sr_cmd:
        if (place -> slst  ||  place -> excst  ||  place -> copyst  ||
            place -> onst  ||  place -> delst  ||  place -> movest  ||
            place -> repst)
            {
            dispmsg(posptr, CKPLACE_MSG1);
            return(YES);
            } /* end then */
        else
            return(NO);
    case copy_cmd:
        if (place -> slst  ||  place -> delst  ||  place -> movest  ||
            place -> srst  ||  place -> excst  ||  place -> repst)
            {
            dispmsg(posptr, CKPLACE_MSG1);
            return(YES);
            } /* end then */
        else
            return(NO);
    case del_cmd:
        if (place -> slst  ||  place -> copyst  ||  place -> excst  ||
            place -> srst  ||  place -> movest  ||  place -> repst  ||
            place -> onst)
            {
            dispmsg(posptr, CKPLACE_MSG1);
            return(YES);
            } /* end then */
        else
            return(NO);
    case move_cmd:
        if (place -> slst  ||  place -> excst  ||  place -> copyst  ||
            place -> srst  ||  place -> delst  ||  place -> repst)
            {
            dispmsg(posptr, CKPLACE_MSG1);
            return(YES);
            } /* end then */
        else
            return(NO);
    case on_cmd:
        if (place -> slst  ||  place -> excst  ||  place -> onfn  ||
            place -> srst  ||  place -> delst  ||  place -> repst)
            {
            dispmsg(posptr, CKPLACE_MSG1);
            return(YES);
            } /* end then */
        else
            return(NO);
    case rep_cmd:
        if (place -> slst  ||  place -> excst  ||  place -> copyst  ||
            place -> srst  ||  place -> delst  ||  place -> movest  ||
            place -> onst)
            {
            dispmsg(posptr, CKPLACE_MSG1);
            return(YES);
            } /* end then */
        else
            return(NO);
    case exc_cmd:
        if (place -> slst  ||  place -> repst  ||  place -> copyst  ||
            place -> srst  ||  place -> delst  ||  place -> movest  ||
            place -> onst)
            {
            dispmsg(posptr, CKPLACE_MSG1);
            return(YES);
            } /* end then */
        else
            return(NO);
    } /* end switch */

/* should never reach here */
return(NO);
} /* end ckplace */
