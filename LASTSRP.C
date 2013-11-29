#include <string.h>
#include "zedit.h"

int  lastsrp(
              int  prevsrp,
              char  *lptr)
/**********************************************************************/
/*                                                                    */
/* Obtain last srp value in record for the next script entry of       */
/* bufline.                                                           */
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
register char  *pos;


pos = strrchr(lptr, PRECDR);
if (pos)
    {
    if (*(++pos) >= BUF_ASCII  &&  *pos < BUF_CHGDIR)
        return(*pos);
    } /* end then */
else
    return(prevsrp);

if (*(pos = pos - 3) == PRECDR)
    if (*(++pos) >= BUF_ASCII  &&  *pos < BUF_CHGDIR)
        return(*pos);

return(prevsrp);

} /* end lastsrp */
