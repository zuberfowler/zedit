/* Do NOT rearrange the order of these includes! */
#include "total.h"
#include "nstdi.h"
#include "nstdo.h"
#include "sctxt.h"
#include "stdcl.h"
#include "zedcl.h"
/**********************************************************************/
/*                                                                    */
/* ZEDIT program header.                                              */
/*                                                                    */
/**********************************************************************/
/*                                                                    */
/* This is ZEDIT source material.                                     */
/*                                                                    */
/* ZEDIT Source Materials are intellectual property                   */
/*     (c) Copyright 1987,2001 by Clyde Thomas Zuber.                 */
/*                                                                    */
/**********************************************************************/


/* general values */
/* touch inusage.c, primary.c */
#define  ZEDIT_VERSION  "1.17"
#define  COPYRIGHT      "(c) Copyright 1987,1994"
#define  PSCOMMENT  \
         "%%% ZEDIT (c) Copyright 1987,1994 by Clyde Thomas Zuber %%%\n"
#ifdef S370
#define  PRECDR          0x0007u
#else
#define  PRECDR          0x007Fu
#endif
#define  CMDLEN           160
#define  CMDMAX            39
#define  STACKMAX          39
#define  MAXLREC          258
#define  MSGMAX            44
#define  PRTMAX            62

/* status values */
#define  ST_TEXT        0x01u
#define  ST_SCRL        0x02u
#define  ST_EXCL        0x04u
#define  ST_HELP        0x08u
#define  ST_PROT        0x10u
#define  ST_MULT        0x20u

#define  ST_NORM        0x03u
#define  ST_NORMEXCL    0x07u
#define  ST_PROTSCRL    0x12u
#define  ST_HELPSCRL    0x1Au
#define  ST_BYPS        0x34u /* BYPS is top of exclude, control rec. */
#define  ST_XBLK        0x30u /* XBLK is end of exclude, display line */

/* optback option values */
#define  EDITBACK       0x0001u
#define  PANLBACK       0x0002u
#define  PNEDBACK       0x0003u
#define  SAVEBACK       0x0004u
#define  SVEDBACK       0x0005u

/* xga8514 option values */
#define  FULLSCR       -1
#define  RDSPLIN       -1

/* gflag values */
#define  MSGON          0x0001u

/* OVR (overlay) masks for Hebrew and Latin scripts */
#define  OVR_LFTMASK      0x00F0u
#define  OVR_RHTMASK      0x000Fu

/* OVR (overlay) flags for Hebrew script */
#define  OVR_TERM       0x01u  /* bit position */
#define  OVR_DAGESH     0x02u  /* bit position */
#define  OVR_SHEWA      0x04u  /* bit position */
#define  OVR_RAPHE      0x08u  /* bit position */
#define  OVR_PATHAH     0x10u
#define  OVR_SEGHOL     0x20u
#define  OVR_HIREQ      0x30u
#define  OVR_QIBBUS     0x40u
#define  OVR_QAMES      0x50u
#define  OVR_SERE       0x60u
#define  OVR_HOLEM      0x70u
#define  OVR_KATUPH     0x80u

/* OVR (overlay) flags for Greek script */
#define  OVR_SIGMATERM  0x01u
#define  OVR_IOTASUB    0x02u
#define  OVR_UMLAUT     0x04u
#define  OVR_ACUTE      0x08u
#define  OVR_CIRCUMFLEX 0x10u
#define  OVR_GRAVE      0x20u
#define  OVR_ROUGH      0x40u
#define  OVR_SMOOTH     0x80u

/* OVR (overlay) flags for Latin script */
#define  OVR_UNDERLINE  0x01u
#define  OVR_CEDILLA    0x02u    /* ogonek or double acute */
/* #define  OVR_UMLAUT     0x04u */
/* #define  OVR_ACUTE      0x08u */
/* #define  OVR_CIRCUMFLEX 0x10u */
/* #define  OVR_GRAVE      0x20u */
#define  OVR_TILDE      0x40u
#define  OVR_BREVE      0x80u
/* multiple bit flags */
#define  OVR_SLASH      0x30u  /* stroke */
#define  OVR_DOT        0x50u  /* overdot, middledot, overcircle */

/* OVR (overlay) flags for ascii/romchar script */
/* #define  OVR_UNDERLINE  0x0001 */


