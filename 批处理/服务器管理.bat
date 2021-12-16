::===================================================
:: *   Encoding: GBK
:: *   Create by      : ZhangDezhi
:: *   Create Time    : 2021-07-31 09:29 
:: *   Last Modified : 2021-07-31 09:29:40
::
:: *   This is Bat script     
::===================================================

@echo off &PUSHD %~DP0 &TITLE 运维管理
mode con cols=80 lines=35
color 02
:menu
cls
echo.
echo                        系统菜单   
echo ==========================================================
echo.
echo ――――――――――【1】系统文件清理       ―――――――
echo.
echo ――――――――――【2】启动Oracle服务     ―――――――
echo.
echo ――――――――――【3】关闭Oracle服务     ―――――――
echo.
echo ――――――――――【4】重启Tomcat服务     ―――――――
echo.
echo ――――――――――【5】开启Tomcat服务     ―――――――
echo.
echo ――――――――――【6】关闭Tomcat服务     ―――――――
echo.
echo ――――――――――【7】重启ETL服务        ―――――――
echo.
echo ――――――――――【8】开启ETL服务        ―――――――
echo.
echo ――――――――――【9】关闭ETL服务        ―――――――
echo.
echo ――――――――――【0】关闭操作系统       ―――――――
echo.
echo ==========================================================
 
set /p user_input=选择并进入命令：
if %user_input%==1 goto a
if %user_input%==2 goto b
if %user_input%==3 goto c
if %user_input%==4 goto d
if %user_input%==5 goto e
if %user_input%==6 goto f
if %user_input%==7 goto g
if %user_input%==8 goto h
if %user_input%==9 goto i
if %user_input%==0 goto j
if not %user_input%=="" goto z 
 
rem 系统文件清理
:a
echo 正在清除系统临时文件 *.tmp *._tmp *.log *.chk *.old 
echo  请稍等...
del /f /s /q %systemdrive%\*.tmp
del /f /s /q %systemdrive%\*._mp
del /f /s /q %systemdrive%\*.log
del /f /s /q %systemdrive%\*.gid
del /f /s /q %systemdrive%\*.chk
del /f /s /q %systemdrive%\*.old
echo 正在清空垃圾箱，备份文件和预缓存脚本...
del /f /s /q %systemdrive%\recycled\*.*
del /f /s /q %windir%\*.bak
del /f /s /q %windir%\prefetch\*.*
echo  系统优化和垃圾清理已经完成！
echo. & pause
goto menu
 
rem 启动Oracle服务
:b
echo.
echo startup OracleService
net start OracleOraDb11g_home1TNSListener      
net start OracleServiceXEDM
echo Oracle Service and listener have been started! 
echo. & pause
goto menu
 
rem 关闭Oracle服务
:c
echo.
echo shutdown OracleService
net stop OracleOraDb11g_home1TNSListener      
net stop OracleServiceXEDM
echo Oracle Service and listener have been shutdown! 
echo. & pause
goto menu
 
rem 重启Tomcat服务
:d
echo.
echo 正在重启Tomcat...
set CATALINA_HOME=D:\xEDM\apache-tomcat-6.0.43
call %CATALINA_HOME%/bin/shutdown.bat
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq Tomcat"
echo 已关闭Tomcat，正在重新启动...
call %CATALINA_HOME%\bin\startup.bat
echo Tomcat已经启动完毕！
echo. & pause
goto menu
 
rem 开启Tomcat服务
:e
echo.
echo 正在启动Tomcat服务...
set CATALINA_HOME=D:\xEDM\apache-tomcat-6.0.43
call %CATALINA_HOME%/bin/startup.bat
echo Tomcat服务已经启动！
echo. & pause
goto menu
 
rem 关闭Tomcat服务
:f
echo.
echo 正在停止Tomcat服务...
set CATALINA_HOME=D:\xEDM\apache-tomcat-6.0.43
call %CATALINA_HOME%/bin/shutdown.bat
taskkill /T /F /IM cmd.exe /FI "WINDOWTITLE eq Tomcat"
echo Tomcat服务已经停止！
echo. & pause
goto menu
 
