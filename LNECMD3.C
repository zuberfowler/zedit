#include <stdlib.h>
#include <string.h>
#include "zedit.h"

struct bufline  *lnecmd3(
              union both_scr  *posptr,
              int  maxlrecl,
              register struct bufline  *curr,
              register struct lineptrs  *place,
              char  *pos,
              char  ccnt[8],
              int  *line_no,
              int  *dschanged)
/**********************************************************************/
/*                                                                    */
/* Process line commands from edit screen.  Anything > o.             */
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
    case 'r':
        if (ccnt[0] == 'e')  /* regular chars command */
            {
            if (lcinval(posptr, lc_any, curr))
                break;
            *dschanged = YES;
            curr -> script = BUF_ASCII;
            srpbufr(posptr, maxlrecl, curr);
            srpbufr(posptr, maxlrecl, curr -> next);
            break;
            } /* end then */
        if (lcinval(posptr, lc_both, curr))
            break;
        if (ckplace(posptr, rep_cmd, place))
            break;
        if (ccnt[0] == 'r')
            {
            if (place -> repst)
                {
                if (cmpline(place -> repst, curr) > 0)
                    {
                    place -> repfn = place -> repst;
                    place -> repst = curr;
                    } /* end then */
                else
                    place -> repfn = curr;
                if (place -> repst -> status == ST_XBLK)
                    place -> repst = place -> repst -> bblk;
                } /* end then */
            else
                place -> repst = curr;
            /* check for number following rep */
            ccnt[0] = '0';
            } /* end then */
        if (!(cnt = vrepcnt(posptr, ccnt)))
            break;
        place -> count = cnt;
        if (place -> repst)
            {
            if (place -> repfn)
                {
                curr = place -> repfn -> next;
                rrepblk(posptr, place, maxlrecl);
                curr = curr -> prev;
                *dschanged = YES;
                } /* end then */
            break;
            } /* end then */
        if (curr -> status == ST_XBLK)
            {
            place -> repst = curr -> bblk;
            place -> repfn = curr;
            curr = curr -> next;
            rrepblk(posptr, place, maxlrecl);
            curr = curr -> prev;
            *dschanged = YES;
            break;
            } /* end then */
        place -> count = 0;
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
            curr -> next -> status = curr -> status;
            strcpy(curr -> next -> bline, curr -> bline);
            curr = curr -> next;
            } /* end for */
        curr -> next = hold;
        hold -> prev = curr;
        renbufr(top);
        *dschanged = YES;
        break;
    case 's':
        if (ccnt[0] == 'p')  /* special chars command */
            {
            if (lcinval(posptr, lc_any, curr))
                break;
            *dschanged = YES;
            curr -> script = BUF_ROMCHAR;
            srpbufr(posptr, maxlrecl, curr);
            srpbufr(posptr, maxlrecl, curr -> next);
            dispmsg(posptr, LNECMD3_MSG1);
            break;
            } /* end then */
        if (curr -> status != ST_XBLK)
            break;
        if (!(cnt = vrepcnt(posptr, ccnt)))
            break;
        place -> excst = curr;
        place -> count = cnt;
        curr = excshow(posptr, place, maxlrecl);
        break;
    case 't':
        switch(ccnt[0])
            {
            case 'e':  /* @ text entry */
                if (lcinval(posptr, lc_bottom, curr))
                    break;
                break;
            case 'f':  /* @ text flow  */
                if (lcinval(posptr, lc_any, curr))
                    break;
                break;
            case 's':  /* @ text split */
                if (lcinval(posptr, lc_any, curr))
                    break;
                break;
            default:
                dispmsg(posptr, LNECMD3_MSG2);
                break;
            } /* end switch */
        break;
    case 'x':  /* exclude */
        if (lcinval(posptr, lc_both, curr))
            break;
        if (ckplace(posptr, exc_cmd, place))
            break;
        if (ccnt[0] == 'x')
            {
            if (place -> excst)
                {
                if (cmpline(place -> excst, curr) > 0)
                    {
                    place -> excfn = place -> excst;
                    place -> excst = curr;
                    } /* end then */
                else
                    place -> excfn = curr;
                curr = exclude(posptr, place);
                } /* end then */
            else
                place -> excst = curr;
            break;
            } /* end then */
        if (!(cnt = vrepcnt(posptr, ccnt)))
            break;
        place -> count = cnt;
        place -> excst = curr;
        place -> excfn = curr;
        curr = exclude(posptr, place);
        *line_no += cnt - 1;
        break;
    } /* end switch */

return(curr);

} /* end lnecmd3 */
