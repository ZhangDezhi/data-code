 echo off
    rem   ������ ����������
    set work=0
    set n=0
    set mo=0
    set number=0
    rem  all������
    set all=5
    set time=%all%
    :show
    :check
    if %number% GTR %mo% set num=%num%��&set /a mo=%mo%+1&goto check

    cls
    echo  ���ڸ�ʽ������ϵͳ���ڴ��ڼ������жϵ�Դ��
    echo.
    echo  ���ȣ� %n% / %all%                                          ʣ��ʱ��:%time%��
    echo.
    echo. 
    echo                                  ��� %work% %%%
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
    echo.��ʽ�����,�밴������.
    :end
    pasue