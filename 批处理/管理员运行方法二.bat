@echo off
%1 mshta vbscript:CreateObject("Shell.Application").ShellExecute("cmd.exe","/c %~s0 ::","","runas",1)(window.close)&&exit
cd /d "%~dp0"

@REM 写在bat文件的顶端就可以实现

@REM 其它方法参考 : https://www.jb51.net/article/193692.htm