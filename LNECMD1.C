#include <stdlib.h>
#include "zedit.h"

struct bufline  *lnecmd1(
              union both_scr  *posptr,
              int  nfield,
              int  rowcol[] [5],
              unsigned int  cmd[],
              int  maxlrecl,
              register struct bufline  *curr,
              register struct lineptrs  *place,
              char  *pos,
              char  ccnt[8],
              int  *line_no,
              int  *dschanged)
/**********************************************************************/
/*                                                                    */
/* Process line commands from edit screen.  Anything < f.             */
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
struct bufline  *hold;
struct bufline  *top;

register int  n;
register int  cnt;


switch(*pos)
    {
    case '#':  /* already processed */
        break;
    case '(':
        if (lcinval(posptr, lc_any, curr))
            break;
        if (ckplace(posptr, sl_cmd, place))
            break;
        if (ccnt[0] == '(')
            {
            if (place -> slst)
                {
                if (cmpline(place -> slst, curr) > 0)
                    {
                    place -> slfn = place -> slst;
                    place -> slst = curr;
                    } /* end then */
                else
                    place -> slfn = curr;
                if (place -> slst -> status == ST_XBLK)
                    place -> slst = place -> slst -> bblk;
                } /* end then */
            else
                place -> slst = curr;
            /* check for number following shift */
            ccnt[0] = '0';
            } /* end then */

        if (!(cnt = vrepcnt(posptr, ccnt)))
            break;
        if (cnt >= maxlrecl)
            {
            dispmsg(posptr, LNECMD1_MSG1);
            cnt = 1;
            } /* end then */
        place -> count = cnt;
        if (place -> slst)
            {
            if (place -> slfn)
                {
                shiftlf(posptr, place, maxlrecl);
                *dschanged = YES;
                } /* end then */
            break;
            } /* end then */
        if (curr -> status == ST_XBLK)
            place -> slst = curr -> bblk;
        else
            place -> slst = curr;
        place -> slfn = curr;
        shiftlf(posptr, place, maxlrecl);
        *dschanged = YES;
        break;
    case ')':
        if (lcinval(posptr, lc_any, curr))
            break;
        if (ckplace(posptr, sr_cmd, place))
            break;
        if (ccnt[0] == ')')
            {
            if (place -> srst)
                {
                if (cmpline(place -> srst, curr) > 0)
                    {
                    place -> srfn = place -> srst;
                    place -> srst = curr;
                    } /* end then */
                else
                    place -> srfn = curr;
                if (place -> srst -> status == ST_XBLK)
                    place -> srst = place -> srst -> bblk;
                } /* end then */
            else
                place -> srst = curr;
            /* check for number following shift */
            ccnt[0] = '0';
            } /* end then */

        if (!(cnt = vrepcnt(posptr, ccnt)))
            break;
        place -> count = cnt;
        if (place -> srst)
            {
            if (place -> srfn)
                {
                shiftrt(posptr, place, maxlrecl);
                *dschanged = YES;
                } /* end then */
            break;
            } /* end then */
        if (curr -> status == ST_XBLK)
            place -> srst = curr -> bblk;
        else
            place -> srst = curr;
        place -> srfn = curr;
        shiftrt(posptr, place, maxlrecl);
        *dschanged = YES;
        break;
    case 'a':
        if (lcinval(posptr, lc_bottom, curr))
            break;
        if (ccnt[0])
            {
            dispmsg(posptr, LNECMD1_MSG2);
            break;
            } /* end then */
        place -> after = curr;
        curr = curr -> next;
        movecpy(posptr, place, maxlrecl);
        curr = curr -> prev;
        /* dschanged set by companion command */
        break;
    case 'b':
        if (lcinval(posptr, lc_top, curr))
            break;
        if (ccnt[0])
            {
            dispmsg(posptr, LNECMD1_MSG2);
            break;
            } /* end then */
        if (curr -> status == ST_XBLK)
            place -> after = curr -> bblk -> prev;
        else
            place -> after = curr -> prev;
        movecpy(posptr, place, maxlrecl);
        /* dschanged set by companion command */
        break;
    case 'c':
        if (lcinval(posptr, lc_both, curr))
            break;
        if (ccnt[0] == 'o') /* COLS */
            {
            place -> colsb = curr;
            pshstck(cmd, COLMS);
            if (cmd[0] == NEXTINPT)
                cmd[0] = NOP;
            break;
            } /* end then, else */
        if (ckplace(posptr, copy_cmd, place))
            break;
        if (ccnt[0] == 'c')
            {
            if (place -> copyst)
                {
                if (cmpline(place -> copyst, curr) > 0)
                    {
                    place -> copyfn = place -> copyst;
                    place -> copyst = curr;
                    } /* end then */
                else
                    place -> copyfn = curr;
                if (place -> copyst -> status == ST_XBLK)
                    place -> copyst = place -> copyst -> bblk;
                movecpy(posptr, place, maxlrecl);
                *dschanged = YES;
                } /* end then */
            else
                place -> copyst = curr;
            break;
            } /* end then */
        if (!(cnt = vrepcnt(posptr, ccnt)))
            break;
        --cnt;
        if (curr -> status == ST_XBLK)
            place -> copyst = curr -> bblk;
        else
            place -> copyst = curr;
        hold = curr;
        n = 0;
        while (n < cnt  &&  hold -> next -> next)
            {
            hold = hold -> next;
            if (!(hold -> status & ST_EXCL))
                ++n;
            } /* end while */
        place -> copyfn = hold;
        movecpy(posptr, place, maxlrecl);
        *dschanged = YES;
        break;
    case 'd':
        if (lcinval(posptr, lc_both, curr))
            break;
        if (ckplace(posptr, del_cmd, place))
            break;
        if (ccnt[0] == 'd')
            {
            if (place -> delst)
                {
                if (cmpline(place -> delst, curr) > 0)
                    {
                    place -> delfn = place -> delst;
                    place -> delst = curr;
                    } /* end then */
                else
                    place -> delfn = curr;
                curr = place -> delfn -> next;
                if (place -> delst -> status == ST_XBLK)
                    place -> delst = place -> delst -> bblk;
                ddelblk(posptr, place, maxlrecl);
                curr = curr -> prev;
                *dschanged = YES;
                } /* end then */
            else
                place -> delst = curr;
            break;
            } /* end then */
        if (!(cnt = vrepcnt(posptr, ccnt)))
            break;
        if (*line_no == rowcol[nfield - 1] [TOP_MAR])
            place -> newcurr = curr -> prev;
        if (curr -> status == ST_XBLK)
            curr = curr -> bblk;
        top = curr -> prev;
        n = 0;
        while (curr -> next  &&  n < cnt)
            {
            if (!(curr -> status & ST_EXCL))
                ++n;
            hold = curr;
            curr = curr -> next;
            free(hold);
            } /* end for */
        *dschanged = YES;
        *line_no += cnt - 1;
        top -> next = curr;
        curr -> prev = top;
        srpbufr(posptr, maxlrecl, curr);
        renbufr(top);
        curr = top;
        break;
    } /* end switch */

return(curr);

} /* end lnecmd1 */
