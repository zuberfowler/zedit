# ZEDITMK1.MAK - Zedit make file.  Requires ZEDITCMP.CMD

$(ZED).EXE:  ascchar.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+ascchar;
    del ascchar.obj

$(ZED).EXE:  backcmd.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+backcmd;
    del backcmd.obj

$(ZED).EXE:  browpan.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+browpan;
    del browpan.obj

$(ZED).EXE:  buftscr.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+buftscr;
    del buftscr.obj

$(ZED).EXE:  buftsln.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+buftsln;
    del buftsln.obj

$(ZED).EXE:  cfgfget.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+cfgfget;
    del cfgfget.obj

$(ZED).EXE:  cfgfpan.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+cfgfpan;
    del cfgfpan.obj

$(ZED).EXE:  cfginit.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+cfginit;
    del cfginit.obj

$(ZED).EXE:  cfgkget.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+cfgkget;
    del cfgkget.obj

$(ZED).EXE:  cfgkpan.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+cfgkpan;
    del cfgkpan.obj

$(ZED).EXE:  chngprm.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+chngprm;
    del chngprm.obj

$(ZED).EXE:  ckplace.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+ckplace;
    del ckplace.obj

$(ZED).EXE:  clrline.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+clrline;
    del clrline.obj

$(ZED).EXE:  clrlxga.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+clrlxga;
    del clrlxga.obj

$(ZED).EXE:  clrpanl.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+clrpanl;
    del clrpanl.obj

$(ZED).EXE:  cmddone.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+cmddone;
    del cmddone.obj

$(ZED).EXE:  cmdline.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+cmdline;
    del cmdline.obj

$(ZED).EXE:  cmdparm.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+cmdparm;
    del cmdparm.obj

$(ZED).EXE:  cmdprse.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+cmdprse;
    del cmdprse.obj

$(ZED).EXE:  cmdrest.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+cmdrest;
    del cmdrest.obj

$(ZED).EXE:  cmdtxts.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+cmdtxts;
    del cmdtxts.obj

$(ZED).EXE:  cmdvals.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+cmdvals;
    del cmdvals.obj

$(ZED).EXE:  cmpline.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+cmpline;
    del cmpline.obj

$(ZED).EXE:  colslin.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+colslin;
    del colslin.obj

$(ZED).EXE:  convinp.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+convinp;
    del convinp.obj

$(ZED).EXE:  convout.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+convout;
    del convout.obj

$(ZED).EXE:  copylin.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+copylin;
    del copylin.obj

$(ZED).EXE:  copyonb.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+copyonb;
    del copyonb.obj

$(ZED).EXE:  ddelblk.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+ddelblk;
    del ddelblk.obj

$(ZED).EXE:  delchar.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+delchar;
    del delchar.obj

$(ZED).EXE:  delnexc.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+delnexc;
    del delnexc.obj

$(ZED).EXE:  delprot.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+delprot;
    del delprot.obj

$(ZED).EXE:  delxblk.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+delxblk;
    del delxblk.obj

$(ZED).EXE:  dispchr.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+dispchr;
    del dispchr.obj

$(ZED).EXE:  displin.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+displin;
    del displin.obj

$(ZED).EXE:  dispmsg.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+dispmsg;
    del dispmsg.obj

$(ZED).EXE:  dispnum.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+dispnum;
    del dispnum.obj

$(ZED).EXE:  ds8cib2.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+ds8cib2;
    del ds8cib2.obj

$(ZED).EXE:  ds8cibm.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+ds8cibm;
    del ds8cibm.obj

$(ZED).EXE:  ds8cxga.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+ds8cxga;
    del ds8cxga.obj

$(ZED).EXE:  ds8lib2.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+ds8lib2;
    del ds8lib2.obj

$(ZED).EXE:  ds8libm.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+ds8libm;
    del ds8libm.obj

$(ZED).EXE:  ds8lxga.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+ds8lxga;
    del ds8lxga.obj

$(ZED).EXE:  dsentry.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+dsentry;
    del dsentry.obj

$(ZED).EXE:  dsp8chr.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+dsp8chr;
    del dsp8chr.obj

