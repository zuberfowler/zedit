#include "zedit.h"

char  *loclcmd(
              register struct bufline  *curr,
              char  lctxt[8],
              char  lcsrp[8],
              char  operand[8])
/**********************************************************************/
/*                                                                    */
/* Find line commands in a line command field and do initial parse.   */
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
static char  *line_cmd = "#\"()abcdfghiklmorstx";

register int  n;
register int  sub;

register char  *pos;
register char  *p;


pos = lindex(lower(lctxt), line_cmd);

if (!pos)
    return(NULL);

p = pos;
++p;

sub = pos - lctxt;
++sub;

n = 0;

while((*p != curr -> lineno[sub])  ||
    ((*p == '0')  &&  ((lcsrp[sub] & SRP_MASK) != SRP_ROMCHAR)))
    {
    ++sub;
    operand[n++] = *p++;
    } /* end while */

if (operand[0] == ' ')
    operand[0] = '\0';

operand[n] = '\0';

/* replace alias with line command */
if (*pos == '"')
    {
    *pos = 'r';
    if (operand[0] == '"')
        operand[0] = 'r';
    } /* end then */

return(pos);

} /* end loclcmd */
