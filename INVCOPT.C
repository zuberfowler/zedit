#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zedit.h"

void  invcopt(
              union both_scr  *posptr[3],
              char  dsn[2] [56],
              int  argc,
              char  *argv[],
              unsigned int  cmd[],
              int  maxlrecl[2],
              int  *rightmar)
/**********************************************************************/
/*                                                                    */
/* Initialization by invocation command line parms.                   */
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
extern char  outfile[];
extern unsigned int  graphic;
extern unsigned int  prtmode;
extern union both_scr  *posxga[2];
register int  i;
unsigned int  invalid;


invalid = YESMAYBE;

/* initialize for z option */
dsn[1] [0] = NO;

/* initialize graphic */
graphic |= UCOLOR;

for (i = 1; i < argc; ++i)
    {
    if (*argv[i] != '/'  &&  *argv[i] != '-')
        invalid = YES;
    switch(*(argv[i] + 1))
        {
        case '1':
            if (prtmode & NOTPRO)
                invalid = YES;
            prtmode |= ONEBUF;
            break;
        case '2':
            prtmode |= PRWIDE;
            break;
        case '3':
            prtmode |= PRDENS;
            break;
        case 'a':
            prtmode |= ALTCDE;
            break;
        case 'b':
            graphic |= RMAR;
            break;
        case 'c':
            if (graphic & ADISPL)
                invalid = YES;
            else
                invalid &= NOMAYBE;
            graphic |= CGA;
            posptr[0] = (union both_scr *) 0xB8000000;
            posptr[1] = (union both_scr *) malloc(32768u);
            if (!posptr[1])
                zfinish(NULL, no_storage);
            posptr[2] = (union both_scr *) malloc(32768u);
            if (!posptr[2])
                zfinish(NULL, no_storage);
            break;
        case 'e':
            if (graphic & ADISPL)
                invalid = YES;
            else
                invalid &= NOMAYBE;
            graphic |= EGA;
            posptr[0] = (union both_scr *) 0xA0000000;
            posptr[1] = (union both_scr *) 0xA8000000;
            break;
        case 'g':
            if (prtmode & PRNTR  ||  prtmode & ONEBUF)
                invalid = YES;
            switch(*(argv[i] + 2))
                {
                case '+':
                    prtmode |= BIGBOX;
                    break;
                case 'x':
                    prtmode |= XGABOX;
                    break;
                } /* end switch */
            prtmode |= PRPPDS;
            break;
#ifdef DOS
        case 'h':
            if (graphic & ADISPL)
                invalid = YES;
            else
                invalid &= NOMAYBE;
            graphic |= HMONO;
            posptr[0] = (union both_scr *) 0xB0000000;
            posptr[1] = (union both_scr *) 0xB8000000;
            break;
        case 'k':
            graphic |= F11F12;
            break;
#endif
        case 'i':
            if (graphic & ADISPL)
                invalid = YES;
            else
                invalid &= NOMAYBE;
            posptr[0] = (union both_scr *) 0xA0000000;
            if (*(argv[i] + 2) == '+')
                {
                graphic |= IBM2;
                posptr[1] = (union both_scr *) malloc(44032u);
                if (!posptr[1])
                    zfinish(NULL, no_storage);
                posptr[2] = (union both_scr *) malloc(44032u);
                if (!posptr[2])
                    zfinish(NULL, no_storage);
                } /* end then */
            else
                {
                graphic |= IBM1;
                posptr[1] = (union both_scr *) 0xA8000000;
                } /* end else */
            break;
        case 'l':
            maxlrecl[0] = atoi(argv[i] + 3);
            if (maxlrecl[0] < 10)
                {
                printf("Maximum lrecl less than ten is too small.\n");
                printf("    value /l=%d\n", maxlrecl[0]);
                zfinish(NULL, general_fail);
                } /* end then */
            maxlrecl[1] = maxlrecl[0];
            break;
        case 'm':
            if (graphic & ADISPL)
                invalid = YES;
            else
                invalid &= NOMAYBE;
            graphic |= VGA;
            graphic &= ~UCOLOR;
            posptr[0] = (union both_scr *) 0xA0000000;
            posptr[1] = (union both_scr *) malloc(44032u);
            if (!posptr[1])
                zfinish(NULL, no_storage);
            posptr[2] = (union both_scr *) malloc(44032u);
            if (!posptr[2])
                zfinish(NULL, no_storage);
            break;
        case 'n':
            if (prtmode & PRNTR)
                invalid = YES;
            prtmode |= PRONLQ;
            prtmode |= PROPRT;
            break;
        case 'o':
            if (strlen(argv[i] + 3) < PRTMAX)
                strcpy(outfile, (argv[i] + 3));
            break;
        case 'p':
            if (prtmode & PRNTR)
                invalid = YES;
            prtmode |= PROPRT;
            break;
        case 'r':
            *rightmar = atoi(argv[i] + 3);
            if (*rightmar < 16)
                *rightmar = 0;  /* will get default value */
            break;
        case 's':
            if (prtmode & PRNTR  ||  prtmode & ONEBUF)
                invalid = YES;
            prtmode |= PSCRPT;
            break;
        case 't':
            if (graphic & ADISPL)
                invalid = YES;
            else
                invalid &= NOMAYBE;
            graphic |= TEXT;
            posptr[0] = (union both_scr *) 0xB8000000;
            posptr[1] = (union both_scr *) 0xB0000000;
            break;
        case 'v':
            if (graphic & ADISPL)
                invalid = YES;
            else
                invalid &= NOMAYBE;
            graphic |= VGA;
            posptr[0] = (union both_scr *) 0xA0000000;
            posptr[1] = (union both_scr *) malloc(44032u);
            if (!posptr[1])
                zfinish(NULL, no_storage);
            posptr[2] = (union both_scr *) malloc(44032u);
            if (!posptr[2])
                zfinish(NULL, no_storage);
            break;
        case 'w':
            graphic &= ~UCOLOR;
            break;
        case 'x':
            if (graphic & ADISPL)
                invalid = YES;
            else
                invalid &= NOMAYBE;
            graphic |= XGA;
            if (*(argv[i] + 2) == 'f')
                graphic |= FXGA;
            /* allocate first 17 lines */
            posptr[0] = (union both_scr  *) malloc(61440u);
            if (!posptr[0])
                zfinish(NULL, no_storage);
            posptr[1] = (union both_scr  *) malloc(61440u);
            if (!posptr[1])
                zfinish(NULL, no_storage);
            /* allocate last 8 lines */
            posxga[0] = (union both_scr  *) malloc(34560u);
            if (!posxga[0])
                zfinish(NULL, no_storage);
            posxga[1] = (union both_scr  *) malloc(34560u);
            if (!posxga[1])
                zfinish(NULL, no_storage);
            break;
        case 'z':
            strcpy(&dsn[0] [0], (argv[i] + 3));
            invalid &= NOMAYBE;
            cmd[1] = EDITPAN;
            break;
        default:
            invalid = YES;
            break;
        } /* end switch */
    } /* end for */

if (invalid)
    {
    graphic = NO;
    inusage();
    zfinish(posptr[0], general_fail);
    } /* end then */

} /* end invcopt */
