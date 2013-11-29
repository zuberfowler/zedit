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


struct bufhelp  helpgen[44] = {

{NULL, &(helpgen[1]), {"*******"}, BUF_ASCII, ST_HELPSCRL,
{"************************  Top of help text  *************************"
}},

{&(helpgen[0]), &(helpgen[2]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"Commonly Used Primary Commands ===> _(Caps to minimum abreviation)"}},

{&(helpgen[1]), &(helpgen[3]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"                                                                  "}},

{&(helpgen[2]), &(helpgen[4]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"BAck - Scroll screen columns to the beginning of the lines.       "}},

{&(helpgen[3]), &(helpgen[5]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"BOttom - Alias for DOWN MAX.                                      "}},

{&(helpgen[4]), &(helpgen[6]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"CAncel - Quit the edit session.  Do NOT save changes.             "}},

{&(helpgen[5]), &(helpgen[7]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"Change x y - Change the string x to the string y in the file.     "}},

{&(helpgen[6]), &(helpgen[8]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"COLumns - Display a column help line on the first line of screen. "}},

{&(helpgen[7]), &(helpgen[9]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"COPy - Get a file and copy it into this one (see A/B line cmds).  "}},

{&(helpgen[8]), &(helpgen[10]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"DELete [X/NX] - Delete all eXcluded or all Not eXcluded lines.    "}},

{&(helpgen[9]), &(helpgen[11]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"DOwn - Scroll the screen display forward or down in the file.     "}},

{&(helpgen[10]), &(helpgen[12]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"ENd - End the edit or browse session.  Save any changes.          "}},

{&(helpgen[11]), &(helpgen[13]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"Find x - Find the string x in the file.                           "}},

{&(helpgen[12]), &(helpgen[14]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"GReek - Switch to the Greek character set.                        "}},

{&(helpgen[13]), &(helpgen[15]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"HEBrew - Switch to the Hebrew character set.                      "}},

{&(helpgen[14]), &(helpgen[16]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"Keys - Display the function key settings on a help line.          "}},

{&(helpgen[15]), &(helpgen[17]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"LAtin - Switch to the Latin character set.                        "}},

{&(helpgen[16]), &(helpgen[18]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"LEFt - Scroll screen columns to the beginning of the lines.       "}},

{&(helpgen[17]), &(helpgen[19]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"LETters - Display the symbolic correspondence for the keyboard.   "}},

{&(helpgen[18]), &(helpgen[20]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"LOcate n - Scroll file to the numeric line number n.              "}},

{&(helpgen[19]), &(helpgen[21]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"Over - Scroll screen columns toward the end of the lines.         "}},

{&(helpgen[20]), &(helpgen[22]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"PRint - Print the entire file being edited or browsed.            "}},

{&(helpgen[21]), &(helpgen[23]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"REGular - Switch to the regular character set.                    "}},

{&(helpgen[22]), &(helpgen[24]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"REPlace - Save edit session specifying different file.            "}},

{&(helpgen[23]), &(helpgen[25]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"RESet - Cancel/erase pending line commands and/or error message.  "}},

{&(helpgen[24]), &(helpgen[26]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"REVerse - Change the direction of text entry.                     "}},

{&(helpgen[25]), &(helpgen[27]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"Right - Scroll screen columns toward the end of the lines.        "}},

{&(helpgen[26]), &(helpgen[28]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"SAve - Write the edit session changes to the file on the disk.    "}},

{&(helpgen[27]), &(helpgen[29]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"SPEcial - Switch to the special character set.                    "}},

{&(helpgen[28]), &(helpgen[30]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"SWap - Display the alternate screen area.                         "}},

{&(helpgen[29]), &(helpgen[31]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"Top - Alias for UP MAX.                                           "}},

{&(helpgen[30]), &(helpgen[32]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"Up - Scroll the screen display backward or up in the file.        "}},

{&(helpgen[31]), &(helpgen[33]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"                                                                  "}},

{&(helpgen[32]), &(helpgen[34]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"*******  Behavior of Some Important Keyboard Control Keys  *******"}},

{&(helpgen[33]), &(helpgen[35]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"<--| Enter or Return - This key is context sensitive and operates "}},

{&(helpgen[34]), &(helpgen[36]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"     as both NEWLINE and ENTER.  If default action is NEWLINE,    "}},

{&(helpgen[35]), &(helpgen[37]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"     then CTRL in combination with this key must be used to signal"}},

{&(helpgen[36]), &(helpgen[38]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"     ENTER.                                                       "}},

{&(helpgen[37]), &(helpgen[39]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"Esc - This key functions the same as the End primary command.     "}},

{&(helpgen[38]), &(helpgen[40]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"Print Screen and * on keypad of enhanced keyboard - Please refer  "}},

{&(helpgen[39]), &(helpgen[41]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"     to the Zedit documentation which describes this function.    "}},

{&(helpgen[40]), &(helpgen[42]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"|<-- and -->| Tab - The tab control keys must be used to switch   "}},

{&(helpgen[41]), &(helpgen[43]), {"       "}, BUF_ASCII, ST_HELPSCRL,
{"     between screen fields in Zedit.  CTRL-U may also be used.    "}},

{&(helpgen[42]), NULL, {"*******"}, BUF_ASCII, ST_HELPSCRL,
{"************************  End of help text  *************************"
}}};
