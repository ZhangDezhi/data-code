::===================================================
:: *   Encoding: GBK
:: *   Create by      : ZhangDezhi
:: *   Create Time    : 2021-06-04 14:39 
:: *   Last Modified : 2021-06-04 14:39:21
::
:: *   This is Bat script     
::===================================================

@echo off
for /f "tokens=3*" %%p in ('REG QUERY "HKCU\Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders" /v Personal') do (
            set DocumentsFolder=%%p
            
        )
echo %DocumentsFolder%
