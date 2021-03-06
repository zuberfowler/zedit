#include "zedit.h"

/**********************************************************************/
/*                                                                    */
/* Graphic character codes for screen display.  Greek character set.  */
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

char  grkchar[128] [14] =
/* null  */ {{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*PSundef*/  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/* space */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*     ! */  {0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
              0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00},

/* grave */  {0x08, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*     # */  {0x00, 0x00, 0x48, 0xFC, 0x48, 0x48, 0xFC,
              0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*     $ */  {0x00, 0x10, 0x10, 0x7E, 0x90, 0x90, 0x7C,
              0x12, 0x12, 0xFC, 0x10, 0x10, 0x00, 0x00},

/*     % */  {0x00, 0x40, 0xA0, 0x42, 0x04, 0x08, 0x10,
              0x20, 0x40, 0x84, 0x0A, 0x04, 0x00, 0x00},

/*     & */  {0x00, 0x00, 0x60, 0x90, 0x90, 0x90, 0x60,
              0xA2, 0x94, 0x88, 0x74, 0x02, 0x00, 0x00},

/* acute */  {0x01, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*     ( */  {0x00, 0x00, 0x08, 0x10, 0x20, 0x20, 0x20,
              0x20, 0x20, 0x10, 0x08, 0x00, 0x00, 0x00},

/*     ) */  {0x00, 0x00, 0x20, 0x10, 0x08, 0x08, 0x08,
              0x08, 0x08, 0x10, 0x20, 0x00, 0x00, 0x00},

/*     * */  {0x00, 0x00, 0x10, 0x92, 0x54, 0x28, 0x54,
              0x92, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00},

/*     + */  {0x00, 0x00, 0x00, 0x10, 0x10, 0x10, 0xFE,
              0x10, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00},

/*     , */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x18, 0x18, 0x30, 0x60, 0x00},

/*     - */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7C,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*     . */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00},

/*     / */  {0x00, 0x00, 0x00, 0x02, 0x04, 0x08, 0x10,
              0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00},

/*     0 */  {0x00, 0x38, 0x44, 0x82, 0x82, 0x92, 0x92,
              0x82, 0x82, 0x44, 0x38, 0x00, 0x00, 0x00},

/*     1 */  {0x00, 0x10, 0x30, 0x50, 0x10, 0x10, 0x10,
              0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00},

/*     2 */  {0x00, 0x3C, 0x42, 0x82, 0x02, 0x04, 0x08,
              0x10, 0x20, 0x40, 0xFE, 0x00, 0x00, 0x00},

/*     3 */  {0x00, 0x7E, 0x02, 0x04, 0x08, 0x18, 0x04,
              0x02, 0x02, 0x84, 0x78, 0x00, 0x00, 0x00},

/*     4 */  {0x00, 0x0C, 0x14, 0x24, 0x44, 0x84, 0x84,
              0xFE, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00},

/*     5 */  {0x00, 0xFE, 0x80, 0x80, 0xF8, 0x04, 0x02,
              0x02, 0x02, 0x04, 0xF8, 0x00, 0x00, 0x00},

/*     6 */  {0x00, 0x20, 0x40, 0x80, 0x80, 0xB8, 0xC4,
              0x82, 0x82, 0x44, 0x38, 0x00, 0x00, 0x00},

/*     7 */  {0x00, 0xFE, 0x02, 0x04, 0x08, 0x10, 0x20,
              0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00},

/*     8 */  {0x00, 0x38, 0x44, 0x44, 0x44, 0x38, 0x44,
              0x82, 0x82, 0x44, 0x38, 0x00, 0x00, 0x00},

/*     9 */  {0x00, 0x3C, 0x42, 0x82, 0x86, 0x8A, 0x72,
              0x02, 0x02, 0x02, 0x04, 0x00, 0x00, 0x00},

/* dot-: */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*     ; */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18,
              0x00, 0x00, 0x18, 0x18, 0x30, 0x60, 0x00},

/*     < */  {0x00, 0x00, 0x04, 0x08, 0x10, 0x20, 0x40,
              0x20, 0x10, 0x08, 0x04, 0x00, 0x00, 0x00},

/*     = */  {0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x00,
              0x00, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00},

/*     > */  {0x00, 0x00, 0x40, 0x20, 0x10, 0x08, 0x04,
              0x08, 0x10, 0x20, 0x40, 0x00, 0x00, 0x00},

/*     ? */  {0x00, 0x3C, 0x42, 0x42, 0x04, 0x08, 0x10,
              0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00},

/*umlaut */  {0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/* ALPHA */  {0x00, 0x00, 0x10, 0x28, 0x44, 0x82, 0x82,
              0xFE, 0x82, 0x82, 0x82, 0x00, 0x00, 0x00},

/* BETA  */  {0x00, 0x00, 0xF8, 0x44, 0x42, 0x44, 0x78,
              0x44, 0x42, 0x44, 0xF8, 0x00, 0x00, 0x00},

/* GAMMA */  {0x00, 0x00, 0xFF, 0x80, 0x80, 0x80, 0x80,
              0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00},

/* DELTA */  {0x00, 0x00, 0x10, 0x10, 0x28, 0x28, 0x44,
              0x44, 0x82, 0x82, 0xFE, 0x00, 0x00, 0x00},

/*EPSILON*/  {0x00, 0x00, 0xFE, 0x80, 0x80, 0x80, 0xF8,
              0x80, 0x80, 0x80, 0xFE, 0x00, 0x00, 0x00},

/* ZETA  */  {0x00, 0x00, 0xFE, 0x02, 0x04, 0x08, 0x10,
              0x20, 0x40, 0x80, 0xFE, 0x00, 0x00, 0x00},

/* ETA   */  {0x00, 0x00, 0x82, 0x82, 0x82, 0x82, 0xFE,
              0x82, 0x82, 0x82, 0x82, 0x00, 0x00, 0x00},

/* THETA */  {0x00, 0x00, 0x7C, 0x82, 0x82, 0xAA, 0xBA,
              0xAA, 0x82, 0x82, 0x7C, 0x00, 0x00, 0x00},

/* IOTA  */  {0x00, 0x00, 0x38, 0x10, 0x10, 0x10, 0x10,
              0x10, 0x10, 0x10, 0x38, 0x00, 0x00, 0x00},

/* rough */  {0x00, 0x00, 0x30, 0x40, 0x40, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/* KAPPA */  {0x00, 0x00, 0x82, 0x84, 0x88, 0x90, 0xA0,
              0xD0, 0x88, 0x84, 0x82, 0x00, 0x00, 0x00},

/* LAMBDA*/  {0x00, 0x00, 0x10, 0x10, 0x28, 0x28, 0x44,
              0x44, 0x82, 0x82, 0x82, 0x00, 0x00, 0x00},

/* MU    */  {0x00, 0x00, 0x82, 0xC6, 0xAA, 0x92, 0x92,
              0x82, 0x82, 0x82, 0x82, 0x00, 0x00, 0x00},

/* NU    */  {0x00, 0x00, 0x82, 0xC2, 0xA2, 0x92, 0x8A,
              0x86, 0x82, 0x82, 0x82, 0x00, 0x00, 0x00},

/*OMICRON*/  {0x00, 0x00, 0x7C, 0x82, 0x82, 0x82, 0x82,
              0x82, 0x82, 0x82, 0x7C, 0x00, 0x00, 0x00},

/* PI    */  {0x00, 0x00, 0xFE, 0x44, 0x44, 0x44, 0x44,
              0x44, 0x44, 0x44, 0x44, 0x00, 0x00, 0x00},

/* XI    */  {0x00, 0x00, 0xFE, 0x00, 0x00, 0x00, 0x7C,
              0x00, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x00},

/* RHO   */  {0x00, 0x00, 0xF8, 0x84, 0x82, 0x82, 0x84,
              0xF8, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00},

/* SIGMA */  {0x00, 0x00, 0xFE, 0x80, 0x40, 0x20, 0x10,
              0x20, 0x40, 0x80, 0xFE, 0x00, 0x00, 0x00},

/* TAU   */  {0x00, 0x00, 0xFE, 0x10, 0x10, 0x10, 0x10,
              0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00},

/*UPSILON*/  {0x00, 0x00, 0x82, 0x44, 0x28, 0x10, 0x10,
              0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00},

/*iotasub*/  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x08},

/* PHI   */  {0x00, 0x00, 0x38, 0x10, 0x7C, 0x92, 0x92,
              0x92, 0x7C, 0x10, 0x38, 0x00, 0x00, 0x00},

/* CHI   */  {0x00, 0x00, 0x82, 0x82, 0x44, 0x28, 0x10,
              0x28, 0x44, 0x82, 0x82, 0x00, 0x00, 0x00},

/* PSI   */  {0x00, 0x00, 0x38, 0x10, 0x92, 0x92, 0x92,
              0x92, 0x7C, 0x10, 0x38, 0x00, 0x00, 0x00},

/* OMEGA */  {0x00, 0x00, 0x38, 0x44, 0x82, 0x82, 0x82,
              0x44, 0x28, 0x28, 0xC6, 0x00, 0x00, 0x00},

/*     [ */  {0x00, 0x00, 0x38, 0x20, 0x20, 0x20, 0x20,
              0x20, 0x20, 0x20, 0x38, 0x00, 0x00, 0x00},

/*     \ */  {0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10,
              0x08, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00},

/*     ] */  {0x00, 0x00, 0x38, 0x08, 0x08, 0x08, 0x08,
              0x08, 0x08, 0x08, 0x38, 0x00, 0x00, 0x00},

/*circum-*/  {0x78, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00,
/* flex  */   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*     _ */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0xFE, 0x00, 0x00},

/*     " */  {0x00, 0x48, 0x48, 0x48, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/* alpha */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x4A,
              0x84, 0x84, 0x4A, 0x31, 0x00, 0x00, 0x00},

/* beta  */  {0x00, 0x1C, 0x22, 0x42, 0x42, 0x84, 0xB8,
              0x84, 0x82, 0x82, 0xBC, 0x80, 0x80, 0x80},

/* gamma */  {0x00, 0x00, 0x00, 0x00, 0x00, 0xC2, 0x22,
              0x24, 0x14, 0x18, 0x10, 0x30, 0x60, 0x80},

/* delta */  {0x00, 0x3C, 0x42, 0x40, 0x30, 0x08, 0x7C,
              0x84, 0x84, 0x84, 0x7C, 0x00, 0x00, 0x00},

/*epsilon*/  {0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x40,
              0x78, 0x40, 0x40, 0x3C, 0x00, 0x00, 0x00},

/* zeta  */  {0x04, 0x0A, 0x3C, 0x08, 0x10, 0x10, 0x20,
              0x20, 0x40, 0x40, 0x7C, 0x04, 0x18, 0x00},

/* eta   */  {0x00, 0x00, 0x00, 0x00, 0x00, 0xBC, 0x44,
              0x44, 0x44, 0x44, 0x44, 0x04, 0x04, 0x00},

/* theta */  {0x00, 0x1C, 0x22, 0x42, 0x82, 0xFE, 0x82,
              0x82, 0x84, 0x88, 0x70, 0x00, 0x00, 0x00},

/* iota  */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10,
              0x10, 0x10, 0x10, 0x08, 0x00, 0x00, 0x00},

/* smooth*/  {0x00, 0x00, 0x30, 0x08, 0x08, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/* kappa */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x50,
              0x60, 0x50, 0x48, 0x44, 0x00, 0x00, 0x00},

/* lambda*/  {0x00, 0xC0, 0x20, 0x20, 0x10, 0x10, 0x18,
              0x28, 0x24, 0x44, 0x43, 0x00, 0x00, 0x00},

/* mu    */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x44,
              0x44, 0x44, 0x44, 0xBA, 0x80, 0x80, 0x00},

/* nu    */  {0x00, 0x00, 0x00, 0x00, 0x00, 0xC2, 0x42,
              0x44, 0x48, 0x50, 0x20, 0x00, 0x00, 0x00},

/*omicron*/  {0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x44,
              0x82, 0x82, 0x44, 0x38, 0x00, 0x00, 0x00},

/* pi    */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xA4,
              0x24, 0x24, 0x24, 0x24, 0x00, 0x00, 0x00},

