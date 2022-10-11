@echo off
echo;
echo 当前IP地址列表：
for /f "tokens=16" %%i in ('ipconfig ^|find /i "ipv4"') do (
set ip=%%i
echo %%i
)

::目前是获取所有 ipv4 地址的最后一个
echo;
set url=http://%ip%/
echo 生成地址：%url%
