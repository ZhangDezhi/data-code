:: RUN THIS SCRIPT TO EXECUTE AHK SCRIPTS FROM THE COMMAND LINE WITHOUT COMPILING.

:: do not show the actions done here in the window
@echo off

:: ================================== Config section ==================================
:: adjust these values

:: the path to the AutoHotkey.exe to be used:
@set AHK_PATH=%PROGRAMFILES%\AutoHotkey\AutoHotkey.exe

:: the (relative or absolute) path to the script to be launched:
@set SCRIPT_PATH=myscript.ahk

:: the alias to be used for the script:
@set SCRIPT_ALIAS=myscript

:: a text to show in the CMD window on launch (you may use the above vars in here, as in the example below) :
@set TEXT=This is a CMD script. Use "%SCRIPT_ALIAS%" to run it.

:: ================================== End of section ==================================

:: create "macro"
doskey %SCRIPT_ALIAS%="%AHK_PATH%" "%SCRIPT_PATH%" $*

:: run a new cmd prompt which inherits the macro
%COMSPEC% /k "echo %TEXT%"