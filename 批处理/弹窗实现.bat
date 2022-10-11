REM msg %username% /time:10 "要显示的内容"

@echo off
title %date% %time:~,8%
mshta vbscript:msgbox("是否确定？",36,"第一bai个")(window.close)
mshta vbscript:msgbox("真的是吗du？",36,"第二个")(window.close) 