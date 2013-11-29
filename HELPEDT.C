#include "zedit.h"

/**********************************************************************/
/*                                                                    */
/* Help panel scrollable text.                                        */
/*                                                                    */
/**********************************************************************/
/*                                                                    */
/* This is ZEDIT source material.                                     */
/*                                                                    */
/* ZEDIT Source Materials are intellectual property                   */
/*     (c) Copyright 1987,2001 by Clyde Thomas Zuber.                 */
/*                                                                    */
/**********************************************************************/
#ifdef DATASEG
#pragma data_seg(ZEDRODAT)
#endif


struct bufhelp  helpedt[36] = {

{NULL, &(helpedt[1]), {"*******"}, BUF_ASCII, ST_HELPSCRL,
{"************************  Top of help text  *************************"
 }},

{&(helpedt[0]), &(helpedt[2]), {"<<<|>>>"}, BUF_ASCII, ST_HELPSCRL,
{"Edit Line Commands     (use U/l case, n is optional numeric digit)"}},

{&(helpedt[1]), &(helpedt[3]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"                                                                  "}},

{&(helpedt[2]), &(helpedt[4]), {"(n     "}, BUF_ASCII, ST_HELPSCRL,
{"Shift left n columns.                                             "}},

{&(helpedt[3]), &(helpedt[5]), {"((n    "}, BUF_ASCII, ST_HELPSCRL,
{"Block shift left n columns.                                       "}},

{&(helpedt[4]), &(helpedt[6]), {")n     "}, BUF_ASCII, ST_HELPSCRL,
{"Shift right n columns.                                            "}},

{&(helpedt[5]), &(helpedt[7]), {"))n    "}, BUF_ASCII, ST_HELPSCRL,
{"Block shift right n columns.                                      "}},

{&(helpedt[6]), &(helpedt[8]), {"A      "}, BUF_ASCII, ST_HELPSCRL,
{"After, used with copy and move commands.                          "}},

{&(helpedt[7]), &(helpedt[9]), {"B      "}, BUF_ASCII, ST_HELPSCRL,
{"Before, used with copy and move commands.                         "}},

{&(helpedt[8]), &(helpedt[10]), {"Cn     "}, BUF_ASCII, ST_HELPSCRL,
{"Copy n lines.                                                     "}},

{&(helpedt[9]), &(helpedt[11]), {"CC     "}, BUF_ASCII, ST_HELPSCRL,
{"Mark beginning and end of a block of lines to be copied.          "}},

{&(helpedt[10]), &(helpedt[12]), {"COLS   "}, BUF_ASCII, ST_HELPSCRL,
{"Display a column marker help line before this line.               "}},

{&(helpedt[11]), &(helpedt[13]), {"Dn     "}, BUF_ASCII, ST_HELPSCRL,
{"Delete n lines.                                                   "}},

{&(helpedt[12]), &(helpedt[14]), {"DD     "}, BUF_ASCII, ST_HELPSCRL,
{"Mark beginning and end of a block of lines to be deleted.         "}},

{&(helpedt[13]), &(helpedt[15]), {"Fn     "}, BUF_ASCII, ST_HELPSCRL,
{"Redisplay First n lines of an excluded block.                     "}},

{&(helpedt[14]), &(helpedt[16]), {"GR     "}, BUF_ASCII, ST_HELPSCRL,
{"Corrects a line with broken script type to GReek.                 "}},

{&(helpedt[15]), &(helpedt[17]), {"HE     "}, BUF_ASCII, ST_HELPSCRL,
{"Corrects a line with broken script type to HEbrew.                "}},

{&(helpedt[16]), &(helpedt[18]), {"In     "}, BUF_ASCII, ST_HELPSCRL,
{"Insert n lines following this line.                               "}},

{&(helpedt[17]), &(helpedt[19]), {"KEYS   "}, BUF_ASCII, ST_HELPSCRL,
{"Display the function key values on a help line.                   "}},

{&(helpedt[18]), &(helpedt[20]), {"Ln     "}, BUF_ASCII, ST_HELPSCRL,
{"Redisplay Last n lines of an excluded block.                      "}},

{&(helpedt[19]), &(helpedt[21]), {"LA     "}, BUF_ASCII, ST_HELPSCRL,
{"Corrects a line with broken script type to LAtin.                 "}},

{&(helpedt[20]), &(helpedt[22]), {"LETS   "}, BUF_ASCII, ST_HELPSCRL,
{"Display the keyboard symbolic correspondence on a help line.      "}},

{&(helpedt[21]), &(helpedt[23]), {"Mn     "}, BUF_ASCII, ST_HELPSCRL,
{"Move n lines.                                                     "}},

{&(helpedt[22]), &(helpedt[24]), {"MM     "}, BUF_ASCII, ST_HELPSCRL,
{"Mark beginning and end of a block of lines to be moved.           "}},

{&(helpedt[23]), &(helpedt[25]), {"On     "}, BUF_ASCII, ST_HELPSCRL,
{"Copy or move indicated line(s) Onto this/these n line(s).         "}},

{&(helpedt[24]), &(helpedt[26]), {"OO     "}, BUF_ASCII, ST_HELPSCRL,
{"Mark beginning and end of a block for an Onto copy or move.       "}},

{&(helpedt[25]), &(helpedt[27]), {"RE     "}, BUF_ASCII, ST_HELPSCRL,
{"Corrects a line with broken script type to REgular.               "}},

{&(helpedt[26]), &(helpedt[28]), {"Rn     "}, BUF_ASCII, ST_HELPSCRL,
{"Repeat line n times.                                              "}},

{&(helpedt[27]), &(helpedt[29]), {"RRn    "}, BUF_ASCII, ST_HELPSCRL,
{"Mark beg. & end of a block of lines to be Repeated n times.       "}},

{&(helpedt[28]), &(helpedt[30]), {"Sn     "}, BUF_ASCII, ST_HELPSCRL,
{"Show (redisplay) first n lines of an excluded block.              "}},

{&(helpedt[29]), &(helpedt[31]), {"SP     "}, BUF_ASCII, ST_HELPSCRL,
{"Corrects a line with broken script type to SPecial.               "}},

{&(helpedt[30]), &(helpedt[32]), {"TF     "}, BUF_ASCII, ST_HELPSCRL,
{"Text Flow. (Currently not implemented, use Move with On).         "}},

{&(helpedt[31]), &(helpedt[33]), {"TS     "}, BUF_ASCII, ST_HELPSCRL,
{"Text Split. (Currently not implemented, use Repeat and del).      "}},

{&(helpedt[32]), &(helpedt[34]), {"Xn     "}, BUF_ASCII, ST_HELPSCRL,
{"EXclude n lines from being displayed.                             "}},

{&(helpedt[33]), &(helpedt[35]), {"XX     "}, BUF_ASCII, ST_HELPSCRL,
{"Mark beginning and end of a block of lines to be eXcluded.        "}},

{&(helpedt[34]), NULL, {"*******"}, BUF_ASCII, ST_HELPSCRL,
{"************************  End of help text  *************************"
}}};
