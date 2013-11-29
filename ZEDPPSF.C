#include <stdio.h>
#include "zedit.h"

void  zedppsf(
              FILE  *prn)
/**********************************************************************/
/*                                                                    */
/* Prepare PostScript printer with font definitions.                  */
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
extern char  ascchar[128] [14];
extern char  grkchar[128] [14];
extern char  hebchar[128] [14];
static char  (*chdef[3])[128] [14] = {(char (*)[128] [14]) ascchar,
    (char (*)[128] [14]) grkchar, (char (*)[128] [14]) hebchar};

static char  *comment = PSCOMMENT;

static char  *part1 = "\
8 dict dup begin\n\
/FontType 3 def\n\
/FontMatrix [1 0 ";

static char  *part2 = "0 ";
static char  *part2s = ".6 ";

static char  *part3 = "\
1 0 0] def\n\
/FontBBox [0 0 0 0] def\n\
/BuildChar\n\
{ 0 begin\n\
/ch exch def\n\
/fontdict exch def\n\
/chname fontdict /Encoding get ch get def\n\
/chinfo fontdict /CharData get chname get def\n\
/width ";

static char  *part4 = ".6 ";
static char  *part4r = "-0.6 ";

static char  *part5 = "\
def\n\
ch 8 eq {/width width -1 mul def} if\n\
width 0 0 0 1 1 setcachedevice\n\
8 14 true [14 0 0 -14 .5 13.5] chinfo cvx imagemask\n\
end\n\
} def\n\
/BuildChar load 0 5 dict put\n\
/Encoding 256 array def\n\
0 1 255 {Encoding exch /.no put} for\n";

static char  *encoding = "Encoding";
static char  *put = "put\n";

static char  *let[3] [114] = {{".no",
              "THN", "odt", "AE ", "ae ", "OE ", "oe ", "xxx", "thn",
"eth", "ske", "mdt", "ocr", "xxx", "esc", "dac", "ced", "dia", "bre",
"bla", "exc", "dqt", "pnd", "dol", "pct", "amp", "quo", "lpa", "rpa",
"ast", "pls", "com", "hyp", "per", "sla", "zer", "one", "two", "thr",
"fou", "fiv", "six", "sev", "eig", "nin", "col", "sem", "les", "equ",
"gre", "que", "at ", "A  ", "B  ", "C  ", "D  ", "E  ", "F  ", "G  ",
"H  ", "I  ", "J  ", "K  ", "L  ", "M  ", "N  ", "O  ", "P  ", "Q  ",
"R  ", "S  ", "T  ", "U  ", "V  ", "W  ", "X  ", "Y  ", "Z  ", "lbk",
"bck", "rbk", "cir", "und", "gra", "a  ", "b  ", "c  ", "d  ", "e  ",
"f  ", "g  ", "h  ", "i  ", "j  ", "k  ", "l  ", "m  ", "n  ", "o  ",
"p  ", "q  ", "r  ", "s  ", "t  ", "u  ", "v  ", "w  ", "x  ", "y  ",
"z  ", "lbc", "ver", "rbc", "wav"},
{
".no",        "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx",
"xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx",
"bla", "exc", "gra", "pnd", "dol", "pct", "amp", "acu", "lpa", "rpa",
"ast", "pls", "com", "hyp", "per", "sla", "zer", "one", "two", "thr",
"fou", "fiv", "six", "sev", "eig", "nin", "dot", "sem", "les", "equ",
"gre", "que", "uml", "ALP", "BET", "GAM", "DEL", "EPS", "ZET", "ETA",
"THE", "IOT", "rou", "KAP", "LAM", "MU ", "NU ", "OMI", "PI ", "XI ",
"RHO", "SIG", "TAU", "UPS", "isu", "PHI", "CHI", "PSI", "OME", "lbk",
"bck", "rbk", "cir", "und", "dqt", "alp", "bet", "gam", "del", "eps",
"zet", "eta", "the", "iot", "smo", "kap", "lam", "mu ", "nu ", "omi",
"pi ", "xi ", "rho", "sig", "tau", "ups", "str", "phi", "chi", "psi",
"ome", "lbc", "ver", "rbc", "wav"},
{
".no",        "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx",
"xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx",
"bla", "exc", "dqt", "pnd", "dol", "pct", "amp", "ale", "lpa", "rpa",
"ast", "pls", "com", "maq", "per", "sla", "zer", "one", "two", "thr",
"fou", "fiv", "six", "sev", "eig", "nin", "sop", "she", "les", "equ",
"gre", "que", "at ", "qam", "QUP", "ktr", "H26", "seg", "hol", "D71",
"D72", "D74", "D75", "D76", "SUP", "mtr", "ntr", "kat", "ptr", "xxx",
"xxx", "sin", "xxx", "xxx", "xxx", "xxx", "sdt", "xxx", "xxx", "lbk",
"bck", "rbk", "cir", "und", "gra", "pat", "bth", "kph", "dal", "ser",
"dag", "gim", "he ", "hir", "tet", "het", "ldh", "mem", "nun", "sam",
"pe ", "qop", "res", "shi", "taw", "qib", "ayi", "waw", "sad", "yod",
"zay", "lbc", "ver", "rbc", "wav"}};

static char  *part6 = "\
/CharData 114 dict def\n\
CharData begin\n";

static char  *part7 = "\
end\n\
/UniqueID ";

static char  *id[5] = {"755", "757", "775", "577", "557"};

static char *name[5] = {"/Ascch", "/Grkch", "/Rhebc", "/Hebch",
     "/Spcch"};

register int  i;
register int  j;
register int  k;

int  ii;
char  buf[16];


for (i = 0; i < 5; ++i)
    {
    fputs(comment, prn);

    fputs(part1, prn);

    if (i == 4)
        fputs(part2s, prn);
    else
        fputs(part2, prn);

    fputs(part3, prn);

    switch(i)
        {
        case 0:
        case 1:
        case 2:
            fputs(part4, prn);
            ii = i;
            break;
        case 3:
            fputs(part4r, prn);
            ii = 2;
            break;
        case 4:
            fputs(part4, prn);
            ii = 0;
            break;
        } /* end switch */

    fputs(part5, prn);

    for (j = 14; j < 127; ++j)
        fprintf(prn, "%s %d /%s %s ", encoding, j, let[ii] [j-13], put);

    fputs(part6, prn);

    /* the position before the first defined char must be empty (.no) */
    for (j = 13; j < 127; ++j)
        {
        fprintf(prn, "/%s [<", let[ii] [j-13]);
        for (k = 0; k < 14; ++k)
            fputs(buf - 2 + sprintf(buf, "%.2x", (*chdef[ii])[j] [k]),
                prn);
        fputs(">] def\n", prn);
        } /* end for */

    fprintf(prn, "%s%s def\nend\n%s ", part7, id[i], name[i]);

    fputs("exch definefont pop\n", prn);
    } /* end for */

} /* end zedppsf */
