/**********************************************************************/
/*                                                                    */
/*  stdcl.h standard functions declaration file.                      */
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
/* entfield subroutine definitions                                    */
/**********************************************************************/
enum   csrfunc  {retcsr, upcsr, downcsr, leftcsr, rightcsr, lefttab,
                 righttab, homecsr, endcsr, nopcsr};

extern void  bufinpt(char inbuf[], int *i, int *inpt, int *scan,
    int *shift);
extern void  bytemap(char in, char out[]);
extern void  clearscr(void);
extern void  delch(int bound, int line_no, int col_no,
    char scrtext[][25][80]);
extern void  dispch(int line_no, int col_no, char scrtext[][25][80]);
extern void  displn(int line_no, char scrtext[][25][80]);
extern void  entfield(enum csrfunc function, int toright, int nfield,
    int rowcol[][5], int *line_no, int *col_no);
extern char  *formdsn(char drive[], char path1[], char path2[],
    char path3[], char name[], char ext[], char vsn_mem[],
    char othdsn[], char dsn[]);
extern char  *fullstr(char str[], char val[], int len);
extern void  getinpt(int *inpt, int *scan, unsigned int *shift,
    unsigned int keyb);
extern char  *ilindex(char *str, char *list);
extern void  insch(int bound, int line_no, int col_no,
    char scrtext[][25][80]);
extern void  invert(char min0, char min1, char min2, char min3,
    char min4, char min5, char min6, char min7, char mout[]);
extern char  *iverify(char *str, char *valid);
extern char  *leftfld(char fld[], int lastsub);
extern char  *leftjust(char str[]);
extern char  *lindex(char *str, char *list);
extern char  *lower(char *str);
extern  int  numeric(char *str);
extern char  *pindex(unsigned int type, int (* *f)[], char *str,
    char *pat);
extern void  poscur(int line_no, int col_no);
extern  int  prockey(int inpt, int scan, int shift, int *line_no,
    int *col_no, int nfield, int rowcol[][5], char scrtext[][25][80]);
extern void  ptrinit(void);
extern char  redadj(unsigned char byte);
extern char  *rightjst(char str[], int lastsub);
extern char  *upper(char *str);
extern char  *verify(char *str, char *valid);
extern void  whenow(char tod[], char greg[]);
extern void  xepslot(char *byte);

#ifdef OS2
extern void F16 LINK16 IOPLibm(void);
extern void F16 LINK16 IOPLcya(void);
extern void F16 LINK16 IOPLpur(void);
extern void F16 LINK16 IOPLpg0(void);
extern void F16 LINK16 IOPLpg1(void);
#endif
