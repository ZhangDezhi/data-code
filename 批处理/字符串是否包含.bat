::===================================================
:: *   Encoding: GBK
:: *   Create by      : ZhangDezhi
:: *   Create Time    : 2021-07-31 09:27 
:: *   Last Modified : 2021-07-31 09:27:48
::
:: *   This is Bat script     
::===================================================

@echo off
set a=55544333
set c=6666dfsfds
set b=44
echo %a%| findstr %b% >nul && (
echo %a%包含%b%
) || (
echo %a%不包含%b%
)
echo %c%| findstr %b% >nul && (
echo %c%包含%b%
) || (
echo %c%不包含%b%
)
pause
