REM 'GBK
@echo off
echo 读取服务器地址文件：

for /f  %%a in (a.txt)  do (
  echo %%a
)
REM Pause>Nul  REM 不显示”请按任意键继续“
Pause