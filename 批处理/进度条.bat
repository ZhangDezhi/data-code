 echo off
    rem   进度条 ▉▉▉▉▉
    set work=0
    set n=0
    set mo=0
    set number=0
    rem  all是总数
    set all=5
    set time=%all%
    :show
    :check
    if %number% GTR %mo% set num=%num%▉&set /a mo=%mo%+1&goto check

    cls
    echo  正在格式化您的系统，在此期间请勿切断电源。
    echo.
    echo  进度： %n% / %all%                                          剩余时间:%time%秒
    echo.
    echo. 
    echo                                  完成 %work% %%%
    echo.
    if not "%num%"=="" echo       %num%
    if not "%num%"=="" echo       %num%
    if %work%==100 goto end
    ping 127.1 -n 3 >nul
    set /a n=%n%+1
    set /a time=%all%-%n%
    set /a work=(%n%)*100/(%all%)
    set /a number=%work%/3
    set /a number=%number%+1
    goto show
    endlocal

    endlocal
    echo.
    echo.
    echo.格式化完毕,请按键继续.
    :end
    pasue