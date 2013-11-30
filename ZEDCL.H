/**********************************************************************/
/*                                                                    */
/*  zedcl.h zedit functions declaration file.                         */
/*                                                                    */
/**********************************************************************/
/*                                                                    */
/* This is ZEDIT source material.                                     */
/*                                                                    */
/* ZEDIT Source Materials are intellectual property                   */
/*     (c) Copyright 1987,2001 by Clyde Thomas Zuber.                 */
/*                                                                    */
/**********************************************************************/

/* zfinish/zepilog code for message and condition code */
enum  fintype  {normal_end, general_fail, open_in, open_out,
                video_fail, no_storage};

/* lcinval type values */
enum  lctype  {lc_top, lc_bottom, lc_both, lc_any};

/* ckplace type values */
enum  cktype  {sl_cmd, sr_cmd, copy_cmd, del_cmd, move_cmd, on_cmd,
               rep_cmd, exc_cmd};

/* zedpprt, zedpx24 defines */
enum  zgraph  {none_of = -1, asc_bot, asc_top, grk_bot, grk_top,
               heb_bot, heb_top, lat_bot, lat_top};

struct bufline
    {
    struct bufline  *prev;
    struct bufline  *next;
    char  lineno[8];
    char  script;
    char  status;
    char  bline[2];
    /* array size 2 is only valid when the following fields exist */
    struct bufline  *eblk;  /* end exclude,   in ST_BYPS record */
    char  filler[94];
    int  rcnt;              /* exclude count, in ST_XBLK record */
    struct bufline  *bblk;  /* begin exclude, in ST_XBLK record */
    } /* end struct */;

/* bufline_hdr is defined for use with the sizeof operator */
/* it must alway match the header portion of bufline */
struct bufline_hdr
    {
    struct bufline  *prev;
    struct bufline  *next;
    char  lineno[8];
    char  script;
    char  status;
    } /* end struct */;

struct bufhelp
    {
    struct bufhelp  *prev;
    struct bufhelp  *next;
    char  lineno[8];
    char  script;
    char  status;
    char  hline[70];
    } /* end struct */;

struct prntdemo
    {
    struct prntdemo  *prev;
    struct prntdemo  *next;
    char  lineno[8];
    char  script;
    char  status;
    char  hline[118];
    };  /* end struct */

struct lineptrs
    {
    struct bufline  *slst;
    struct bufline  *slfn;

    struct bufline  *srst;
    struct bufline  *srfn;

    struct bufline  *colsb;
    struct bufline  *after;

    struct bufline  *copyst;
    struct bufline  *copyfn;

    struct bufline  *delst;
    struct bufline  *delfn;

    struct bufline  *movest;
    struct bufline  *movefn;

    struct bufline  *onst;
    struct bufline  *onfn;

    struct bufline  *repst;
    struct bufline  *repfn;

    struct bufline  *excst;
    struct bufline  *excfn;

    struct bufline  *newcurr;
    struct bufline  *oldcurr;

    int  count;
    unsigned int  oldpanel;
    } /* end struct */;


extern void  backcmd(union both_scr *posptr, unsigned int *panel,
    int nfield, int rowcol[][5], char inptext[][25][80], char dsn[],
    int maxlrecl, unsigned int cmd[], int coloffset,
    struct bufline **first, struct bufline *curr, int wherest[],
    int wherend[], int *dschanged, struct lineptrs *place, char prm[]);
extern void  browpan(union both_scr *posptr, int *line_no, int *col_no,
    int *nfield, int * *rowcol_ptr, char inptext[][25][80], char dsn[],
    int rightmar);
extern void  buftscr(union both_scr *posptr, int nfield,
    int rowcol[][5], char inptext[][25][80], struct bufline *curr,
    int maxlrecl, int coloffset, int wherest[], int wherend[],
    struct lineptrs *place, int clrmsg);
extern void  buftsln(union both_scr *posptr, int nfield,
    int rowcol[][5], struct bufline *curr, int line_no, int maxlrecl,
    char inptext[][25][80], int *where, int *amode, int *eol,
    int *toright, int *col_no);
extern void  cfgfget(union both_scr *posptr, int rowcol[][5],
    char inptext[][25][80]);
extern void  cfgfpan(union both_scr *posptr, int *line_no, int *col_no,
    int *nfield, int * *rowcol_ptr, char inptext[][25][80]);
extern void  cfginit(void);
extern  int  cfgkget(union both_scr *posptr, int rowcol[][5],
    char inptext[][25][80]);
