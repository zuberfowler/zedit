#include "zedit.h"

int  letsheb(
              int  i,  /* main index */
              int  e,  /* extra char count, return value */
              int  d,  /* displacement */
              char  bline[])
/**********************************************************************/
/*                                                                    */
/* Insert required extra primary letter before an overlay letter.     */
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
extern char  hebexch[256];


switch(hebexch[i])
    {
    case KAPH_TERM:
        bline[i+e+d] = KAPH;
        ++e;
        break;
    case MEM_TERM:
        bline[i+e+d] = MEM;
        ++e;
        break;
    case NUN_TERM:
        bline[i+e+d] = NUN;
        ++e;
        break;
    case PE_TERM:
        bline[i+e+d] = PE;
        ++e;
        break;
    case SADHE_TERM:
        bline[i+e+d] = SADHE;
        ++e;
        break;
    case DAGESH:
    case HIREQ:
    case HOLEM:
    case PATHAH:
    case QAMES:
    case QIBBUS:
    case SEGHOL:
    case SERE:
    case SHEWA:
        bline[i+e+d] = BLANK;
        ++e;
        break;
    } /* end switch */

bline[i+e+d] = hebexch[i];

return(e);
} /* end letsheb */
