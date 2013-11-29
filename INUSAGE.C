#include <stdio.h>
#include <stdlib.h>
#include "zedit.h"

void  inusage(void)
/**********************************************************************/
/*                                                                    */
/* Display usage information to standard out.                         */
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
int  dummy;


printf("\nZedit V%s %s by Clyde Thomas Zuber\n",
    ZEDIT_VERSION, COPYRIGHT);
printf("Invalid command line selection, edit and print usage:\n");
printf("  zedit /i /p\n\n");
printf("    b  - use /r= value for both screen and print\n");
printf("*   c  - 320 X 200 CGA graphic\n");
#ifdef VMS
printf("                   VT240 Regis graphic\n");
#endif
printf("*   e  - 640 X 350 EGA/VGA standard graphic\n");
#ifdef DOS
printf("*   h  - 720 X 348 Hercules graphic\n");
#endif
printf("*   i  - 720 X 350 IBM VGA non-standard graphic\n");
printf("*   i+ - 720 X 480 IBM VGA non-standard graphic\n");
#ifdef DOS
printf("    k  - allow DOS to use F11 and F12 keys\n");
#endif
printf("*   m  - 640 X 480 IBM MCGA standard graphic\n");
printf("*   t  - text mode, non-graphic\n");
printf("*   v  - 640 X 480 IBM VGA hi-res standard graphic\n");
printf("    w  - white display\n");
printf("*   x  - 1024 X 768 XGA/8514 super-res standard graphic\n");
printf("    z  - menu bypass, direct input file selection\n\n");
printf("* One of the above display options must be selected,\n");
printf("    or the /z option to print without editing.\n\n");
printf("Press a key, print options follow...\n");

/* wait for any input */
getinpt(&dummy, &dummy, (unsigned int *) &dummy, NO);

printf("Usage to print only (no display option):\n");
printf("  zedit /z=indsn /o=outdsn /g /l=maxlrecl /r=rmar\n");
printf("    a  - use alternate printer control codes\n");
printf("    g  - PPDS/ASCII dual density graphic,  9 X 14 chars\n");
printf("    g+ - PPDS/ASCII dual density graphic,  9 X 19 chars\n");
printf("    gx - PPDS/ASCII dual density graphic, 12 X 30 chars\n");
printf("    n  - Proprinter NLQ mode on print command\n");
printf("    p  - Proprinter mode on print command\n");
printf("    s  - PostScript mode on print command\n");
printf("    1  - use only one buffer for font download\n");
printf("    2  - change PPDS/ASCII to single density graphic\n");
printf("    3  - high density print stream on PPDS/ASCII graphic\n");
printf("    l=lrecl  - maximum logical record length\n");
printf("    o=outdsn - output is put in this data set\n");
printf("    r=rmar   - right print margin for Hebrew\n\n");
printf("Default output is to the printer (/o=prn).\n");
printf("Default control codes are for Epson FX printer.\n");
printf("Default maximum lrecl is 258 (or panel specification).\n");
printf("Default Hebrew right margin is 72 (or 80 in browse).\n");

} /* end inusage */
