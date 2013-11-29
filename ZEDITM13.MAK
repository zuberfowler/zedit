# ZEDITMAK.M13 - Zedit OS/2 V1.3 extra parts

$(ZED).EXE:  savevio.c
    $(CC)   $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+savevio;
    del savevio.obj
