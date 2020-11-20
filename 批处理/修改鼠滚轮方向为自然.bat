@echo off
cls
set v= 1
for /f "tokens=1* delims=\" %a in ('reg query  "HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Enum" /v FlipFlopWheel /s 2^>nul') do  if "%a"=="HKEY_LOCAL_MACHINE" reg add "%a\%b"  /v FlipFlopWheel /t REG_DWORD /d %v%  /f 
REM **************执行完成后，请重新拔插鼠标,鼠标滚动方向改为“自然”*************
echo on