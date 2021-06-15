::===================================================
:: *   Encoding: GBK
:: *   Create by      : ZhangDezhi
:: *   Create Time    : 2021-06-15 17:30 
:: *   Last Modified : 2021-06-15 17:30:28
::
:: *   This is Bat script     
::===================================================


:: 方法一
for /L %i IN (1,1,254) DO ping -w 2 -n 1 192.168.1.%i

::处理完成执行:    arp -a
::
:: 方法二
for /L %i in (1,1,255) do ping -n 1 -w 60 192.168.1.%i | find "回复" >>d:\pingall.txt


:: 方法三
::
::
@echo off
echo **********************************我是分割线**********************************
echo 要输入的文本内容如下：
echo 执行中，请稍后...
echo ping日期：%date% > pingall.txt
echo ping时间：%time% >> pingall.txt
echo.>>pingall.txt
echo 具体数据：>>pingall.txt
@echo on
for /L %i in (1,1,255) do ping -n 1 -w 60 192.168.1.%i | find "回复" >> pingall.txt
%for /L %i in (1,1,255) do  echo %~i%
@echo off
echo -------------------------------------------------------------------------------
echo ----------------------------------------------------------->> pingall.txt
@echo on
echo 执行结束，请双击打开pingall.txt查看。

echo **********************************我是分割线**********************************
pause



:: 查看局域网内IP
:: 看到局域网中所有正在运行的电脑
net view  
