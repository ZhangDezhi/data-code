@ECHO OFF&PUSHD %~DP0 &TITLE �����������

mode con cols=36 lines=20

color 2C

:menu

cls

echo.

echo ��ʲô��� �Ͱ����� ˵��ô��

echo ==============================

echo.

echo ����1��˵�Ұ���

echo.

echo ����2��˵������

echo.

echo ����3��˵����QQ

echo.

echo ==============================

echo.

echo.

set /p user_input=���������֣�

if %user_input% equ 1 echo �Ұ���

if %user_input% equ 2 echo ������

if %user_input% equ 3 echo ����QQ

pause

goto menu