$(ZED).EXE:  dsp8lin.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+dsp8lin;
    del dsp8lin.obj

$(ZED).EXE:  dspcib2.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+dspcib2;
    del dspcib2.obj

$(ZED).EXE:  dspcibm.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+dspcibm;
    del dspcibm.obj

$(ZED).EXE:  dspcxga.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+dspcxga;
    del dspcxga.obj

$(ZED).EXE:  dsplib2.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+dsplib2;
    del dsplib2.obj

$(ZED).EXE:  dsplibm.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+dsplibm;
    del dsplibm.obj

$(ZED).EXE:  dsplxga.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+dsplxga;
    del dsplxga.obj

$(ZED).EXE:  edbrpan.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+edbrpan;
    del edbrpan.obj

$(ZED).EXE:  editpan.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+editpan;
    del editpan.obj

$(ZED).EXE:  entpanl.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+entpanl;
    del entpanl.obj

$(ZED).EXE:  eraseof.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+eraseof;
    del eraseof.obj

$(ZED).EXE:  exclude.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+exclude;
    del exclude.obj

$(ZED).EXE:  excmerg.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+excmerg;
    del excmerg.obj

$(ZED).EXE:  excrdsp.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+excrdsp;
    del excrdsp.obj

$(ZED).EXE:  excremv.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+excremv;
    del excremv.obj

$(ZED).EXE:  excshow.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+excshow;
    del excshow.obj

$(ZED).EXE:  excxblk.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+excxblk;
    del excxblk.obj

$(ZED).EXE:  fillscr.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+fillscr;
    del fillscr.obj

$(ZED).EXE:  findprm.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+findprm;
    del findprm.obj

$(ZED).EXE:  fkeyset.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+fkeyset;
    del fkeyset.obj

$(ZED).EXE:  freebuf.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+freebuf;
    del freebuf.obj

$(ZED).EXE:  funckey.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+funckey;
    del funckey.obj

$(ZED).EXE:  getfile.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+getfile;
    del getfile.obj

$(ZED).EXE:  getstrt.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+getstrt;
    del getstrt.obj

$(ZED).EXE:  grphreg.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+grphreg;
    del grphreg.obj

$(ZED).EXE:  grkchar.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+grkchar;
    del grkchar.obj

$(ZED).EXE:  grkexch.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+grkexch;
    del grkexch.obj

$(ZED).EXE:  hebchar.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+hebchar;
    del hebchar.obj

$(ZED).EXE:  hebexch.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+hebexch;
    del hebexch.obj

$(ZED).EXE:  hebhiex.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+hebhiex;
    del hebhiex.obj

$(ZED).EXE:  helpedt.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+helpedt;
    del helpedt.obj

$(ZED).EXE:  helpgen.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+helpgen;
    del helpgen.obj

$(ZED).EXE:  inschar.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+inschar;
    del inschar.obj

$(ZED).EXE:  inusage.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+inusage;
    del inusage.obj

$(ZED).EXE:  invcopt.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+invcopt;
    del invcopt.obj

$(ZED).EXE:  keyslin.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+keyslin;
    del keyslin.obj

$(ZED).EXE:  lastsrp.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+lastsrp;
    del lastsrp.obj

$(ZED).EXE:  lcinval.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+lcinval;
    del lcinval.obj

$(ZED).EXE:  letsgrk.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+letsgrk;
    del letsgrk.obj

$(ZED).EXE:  letsheb.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+letsheb;
    del letsheb.obj

$(ZED).EXE:  letslin.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+letslin;
    del letslin.obj

$(ZED).EXE:  linecmd.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+linecmd;
    del linecmd.obj

$(ZED).EXE:  lnecmd1.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+lnecmd1;
    del lnecmd1.obj

$(ZED).EXE:  lnecmd2.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+lnecmd2;
    del lnecmd2.obj

$(ZED).EXE:  lnecmd3.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+lnecmd3;
    del lnecmd3.obj

$(ZED).EXE:  loclcmd.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+loclcmd;
    del loclcmd.obj
