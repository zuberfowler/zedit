# ZEDITMK2.MAK - Zedit make file.  Requires ZEDITCMP.CMD

$(ZED).EXE:  mergeon.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+mergeon;
    del mergeon.obj

$(ZED).EXE:  misccmd.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+misccmd;
    del misccmd.obj

$(ZED).EXE:  movelin.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+movelin;
    del movelin.obj

$(ZED).EXE:  moveonb.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+moveonb;
    del moveonb.obj

$(ZED).EXE:  movecpy.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+movecpy;
    del movecpy.obj

$(ZED).EXE:  msgtext.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+msgtext;
    del msgtext.obj

$(ZED).EXE:  optback.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+optback;
    del optback.obj

$(ZED).EXE:  ov8cib2.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+ov8cib2;
    del ov8cib2.obj

$(ZED).EXE:  ov8cibm.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+ov8cibm;
    del ov8cibm.obj

$(ZED).EXE:  ov8cxga.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+ov8cxga;
    del ov8cxga.obj

$(ZED).EXE:  overchr.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+overchr;
    del overchr.obj

$(ZED).EXE:  ovr8chr.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+ovr8chr;
    del ovr8chr.obj

$(ZED).EXE:  ovrcib2.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+ovrcib2;
    del ovrcib2.obj

$(ZED).EXE:  ovrcibm.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+ovrcibm;
    del ovrcibm.obj

$(ZED).EXE:  ovrcxga.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+ovrcxga;
    del ovrcxga.obj

$(ZED).EXE:  pan2cmd.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+pan2cmd;
    del pan2cmd.obj

$(ZED).EXE:  panlcmd.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+panlcmd;
    del panlcmd.obj

$(ZED).EXE:  pascchr.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+pascchr;
    del pascchr.obj

$(ZED).EXE:  pgrkchr.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+pgrkchr;
    del pgrkchr.obj

$(ZED).EXE:  phebchr.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+phebchr;
    del phebchr.obj

$(ZED).EXE:  platchr.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+platchr;
    del platchr.obj

$(ZED).EXE:  primary.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+primary;
    del primary.obj

$(ZED).EXE:  primcmd.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+primcmd;
    del primcmd.obj

$(ZED).EXE:  procedt.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+procedt;
    del procedt.obj

$(ZED).EXE:  procinp.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+procinp;
    del procinp.obj

$(ZED).EXE:  procscn.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+procscn;
    del procscn.obj

$(ZED).EXE:  promchr.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+promchr;
    del promchr.obj

$(ZED).EXE:  protlin.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+protlin;
    del protlin.obj

$(ZED).EXE:  pshstck.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+pshstck;
    del pshstck.obj

$(ZED).EXE:  rdspasc.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+rdspasc;
    del rdspasc.obj

$(ZED).EXE:  rdspgrk.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+rdspgrk;
    del rdspgrk.obj

$(ZED).EXE:  rdspheb.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+rdspheb;
    del rdspheb.obj

$(ZED).EXE:  rdsplat.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+rdsplat;
    del rdsplat.obj

$(ZED).EXE:  rdsplin.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+rdsplin;
    del rdsplin.obj

$(ZED).EXE:  rdsprom.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+rdsprom;
    del rdsprom.obj

$(ZED).EXE:  readbuf.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+readbuf;
    del readbuf.obj

$(ZED).EXE:  renbufr.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+renbufr;
    del renbufr.obj

$(ZED).EXE:  revchar.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+revchar;
    del revchar.obj

$(ZED).EXE:  revcib2.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+revcib2;
    del revcib2.obj

$(ZED).EXE:  revcibm.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+revcibm;
    del revcibm.obj

$(ZED).EXE:  revcxga.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+revcxga;
    del revcxga.obj

$(ZED).EXE:  revline.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+revline;
    del revline.obj

$(ZED).EXE:  revlxga.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+revlxga;
    del revlxga.obj

$(ZED).EXE:  rhebrew.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+rhebrew;
    del rhebrew.obj

$(ZED).EXE:  rrepblk.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+rrepblk;
    del rrepblk.obj

$(ZED).EXE:  scrlcmd.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+scrlcmd;
    del scrlcmd.obj

$(ZED).EXE:  scrpesc.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+scrpesc;
    del scrpesc.obj

