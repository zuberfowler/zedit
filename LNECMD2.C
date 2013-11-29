#include <stdlib.h>
#include <string.h>
#include "zedit.h"

struct bufline  *lnecmd2(
              union both_scr  *posptr,
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
/* Process line commands from edit screen.  Anything between f and o. */
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
unsigned int  len_bufline;


switch(*pos)
    {
    case 'f':
        if (curr -> status != ST_XBLK)
            break;
        if (!(cnt = vrepcnt(posptr, ccnt)))
            break;
        place -> excst = curr;
        place -> count = cnt;
        curr = excshow(posptr, place, maxlrecl);
        break;
    case 'g':
        if (ccnt[0] == 'r')  /* Greek chars command */
            {
            if (lcinval(posptr, lc_any, curr))
                break;
            *dschanged = YES;
            curr -> script = BUF_GREEK;
            srpbufr(posptr, maxlrecl, curr);
            srpbufr(posptr, maxlrecl, curr -> next);
            dispmsg(posptr, LNECMD2_MSG1);
            break;
            } /* end then */
        dispmsg(posptr, LNECMD2_MSG2);
        break;
    case 'h':
        if (ccnt[0] == 'e')  /* Hebrew chars command */
            {
            if (lcinval(posptr, lc_any, curr))
                break;
            *dschanged = YES;
            curr -> script = BUF_HEBREW;
            srpbufr(posptr, maxlrecl, curr);
            srpbufr(posptr, maxlrecl, curr -> next);
            dispmsg(posptr, LNECMD2_MSG1);
            break;
            } /* end then */
        dispmsg(posptr, LNECMD2_MSG2);
        break;
    case 'i':
        if (lcinval(posptr, lc_bottom, curr))
            break;
        if (!(cnt = vrepcnt(posptr, ccnt)))
            break;
        len_bufline = sizeof(struct bufline_hdr) + maxlrecl;
        top = curr;
        hold = curr -> next;
        for (n = 0; n < cnt; ++n)
            {
            curr -> next = (struct bufline *) malloc(len_bufline);
            if (!(curr -> next))
                zfinish(posptr, no_storage);
            memset(curr -> next, '\0', len_bufline);
            curr -> next -> prev = curr;
            curr -> next -> script = curr -> script;
            curr = curr -> next;
            curr -> status = ST_NORM;
            curr -> bline[0] = '\n';
            } /* end for */
        curr -> next = hold;
        hold -> prev = curr;
        renbufr(top);
        *dschanged = YES;
        break;
    case 'k':
        if (lcinval(posptr, lc_top, curr))
            break;
        place -> colsb = curr;
        pshstck(cmd, KEYS);
        if (cmd[0] == NEXTINPT)
            cmd[0] = NOP;
        break;
    case 'l':
        if (ccnt[0] == 'a')  /* Latin chars command */
            {
            if (lcinval(posptr, lc_any, curr))
                break;
            *dschanged = YES;
            curr -> script = BUF_LATIN;
            srpbufr(posptr, maxlrecl, curr);
            srpbufr(posptr, maxlrecl, curr -> next);
            dispmsg(posptr, LNECMD2_MSG1);
            break;
            } /* end then */
        if (ccnt[0] == 'e')  /* Lets command */
            {
            if (lcinval(posptr, lc_top, curr))
                break;
            place -> colsb = curr;
            pshstck(cmd, LETS);
            if (cmd[0] == NEXTINPT)
                cmd[0] = NOP;
            break;
            } /* end then */
        if (curr -> status != ST_XBLK)
            break;
        if (!(cnt = vrepcnt(posptr, ccnt)))
            break;
        place -> excfn = curr;
        place -> count = cnt;
        curr = excshow(posptr, place, maxlrecl);
        break;
    case 'm':
        if (lcinval(posptr, lc_both, curr))
            break;
        if (ckplace(posptr, move_cmd, place))
            break;
        if (ccnt[0] == 'm')
            {
            if (place -> movest)
                {
                if (cmpline(place -> movest, curr) > 0)
                    {
                    place -> movefn = place -> movest;
                    place -> movest = curr;
                    } /* end then */
                else
                    place -> movefn = curr;
                curr = place -> movefn -> next;
                if (place -> movest -> status == ST_XBLK)
                    place -> movest = place -> movest -> bblk;
                movecpy(posptr, place, maxlrecl);
                curr = curr -> prev;
                *dschanged = YES;
                } /* end then */
            else
                place -> movest = curr;
            break;
            } /* end then */
        if (!(cnt = vrepcnt(posptr, ccnt)))
            break;
        --cnt;
        if (curr -> status == ST_XBLK)
            place -> movest = curr -> bblk;
        else
            place -> movest = curr;
        hold = curr;
        n = 0;
        while (n < cnt  &&  hold -> next -> next)
            {
            hold = hold -> next;
            if (!(hold -> status & ST_EXCL))
                ++n;
            } /* end while */
        place -> movefn = hold;
        curr = hold -> next;
        movecpy(posptr, place, maxlrecl);
        curr = curr -> prev;
        *line_no += cnt;
        *dschanged = YES;
        break;
    case 'o':
        /* dschanged set by companion command */
        if (lcinval(posptr, lc_both, curr))
            break;
        if (ckplace(posptr, on_cmd, place))
            break;
        if (ccnt[0] == 'o')
            {
            if (place -> onst)
                {
                if (cmpline(place -> onst, curr) > 0)
                    {
                    place -> onfn = place -> onst;
                    place -> onst = curr;
                    } /* end then */
                else
                    place -> onfn = curr;
                if (place -> onst -> status == ST_XBLK)
                    place -> onst = place -> onst -> bblk;
                movecpy(posptr, place, maxlrecl);
                } /* end then */
            else
                place -> onst = curr;
            break;
            } /* end then */
        if (!(cnt = vrepcnt(posptr, ccnt)))
            break;
        --cnt;
        if (curr -> status == ST_XBLK)
            place -> onst = curr -> bblk;
        else
            place -> onst = curr;
        hold = curr;
        n = 0;
        while (n < cnt  &&  hold -> next -> next)
            {
            hold = hold -> next;
            if (!(hold -> status & ST_EXCL))
                ++n;
            } /* end while */
        place -> onfn = hold;
        movecpy(posptr, place, maxlrecl);
        break;
    } /* end switch */

return(curr);

} /* end lnecmd2 */
