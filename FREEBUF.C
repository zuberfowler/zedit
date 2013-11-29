#include <stdlib.h>
#include "zedit.h"

#ifdef OS2
#define INCL_DOS
#define INCL_SUB
#define INCL_NOPMAPI
#include <os2.h>
#endif

void  freebuf(
              register struct bufline  *ptr)
/**********************************************************************/
/*                                                                    */
/* Free the data set buffer.                                          */
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
#ifdef OS2
extern long  sem_pr;
unsigned char  cc;
#endif


#ifdef OS2
#ifndef DEBUG
/* unlock the screen for possible wait */
VioScrUnLock(0);
DosSemWait(&sem_pr, -1L);
while (VioScrLock(LOCKIO_WAIT, &cc, 0))
    DosSleep(1000L);
#endif
#endif

while(ptr -> next)
    {
    ptr = ptr -> next;
    free(ptr -> prev);
    } /* end while */

free(ptr);

} /* end freebuf */