extern void  cfgkpan(union both_scr *posptr, int *line_no, int *col_no,
    int *nfield, int * *rowcol_ptr, char inptext[][25][80]);
extern void  chngprm(union both_scr *posptr, int maxlrecl, char pat[],
    char prm2[], int map[], int onscr, struct bufline *ptr,
    int *dschanged);
extern  int  ckplace(union both_scr *posptr, enum cktype type,
    struct lineptrs *place);
extern void  clrlhmn(union both_scr *posptr, int line_no);
extern void  clrline(union both_scr *posptr, int line_no);
extern void  clrlxga(union both_scr *posptr, int line_no);
extern void  clrpanl(union both_scr *posptr);
extern void  cmddone(union both_scr *posptr, int toright,
    unsigned int panel, int nfield, int rowcol[][5], int *line_no,
    int *col_no, char inptext[][25][80], unsigned int cmd[], char dsn[],
    int *maxlrecl, int *amount, char cmdln[], char prm1[], char prm2[]);
extern void  cmdline(union both_scr *posptr, unsigned int cmd[],
    char cmdln[]);
extern  int  cmdparm(unsigned int cmd, int toright, int line_no,
    int col_no, char scrfield[], int nfield, int rowcol[][5],
    char cmdln[], char prm1[], char prm2[]);
extern char  *cmdprse(char cmd[], char cmdln[]);
extern void  cmdrest(union both_scr *posptr, int toright,
    int rowcol[][5], int *line_no, int *col_no,
    char inptext[][25][80]);
extern  int  cmpline(struct bufline *lo, struct bufline *hi);
extern struct bufline  *colslin(union both_scr *posptr, int maxlrecl,
    struct bufline *curr, struct lineptrs *place);
extern void  convinp(union both_scr *posptr, unsigned int inpt,
    unsigned int shift, int amode, int toright, int *line_no,
    int *col_no, int nfield, int rowcol[][5],
    char inptext[][25][80], unsigned int display);
extern void  convout(int len_in, char txt_in[], char srp_in[],
    char ovr_in[], int prevsrp, char lineout[], int where, char save[]);
extern void  copylin(union both_scr *posptr, struct lineptrs *place,
    int maxlrecl);
extern void  copyonb(struct lineptrs *place);
extern void  ddelblk(union both_scr *posptr, struct lineptrs *place,
    int maxlrecl);
extern void  delchar(int toright, int f, int rowcol[][5], int line_no,
    int col_no, char inptext[][25][80]);
extern void  delnexc(union both_scr *posptr, int maxlrecl,
    struct bufline *ptr, struct bufline * *curr);
extern void  delprot(struct bufline *ptr, struct bufline * *curr);
extern void  delxblk(union both_scr *posptr, int maxlrecl,
    struct bufline *ptr, struct bufline * *curr);
extern void  dispchr(union both_scr *posptr, char c, int line_no,
    int col_no, char dots[][14]);
extern void  displin(union both_scr *posptr, char line[], int line_no,
    char dots[][14]);
extern void  dispmsg(union both_scr *posptr, int msgno);
extern void  dispnum(union both_scr *posptr, int nfield,
    int rowcol[][5], char stat, int num_line, int num_col,
    char numdigit[], int nd_col, char inptext[][25][80]);
extern void  ds8chmn(union both_scr *posptr, char c, int line_no,
    int col_no);
extern void  ds8cib2(union both_scr *posptr, char c, int line_no,
    int col_no);
extern void  ds8cibm(union both_scr *posptr, char c, int line_no,
    int col_no);
extern void  ds8cxga(union both_scr *posptr, char c, int line_no,
    int col_no);
extern void  ds8lhmn(union both_scr *posptr, char line[], int line_no);
extern void  ds8lib2(union both_scr *posptr, char line[], int line_no);
extern void  ds8libm(union both_scr *posptr, char line[], int line_no);
extern void  ds8lxga(union both_scr *posptr, char line[], int line_no);
extern void  dsentry(union both_scr *posptr, int *line_no, int *col_no,
    int *nfield, int * *rowcol_ptr, char inptext[][25][80],
    char *selfor);
extern void  dsp8chr(union both_scr *posptr, char c, int line_no,
    int col_no);
extern void  dsp8lin(union both_scr *posptr, char line[], int line_no);
extern void  dspchmn(union both_scr *posptr, char c, int line_no,
    int col_no, char dots[][14]);
