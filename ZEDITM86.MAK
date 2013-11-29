# ZEDITMAK.M86 - Zedit DOS extra parts

$(ZED).EXE:  clrlhmn.c
    $(CC)   $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+clrlhmn;
    del clrlhmn.obj

$(ZED).EXE:  ds8chmn.c
    $(CC)   $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+ds8chmn;
    del ds8chmn.obj

$(ZED).EXE:  ds8lhmn.c
    $(CC)   $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+ds8lhmn;
    del ds8lhmn.obj

$(ZED).EXE:  dspchmn.c
    $(CC)   $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+dspchmn;
    del dspchmn.obj

$(ZED).EXE:  dsplhmn.c
    $(CC)   $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+dsplhmn;
    del dsplhmn.obj

$(ZED).EXE:  ibmmode.c
    $(CC)   $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+ibmmode;
    del ibmmode.obj

$(ZED).EXE:  ov8chmn.c
    $(CC)   $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+ov8chmn;
    del ov8chmn.obj

$(ZED).EXE:  ovrchmn.c
    $(CC)   $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+ovrchmn;
    del ovrchmn.obj

$(ZED).EXE:  revchmn.c
    $(CC)   $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+revchmn;
    del revchmn.obj

$(ZED).EXE:  revlhmn.c
    $(CC)   $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+revlhmn;
    del revlhmn.obj

$(ZED).EXE:  scrphmn.c
    $(CC)   $(CPARM) $** 1>>g:$*.msg 2>>g:$*.out
    $(LIBCMD) $* -+scrphmn;
    del scrphmn.obj
