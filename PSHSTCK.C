#include "zedit.h"

void  pshstck(
              unsigned int  cmd[],
              unsigned int  addition)
/**********************************************************************/
/*                                                                    */
/* Add a command to the cmd stack, skipping the zero (current)        */
/* location.                                                          */
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
register int  c;


for (c = STACKMAX - 1; c > 1; --c)
    cmd[c] = cmd[c - 1];
cmd[1] = addition;

} /* end pshstck */