extern void  dspcib2(union both_scr *posptr, char c, int line_no,
    int col_no, char dots[][14]);
extern void  dspcibm(union both_scr *posptr, char c, int line_no,
    int col_no, char dots[][14]);
extern void  dspcxga(union both_scr *posptr, char c, int line_no,
    int col_no, char dots[][14]);
extern void  dsplhmn(union both_scr *posptr, char line[], int line_no,
    char dots[][14]);
extern void  dsplib2(union both_scr *posptr, char line[], int line_no,
    char dots[][14]);
extern void  dsplibm(union both_scr *posptr, char line[], int line_no,
    char dots[][14]);
extern void  dsplxga(union both_scr *posptr, char line[], int line_no,
    char dots[][14]);
extern void  edbrpan(union both_scr *posptr, char inptext[][25][80],
    char dsn[], int edit);
extern void  editpan(union both_scr *posptr, int *line_no, int *col_no,
    int *nfield, int * *rowcol_ptr, char inptext[][25][80], char dsn[],
    int rightmar);
extern  int  entpanl(union both_scr *posptr, int inpt, int scan,
    unsigned int shift, int amode, int toright, int *line_no,
    int *col_no, int f, int nfield, int rowcol[][5],
    char inptext[][25][80]);
extern void  eraseof(union both_scr *posptr, int toright,
    int rowcol[][5], char inptext[][25][80], int line_no, int col_no);
extern struct bufline  *exclude(union both_scr *posptr,
    struct lineptrs *place);
extern struct bufline  *excmerg(struct bufline *ptr);
extern void  excrdsp(union both_scr *posptr, struct bufline *ptr);
extern struct bufline  *excremv(struct bufline *pos, int *n);
extern struct bufline  *excshow(union both_scr *posptr,
    struct lineptrs *place, int maxlrecl);
extern void  excxblk(struct bufline *ptr);
extern void  fillscr(union both_scr *posptr);
extern void  findprm(union both_scr *posptr, int *line_no, int *col_no,
    int nfield, int rowcol[][5], int maxlrecl, unsigned int cmd,
    int *coloffset, struct bufline *first, struct bufline * *curr,
    int *dschanged, char new_prm1[], char new_prm2[], char text[],
    int map[]);
extern void  freebuf(struct bufline *ptr);
extern unsigned int  funckey(int scan, unsigned int shift);
extern void  getstrt(int coloffset, char *bline, int temp_rowcol[][5],
    char *scratch, int *where, int *amode, int *eol, int *toright);
extern void  grphreg(void);
extern void  ibmmode(void);
extern  int  inschar(union both_scr *posptr, int toright,
    int rowcol[][5], int line_no, int col_no, char inptext[][25][80]);
extern void  inusage(void);
extern void  invcopt(union both_scr *posptr[], char dsn[][56],
    int argc, char *argv[], unsigned int cmd[], int maxlrecl[],
    int *rightmar);
extern struct bufline  *keyslin(union both_scr *posptr,
    struct bufline *curr, struct lineptrs *place);
extern  int  lastsrp(int prevsrp, char *lptr);
extern  int  lcinval(union both_scr *posptr, enum lctype type,
    struct bufline *curr);
extern  int  letsgrk(int i, int e, int d, char bline[]);
extern  int  letsheb(int i, int e, int d, char bline[]);
extern struct bufline  *letslin(union both_scr *posptr, int maxlrecl,
    struct bufline *curr, struct lineptrs *place);
extern void  linecmd(union both_scr *posptr, int nfield,
    int rowcol[][5], char inptext[][25][80], unsigned int cmd[],
    int maxlrecl, struct bufline *curr, struct lineptrs *place,
    int *dschanged);
extern struct bufline  *lnecmd1(union both_scr *posptr, int nfield,
    int rowcol[][5], unsigned int cmd[], int maxlrecl,
    struct bufline *curr, struct lineptrs *place, char *pos,
    char ccnt[], int *line_no, int *dschanged);
extern struct bufline  *lnecmd2(union both_scr *posptr,
    unsigned int cmd[], int maxlrecl, struct bufline *curr,
    struct lineptrs *place, char *pos, char ccnt[], int *line_no,
    int *dschanged);
extern struct bufline  *lnecmd3(union both_scr *posptr,
    int maxlrecl, struct bufline *curr, struct lineptrs *place,
    char *pos, char ccnt[], int *line_no, int *dschanged);
extern char  *loclcmd(struct bufline *curr, char lctxt[], char lcsrp[],
    char operand[]);
