# ZEDITMAK.M20 - Zedit OS/2 V2.0 extra parts

$(ZED).EXE:  savevio.c
    $(CC)   $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+savevio;
    del savevio.obj

$(ZED).EXE:  zedpprm.c
    $(CC)   $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+zedpprm;
    del zedpprm.obj
