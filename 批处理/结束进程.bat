::===================================================
:: *   Encoding: GBK
:: *   Create by      : ZhangDezhi
:: *   Create Time    : 2021-06-04 14:42 
:: *   Last Modified : 2021-06-04 14:42:42
::
:: *   This is Bat script     
::===================================================


@echo off
C:\Windows\system32\taskkill.exe /f /im qq.exe



taskkill /f /im *.exe
::结束程序
start *.exe
::::运行程序
::
::
::
::windows下的脚本： 判断进程是否存在
tasklist|find /i "notepad.exe" （检查是否存在notepad.exe进程，如果检测到，下面比较的值为0，为0表示存在。）
    if %errorlevel%==0 (
    start "" "test.exe"（启动test.exe）
    )


::循环插件
:loop
ping -n 5 127.0.0.1 (5秒执行一次下面的指令）
        tasklist|find /i "notepad.exe" （检查是否存在notepad.exe进程，如果检测到，下面比较的值为0，为0表示存在。）
        if %errorlevel%==0 (
            start "" "test.exe"（启动test.exe）

            )
        goto :loop （循环）)
