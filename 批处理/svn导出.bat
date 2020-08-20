REM 　需要说明一下，Subversion命令无法直接导出版本差异文件。
REM 　简单介绍一下思路，先用diff命令获得版本差异文件列表，再循环这个文件列表逐个导出文件。


@echo off
setlocal enabledelayedexpansion
set config_file=build.properties
set from_version=%1
set to_version=%2

rem 输入参数
rem set /p from_version=请输入补丁升级前的版本：
rem set /p to_version=请输入补丁升级后的版本：

rem 读取配置文件
for /f "tokens=1,2 delims==" %%i in (%config_file%) do (
    set %%i=%%j
)

rem 删除临时文件
set current_path=%~dp0
del /f /s /q %current_path%%tempdir%

rem 比较差异文件
svn diff --summarize -r %from_version%:%to_version% %url% > file_list.txt

rem 导出差异文件
for /f "delims=" %%i in (file_list.txt) do (
    call :export %%i
)
goto :EOF

:export
set fullpath=%2
set filename=%~nx2
set "filepath=!fullpath:%filename%=!"
set "filepath=!filepath:%url%=!"
set "filepath=%filepath:/=\%"
if not exist %tempdir%%filepath% mkdir %tempdir%%filepath%
svn export -r %to_version% %fullpath% %tempdir%%filepath%%filename%

