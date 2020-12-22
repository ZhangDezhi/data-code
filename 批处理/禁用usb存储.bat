:: disable usb devices
::禁止
reg add HKLM\SYSTEM\CurrentControlSet\Services\UsbStor /v "Start" /t REG_DWORD /d "4" /f

::允许
reg add HKLM\SYSTEM\CurrentControlSet\Services\UsbStor /v "Start" /t REG_DWORD /d "3" /f


::方法二:user是用户

cacls %windir%\Inf\Usbstor.pnf /d user
cacls %windir%\Inf\Usbstor.inf /d user

:: 允许 
cacls %windir%\Inf\Usbstor.pnf /p user:R
cacls %windir%\Inf\Usbstor.inf /p user:R

::参考: https://stackoverflow.com/questions/13267236/how-disable-and-enable-usb-port-via-command-prompt
