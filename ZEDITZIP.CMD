/**********************************************************************/
/* ZEDITZIP.CMD - Zedit backup in ZIP file                            */
/* make incremental pkzip backup of zedit parts                       */
/**********************************************************************/
'@echo on'
'dir *.zip'
say "Enter next level letter"
pull let .
lvl = '117'

'pkzip zed'lvl || let 'd:\str\stdf\*.a86'
'pkzip zed'lvl || let 'd:\str\stdf\*.asm'
'pkzip zed'lvl || let 'd:\str\stdf\*.c'
'pkzip zed'lvl || let 'd:\str\stdf\*.cmd'
'pkzip zed'lvl || let 'd:\str\stdf\*.mak'
'pkzip zed'lvl || let 'd:\str\header\*.h'
'pkzip zed'lvl || let 'd:\str\zedit\*.a86'
'pkzip zed'lvl || let 'd:\str\zedit\*.asm'
'pkzip zed'lvl || let 'd:\str\zedit\*.c'
'pkzip zed'lvl || let 'd:\str\zedit\*.cmd'
'pkzip zed'lvl || let 'd:\str\zedit\*.spf'
'pkzip zed'lvl || let 'd:\str\zedit\*.def'
'pkzip zed'lvl || let 'd:\str\zedit\*.ico'
'pkzip zed'lvl || let 'd:\str\zedit\*.mak'
'pkzip zed'lvl || let 'd:\str\zedit\*.obj'
'pkzip zed'lvl || let 'd:\str\zedit\*.ps '
'pkzip zed'lvl || let 'd:\str\zedit\*.scr'
'pkzip zed'lvl || let 'd:\str\zedit\*.avl'
'pkzip zed'lvl || let 'd:\str\zedit\*.tst'
'pkzip zed'lvl || let 'd:\str\zedit\zedit1.exe'
'pkzip zed'lvl || let 'd:\str\zedit\zedit3p.exe'

say "zed"lvl || let "backup finished!"