/* TRP (trope) flags for Hebrew script [in SRP byte] */
#define  TRP_MAHPAKATUM  0x08u
#define  TRP_SEGHOLTA    0x10u
#define  TRP_GERES       0x18u
#define  TRP_GARSAYIM    0x20u
#define  TRP_SILLUQ      0x28u
#define  TRP_REBIA       0x30u
#define  TRP_ZAQEF       0x38u
#define  TRP_ZAQEFMAG    0x40u
#define  TRP_KEPULA      0x48u
#define  TRP_MEREKA      0x50u
#define  TRP_TIPHA       0x58u
#define  TRP_MUNAH       0x60u
#define  TRP_GALGAL      0x68u
#define  TRP_ILLUJ       0x70u
#define  TRP_TEBIR       0x78u
#define  TRP_DEHI        0x80u
#define  TRP_SALSELET    0x88u
#define  TRP_DARGA       0x90u
#define  TRP_PAZERMAG    0x98u
#define  TRP_PASTA       0xA0u  /* AZLA */
#define  TRP_PAZER       0xA8u
#define  TRP_MAHPAK      0xB0u
#define  TRP_YETIB       0xB8u
#define  TRP_ATNAH       0xC0u
#define  TRP_TELISAPAR   0xC8u
#define  TRP_TELISAMAG   0xD0u
#define  TRP_SINNORIT    0xD8u  /* ZARQA */
/* #define  TRP_XXXXX       0xE0u */
/* #define  TRP_XXXXX       0xE8u */
/* #define  TRP_XXXXX       0xF0u */
/* #define  TRP_XXXXX       0xF8u */

/* cmd routine selectors */
#define  TODOCMD        0xFF00u   /*     0-  255 used negatively */
#define  SCRLCMD        0x0100u   /*   256-  511 */
#define  STCKCMD        0x0200u   /*   512-  767 */
#define  MISCCMD        0x0400u   /*  1024- 1279 */
#define  SRCHCMD        0x0800u   /*  2048- 2303 */
#define  PANLCMD        0x1000u   /*  4096- 4351 */
#define  BACKCMD        0x2000u   /*  8192- 8447 */
#define  PRIMCMD        0x4000u   /* 16384-16639 */
#define  PAN2CMD        0x8000u   /* 32768-33023 */


/* "first level" cmd values  range 0-127 */
#define  FRSTLVL         128u   /* group less than this value */

#define  REVERSE         127u
#define  REGULAR         126u
#define  SPECIAL         125u
#define  GREEK           124u
#define  HEBREW          123u
#define  LATIN           122u

#define  CLRSCR          63u
#define  CLRINPT         62u
#define  NVIDEO          61u
#define  VIDEO           60u
#define  REFRESH         59u
#define  SPLIT           58u    /* internal (split=swap ext) */
#define  SWAP            57u

/* general purpose cmd values  range 128-255 */
#define  NOP             255u
#define  NEXTINPT        254u
#define  ENTER           253u
#define  ERASEEOF        252u

/* scrlcmd cmd values  range 256-511 */
#define  UP              256u
#define  DOWN            257u
#define  LEFT            258u
#define  RIGHT           259u
#define  LOCATE          260u

#define  COLMS           400u    /* command is COLS/COLUMNS */
#define  KEYS            401u
#define  LETS            402u

/* stckcmd cmd values  range 512-767, x'200'-x'2FF' */
#define  SEL_PRIMARY     512u
#define  SEL_BROWPAN     513u
#define  SEL_EDITPAN     514u
#define  SEL_DSENTRY     515u
/*#define  SEL_UNEDPAN     516u*/
/*#define  SEL_NBROPAN     517u*/
#define  SEL_CFGKPAN     518u
#define  SEL_CFGFPAN     519u
#define  SEL_COPYDSN     520u

/* misccmd cmd values  range 1024-1279 */
/* range CURSOR - HELP used in cmddone */
#define  CURSOR          1024u
#define  RTAB            1025u  /* left (ie. reverse tab) */
#define  HELP            1028u
#define  RESET           1100u
#define  PRINT           1102u
#define  DELNX           1105u
#define  DELX            1107u

/* srchcmd cmd values  range 2048-2303 */
#define  FIND            2048u
#define  CHANGE          2049u

/* panlcmd cmd and panel values  range 4096-4351, bit switch defined */
/* care must be taken with high order byte to use these for bit mask */
#define  NOPANEL         0x1000u
#define  PRIMARY         0x1001u
#define  DSENTRY         0x1002u
#define  CFGKPAN         0x1004u
#define  CFGFPAN         0x1008u
#define  HBROPAN         0x1010u
#define  BROWPAN         0x1020u
#define  HEDTPAN         0x1040u
#define  EDITPAN         0x1080u

