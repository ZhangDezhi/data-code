::===================================================
:: *   Encoding: GBK
:: *   Create by      : ZhangDezhi
:: *   Create Time    : 2021-07-31 09:34 
:: *   Last Modified : 2021-07-31 09:34:34
::
:: *   This is Bat script     
::===================================================


::config.ini
::abc=abc
::a=a
::localpath=D:\local\path


@echo off
setlocal enabledelayedexpansion
for /f "delims=" %%i in ('type "readIni.ini"^| find /i "="') do set %%i
echo %a%
echo %b%
endlocal

pause
