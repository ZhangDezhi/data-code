@echo off
set testPath="D:/Demo/xyz/11111111.txt"
call :print %testPath%
 
:print
rem ��ȡ���ļ�·��
set file_path=%~dp1
echo %file_path%
rem ��ȡ���ļ�����
set file_name=%~n1
echo %file_name%
rem ��ȡ���ļ���׺
set suffix=%~x1
echo %suffix%
rem ��ȡ�������ĸ���ʼ ��ȡ�ĸ�����
set specStr=%file_name:~-4,4%
echo %specStr%
pause
