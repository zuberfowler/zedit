#include "zedit.h"

/**********************************************************************/
/*                                                                    */
/* Command values that may be assigned to PFkeys.                     */
/*                                                                    */
/**********************************************************************/
/*                                                                    */
/* This is ZEDIT source material.                                     */
/*                                                                    */
/* ZEDIT Source Materials are intellectual property                   */
/*     (c) Copyright 1987,2001 by Clyde Thomas Zuber.                 */
/*                                                                    */
/**********************************************************************/

#ifdef DATASEG
#pragma data_seg(ZEDRODAT)
#endif

unsigned int  cmdvals[CMDMAX] = {
    BROWSE,   CANCEL,   CHANGE,   COLMS,    CONFIG,   COPY,
    CURSOR,   DOWN,     EDIT,     END,      ERASEEOF, EXITSYS,
    EXPGRK,   EXPHEB,   EXPHHI,   FIND,     GREEK,    HEBREW,
    HELP,     IMPGRK,   IMPHEB,   KEYS,     LATIN,    LEFT,
    LETS,     LOCATE,   PRINT,    REFRESH,  REGULAR,  REPLACE,
    RESET,    RETURN,   REVERSE,  RIGHT,    RTAB,     SAVE,
    SPECIAL,  SWAP,     UP};

