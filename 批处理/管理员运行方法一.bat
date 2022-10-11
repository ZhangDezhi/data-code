@ echo off
%1 %2
ver|find "5.">nul&&goto :Admin
mshta vbscript:createobject("shell.application").shellexecute("%~s0","goto :Admin","","runas",1)(window.close)&goto :eof
:Admin
//在你的bat开头加上上面的命令即可
//下面是你需要执行的命令
set path=%~dp0
echo install mysql service...
echo %path%
cd %path%\bin\
mysqld.exe --remove mysql
mysqld.exe --install mysql
echo start mysql Serviceo
"%SystemRoot%"\system32\net start mysql