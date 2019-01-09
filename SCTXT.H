/**********************************************************************/
/*                                                                    */
/* sctxt program header (for use with rowcol, scrtext format buffer)  */
/*                                                                    */
/**********************************************************************/
/*                                                                    */
/* This is ZEDIT source material.                                     */
/*                                                                    */
/* ZEDIT Source Materials are intellectual property                   */
/*     (c) Copyright 1987,2001 by Clyde Thomas Zuber.                 */
/*                                                                    */
/**********************************************************************/

/**********************************************************************/
/* rowcol definition and use                                          */
/**********************************************************************/

/* rowcol second subscript values */
#define  TOP_MAR      0
#define  LEFT_MAR     1
#define  RIGHT_MAR    2
#define  BOTTOM_MAR   3
#define  ATTRIB       4

/* attribute values */
#define  RC_ENTRY     0
/* #define  RC_REVENTRY  1 */
#define  RC_NORMAL    2
#define  RC_CHANGED   3
/* #define  RC_REVERSE   4 */
/* #define  RC_CHGREV    5 */
#define  RC_PROTECT   8
/* #define  RC_REVPROT   9 */

/**********************************************************************/
/* scrtext definition and use, SRP and OVR are optional               */
/**********************************************************************/

/* subscript values for scrtext [attribute/text/script/overlay] */
/* ATR is minimum and OVR is maximum range */
#define  ATR  0
#define  TXT  1
#define  SRP  2
#define  OVR  3


/* ATR (attribute) flags for charsets */
#define  ATR_MASK     0x07u
#define  ATR_HILIGHT  0x01u  /* bit position */
#define  ATR_REVERSE  0x02u  /* bit position */
#define  ATR_PROTECT  0x04u  /* bit position */
#define  ATR_HREVERS  0x03u
#define  ATR_HPROTEC  0x05u
#define  ATR_REVPROT  0x06u
#define  ATR_HREVPRO  0x07u

/* SRP (script) flags for charsets */
#define  TRP_MASK     0xF8u
#define  SRP_MASK     0x07u
#define  SRP_INIT     0x00u
#define  SRP_ASCII    0x01u
#define  SRP_ROMCHAR  0x02u
#define  SRP_GREEK    0x03u
#define  SRP_HEBREW   0x04u
#define  SRP_LATIN    0x05u
#define  SRP_UNUSED   0x06u
#define  SRP_CHGDIR   0x07u

#define  BUF_SRPMASK  0xC7
#define  BUF_ASCII    'A'       /* 0x41 or 0xC1 */
#define  BUF_ROMCHAR  'B'       /* 0x42 or 0xC2 */
#define  BUF_GREEK    'C'       /* 0x43 or 0xC3 */
#define  BUF_HEBREW   'D'       /* 0x44 or 0xC4 */
#define  BUF_LATIN    'E'       /* 0x45 or 0xC5 */
#define  BUF_UNUSED   'F'       /* 0x46 or 0xC6 */
#define  BUF_CHGDIR   'G'       /* 0x47 or 0xC7 */