extern char  *mergeon(char *frstr, char *tostr);
extern void  misccmd(union both_scr *posptr, int toright, int *line_no,
    int *col_no, unsigned int *panel, int *nfield, int rowcol[][5],
    char inptext[][25][80], int maxlrecl, unsigned int cmd,
    int coloffset, struct bufline * *first, struct bufline * *curr,
    int wherest[], int wherend[], int *dschanged, struct lineptrs *place,
    int rightmar, int * *rcptr);
extern void  movecpy(union both_scr *posptr, struct lineptrs *place,
    int maxlrecl);
extern void  movelin(union both_scr *posptr, struct lineptrs *place,
    int maxlrecl);
extern void  moveonb(union both_scr *posptr, struct lineptrs *place,
    int maxlrecl);
extern void  optback(union both_scr *posptr, unsigned int panel,
    int nfield, int rowcol[][5], char inptext[][25][80], char dsn[],
    int maxlrecl, unsigned int cmd[], struct bufline **first,
    struct bufline *curr, int wherest[], int wherend[], int *dschanged,
    unsigned int option);
extern void  ov8chmn(union both_scr *posptr, char c, int line_no,
    int col_no);
extern void  ov8cib2(union both_scr *posptr, char c, int line_no,
    int col_no);
extern void  ov8cibm(union both_scr *posptr, char c, int line_no,
    int col_no);
extern void  ov8cxga(union both_scr *posptr, char c, int line_no,
    int col_no);
extern void  overchr(union both_scr *posptr, char c, int line_no,
    int col_no, char dots[][14], int stretch);
extern void  ovr8chr(union both_scr *posptr, char c, int line_no,
    int col_no);
extern void  ovrchmn(union both_scr *posptr, char c, int line_no,
    int col_no, char dots[][14]);
extern void  ovrcib2(union both_scr *posptr, char c, int line_no,
    int col_no, char dots[][14], int stretch);
extern void  ovrcibm(union both_scr *posptr, char c, int line_no,
    int col_no, char dots[][14]);
extern void  ovrcxga(union both_scr *posptr, char c, int line_no,
    int col_no, char dots[][14], int stretch);
extern void  pan2cmd(union both_scr *posptr, int *line_no, int *col_no,
    unsigned int *panel, int *nfield, int * *rowcol,
    char inptext[][25][80], char dsn[], int maxlrecl,
    unsigned int cmd[], int *coloffset, struct bufline *curr,
    int wherest[], int wherend[], int *dschanged,
    struct lineptrs *place, int rightmar);
extern void  panlcmd(union both_scr *posptr, int *line_no, int *col_no,
    unsigned int *panel, int *nfield, int * *rowcol,
    char inptext[][25][80], char dsn[], int maxlrecl,
    unsigned int cmd[], int *coloffset, struct bufline * *first,
    struct bufline * *curr, int wherest[], int wherend[],
    int *dschanged, struct lineptrs *place, int rightmar);
extern void  pascchr(union both_scr *posptr, int inpt,
    unsigned int shift, int toright, int nfield, int rowcol[][5],
    int *line_no, int *col_no, char inptext[][25][80],
    unsigned int display);
extern void  pgrkchr(union both_scr *posptr, int inpt,
    unsigned int shift, int toright, int nfield, int rowcol[][5],
    int *line_no, int *col_no, char inptext[][25][80],
    unsigned int display);
extern void  phebchr(union both_scr *posptr, int inpt,
    unsigned int shift, int toright, int nfield, int rowcol[][5],
    int *line_no, int *col_no, char inptext[][25][80],
    unsigned int display);
extern void  platchr(union both_scr *posptr, int inpt,
    unsigned int shift, int toright, int nfield, int rowcol[][5],
    int *line_no, int *col_no, char inptext[][25][80],
    unsigned int display);
extern void  primary(union both_scr *posptr, int *line_no, int *col_no,
    int *nfield, int * *rowcol_ptr, char inptext[][25][80]);
extern void  primcmd(union both_scr *posptr, unsigned int cmd[],
    struct bufline *first);
extern void  procedt(union both_scr *posptr, unsigned int panel,
    int nfield, int rowcol[][5], int coloffset,
    struct bufline * *curr, int wherest[], int wherend[],
    int *dschanged, char inptext[][25][80], unsigned int cmd[],
    int maxlrecl, struct lineptrs *place, char cmdln[]);