$(ZED).EXE:  scrprnt.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+scrprnt;
    del scrprnt.obj

$(ZED).EXE:  scrpxga.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+scrpxga;
    del scrpxga.obj

$(ZED).EXE:  scrtbuf.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+scrtbuf;
    del scrtbuf.obj

$(ZED).EXE:  shiftlf.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+shiftlf;
    del shiftlf.obj

$(ZED).EXE:  shiftrt.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+shiftrt;
    del shiftrt.obj

$(ZED).EXE:  srchcmd.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+srchcmd;
    del srchcmd.obj

$(ZED).EXE:  srpbufr.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+srpbufr;
    del srpbufr.obj

$(ZED).EXE:  statlin.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+statlin;
    del statlin.obj

$(ZED).EXE:  stckcmd.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+stckcmd;
    del stckcmd.obj

$(ZED).EXE:  textreg.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+textreg;
    del textreg.obj

$(ZED).EXE:  topline.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+topline;
    del topline.obj

$(ZED).EXE:  tranheb.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+tranheb;
    del tranheb.obj

$(ZED).EXE:  transcr.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+transcr;
    del transcr.obj

$(ZED).EXE:  txtonly.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+txtonly;
    del txtonly.obj

$(ZED).EXE:  vrepcnt.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+vrepcnt;
    del vrepcnt.obj

$(ZED).EXE:  wrtebuf.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+wrtebuf;
    del wrtebuf.obj

$(ZED).EXE:  xga8514.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+xga8514;
    del xga8514.obj

$(ZED).EXE:  zdriver.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zdriver;
    del zdriver.obj

$(ZED).EXE:  zedascb.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedascb;
    del zedascb.obj

$(ZED).EXE:  zedasct.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedasct;
    del zedasct.obj

$(ZED).EXE:  zedgrkb.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedgrkb;
    del zedgrkb.obj

$(ZED).EXE:  zedgrkt.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedgrkt;
    del zedgrkt.obj

$(ZED).EXE:  zedhebb.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedhebb;
    del zedhebb.obj

$(ZED).EXE:  zedhebt.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedhebt;
    del zedhebt.obj

$(ZED).EXE:  zedinit.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedinit;
    del zedinit.obj

$(ZED).EXE:  zedlatb.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedlatb;
    del zedlatb.obj

$(ZED).EXE:  zedlatt.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedlatt;
    del zedlatt.obj

$(ZED).EXE:  zedlchr.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedlchr;
    del zedlchr.obj

$(ZED).EXE:  zedlogo.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedlogo;
    del zedlogo.obj

$(ZED).EXE:  zedmain.c
    $(CC) $(CPRM2) $** 1>>g:$*.msg 2>>g:$*.out
    if exist $*.obj del $*.obj
    ren zedmain.obj $*.OBJ
    fdate $*.lib

$(ZED).EXE:  zedpbse.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedpbse;
    del zedpbse.obj

$(ZED).EXE:  zedpbuf.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedpbuf;
    del zedpbuf.obj

$(ZED).EXE:  zedpfnt.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedpfnt;
    del zedpfnt.obj

$(ZED).EXE:  zedpimg.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedpimg;
    del zedpimg.obj

$(ZED).EXE:  zedplsp.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedplsp;
    del zedplsp.obj

$(ZED).EXE:  zedplup.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedplup;
    del zedplup.obj

$(ZED).EXE:  zedppre.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedppre;
    del zedppre.obj

$(ZED).EXE:  zedpprt.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedpprt;
    del zedpprt.obj

$(ZED).EXE:  zedppsf.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedppsf;
    del zedppsf.obj

$(ZED).EXE:  zedppsp.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedppsp;
    del zedppsp.obj

$(ZED).EXE:  zedpram.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedpram;
    del zedpram.obj

$(ZED).EXE:  zedprom.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedprom;
    del zedprom.obj

$(ZED).EXE:  zedpx24.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedpx24;
    del zedpx24.obj

$(ZED).EXE:  zepilog.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zepilog;
    del zepilog.obj

$(ZED).EXE:  zfinish.c
    $(CC) $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zfinish;
    del zfinish.obj

$(ZED).EXE:  $*.lib
    zeditlnk $*
    if exist $*.bak del $*.bak
