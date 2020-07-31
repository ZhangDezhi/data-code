@echo off
set testPath="D:/Demo/xyz/11111111.txt"
call :print %testPath%
 
:print
rem 获取到文件路径
set file_path=%~dp1
echo %file_path%
rem 获取到文件名称
set file_name=%~n1
echo %file_name%
rem 获取到文件后缀
set suffix=%~x1
echo %suffix%
rem 截取倒数第四个开始 截取四个长度
set specStr=%file_name:~-4,4%
echo %specStr%
pause
