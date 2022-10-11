rem way 1
set str=machine-order-service
set matchStr=orderd
echo %str% | findstr %matchStr% >nul && echo yes || echo no
rem end way 1
pause

rem way 2
setLocal EnableDelayedExpansion
if not "x!str:%matchStr%=!"=="x%str%" (
    echo Y
) else (
    echo N
)
endlocal
rem end way 2


:: 一般情况判断完全匹配的时候用==
@echo off 
if "%1"=="abc"  @echo OK


:: 部份匹配
@echo off
echo %1|findstr "^abc" >nul
echo %errorlevel%

::
@echo off
echo %1|findstr "^abc" >nul
if %errorlevel% equ 0 (
echo ok
) else (
echo not ok
)



::

@echo off
    setlocal enableextensions disabledelayedexpansion

    >"tempFile" (
        echo bob binson
        echo ted jones
        echo binson
    )

    set "pattern=binson"

    for /f "usebackq delims=" %%a in ("tempFile") do (
        echo data: %%a

        set "line=%%a"
        setlocal enabledelayedexpansion
        if "!line:%pattern%=!"=="!line!" (
            echo .... pattern not found
        ) else (
            echo .... pattern found
        )
        endlocal
    )

    del /q tempFile


pause

