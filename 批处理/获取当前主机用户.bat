@echo off
echo 本机上拥有以下用户：
echo.
for /f "skip=4 tokens=1-3" %%i in ('net user') do (
    if not "%%i"=="命令成功完成。" echo %%i
    if not "%%j"=="" echo %%j
    if not "%%k"=="" echo %%k
)
echo.
echo 当前登录本机的账户是：%username%
pause>nul