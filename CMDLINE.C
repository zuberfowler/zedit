#include "zedit.h"

void  cmdline(
              union both_scr  *posptr,
              unsigned int  cmd[],
              char  cmdln[])
/**********************************************************************/
/*                                                                    */
/* Interpret a command entered on the command line in character       */
/* input (as opposed to a function key).                              */
/*                                                                    */
/* <<NOTE>> Whenever a new command is added, it must also be added    */
/* to cfgfpan if it is to be allowed on a function key.               */
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
register int  c = 0;
char  command[CMDLEN];


/* get rid of PRECDR & SRP indicators */
cmdln[0] = ' ';
cmdln[1] = ' ';

/* initialize */
cmd[c] = NOP;

if (!leftjust(cmdln))
    return;

cmdprse(command, cmdln);
lower(command);

/* implement return-immediate function */
if (command[c] == '=')
    {
    cmd[c++] = RETURN;
    cmd[c] = NOP;
    } /* end then */

switch(command[c])
    {
    case '0':
        cmd[c] = CONFIG;
        break;
    case '1':
        cmd[c] = BROWSE;
        break;
    case '2':
        cmd[c] = EDIT;
        break;
    case '5':
        switch(command[c+1])
            {
            case '1':
                cmd[c] = IMPGRK;
                break;
            case '2':
                cmd[c] = IMPHEB;
                break;
            case '3':
                cmd[c] = EXPGRK;
                break;
            case '4':
                cmd[c] = EXPHEB;
                break;
            case '6':
                cmd[c] = EXPHHI;
                break;
            } /* end switch */
        break;
    case 'b':
        switch(command[1])
            {
            case 'a':  /* BACK */
                cmd[c] = LEFT;
                break;
            case 'o':  /* BOTTOM alias DOWN Max */
                cmd[c] = DOWN;
                if (!leftjust(cmdln))
                    cmdln[0] = 'm';
                break;
            case 'r':
                cmd[c] = BROWSE;
                break;
            } /* end switch */
        break;
    case 'c':
        switch(command[1])
            {
            case '\0':
                cmd[c] = CHANGE;
                break;
            case 'a':
                cmd[c] = CANCEL;
                break;
            case 'h':
                cmd[c] = CHANGE;
                break;
            case 'o':
                switch(command[2])
                    {
                    case 'l':  /* COLS or COLUMNS */
                        cmd[c] = COLMS;
                        break;
                    case 'n':
                        cmd[c] = CONFIG;
                        break;
                    case 'p':
                        cmd[c] = COPY;
                        break;
                    } /* end switch */
                break;
            case 'r':  /* alias CREATE */
                cmd[c] = REPLACE;
                break;
            case 'u':
                cmd[c] = CURSOR;
                break;
            } /* end switch */
        break;
    case 'd':
        switch(command[1])
            {
            case 'e':
                if (command[2] == 'l')
                    {
                    do  {
                        leftjust(cmdln);
                        cmdprse(command, cmdln);
                        lower(command);
                        } while(command[0] == 'a');
                    switch(command[0])
                        {
                        case 'n':
                            if (command[1] == 'x')
                                cmd[c] = DELNX;
                            break;
                        case 'x':
                            cmd[c] = DELX;
                            break;
                        } /* end switch */
                    } /* end then */
                break;
            case 'o':
                cmd[c] = DOWN;
                break;
            } /* end switch */
        break;
    case 'e':
        switch(command[1])
            {
            case 'd':
                cmd[c] = EDIT;
                break;
            case 'n':
                cmd[c] = END;
                break;
            case 'r':
                cmd[c] = ERASEEOF;
                break;
            case 'x':
                switch(command[2])
                    {
                    case 'i':
                        cmd[c] = EXITSYS;
                        break;
                    case 'p':
                        switch(command[3])
                            {
                            case 'g':
                                cmd[c] = EXPGRK;
                                break;
                            case 'h':
                                if (command[4] == 'h')
                                    cmd[c] = EXPHHI;
                                else
                                    cmd[c] = EXPHEB;
                                break;
                            } /* end switch */
                        break;
                    } /* end switch */
                break;
            } /* end switch */
        break;
    case 'f':
        switch(command[1])
            {
            case '\0':
                cmd[c] = FIND;
                break;
            case 'i':
                switch(command[2])
                    {
                    case 'l':  /* FILE */
                        cmd[c] = END;
                        break;
                    case 'n':
                        cmd[c] = FIND;
                        break;
                    } /* end switch */
                break;
            } /* end switch */
        break;
    case 'g':
        switch(command[1])
            {
            case 'e':  /* GET */
                cmd[c] = COPY;
                break;
            case 'r':
                cmd[c] = GREEK;
                break;
            } /* end switch */
        break;
    case 'h':
        switch(command[1])
            {
            case 'e':
                switch(command[2])
                    {
                    case 'b':
                        cmd[c] = HEBREW;
                        break;
                    case 'l':
                        cmd[c] = HELP;
                        break;
                    } /* end switch */
                break;
            } /* end switch */
        break;
    case 'i':
        switch(command[1])
            {
            case 'm':
                switch(command[2])
                    {
                    case 'p':
                        switch(command[3])
                            {
                            case 'g':
                                cmd[c] = IMPGRK;
                                break;
                            case 'h':
                                cmd[c] = IMPHEB;
                                break;
                            } /* end switch */
                        break;
                    } /* end switch */
                break;
            } /* end switch */
        break;
    case 'k':
        cmd[c] = KEYS;
        break;
    case 'l':
        switch(command[1])
            {
            case 'a':
                cmd[c] = LATIN;
                break;
            case 'e':
                switch(command[2])
                    {
                    case 'f':
                        cmd[c] = LEFT;
                        break;
                    case 't':
                        cmd[c] = LETS;
                        break;
                    } /* end switch */
                break;
            case 'i':  /* LIST */
                cmd[c] = LOCATE;
                break;
            case 'o':
                cmd[c] = LOCATE;
                break;
            } /* end switch */
        break;
    case 'o': /* OVER */
        cmd[c] = RIGHT;
        break;
    case 'p':
        switch(command[1])
            {
            case 'r':
                cmd[c] = PRINT;
                break;
            case 'u':  /* PUT */
                cmd[c] = REPLACE;
                break;
            } /* end switch */
        break;
    case 'q':
        cmd[c] = CANCEL;
        break;
    case 'r':
        switch(command[1])
            {
            case 'e':
                switch(command[2])
                    {
                    case 'f':
                        cmd[c] = REFRESH;
                        break;
                    case 'g':
                        cmd[c] = REGULAR;
                        break;
                    case 'p':
                        cmd[c] = REPLACE;
                        break;
                    case 's':
                        cmd[c] = RESET;
                        break;
                    case 't':
                        cmd[c] = RETURN;
                        break;
                    case 'v':
                        cmd[c] = REVERSE;
                        break;
                    } /* end switch */
                break;
            case 'i':
                cmd[c] = RIGHT;
                break;
            case 't':
                cmd[c] = RTAB;
                break;
            } /* end switch */
        break;
    case 's':
        switch(command[1])
            {
            case 'a':
                cmd[c] = SAVE;
                break;
            case 'p':
                switch(command[2])
                    {
                    case 'e':
                        cmd[c] = SPECIAL;
                        break;
                    case 'l':  /* alias SPLIT */
                        cmd[c] = SWAP;
                        break;
                    } /* end switch */
                break;
            case 'w':
                cmd[c] = SWAP;
                break;
            case 'y':  /* alias SYSTEM */
                cmd[c] = EXITSYS;
                break;
            } /* end switch */
        break;
    case 't':  /* TOP alias UP Max */
        cmd[c] = UP;
        if (!leftjust(cmdln))
            cmdln[0] = 'm';
        break;
    case 'u':
        cmd[c] = UP;
        break;
    case 'x':
        if (c)
            cmd[c] = EXITSYS;
        else
            cmd[c] = XXITSYS;
        break;
    } /* end switch */

if (cmd[c] == NOP)
    dispmsg(posptr, CMDLINE_MSG1);

} /* end cmdline */