extern void  procinp(union both_scr *posptr, int inpt, int scan,
    unsigned int shift, int amode, int toright, unsigned int panel,
    int nfield, int rowcol[][5], int coloffset, struct bufline * *curr,
    int wherest[], int wherend[], int *dschanged,
    char inptext[][25][80], char dsn[], int *amount, int *maxlrecl,
    int *line_no, int *col_no, unsigned int cmd[],
    struct lineptrs *place, char prm1[], char prm2[]);
extern  int  procscn(union both_scr *posptr, int inpt, int scan,
    unsigned int shift, int toright, unsigned int panel, int nfield,
    int rowcol[][5], int coloffset, struct bufline * *curr,
    int wherest[], int wherend[], int *dschanged, char inptext[][25][80],
    char dsn[], int *amount, int *maxlrecl, int *line_no, int *col_no,
    unsigned int cmd[], struct lineptrs *place, char prm1[], char prm2[],
    char cmdln[]);
extern void  promchr(union both_scr *posptr, int inpt,
    unsigned int shift, int toright, int nfield, int rowcol[][5],
    int *line_no, int *col_no, char inptext[][25][80],
    unsigned int display);
extern struct bufline  *protlin(union both_scr *posptr,
    struct bufline *curr, int len);
extern void  pshstck(unsigned int cmd[], unsigned int addition);
extern void  rdspasc(union both_scr *posptr, int line_no, int col_no,
    char inptext[][25][80]);
extern void  rdspgrk(union both_scr *posptr, int line_no, int col_no,
    char inptext[][25][80]);
extern void  rdspheb(union both_scr *posptr, int line_no, int col_no,
    char inptext[][25][80]);
extern void  rdsplat(union both_scr *posptr, int line_no, int col_no,
    char inptext[][25][80]);
extern void  rdsplin(union both_scr *posptr, int line_no, int startcol,
    int endcol, char inptext[][25][80]);
extern void  rdsprom(union both_scr *posptr, int line_no, int col_no,
    char inptext[][25][80]);
extern void  renbufr(struct bufline *ptr);
extern void  revchar(union both_scr *posptr, int line_no, int col_no);
extern void  revchmn(union both_scr *posptr, int line_no, int col_no);
extern void  revcib2(union both_scr *posptr, int line_no, int col_no);
extern void  revcibm(union both_scr *posptr, int line_no, int col_no);
extern void  revcxga(union both_scr *posptr, int line_no, int col_no);
extern void  revlhmn(union both_scr *posptr, int line_no);
extern void  revline(union both_scr *posptr, int line_no);
extern void  revlxga(union both_scr *posptr, int line_no);
extern void  rhebrew(char prm[], char con[], char rev[], char bkc[]);
extern void  rrepblk(union both_scr *posptr, struct lineptrs *place,
    int maxlrecl);
extern struct bufline  *scrlcmd(union both_scr *posptr,
    unsigned int panel, int nfield, int rowcol[][5],
    char inptext[][25][80], int amount, int maxlrecl,
    unsigned int cmd[], int *coloffset, struct bufline *first,
    struct bufline *curr, int wherest[], int wherend[], int *dschanged,
    struct lineptrs *place);
extern void  scrprnt(union both_scr *posptr);
extern void  scrtbuf(union both_scr *posptr, int nfield,
    int rowcol[][5], char inptext[][25][80], struct bufline *curr,
    int maxlrecl, int wherest[], int wherend[], int *dschanged);
extern void  shiftlf(union both_scr *posptr, struct lineptrs *place,
    int maxlrecl);
extern void  shiftrt(union both_scr *posptr, struct lineptrs *place,
    int maxlrecl);
extern void  srchcmd(union both_scr *posptr, int *line_no, int *col_no,
    unsigned int panel, int nfield, int rowcol[][5],
    char inptext[][25][80], int maxlrecl, unsigned int cmd,
    int *coloffset, struct bufline *first, struct bufline * *curr,
    int wherest[], int wherend[], int *dschanged,
    struct lineptrs *place, char prm1[], char prm2[]);
extern void  srpbufr(union both_scr *posptr, int maxlrecl,
    struct bufline *ptr);
extern void  statlin(union both_scr *posptr, int amode,
    unsigned int shift, int toright, char inptext[][25][80]);
extern void  stckcmd(unsigned int cmd[]);
extern void  textreg(void);
extern void  topline(union both_scr *posptr, int nfield,
    int rowcol[][5], char inptext[][25][80], struct bufline *curr,
    int maxlrecl, int coloffset, int clrmsg);
