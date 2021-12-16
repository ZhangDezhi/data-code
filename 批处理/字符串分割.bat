::===================================================
:: *   Encoding: GBK
:: *   Create by      : ZhangDezhi
:: *   Create Time    : 2021-07-31 09:36 
:: *   Last Modified : 2021-07-31 09:36:14
::
:: *   This is Bat script     
::===================================================

@echo off
for /f "delims=.， tokens=2" %%i in (将进酒·君不见.txt) do echo %%i>>1.txt
for /f "delims=. tokens=2" %%i in (将进酒·君不见.txt) do echo %%i>>2.txt


::
::    delims=.，，指定了分隔符，这里指定了.和，为分割符
::        tokens=2,指定了分割后，取哪一个部分，分割后的第一部分为1。
::            当省略delims参数，默认使用空格作为分割符；当省略tokens参数时，默认取第1部分
