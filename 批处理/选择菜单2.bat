cls
@ECHO OFF
CLS
color 0a

GOTO MENU
:MENU
ECHO.
ECHO.               =-=-=-=-=������˵�ʾ��=-=-=-=-=
ECHO.
ECHO.                       1  ִ������a
ECHO.
ECHO.                       2  ִ������b
ECHO.
ECHO.                       3  ִ������c
ECHO.
ECHO.                       4  ��   ��
ECHO.
ECHO.
ECHO.
echo.                ������ѡ����Ŀ����ţ�
set /p  ID=
if "%id%"=="1"  goto cmd1

if "%id%"=="2" goto cmd2

if "%id%"=="3" goto cmd3

IF "%id%"=="4"  exit
PAUSE

:cmd1

echo ִ������a
rem explorer "http://www.blueidea.com"
goto MENU

:cmd2

echo ִ������b
echo ����ע��������(reg add ���� ֵ)
GOTO MENU

:cmd3
echo ִ������c
echo ����ϵͳ��������(sc)
GOTO MENU 