/* bit masks for panlcmd above and pan2cmd below */
#define  PROCPAN         0x000Eu  /* dsentry, cfgkpan, cfgfpan */
#define  PRDSPAN         0x0003u  /* either primary or dsentry */
#define  BRBRPAN         0x0030u  /* either browse */
#define  EDEDPAN         0x00C0u  /* either edit */
#define  EDBRPAN         0x00F0u  /* all - edit or browse */
#define  HELPPAN         0x0050u  /* either type of help display */
#define  WHCHPAN         0x00FFu  /* turn off cmd grouping */
#define  IMPPROC         0x0003u  /* both imports */
#define  IMEXPRC         0x000Fu  /* either import or export */
#define  COPYPRC         0x0030u  /* both copy phases */

/* pan2cmd cmd and panel values  range 32768-33023 bit switch defined*/
/* care must be taken with high order byte to use these for bit mask */
#define  IGRKPRC         0x8001u
#define  IHEBPRC         0x8002u
#define  EGRKPRC         0x8004u
#define  EHEBPRC         0x8008u
#define  EHHIPRC         0x800Au
#define  COPY            0x8010u
#define  COPYDSN         0x8020u

/* backcmd cmd values  range 8192-8447 */
/* range EXITSYS - CANCEL used in cmddone */
#define  EXITSYS         8192u
#define  END             8193u
#define  RETURN          8194u
#define  CANCEL          8195u
#define  SAVE            8196u
#define  REPLACE         8197u
#define  XXITSYS         8447u

/* primcmd cmd values  range 16384-16639 (x'4000'-x'40FF') */
#define  BROWSE          16384u
#define  EDIT            16385u
/*#define  NBROWSE         16386u*/
/*#define  UNNEDIT         16387u*/
#define  CONFIG          16388u
#define  IMPGRK          16389u
#define  IMPHEB          16390u
#define  EXPGRK          16391u
#define  EXPHEB          16392u
#define  EXPHHI          16393u


/* Hebrew symbol equivalents */
#define  SHEWA               ';'
#define  SHEWA_UP            0x1C
#define  PATHAH              'a'
#define  PATHAH_RT           0x11
#define  SEGHOL              'E'
#define  SEGHOL_RT           0x10
#define  HIREQ               'i'
#define  HIREQ_RT            0x12
#define  QIBBUS              'u'
#define  QIBBUS_RT           0x1F
#define  QAMES               'A'
#define  QAMES_UP            0x1D
#define  QAMES_RT            0x0E
#define  QAMES_KATUPH        'O'
#define  QAMES_KRT           0x0F
#define  SERE                'e'
#define  SERE_RT             0x12
#define  HOLEM               'F'
#define  HOLEM26             0x1E
#define  DAGESH              'f'
#define  DAGESH71            0x15
#define  DAGESH72            0x16
#define  DAGESH74            0x17
#define  DAGESH75            0x18
#define  DAGESH76            0x19
#define  SOPH_PASUQ          ':'
#define  MAQQEPH             '-'
#define  RAPHE               '_'
#define  PASEQ               '|'

/* Hebrew letter equivalents */
#define  ALEPH               '\''
#define  GIMEL               'g'
#define  HE                  'h'
#define  WAW                 'w'
#define  ZAYIN               'z'
#define  HETH                'k'
#define  TETH                'j'
#define  KAPH                'c'
#define  KAPH_TERM           'C'
#define  MEM                 'm'
#define  MEM_TERM            'M'
#define  NUN                 'n'
#define  NUN_TERM            'N'
#define  SAMEKH              'o'
#define  AYIN                'v'
#define  PE                  'p'
#define  PE_TERM             'P'
#define  SADHE               'x'
#define  SADHE_TERM          'X'
#define  QOPH                'q'
#define  RESH                'r'
#define  SIN                 'S'
#define  SHIN                's'
#define  TAW                 't'

/* Hebrew accent equivalents */
#define  MAHPAKATUM          'B'
#define  SEGHOLTA            'D'
#define  GERES               'G'
#define  GARSAYIM            'H'
#define  SILLUQ              'I'
#define  REBIA               'J'
#define  ZAQEF               'K'
#define  ZAQEF_MAG           'L'
#define  KEPULA              'Q'
#define  MEREKA              'R'
#define  TIPHA               'T'
#define  MUNAH               'U'
#define  GALGAL              'V'
#define  ILLUJ               'W'
#define  TEBIR               'Y'
#define  DEHI                'Z'
#define  SALSELET            '#'
#define  DARGA               '$'
#define  PAZER_MAG           '%'
#define  PASTA               '&'  /* AZLA */
#define  PAZER               '+'
#define  MAHPAK              '<'
#define  YETIB               '>'
#define  ATNAH               '^'
#define  TELISA_PAR          '{'
#define  TELISA_MAG          '}'
#define  SINNORIT            '~'  /* ZARQA */

