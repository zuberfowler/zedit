#include <stdio.h>
#include <stdlib.h>
#include "zedit.h"

#ifdef OS2
#define INCL_DOS
#define INCL_NOPMAPI
#include <os2.h>
#endif

void  zfinish(
              union both_scr  *posptr,
              enum fintype  code)
/**********************************************************************/
/*                                                                    */
/* Exit point for severe error situations.  The bell is rung for the  */
/* count of code in case terminal is in a graphics mode that will     */
/* prevent the message being in readable form.                        */
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
register int  ring;


for (ring = 0; ring < code; ++ring)
#ifdef OS2
    DosBeep(100, 250);
#else
    printf("%c", BELL);
#endif

switch(code)
    {
    case general_fail:
        printf("ERROR - abnormal program termination.\n");
        printf("    error code = %d\n", code);
        break;
    case open_in:
        printf("ERROR - open failed on input data set.\n");
        printf("    error code = %d\n", code);
        break;
    case open_out:
        zepilog(posptr, code);
        printf("ERROR - open failed on output data set.\n");
        printf("    error code = %d\n", code);
        break;
    case video_fail:
        printf("ERROR - unable to establish selected video mode.\n");
        printf("    error code = %d\n", code);
        break;
    case no_storage:
        zepilog(posptr, code);
        printf("ERROR - unable to obtain additional storage.\n");
        printf("    error code = %d\n", code);
        break;
    } /* end switch */

exit(code);

} /* end zfinish */