extern void  tranheb(char dsn[], int maxlrecl, struct bufline *first);
extern void  transcr(union both_scr *posptr, char dsn[], int maxlrecl,
    int scrinit, char exchange[], struct bufline *first);
extern void  txtonly(int amode, char bline[], char txtline[],
    int map[]);
extern  int  vrepcnt(union both_scr *posptr, char charcnt[]);
extern  int  wrtebuf(char dsn[], struct bufline *ptr);
extern void  xga8514(union both_scr *posptr, int line_no, int col_no);
extern unsigned int  zdriver(union both_scr *posptr, int inpt, int scan,
    unsigned int shift, int amode, int toright, int *line_no,
    int *col_no, unsigned int *panel, int *nfield, int * *rowcol,
    char inptext[][25][80], char dsn[], int *maxlrecl, int *coloffset,
    struct bufline * *first, struct bufline * *curr, int wherest[],
    int wherend[], int *dschanged, struct lineptrs *place,
    unsigned int cmd[], int rightmar);
extern  int  LINKMSC  main(int argc, char *argv[]);
extern  unsigned short  zedinit(int argc, char *argv[],
    union both_scr *posptr[], char inptext[][4][25][80],
    char dsn[][56], int maxlrecl[], struct lineptrs place[],
    unsigned int cmd[], int *rightmar);
extern void  zedlogo(union both_scr *posptr);
extern void  zedpbse(char dsn[], int maxlrecl, int rightmar);
extern void  LINKMSC  zedpbuf(union both_scr *posptr, int maxlrecl,
    struct bufline *ptr, int rightmar);
extern void  zedpimg(union both_scr *real_posptr, int maxlrecl,
    struct bufline *curr, int rightmar);
extern void  zepilog(union both_scr *posptr, enum fintype code);
extern void  zfinish(union both_scr *posptr, enum fintype code);

#ifdef STDIO
extern struct bufline  *getfile(union both_scr *posptr,
    struct bufline *curr, FILE *ds, int maxlrecl);
extern struct bufline  *readbuf(union both_scr *posptr, FILE *ds,
    int maxlrecl);
extern void  scrpesc(FILE *prn, short llen);
extern void  scrphmn(union both_scr *posptr, FILE *prn);
extern void  scrpxga(union both_scr *posptr, FILE *prn);
extern void  zedpfnt(int graph, char sel, FILE *prn, char halfch[][8]);
extern void  zedplsp(FILE *prn);
extern void  zedplup(int graph, FILE *prn);
extern void  zedppre(int maxlrecl, FILE *prn, int rightmar, int amode,
    int toright, char prchar, char prbuf[]);
extern void  zedpprt(FILE *prn, int rightmar, int toright, char prbuf[],
    int true_linesize, int q, int last_amode[], int pb[]);
extern void  zedppsf(FILE *prn);
extern void  zedppsp(int regular, FILE *prn, int rightmar, int amode,
    int toright, char prchar);
extern void  zedpram(FILE *prn);
extern void  zedprom(FILE *prn);
extern void  zedpx24(FILE *prn);
#endif

#ifdef OS2
#ifdef M_I386
#define DosAllocSeg     Dos16AllocSeg
#define DosSemClear     Dos16SemClear
#define DosSemRequest   Dos16SemRequest
#define DosSemSet       Dos16SemSet
#define DosSemSetWait   Dos16SemSetWait
#define DosSemWait      Dos16SemWait

extern unsigned short F16 LINK16 DosAllocSeg(unsigned short bufsze,
    unsigned short S16  segmt, unsigned short shareattr);
extern unsigned short F16 LINK16 DosSemClear(void S16 hsem);
extern unsigned short F16 LINK16 DosSemSet(void S16 hsem);
extern unsigned short F16 LINK16 DosSemWait(void S16 hsem,
    long lTimeOut);
extern unsigned short F16 LINK16 DosSemSetWait(void S16 hsem,
    long lTimeOut);
extern unsigned short F16 LINK16 DosSemRequest(void S16 hsem,
    long lTimeOut);
#endif

extern void LINKAGE  savevio(unsigned long  posprm);
extern void LINKAGE  zedpprm(unsigned long  parm);

#pragma pack(2)
struct parameter
    {
    union both_scr  *posptr;
    short  maxlrecl;
    struct bufline  *ptr;
    short  rightmar;
    } /* end struct */;
#pragma pack()
#endif