/* Greek letter equivalents */
#define  ALPHA       'a'
#define  EPSILON     'e'
#define  ETA         'g'
#define  IOTA        'i'
#define  OMICRON     'o'
#define  RHO         'r'
#define  SIGMA       's'
#define  SIGMATERM   'v'
#define  UPSILON     'u'
#define  OMEGA       'z'

/* Greek accents, iota subscript, breathing marks, equivalents */
#define  ACUTE       '\''
#define  GRAVE       '"'
#define  CIRCUMFLEX  '^'
#define  IOTASUB     'V'
#define  SMOOTH      'j'
#define  ROUGH       'J'
#define  UMLAUT      '@'


/* Latin named letters */

#define  C_AE           '{'
#define  C_AE_CH        0x10u

#define  S_AE           '['
#define  S_AE_CH        0x11u

#define  C_OE           '}'
#define  C_OE_CH        0x12u

#define  S_OE           ']'
#define  S_OE_CH        0x13u

#define  C_THORN        '|'
#define  C_THORN_CH     0x0Eu

#define  S_THORN        '\\'
#define  S_THORN_CH     0x15u

#define  ETH            '&'
#define  ETH_CH         0x16u


/* Latin diacritics */

/* #define  ACUTE       '\'' */
/* #define  CIRCUMFLEX  '^'  */
#define  LGRAVE         '`'
#define  UNDERLINE      '_'
#define  TILDE          '~'

#define  SLASH          '/'  /* stroke */
#define  SLASH_CH       0x17u

#define  DOT            '%'  /* over and middle dot, over circle */
#define  MIDDOT_CH      0x18u
#define  OVERCIR_CH     0x19u
#define  OVERDOT_CH     0x0Fu

#define  CEDILLA        '$'  /* also double acute */
#define  DOUBLEAC_CH    0x1Cu
#define  CEDILLA_CH     0x1Du

/* #define  UMLAUT      '@'  */
#define  UMLAUT_CH      0x1Eu

#define  BREVE          '#'
#define  BREVE_CH       0x1Fu


/* Message defines, msgno in dispmsg */
#define CFGFGET_MSG1   0
#define CFGKGET_MSG1   1
#define CFGKGET_MSG2   2
#define CHNGPRM_MSG1   3
#define CKPLACE_MSG1   4
#define CMDLINE_MSG1   5
#define EDITPAN_MSG1   6
#define ENTPANL_MSG1   7
#define ENTPANL_MSG2   8
#define ERASEOF_MSG1  ENTPANL_MSG2
#define FINDPRM_MSG1   9
#define FINDPRM_MSG2  10
#define FINDPRM_MSG3  11
#define FINDPRM_MSG4  12
#define INSCHAR_MSG1  13
#define LCINVAL_MSG1  14
#define LNECMD1_MSG1  15
#define LNECMD1_MSG2  16
#define LNECMD2_MSG1  17
#define LNECMD2_MSG2  18
#define LNECMD3_MSG1  LNECMD2_MSG1
#define LNECMD3_MSG2  LNECMD2_MSG2
#define MISCCMD_MSG1  OPTBACK_MSG3
#define MISCCMD_MSG2  19
#define MOVECPY_MSG1  20
#define MOVECPY_MSG2  21
#define MOVEONB_MSG1  22
#define OPTBACK_MSG1  23
#define OPTBACK_MSG2  24
#define OPTBACK_MSG3  25
#define PAN2CMD_MSG1  26
#define PAN2CMD_MSG2  OPTBACK_MSG3
#define PAN2CMD_MSG3  27
#define PANLCMD_MSG1  PAN2CMD_MSG1
#define PANLCMD_MSG2  28
#define PGRKCHR_MSG1  29
#define PGRKCHR_MSG2  30
#define PHEBCHR_MSG1  31
#define PHEBCHR_MSG2  32
#define PHEBCHR_MSG3  33
#define PHEBCHR_MSG4  34
#define PRIMCMD_MSG1  35
#define PROCINP_MSG1  36
#define PROCINP_MSG2  ENTPANL_MSG2
#define SCRLCMD_MSG1  MISCCMD_MSG1
#define SCRLCMD_MSG2  37
#define SCRPRNT_MSG1  38
#define SCRTBUF_MSG1  39
#define SHIFTRT_MSG1  40
#define SRCHCMD_MSG1  MISCCMD_MSG1
#define SRCHCMD_MSG2  OPTBACK_MSG3
#define SRPBUFR_MSG1  41
#define VREPCNT_MSG1  42
#define ZEDMAIN_MSG1  43