/* xi    */  {0x18, 0x10, 0x1E, 0x20, 0x20, 0x20, 0x3C,
              0x40, 0x40, 0x40, 0x7C, 0x04, 0x18, 0x00},

/* rho   */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x11,
              0x21, 0x21, 0x22, 0x5C, 0x40, 0x80, 0x80},

/* sigma */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x7E, 0x88,
              0x84, 0x84, 0x48, 0x30, 0x00, 0x00, 0x00},

/* tau   */  {0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0x10,
              0x10, 0x10, 0x10, 0x10, 0x00, 0x00, 0x00},

/*upsilon*/  {0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x44,
              0x44, 0x44, 0x44, 0x38, 0x00, 0x00, 0x00},

/*sigmatr*/  {0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x84,
              0x80, 0x70, 0x08, 0x04, 0x38, 0x00, 0x00},

/* phi   */  {0x00, 0x00, 0x00, 0x08, 0x08, 0x3C, 0x4A,
              0x89, 0x91, 0x52, 0x3C, 0x10, 0x10, 0x00},

/* chi   */  {0x00, 0x00, 0x00, 0x00, 0x00, 0xC4, 0x24,
              0x28, 0x18, 0x10, 0x28, 0x24, 0x46, 0x00},

/* psi   */  {0x00, 0x00, 0x00, 0x10, 0x10, 0x92, 0x92,
              0x92, 0x92, 0x94, 0x78, 0x10, 0x10, 0x00},

/* omega */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x44, 0x82,
              0x92, 0x92, 0x92, 0x6C, 0x00, 0x00, 0x00},

/*     { */  {0x00, 0x18, 0x20, 0x20, 0x20, 0x20, 0x40,
              0x20, 0x20, 0x20, 0x20, 0x18, 0x00, 0x00},

/*     | */  {0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
              0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00},

/*     } */  {0x00, 0x60, 0x10, 0x10, 0x10, 0x10, 0x08,
              0x10, 0x10, 0x10, 0x10, 0x60, 0x00, 0x00},

/*     ~ */  {0x00, 0x60, 0x92, 0x0C, 0x00, 0x00, 0x00,
              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},

/*       */  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
              0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
