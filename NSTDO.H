/**********************************************************************/
/*                                                                    */
/* nstdo program header (non-standard output).                        */
/* graph program header (for use with graphic type terminals).        */
/* This header depends on compiler values determined in total.h.      */
/*                                                                    */
/**********************************************************************/
/*                                                                    */
/* This is ZEDIT source material.                                     */
/*                                                                    */
/* ZEDIT Source Materials are intellectual property                   */
/*     (c) Copyright 1987,2001 by Clyde Thomas Zuber.                 */
/*                                                                    */
/**********************************************************************/

#ifdef MSC
#define prtcntl  outp
#define prtinpt  inp
#endif

#ifdef TC
#define prtcntl  outport
#define prtinpt  inport
#endif

#ifdef C86
#define prtcntl  outportw
#define prtinpt  inportw
#endif

/* screen regs, values */
#define  ADDR_REG   0x03B4
#define  DATA_REG   0x03B5
#define  DISP_MODE  0x03B8
#define  TEXT0_NVIDEO     0x0020
#define  TEXT0_VIDEO      0x0028
#define  GRAPH0_NVIDEO  0x0022
#define  GRAPH0_VIDEO   0x002A
#define  TEXT1_NVIDEO     0x00A0
#define  TEXT1_VIDEO      0x00A8
#define  GRAPH1_NVIDEO  0x00A2
#define  GRAPH1_VIDEO   0x00AA

/* attribute byte screen values for monochrome display */
#define  M_UNDER    0x0001u  /* low,  norm,        under */
#define  M_NORM     0x0007u  /* low,  norm,              */
#define  M_REV      0x0070u  /* low,  rev,               */
#define  M_HUND     0x0009u  /* high, norm,        under */
#define  M_HIGH     0x000Fu  /* high, norm,              */
#define  M_HREV     0x0078u  /* high, rev,               */
#define  M_BUNDER   0x0081u  /* low,  norm, blink, under */
#define  M_BNORM    0x0087u  /* low,  norm, blink        */
#define  M_BREV     0x00F0u  /* low,  rev,  blink        */
#define  M_BHUND    0x0089u  /* high, norm, blink, under */
#define  M_BHIGH    0x008Fu  /* high, norm, blink        */
#define  M_BHREV    0x00F8u  /* high, rev,  blink        */

/* attribute byte screen masks for monochrome display */
#define  M_INTENSE  0x0008u
#define  M_BLINK    0x0080u


/*****************/
/* graphic flags */
/*****************/
/* masks */
#define ADISPL 0x017Fu  /* any display mode mask */
#define DISPL  0x007Fu  /* graphic display mode mask */
#define NOT_H  0x007Du  /* ie. CGA, EGA or IBM, not Hercules mask */
#define IBM    0x0030u  /* custom display mask */
#define ONESCR 0x0069u  /* ie. CGA, VGA, IBM2, or XGA */
#define TWOSCR 0x0016u  /* ie. HMONO, EGA or IBM1 */
#define HIRES  0x0028u  /* ie. VGA or IBM2 */
#define LORES  0x0014u  /* ie. EGA or IBM1 */
#define YESXGA 0x0051u  /* YES | XGA - in display parameter */

/* bit definitions */
#define CGA    0x0001u  /* CGA display mode */
#define HMONO  0x0002u  /* Hercules display mode */
#define EGA    0x0004u  /* EGA display mode */
#define VGA    0x0008u  /* VGA/MCGA display mode */
#define IBM1   0x0010u  /* custom display mode 1 */
#define IBM2   0x0020u  /* custom display mode 2 */
#define XGA    0x0040u  /* XGA/8514 display mode */
#define UCOLOR 0x0080u  /* set default color (also, not MCGA) */
#define TEXT   0x0100u  /* text mode */
#define RMAR   0x0200u  /* use rightmar on edit and browse displays */
#define F11F12 0x2000u  /* enhanced keyboard available (also nstdi.h) */
#define FXGA   0x8000u  /* fake XGA/8514 selection (use HDILIKE) */


/*****************/
/* prtmode flags */
/*****************/
/* masks */
#define PRNTR  0x000Fu  /* print mode mask */
#define NOTPRO 0x0009u  /* not a Proprinter char download mode */

/* bit definitions */
#define PSCRPT 0x0001u  /* PostScript printer */
#define PRONLQ 0x0002u  /* IBM Proprinter NLQ */
#define PROPRT 0x0004u  /* IBM Proprinter */
#define PRPPDS 0x0008u  /* IBM PPDS printing */

#define ONEBUF 0x0010u  /* do not use high ASCII codes to print */
#define ALTCDE 0x0020u  /* IBM 5182 color, Epson LQ (NEC 24-pin) */
#define BIGBOX 0x0040u  /* use large 9 X 19 char box /g+ print mode */
#define XGABOX 0x0080u  /* use large 12 X 15 char box /gx print mode */
#define PRWIDE 0x0100u  /* use single density graphic mode */
#define PRDENS 0x0200u  /* 24-pin printers */


/* structure definitions, these do not allocate storage */
struct  scr_field
    {
    char  scr[91] [90];
    char  fill[2];
    }; /* end struct */

struct  scr_area
    {
    struct scr_field  pos[4];
    }; /* end struct */

struct  norm_pos
    {
    char  char_byte;
    char  attr_byte;
    }; /* end struct */

struct  norm_line
    {
    struct norm_pos  ncol[80];
    }; /* end struct */

struct  norm_scr
    {
    struct norm_line  nline[25];
    }; /* end struct */

struct  color_field
    {
    char  cscr[100] [80];
    char  cfill[192];
    }; /* end struct */

struct  color_scr
    {
    struct color_field  cpos[2];
    }; /* end struct */

struct  ega_scr
    {
    char  escr[25] [14] [80];
    }; /* end struct */

struct  vga_scr
    {
    char  vscr[25] [19] [80];
    }; /* end struct */

struct  ibm_scr
    {
    char  iscr[25] [14] [90];
    }; /* end struct */

struct  ibm2scr
    {
    char  i2scr[25] [19] [90];
    }; /* end struct */

struct  xga_pos
    {
    char  xb;
    char  sx;
    char  xs;
    }; /* end struct */

struct  xga_line
    {
    char  x1fill[4];
    struct xga_pos  xp[40];
    char  x2fill[4];
    }; /* end struct */

struct  xga_scr
    {
    /* in two parts: 16/9 lines (posptr/posxga) */
    struct xga_line  xl[16] [30];
    }; /* end struct */

struct  prt_img
    {
    char  pimg[57] [8] [90];
    }; /* end struct */

struct  xi_line
    {
    char  xi1fill[4];
    char  xk[120];
    char  xi2fill[4];
    }; /* end struct */

struct  xga_img
    {
    struct xi_line  xj[60] [8];
    }; /* end struct */

union  both_scr
    {
    struct scr_area   sa;
    struct norm_scr   ns;
    struct color_scr  cs;
    struct ega_scr    es;
    struct vga_scr    vs;
    struct ibm_scr    is;
    struct ibm2scr    i2;
    struct xga_scr    xs;
    struct prt_img    pi;
    struct xga_img    xi;
    }; /* end union */

struct  rombios
    {
    unsigned char  rchr[128] [8];
    }; /* end struct */

extern int LINKMSC  prtcntl(unsigned int port, int value);
extern int LINKMSC  prtinpt(unsigned int port);
