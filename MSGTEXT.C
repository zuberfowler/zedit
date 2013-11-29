#include "zedit.h"

/**********************************************************************/
/*                                                                    */
/* Text of messages which may be displayed.                           */
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

char  msgtext[MSGMAX] [80] = {

/* CFGFGET_MSG1        0     */
{"! Unable to open zedit configuration file for output."},

/* CFGKGET_MSG1        1     */
{"! Greek character(s) defined more than once; something is left out."},

/* CFGKGET_MSG2        2     */
{"! Hebrew character(s) defined more than once; something is left\
 out."},

/* CHNGPRM_MSG1        3     */
{"! Change would make line greater than maximum logical record\
 length."},

/* CKPLACE_MSG1        4     */
{"! Line command conflict. Use reset primary command to start over."},

/* CMDLINE_MSG1        5     */
{"! Command as entered was not valid. Check spelling and syntax."},

/* EDITPAN_MSG1        6     */
{"Use TAB key to move between line command area and edit data area."},

/* ENTPANL_MSG1        7     */
{"! Print screen already in progress, please release key."},
/* ENTPANL_MSG2        8     */
{"! This is a protected field, nothing may be entered or deleted."},

/* ERASEOF_MSG1 ENTPANL_MSG2 */

/* FINDPRM_MSG1        9     */
{"! No search argument has been entered."},
/* FINDPRM_MSG2       10     */
{"Successful search."},
/* FINDPRM_MSG3       11     */
{"Search argument is not in the file."},
/* FINDPRM_MSG4       12     */
{"Search has reached bottom of data."},

/* INSCHAR_MSG1       13     */
{"! Character would be lost from screen boundary, editor in insert\
 mode."},

/* LCINVAL_MSG1       14     */
{"! Line command invalid on this line."},

/* LNECMD1_MSG1       15     */
{"! Specified shift left is greater than maximum record length, 1\
 used."},
/* LNECMD1_MSG2       16     */
{"! Repetition count may not be used with this line command."},

/* LNECMD2_MSG1       17     */
{"Character set has been changed for specified line, check for\
 errors."},
/* LNECMD2_MSG2       18     */
{"! Line command not recognized, processing has been terminated."},

/* LNECMD3_MSG1 LNECMD2_MSG1 */
/* LNECMD3_MSG2 LNECMD2_MSG2 */

/* MISCCMD_MSG1 OPTBACK_MSG3 */
/* MISCCMD_MSG2       19     */
{"! Command is only valid while in a Browse or Edit session."},

/* MOVECPY_MSG1       20     */
{"! Line command conflict, A or B specified at same time as O."},
/* MOVECPY_MSG2       21     */
{"! Block cannot be copied or moved to a point within itself."},

/* MOVEONB_MSG1       22     */
{"! More source lines than target lines, source will not be deleted."},

/* OPTBACK_MSG1       23     */
{"! Output data set did not open, edit session has not been saved."},
/* OPTBACK_MSG2       24     */
{"Data Set has been saved in disk file."},
/* OPTBACK_MSG3       25     */
{"! Command is only valid while in an Edit session."},

/* PAN2CMD_MSG1       26     */
{"! Data set did not open, check to make sure it exists."},
/* PAN2CMD_MSG2 OPTBACK_MSG3 */
/* PAN2CMD_MSG3       27     */
{"Copy command canceled."},

/* PANLCMD_MSG1 PAN2CMD_MSG1 */
/* PANLCMD_MSG2       28     */
{"! Edit data set did not open (read/write mode)."},

/* PGRKCHR_MSG1       29     */
{"! Improper Greek text, terminal sigma should not be inside of a\
 word."},
/* PGRKCHR_MSG2       30     */
{"! Sigma at end of word is not the terminal form."},

/* PHEBCHR_MSG1       31     */
{"! Dagesh is not used with Aleph, Heth, or Ayin."},
/* PHEBCHR_MSG2       32     */
{"! Raphe is not used with Aleph, He, Heth, Ayin, or Resh."},
/* PHEBCHR_MSG3       33     */
{"! Improper Hebrew text, terminal character should not be inside\
 of a word."},
/* PHEBCHR_MSG4       34     */
{"! Kaph, Mem, Nun, Pe or Sadhe non-terminal form used at end of\
 word."},

/* PRIMCMD_MSG1       35     */
{"! Command is only valid from the Primary Option Menu."},

/* PROCINP_MSG1       36     */
{"! Unsupported function or key."},
/* PROCINP_MSG2 ENTPANL_MSG2 */

/* SCRLCMD_MSG1 MISCCMD_MSG1 */
/* SCRLCMD_MSG2       37     */
{"! Locate line not found in data set, top of data displayed."},

/* SCRPRNT_MSG1       38     */
{"! Print file did not open, function aborted."},

/* SCRTBUF_MSG1       39     */
{"! Record was truncated to maximum length defined (default 258)."},

/* SHIFTRT_MSG1       40     */
{"! Right shift count has caused data loss. If unintended use CANCEL."},

/* SRCHCMD_MSG1 MISCCMD_MSG1 */
/* SRCHCMD_MSG2 OPTBACK_MSG3 */

/* SRPBUFR_MSG1       41     */
{"! Line command has caused data loss. If unintended use CANCEL."},

/* VREPCNT_MSG1       42     */
{"! Line command repetition count was not numeric."},

/* ZEDMAIN_MSG1       43     */
{"! Video display option does not support SPLIT/SWAP screen."}};