rem 重启ETL服务
:g
echo.
set xEDM_HOME=D:\xEDM\启动服务
echo 正在重启ETL服务...
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_01"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_02"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_03"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_04"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_05"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_06"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_07"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_08"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_09"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_10"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_11"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_12"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_13"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_14"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_15"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_16"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_17"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_18"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_19"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_20"
rem taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuantPP_TP"
echo  ETL服务已经关闭，正在重新启动...
start %xEDM_HOME%\ETL_01.bat.lnk
start %xEDM_HOME%\ETL_02.bat.lnk
start %xEDM_HOME%\ETL_03.bat.lnk
start %xEDM_HOME%\ETL_04.bat.lnk
start %xEDM_HOME%\ETL_05.bat.lnk
start %xEDM_HOME%\ETL_06.bat.lnk
start %xEDM_HOME%\ETL_07.bat.lnk
start %xEDM_HOME%\ETL_08.bat.lnk
start %xEDM_HOME%\ETL_09.bat.lnk
start %xEDM_HOME%\ETL_10.bat.lnk
start %xEDM_HOME%\ETL_11.bat.lnk
start %xEDM_HOME%\ETL_12.bat.lnk
start %xEDM_HOME%\ETL_13.bat.lnk
start %xEDM_HOME%\ETL_14.bat.lnk
start %xEDM_HOME%\ETL_15.bat.lnk
start %xEDM_HOME%\ETL_16.bat.lnk
start %xEDM_HOME%\ETL_17.bat.lnk
start %xEDM_HOME%\ETL_18.bat.lnk
start %xEDM_HOME%\ETL_19.bat.lnk
start %xEDM_HOME%\ETL_20.bat.lnk
rem start %xEDM_HOME%\PP_TP.bat.lnk
echo ETL服务已启动完毕！
echo. & pause
goto menu
 
rem 开启ETL服务
:h
echo.
set xEDM_HOME=D:\xEDM\启动服务
echo 正在开启ETL服务...
start %xEDM_HOME%\ETL_01.bat.lnk
start %xEDM_HOME%\ETL_02.bat.lnk
start %xEDM_HOME%\ETL_03.bat.lnk
start %xEDM_HOME%\ETL_04.bat.lnk
start %xEDM_HOME%\ETL_05.bat.lnk
start %xEDM_HOME%\ETL_06.bat.lnk
start %xEDM_HOME%\ETL_07.bat.lnk
start %xEDM_HOME%\ETL_08.bat.lnk
start %xEDM_HOME%\ETL_09.bat.lnk
start %xEDM_HOME%\ETL_10.bat.lnk
start %xEDM_HOME%\ETL_11.bat.lnk
start %xEDM_HOME%\ETL_12.bat.lnk
start %xEDM_HOME%\ETL_13.bat.lnk
start %xEDM_HOME%\ETL_14.bat.lnk
start %xEDM_HOME%\ETL_15.bat.lnk
start %xEDM_HOME%\ETL_16.bat.lnk
start %xEDM_HOME%\ETL_17.bat.lnk
start %xEDM_HOME%\ETL_18.bat.lnk
start %xEDM_HOME%\ETL_19.bat.lnk
start %xEDM_HOME%\ETL_20.bat.lnk
rem start %xEDM_HOME%\PP_TP.bat.lnk
echo ETL服务已经开启！
echo. & pause
goto menu
 
rem 关闭ETL服务
:i
echo.
echo 正在关闭启ETL服务...
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_01"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_02"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_03"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_04"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_05"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_06"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_07"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_08"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_09"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_10"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_11"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_12"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_13"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_14"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_15"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_16"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_17"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_18"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_19"
taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuant_ETL_20"
rem taskkill /T /F /IM httpd.exe /FI "WINDOWTITLE eq xQuantPP_TP"
echo ETL服务已经关闭！
echo. & pause
goto menu
 
rem 关闭计算机
:j
echo.
echo 操作系统将在3秒后关闭...
shutdown -s -t 0
echo. & pause
goto menu
 
:z
echo.
echo 你的选择无效，请按任意键返回菜单！
echo. & pause
goto menu
