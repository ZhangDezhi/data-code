:: 多条件判断
chcp 65001
@echo off 
choice /C dme /M "defrag,mem,end"
if errorlevel 3 goto end
if errorlevel 2 goto mem 
if errotlevel 1 goto defrag

:defrag 
echo AAA
pause
goto end

:mem 
echo BBB
pause
goto end

:end 
echo CCCC 
pause


::-------------------------------

::设置编码方式
chcp 65001

@echo off

　　
::空格，英文冒号表示注释
echo.
set /p a= 请输入内容：

if "%a%"=="1" (
    echo 1111111111111111111111111111
    pause
)else (
    if "%a%"=="2" (
        echo 222222222222222222222222
        pause
    )else (
        if "%a%"=="3" (
            echo 3333333333333333333333
            pause
        )else (
            if "%a%"=="4" (
                echo 444444444444444444444444444444444444
                pause
            )
        )
    )
    echo 没有多余的选择，按任意键盘退出
    pause
    exit
)
