#include "zedit.h"

void  editpan(
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
/* Edit panel definition.                                             */
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

static int  rowcol[4] [5] =
   {{1, 13, 60,  1, RC_ENTRY},
    {1, 75, 79,  1, RC_ENTRY},
    {2,  0,  6, 23, RC_NORMAL},
    {2,  8, 79, 23, RC_NORMAL}};

static int  rowcol_cga[4] [5] =
   {{1, 13, 60,  1, RC_ENTRY},
    {1, 75, 79,  1, RC_ENTRY},
    {2,  0,  6, 13, RC_NORMAL},
    {2,  8, 79, 13, RC_NORMAL}};


/* pass field assignments to other routines */
*nfield = 3;
if (graphic & CGA)
    {
    if (graphic & RMAR)
        rowcol_cga[*nfield] [RIGHT_MAR] =
            (rightmar > 72) ? 79 : (rightmar + 7);
    *rowcol_ptr = (int *) rowcol_cga;
    } /* end then */
else
    {
    if (graphic & RMAR)
        rowcol[*nfield] [RIGHT_MAR] =
            (rightmar > 72) ? 79 : (rightmar + 7);
    *rowcol_ptr = (int *) rowcol;
    } /* end else */

edbrpan(posptr, inptext, dsn, YES);

*line_no = rowcol[2] [TOP_MAR];
*col_no = rowcol[2] [LEFT_MAR];

dispmsg(posptr, EDITPAN_MSG1);

} /* end editpan */
