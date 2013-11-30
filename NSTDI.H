/**********************************************************************/
/*                                                                    */
/* nstdi program header (non standard input).                         */
/* This header depends on compiler values established in total.h.     */
/*                                                                    */
/**********************************************************************/
/*                                                                    */
/* This is ZEDIT source material.                                     */
/*                                                                    */
/* ZEDIT Source Materials are intellectual property                   */
/*     (c) Copyright 1987,2001 by Clyde Thomas Zuber.                 */
/*                                                                    */
/**********************************************************************/

#ifdef TC
#define sysint  int86
#endif

#ifdef MSC
#define sysint  int86
#endif

/* flag value for getinpt (also graphic flag in nstdo.h) */
#define F11F12 0x2000u /* enhanced keyboard available */

/* ascii input characters */
#define  B_S             0x0008
#define  HORZ_TAB        0x0009
#define  LINE_FEED       0x000A
#define  C_RETURN        0x000D
#define  CNTL_U          0x0015
#define  ESC             0x001B
#define  CNTL_UNDERLINE  0x001F

/* keyboard key scan values */
#define  ESCAPE          0x0001
#define  BACKSPACE       0x000E
#define  TAB_KEY         0x000F
#define  RETURN_KEY      0x001C
#define  PRTSC           0x0037

#define  F1         0x003B
#define  F2         0x003C
#define  F3         0x003D
#define  F4         0x003E
#define  F5         0x003F
#define  F6         0x0040
#define  F7         0x0041
#define  F8         0x0042
#define  F9         0x0043
#define  F10        0x0044

#define  HOME          0x0047
#define  UP_ARROW      0x0048
#define  PGUP          0x0049
#define  LEFT_ARROW    0x004B
#define  RIGHT_ARROW   0x004D
#define  END_KEY       0x004F
#define  DOWN_ARROW    0x0050
#define  PGDOWN        0x0051
#define  INS           0x0052
#define  DEL           0x0053

#define  SHIFT_F1   0x0054
#define  SHIFT_F2   0x0055
#define  SHIFT_F3   0x0056
#define  SHIFT_F4   0x0057
#define  SHIFT_F5   0x0058
#define  SHIFT_F6   0x0059
#define  SHIFT_F7   0x005A
#define  SHIFT_F8   0x005B
#define  SHIFT_F9   0x005C
#define  SHIFT_F10  0x005D

#define  CNTL_F1    0x005E
#define  CNTL_F2    0x005F
#define  CNTL_F3    0x0060
#define  CNTL_F4    0x0061
#define  CNTL_F5    0x0062
#define  CNTL_F6    0x0063
#define  CNTL_F7    0x0064
#define  CNTL_F8    0x0065
#define  CNTL_F9    0x0066
#define  CNTL_F10   0x0067

#define  ALT_F1     0x0068
#define  ALT_F2     0x0069
#define  ALT_F3     0x006A
#define  ALT_F4     0x006B
#define  ALT_F5     0x006C
#define  ALT_F6     0x006D
#define  ALT_F7     0x006E
#define  ALT_F8     0x006F
#define  ALT_F9     0x0070
#define  ALT_F10    0x0071

#define  FLEFT_ARROW   0x0073
#define  FRIGHT_ARROW  0x0074
#define  CNTL_END      0x0075
#define  CNTL_PGDOWN   0x0076
#define  CNTL_PGUP     0x0084

#define  F11        0x0085
#define  F12        0x0086
#define  SHIFT_F11  0x0087
#define  SHIFT_F12  0x0088
#define  CNTL_F11   0x0089
#define  CNTL_F12   0x008A
#define  ALT_F11    0x008B
#define  ALT_F12    0x008C

#define  FUP_ARROW     0x008D
#define  FDOWN_ARROW   0x0091
#define  CNTL_DEL      0x0093
#define  KEYPAD_RETURN 0x00E0

/* shift flag masks */
#define  LOCK_MASK    0xF0u
#define  SHIFT_MASK   0x0Fu
#define  BOTH_SHIFT   0x03u
/* pass special flag in shift */
#define  EXCLMSG      0x0Fu

/* shift flag codes */
#define  RIGHT_SHIFT  0x01u
#define  LEFT_SHIFT   0x02u
#define  CNTL_KEY     0x04u
#define  ALT_KEY      0x08u
#define  SCROLL_LOCK  0x10u
#define  NUM_LOCK     0x20u
#define  CAPS_LOCK    0x40u
#define  INS_LOCK     0x80u

/* word registers */

struct regs_word
    {
    unsigned short  ax;
    unsigned short  bx;
    unsigned short  cx;
    unsigned short  dx;
    unsigned short  rc_si;
    unsigned short  rc_di;
    unsigned short  rc_ds;
    unsigned short  rc_es;
    };

/* byte registers */

struct regs_char
    {
    char  al, ah;
    char  bl, bh;
    char  cl, ch;
    char  dl, dh;
    };

/* general purpose registers union */
/* overlays the corresponding word and byte registers */

union regs_both
    {
    struct regs_word  x;
    struct regs_char  h;
    };

extern int LINKMSC  sysint(int interupt, union regs_both *inregs,
    union regs_both *outregs);
