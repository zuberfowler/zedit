/**********************************************************************/
/*                                                                    */
/* hdafi program header for 8514/XGA function calls                   */
/* [high definition AF (application function?) interface]             */
/*                                                                    */
/**********************************************************************/
/*                                                                    */
/* This is ZEDIT source material.                                     */
/*                                                                    */
/* ZEDIT Source Materials are intellectual property                   */
/*     (c) Copyright 1987,2001 by Clyde Thomas Zuber.                 */
/*                                                                    */
/**********************************************************************/
#pragma pack(2)

struct  hopen_parm
    {
    unsigned short  len;
             char   flags;
             char   mode;
             char   rc;
    }; /* end struct */

struct  hqdps_parm
    {
    unsigned short  len;
    unsigned short  bufsize;
    unsigned short  stack_used;
    unsigned short  palsize;
    }; /* end struct */

struct  hinit_parm
    {
    unsigned short  len;
    unsigned short  tstate_seg;
    }; /* end struct */

struct  hsmx_parm
    {
    unsigned short  len;
             char   foreground;
             char   background;
    }; /* end struct */

#define MIX_NOC    0x00   /* No change to mix          */
#define MIX_OR     0x01   /* OR                        */
#define MIX_OVER   0x02   /* Overpaint                 */
#define MIX_XOR    0x04   /* Exclusive OR              */
#define MIX_LEAVE  0x05   /* Leave alone               */
#define MIX_ADD    0x08   /* Add color to screen       */
#define MIX_SUB    0x09   /* Screen subtract color     */
#define MIX_MEAN   0x0B   /* Average of screen & color */

struct  hscol_parm
    {
    unsigned short  len;
             long   color;
    }; /* end struct */

#define HD_RED     0x0049L
#define HD_BLUE    0x0092L
#define HD_GREEN   0x0024L
#define HD_WHITE   0x00FFL    /* RED   | GREEN | BLUE */
#define HD_CYAN    0x00B6L    /* GREEN | BLUE         */
#define HD_MAGENT  0x00DBL    /* RED   | BLUE         */
#define HD_YELLOW  0x006DL    /* RED   | GREEN        */

struct  hbbw_parm
    {
    unsigned short  len;
    unsigned short  fmt;
    unsigned short  wid;
    unsigned short  hei;
             short  xcord;
             short  ycord;
             short  lmar;
             short  tmar;
             short  wsub;
             short  hsub;
    }; /* end struct */

struct  hbbchn_parm
    {
    unsigned short     len;
             char S16  sdat;
    unsigned short     ldat;
    }; /* end struct */

struct  hclose_parm
    {
    unsigned short  len;
             char   flags;
    }; /* end struct */

#ifdef IBMCPP
#define  PAFILNK  F16 LINK16 S16
#else
#ifdef IBMC
#define  PAFILNK  S16 F16 LINK16
#else
#define  PAFILNK  LINK16 S16
#endif
#endif

struct afi_entries
    {
    int (PAFILNK  hdient[61])(char S16);
    }; /* end struct */

#ifdef OS2
#ifdef M_I386
#define DosGetProcAddr  Dos16GetProcAddr
typedef  int (PAFILNK _PAFI)(char S16);
typedef  _PAFI S16 PAFI;

extern unsigned short F16 LINK16  DosGetProcAddr(unsigned short,
    char S16, PAFI);
#endif
#endif

extern int  makeafi(void);
extern void  *(LINKMSC  getafi(void));
extern void C16  callafi(int, char S16);

#define HLINE(X)   callafi( 0,(char S16) X)
#define HCLINE(X)  callafi( 1,(char S16) X)
#define HRLINE(X)  callafi( 2,(char S16) X)
#define HCRLINE(X) callafi( 3,(char S16) X)
#define HSCP(X)    callafi( 4,(char S16) X)
#define HBAR()     callafi( 5,(char S16) 0L)
#define HEAR(X)    callafi( 6,(char S16) X)
#define HSCOL(X)   callafi( 7,(char S16) X)
#define HOPEN(X)   callafi( 8,(char S16) X)
#define HSMX(X)    callafi( 9,(char S16) X)
#define HSBCOL(X)  callafi(10,(char S16) X)
#define HSLT(X)    callafi(11,(char S16) X)
#define HSLW(X)    callafi(12,(char S16) X)
#define HEGS()     callafi(13,(char S16) 0L)
#define HSGQ(X)    callafi(14,(char S16) X)
#define HSCMP(X)   callafi(15,(char S16) X)
#define HINT(X)    callafi(16,(char S16) X)
#define HSPATTO(X) callafi(17,(char S16) X)
#define HSPATT(X)  callafi(18,(char S16) X)
#define HLDPAL(X)  callafi(19,(char S16) X)
#define HSHS(X)    callafi(20,(char S16) X)
#define HBBW(X)    callafi(21,(char S16) X)
#define HCBBW(X)   callafi(22,(char S16) X)
#define HBBR(X)    callafi(23,(char S16) X)
#define HBBCHN(X)  callafi(24,(char S16) X)
#define HBBC(X)    callafi(25,(char S16) X)
#define HSCOORD(X) callafi(26,(char S16) X)
#define HQCOORD(X) callafi(27,(char S16) X)
#define HSMODE(X)  callafi(28,(char S16) X)
#define HQMODE(X)  callafi(29,(char S16) X)
#define HQMODES(X) callafi(30,(char S16) X)
#define HQDPS(X)   callafi(31,(char S16) X)
#define HRECT(X)   callafi(32,(char S16) X)
#define HSBP(X)    callafi(33,(char S16) X)
#define HCLOSE(X)  callafi(34,(char S16) X)
#define HESC()     callafi(35,(char S16) 0L)
#define HXLATE(X)  callafi(36,(char S16) X)
#define HSCS(X)    callafi(37,(char S16) X)
#define HCHST(X)   callafi(38,(char S16) X)
#define HCCHST(X)  callafi(39,(char S16) X)
#define ABLKMFI(X) callafi(40,(char S16) X)
#define ABLKCGA(X) callafi(41,(char S16) X)
#define AERASE(X)  callafi(42,(char S16) X)
#define ASCROLL(X) callafi(43,(char S16) X)
#define ACURSOR(X) callafi(44,(char S16) X)
#define ASCUR(X)   callafi(45,(char S16) X)
#define ASFONT(X)  callafi(46,(char S16) X)
#define AXLATE(X)  callafi(47,(char S16) X)
#define HINIT(X)   callafi(48,(char S16) X)
#define HSYNC(X)   callafi(49,(char S16) X)
#define HMRK(X)    callafi(50,(char S16) X)
#define HCMRK(X)   callafi(51,(char S16) X)
#define HSMARK(X)  callafi(52,(char S16) X)
#define HSLPC()    callafi(53,(char S16) 0L)
#define HRLPC()    callafi(54,(char S16) 0L)
#define HQCP(X)    callafi(55,(char S16) X)
#define HQDFPAL(X) callafi(56,(char S16) X)
#define HSPAL(X)   callafi(57,(char S16) X)
#define HRPAL(X)   callafi(58,(char S16) X)
        /* blank entry no. 59 */
#define ASCELL(X)  callafi(60,(char S16) X)

#pragma pack()
