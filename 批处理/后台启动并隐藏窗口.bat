@echo off

if "%1"=="h" goto begin

start mshta vbscript:createobject("wscript.shell").run("""%~nx0"" h",0)(window.close)&&exit

:begin

:: 具体脚本 /b 表示后台启动
start /b run.cmd  