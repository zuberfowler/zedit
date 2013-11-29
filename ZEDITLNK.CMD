/**********************************************************************/
/* ZEDITLNK.CMD - Link Zedit modules                                  */
/**********************************************************************/
'@echo on'
arg zed .

inc = ""
pun = ",,,"
/* does not work for zedit3p */
/* out = '1>>g:\'zed'.lnk 2>>g:\'zed'.err' */

if zed = "ZEDIT1" then do
    link = "link"
    opt  = "/e /f /m:full /nologo /packc /se:320 /stack:56832"
    lib  = "llibce"
    stdf = "stdf1l"
    def  = ";"
    end
else if zed = "ZEDIT2" then do
    link = "link"
    opt  = "/e /f /m:full /nologo /packc /packd /se:320"
    lib  = "llibcep"
    stdf = "stdf2l"
    def  = ",zedit2"
    end
else if zed = "ZEDIT2T" then do
    link = "link"
    opt  = "/co /e /f /m:full /nologo /packd /se:320"
    lib  = "llibcep"
    stdf = "stdf2l"
    def  = ",zedit2t"
    end
else if zed = "ZEDIT3O" then do
    link = "link386"
    opt  = "/nofree /a:4 /base:65536 /e /f /m:full /nologo /packc /packd"
    lib  = "os2386"
    stdf = "stdf3i"
    def  = ",zedit3"
    end
else if zed = "ZEDIT3OP" then do
    link = "icc"
    opt  = '/Fm /B"/base:65536 /f /m:full /nologo /packc /packd"'
    zed  = ""
    pun  = "ZEDIT3P.OBJ zedit3p.lib"
    lib  = "os2386.lib"
    stdf = "stdf3p.lib"
    def  = "zedit3.def"
    end
else if zed = "ZEDIT3" then do
    link = "ilink"
    opt  = "/nofree /a:4 /base:65536 /e /f /m:full /nologo /packc /packd"
    lib  = "os2386"
    stdf = "stdf3i"
    def  = ",zedit3"
    end
else if zed = "ZEDIT3P" then do
    link = "icc"
    opt  = '/Fm /B"/base:65536 /f /m:full /nologo /packc /packd"'
    zed  = ""
    pun  = "ZEDIT3P.OBJ zedit3p.lib"
    lib  = "os2386.lib"
    stdf = "stdf3p.lib"
    def  = "zedit3.def"
    end
else if zed = "ZEDIT3G" then do
    link = "link386"
    opt  = "/a:4 /base:65536 /e /f /m:full /nologo /packc /packd"
    lib  = "os2386"
    stdf = "stdf3g"
    def  = ",zedit3"
    end
else if zed = "ZEDIT3M" then do
    link = "link386"
    opt  = "/a:4 /base:65536 /e /f /m:full /nologo /packc /packd"
    lib  = "os2386"
    stdf = "stdf3m"
    def  = ",zedit3"
    end
else if zed = "ZEDIT3T" then do
    link = "link386"
    opt  = "/a:4 /de /e /f /m:full /nologo"
    inc  = "d:\cpp\lib\dde4xtra.obj"
    lib  = "os2386"
    stdf = "stdf3t"
    def  = ",zedit3"
    end
else if zed = "ZEDIT3MT" then do
    link = "link386"
    opt  = "/a:4 /de /e /f /m:full /nologo"
    lib  = "os2386"
    stdf = "stdf3m"
    def  = ",zedit3"
    end
else if zed = "ZEDIT3W" then do
    link = "wlink"
    opt  = "@zedit3w.lnk"
    zed  = ""
    pun  = ""
    lib  = ""
    stdf = ""
    def  = ""
    end

link opt zed inc pun lib zed stdf def

exit(0)
