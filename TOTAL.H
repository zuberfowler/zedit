/**********************************************************************/
/*                                                                    */
/* total program header (common definitions to most programs).        */
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
/*                                                                    */
/* VMS and MSDOS are predefined by their particular compilers.        */
/* OS2, VMS, S370, and DOS are used for compile portability.          */
/*                                                                    */
/**********************************************************************/
#ifndef OS2
#ifdef __OS2__
#define OS2
#endif
#endif

#ifdef __IBMC__
#ifndef IBMC
#define IBMC
#endif
#ifndef  NULL
#define  NULL  ((void *) 0)
#endif
#endif

#ifdef __IBMCPP__
#ifndef IBMC
#define IBMC
#endif
#define IBMCPP
#ifndef  NULL
#define  NULL  0
#endif
#endif

#ifdef IBMC
#define  DATASEG
#define  PTRINIT
#define  M_I386
#define  C16      _Far16 _Cdecl
#define  F16      _Far16
#define  S16      *_Seg16
#define  LINK16   _Pascal
#define  LINKAGE  _System
#define  LINKMSC
#define  EXPPTR(sel, off)  ((void *)((((sel)&0xfff8u)<<13u)|(off)))
#if __IBMC__ >= 200
#define  CTOOLS
#define  INLINE   _Inline
#else
#define  itoa     _itoa
#endif

#else

#ifdef __WATCOMC__
#define  WATCOMC
#define  PTRINIT
#define  C16      __far16 __cdecl
#define  F16      __far16
#define  S16      *_Seg16
#define  LINK16   __pascal
#define  LINKAGE  __syscall
#define  LINKMSC
#define  PTRCONV
#define  EXPPTR(sel, off)  ((void *)((((sel)&0xfff8u)<<13u)|(off)))
#define  HISECT(p) (((unsigned short *)&(p))[1])
#define  LOSECT(p) (((unsigned short *)&(p))[0])
#ifndef  NULL
#define  NULL  ((void *) 0)
#endif

#else

#ifdef GNU
#ifndef  NULL
#define  NULL  ((void *) 0)
#endif
#define  EXDCL
#define  M_I386
#define  C16      _Far16 _Cdecl
#define  F16      _Far16
#define  S16      *_Seg16
#define  LINK16   _Pascal
#define  LINKAGE  _System
#define  LINKMSC
#define  EXPPTR(sel, off)  ((void *)((((sel)&0xfff8u)<<13u)|(off)))

#else

#ifdef AIX
#define  C16
#define  F16
#define  S16
#define  LINK16
#define  LINKAGE
#define  LINKMSC

#else

#ifndef S370
#ifndef VMS
#ifdef MSDOS
#ifndef  NULL
#define  NULL  ((void *) 0)
#endif
#ifdef M_I386
#define  MSC386
#define  C16      _cdecl
#define  F16      _far16
#define  S16      _far16*
#define  LINK16   _pascal
#define  LINKAGE  _syscall
#define  LINKMSC
#define  PTRCONV
#define  EXPPTR(sel, off)  ((void *)((((sel)&0xfff8u)<<13u)|(off)))
#define  HISECT(p) (((unsigned short *)&(p))[1])
#define  LOSECT(p) (((unsigned short *)&(p))[0])
#else
#define  MSC
#define  C16      cdecl
#define  F16      far
#define  S16      far*
#define  LINK16   pascal
#define  LINKAGE  cdecl
#define  LINKMSC  cdecl
#ifdef OS2
#define  EXPPTR   MAKEP
#else
#define  DOS
#endif
#endif
#else
#ifdef __MSDOS__
#define  TC
#define  DOS
#else
#define  C86
#define  DOS
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif

#define SELPTR(p) \
  ((unsigned short) (((unsigned long)((void S16)(p)) >> 16u) & 0xFFFF))
#define OFFPTR(p) \
  ((unsigned short) ((unsigned long)((void S16)(p))))

#ifdef _FILE_DEFINED
#define STDIO
#else

#ifdef __stdio_h
#define STDIO
#else

#ifdef _STDIO_H_
#define STDIO
#else

#ifdef _STDIO_H_INCLUDED
#define STDIO
#endif

#endif
#endif
#endif


#ifdef VMS
#define  PUNCSTRT '['
#define  PUNCMID  '.'
#define  PUNCTERM ']'
#else
#ifdef S370
#define  PUNCSTRT '\''
#define  PUNCMID  '.'
#define  PUNCTERM '\''
#else
#define  PUNCSTRT '\\'
#define  PUNCMID  '\\'
#define  PUNCTERM '\\'
#endif
#endif

/* general byte values */
#ifndef  INLINE
#define  INLINE
#endif

#ifdef S370
#define  BELL           0x002F
#else
#define  BELL           0x0007
#endif

#define  EMPTY          0x0000u
#define  YES            0x0011u
#define  YESMAYBE       0x0010u
#define  NOMAYBE        0x0001u
#define  NO             0x0000u
/*       YESXGA         0x0051u  YES | XGA - display parm in nstdo.h */
#define  BLANK          ' '

/* i/o values for standard functions */
#ifndef  SEEK_SET
#define  SEEK_SET      0
#endif
#ifndef  SEEK_CUR
#define  SEEK_CUR      1
#endif
#ifndef  SEEK_END
#define  SEEK_END      2
#endif
#define  OLD_INPUT     "r"
#define  NEW_OUTPUT    "w"
#define  MOD_OUTPUT    "a"
#define  OLD_INBIN     "rb"
#define  NEW_OUTBIN    "wb"
#define  MOD_OUTBIN    "ab"
#define  OLD_INOUT     "r+"
#define  NEW_INOUT     "w+"
#define  MOD_INOUT     "a+"
#define  OLD_IOBIN     "rb+"
#define  NEW_IOBIN     "wb+"
#define  MOD_IOBIN     "ab+"

/* pindex type (first parameter) values */
#define  PINIT  0x0001u
#define  PFIND  0x0002u
#define  PTERM  0x0004u
#define  PONCE  0x0007u

#ifdef  EXDCL
#include "exdcl.h"
#endif
