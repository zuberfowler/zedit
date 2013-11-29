/**********************************************************************/
/* ZEDITCMP.CMD - Zedit compile control                               */
/* For version change:  fdate primary.c, inusage.c                    */
/* Requires ZEDITM13.MAK, ZEDITM20.MAK                                */
/*          ZEDITMK1.MAK, ZEDITMK2.MAK                                */
/* /Fa option for assembler output                                    */
/**********************************************************************/
arg ver .
'@echo off'

select;
  when(ver = '1') then do;
    /* DOS 8086 mode  MSC */
    'set ZED=ZEDIT1'
    'set CC=cl'
    'set CPARM=/Alfu /c /Grst48 /J /nologo /Oax /W4 /Zl'
    'set CPRM2=/Alfu /c /Grst48 /J /nologo /Oax /W4'
    'set LIBCMD=libms /nologo'
    'call inctk13'
    'make zeditm86.mak'
    if (rc \= 0)
      then exit(rc)
    end;
  when(ver = '2') then do;
    /* OS/2 80286 mode  MSC  (was /Oax) */
    'set ZED=ZEDIT2'
    'set CC=cl'
    'set CPARM=/DOS2 /Alfu /c /G2rst0 /J /nologo /Oalt /W4 /Zl'
    'set CPRM2=/DOS2 /Alfu /c /G2rst0 /J /nologo /Oalt /W4 /Zl'
    'set LIBCMD=libms /nologo'
    'call inctk13'
    'make zeditm13.mak'
    if (rc \= 0)
      then exit(rc)
    end;
  when(ver = '2T') then do;
    /* OS/2 80286 mode  MSC DEBUG */
    'set ZED=zedit2t'
    'set CC=cl'
    /* /Zl may cause problems for SD386 */
    'set CPARM=/DOS2 /DDEBUG /Alfu /c /G2rt0 /J /nologo /Od /W4 /Zil'
    'set CPRM2=/DOS2 /DDEBUG /Alfu /c /G2rt0 /J /nologo /Od /W4 /Zil'
    'set LIBCMD=libms /nologo'
    'call inctk13'
    'make zeditm13.mak'
    if (rc \= 0)
      then exit(rc)
    end;
  when(ver = '3O') then do;
    /* C - OS/2 80386 mode  IBM C/C++ Tools Set Version 2 */
    'set ZED=ZEDIT3O'
    'set CC=icc'
    'set CPARM=/c /Fi /Gfins /Si /Wall+ppt-trd-uni-'
    'set CPRM2=/c /Fi /Gfis  /Si /Wall+ppt-trd-uni-'
    'set LIBCMD=lib /q'
    'call incsetp'
    'make zeditm20.mak'
    if (rc \= 0)
      then exit(rc)
    end;
  when(ver = '3OP') then do;
    /* C++ OS/2 80386 mode  IBM C/C++ Tools Set Version 2 */
    'set ZED=ZEDIT3OP'
    'set CC=icc'
    'set CPARM=/c /Fi /Gfins /Si /Tdp /Wall+ppt-trd-uni-'
    'set CPRM2=/c /Fi /Gfis  /Si /Tdp /Wall+ppt-trd-uni-'
    'set LIBCMD=lib /q'
    'call incsetp'
    'make zeditm20.mak'
    if (rc \= 0)
      then exit(rc)
    end;
  when(ver = '3') then do;
    /* C - OS/2 80386 mode  IBM C/C++ Tools Set */
    'set ZED=ZEDIT3'
    'set CC=icc'
    'set CPARM=/c /Fi /Gfins /Si /Wall+ppt-trd-uni-'
    'set CPRM2=/c /Fi /Gfis  /Si /Wall+ppt-trd-uni-'
    'set LIBCMD=lib /q'
    'call incsetp'
    'make zeditm20.mak'
    if (rc \= 0)
      then exit(rc)
    end;
  when(ver = '3P') then do;
    /* C++ OS/2 80386 mode  IBM C/C++ Tools Set */
    'set ZED=ZEDIT3P'
    'set CC=icc'
    'set CPARM=/c /Fi /Gfins /Si /Tdp /Wall+ppt-trd-uni-'
    'set CPRM2=/c /Fi /Gfis  /Si /Tdp /Wall+ppt-trd-uni-'
    'set LIBCMD=lib /q'
    'call incsetp'
    'make zeditm20.mak'
    if (rc \= 0)
      then exit(rc)
    end;
  when(ver = '3T') then do;
    /* OS/2 80386 mode  IBM C/C++ Tools Set DEBUG */
    'set ZED=zedit3t'
    'set CC=icc'
    'set CPARM=/DDEBUG /c /Fi /Gfhins /O- /Si /Ti /Wall+ppt-trd-uni-'
    'set CPRM2=/DDEBUG /c /Fi /Gfhis  /O- /Si /Ti /Wall+ppt-trd-uni-'
    'set LIBCMD=lib /q'
    'call incsetp'
    'make zeditm20.mak'
    if (rc \= 0)
      then exit(rc)
    end;
  when(ver = '3M') then do;
    /* OS/2 80386 mode  SDKC */
    'set ZED=ZEDIT3M'
    'set CC=cl386'
    /* /Oe failing on posptr = posxga[p] in dspcxga.c */
    /* 'set CPARM=/DOS2 /c /G3sm /J /nologo /Oatlegc /W4 /Zp2l' */
    'set CPARM=/DOS2 /c /G3sm /J /nologo /Oagilpt  /W4 /Zp2l'
    'set CPRM2=/DOS2 /c /G3sm /J /nologo /Oaegilpt /W4 /Zp2'
    'set LIBCMD=lib /q'
    'call incsdkc'
    'make zeditm20.mak'
    if (rc \= 0)
      then exit(rc)
    end;
  when(ver = '3MT') then do;
    /* OS/2 80386 mode  SDKC DEBUG */
    'set ZED=zedit3mt'
    'set CC=cl386'
    /* /Zl may cause problems for SD386 */
    'set CPARM=/DOS2 /DDEBUG /c /J /G3m /nologo /Od /W4 /Zp2il'
    'set CPRM2=/DOS2 /DDEBUG /c /J /G3m /nologo /Od /W4 /Zp2i'
    'set LIBCMD=lib /q'
    'call incsdkc'
    'make zeditm20.mak'
    if (rc \= 0)
      then exit(rc)
    end;
  when(ver = '3G') then do;
    exit(16)
    /* OS/2 80386 mode  GNU */
    'set ZED=ZEDIT3G'
    'set CC=gcc'
    /* @@ need to set default to unsigned char @@ */
    'set CPARM=-DGNU -DOS2 -c -O2 -Wall'
    'set CPRM2=-DGNU -DOS2 -c -O2 -Wall'
    'set LIBCMD=lib /q'
    'call incgnuc'
    'make zeditm20.mak'
    if (rc \= 0)
      then exit(rc)
    end;
  when(ver = '3W') then do;
    /* C - OS/2 80386 mode  Watcom C/C++ 32 */
    'set ZED=ZEDIT3W'
    'set CC=wcc386'
    'set CPARM=-fpi87 -fp5 -oneatx -sg -w4 -zl -zp4 -zq -5r'
    'set CPRM2=-fpi87 -fp5 -oneatx -sg -w4     -zp4 -zq -5r'
    'set LIBCMD=lib /q'
    'call incwatc'
    'make zeditm20.mak'
    if (rc \= 0)
      then exit(rc)
    end;
  otherwise do;
    say "Usage:  ZEDITCMP ver"
    say "  ver:  1, 2, 2t, 3, 3p, 3t, 3o, 3op, 3m, 3mt, 3w"
    exit(16)
    end;
  end;

'@make zeditmk1.mak'
if (rc \= 0)
  then exit(rc)
'@make zeditmk2.mak'
