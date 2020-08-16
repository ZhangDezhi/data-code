REM 'GBK
@echo off
echo 读取服务器地址文件：
setlocal enabledelayedexpansion REM 不能省略
for /f  "delims="  %%a in (a.txt)  do (
  set value=%%a
   REM 使用这种方式
  echo !value!     
)
REM Pause>Nul  REM 不显示”请按任意键继续“
Pause

