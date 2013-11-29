#include "zedit.h"

/**********************************************************************/
/*                                                                    */
/* Command names for commands that may be assigned to PFkeys.         */
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

char  cmdtxts[CMDMAX] [6] = {
    {"Brows"}, {"Cance"}, {"Chang"}, {"Cols "}, {"Confi"}, {"Copy "},
    {"Curso"}, {"Down "}, {"Edit "}, {"End  "}, {"Erase"}, {"Exits"},
    {"Expgr"}, {"Exphe"}, {"Exphh"}, {"Find "}, {"Greek"}, {"Hebre"},
    {"Help "}, {"Impgr"}, {"Imphe"}, {"Keys "}, {"Latin"}, {"Left "},
    {"Lette"}, {"Locat"}, {"Print"}, {"Refre"}, {"Regul"}, {"Repla"},
    {"Reset"}, {"Retur"}, {"Rever"}, {"Right"}, {"Rtab "}, {"Save "},
    {"Speci"}, {"Swap "}, {"Up   "}};
