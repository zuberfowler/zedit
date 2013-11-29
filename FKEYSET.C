#include "zedit.h"

/**********************************************************************/
/*                                                                    */
/* Function key values with defaults predefined.                      */
/*                                                                    */
/**********************************************************************/
/*                                                                    */
/* This is ZEDIT source material.                                     */
/*                                                                    */
/* ZEDIT Source Materials are intellectual property                   */
/*     (c) Copyright 1987,2001 by Clyde Thomas Zuber.                 */
/*                                                                    */
/**********************************************************************/

/* function key values */
unsigned int  fkeyset[4] [12] =
    /* no shift */ {{REFRESH, SWAP, END, EXITSYS, REGULAR, GREEK,
                     HEBREW, REVERSE, LATIN, LEFT, RIGHT, SPECIAL},
    /* ispf/pdf */
    /* shift up */  {HELP, SWAP, END, PRINT, FIND, CHANGE,
                     UP, DOWN, SWAP, LEFT, RIGHT, CURSOR},

    /* cntl key */  {HELP, SWAP, ERASEEOF, RETURN, FIND, CHANGE,
                     RESET, CANCEL, LEFT, RIGHT, SAVE, EXITSYS},

    /* alt key  */  {HELP, SWAP, END, RETURN, REGULAR, GREEK,
                     HEBREW, REVERSE, LATIN, SPECIAL, LEFT, RIGHT}};
