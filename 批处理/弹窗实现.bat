REM msg %username% /time:10 "Ҫ��ʾ������"

@echo off
title %date% %time:~,8%
mshta vbscript:msgbox("�Ƿ�ȷ����",36,"��һbai��")(window.close)
mshta vbscript:msgbox("�������du��",36,"�ڶ���")(window.close) 