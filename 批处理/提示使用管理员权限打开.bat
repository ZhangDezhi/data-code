@echo off&(cd/d "%~dp0")&(cacls "%SystemDrive%\System Volume Information" >nul 2>&1)||(color 4f&echo 请右键“以管理员身份运行”&echo.&pause&exit /b)


:: 参考: https://www.zhihu.com/question/34541107