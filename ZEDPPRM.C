#include "zedit.h"

void LINKAGE  zedpprm(
              unsigned long  parm)
/**********************************************************************/
/*                                                                    */
/* OS/2 Version 2 Only.                                               */
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
register struct parameter  *p;


p = (struct parameter  *) parm;

zedpbuf(p -> posptr, (long) p -> maxlrecl, p -> ptr,
    (long) p -> rightmar);

} /* end zedpprm */
