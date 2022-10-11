::===================================================
:: *   Encoding: GBK
:: *   Create by      : ZhangDezhi
:: *   Create Time    : 2021-07-31 09:33 
:: *   Last Modified : 2021-07-31 09:33:58
::
:: *   This is Bat script     
::===================================================

@echo off

:: 获取电脑本机IP
 for /f "tokens=16" %%i in ('ipconfig ^|find /i "ipv4"') do set ip=%%i

 echo ip=%ip%

 pause
