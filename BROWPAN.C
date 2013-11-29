#include "zedit.h"

void  browpan(
              union both_scr  *posptr,
              int  *line_no,
              int  *col_no,
              int  *nfield,
              int  **rowcol_ptr,
              char  inptext[] [25] [80],
              char  dsn[56],
              int  rightmar)
/**********************************************************************/
/*                                                                    */
/* Browse panel definition.                                           */
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
extern unsigned int  graphic;

static int  rowcol[3] [5] =
   {{1, 13, 60,  1, RC_ENTRY},
    {1, 75, 79,  1, RC_ENTRY},
    {2,  0, 79, 23, RC_PROTECT}};

static int  rowcol_cga[3] [5] =
   {{1, 13, 60,  1, RC_ENTRY},
    {1, 75, 79,  1, RC_ENTRY},
    {2,  0, 79, 13, RC_PROTECT}};


/* pass field assignments to other routines */
*nfield = 2;
if (graphic & CGA)
    {
    if (graphic & RMAR)
        rowcol_cga[*nfield] [RIGHT_MAR] =
            (rightmar > 79) ? 79 : (rightmar - 1);
    *rowcol_ptr = (int *) rowcol_cga;
    } /* end then */
else
    {
    if (graphic & RMAR)
        rowcol[*nfield] [RIGHT_MAR] =
            (rightmar > 79) ? 79 : (rightmar - 1);
    *rowcol_ptr = (int *) rowcol;
    } /* end else */

edbrpan(posptr, inptext, dsn, NO);

*line_no = rowcol[0] [TOP_MAR];
*col_no = rowcol[0] [LEFT_MAR];

} /* end browpan */
