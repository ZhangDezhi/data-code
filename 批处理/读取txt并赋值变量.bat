REM 'GBK
@echo off
echo ��ȡ��������ַ�ļ���
setlocal enabledelayedexpansion REM ����ʡ��
for /f  "delims="  %%a in (a.txt)  do (
  set value=%%a
   REM ʹ�����ַ�ʽ
  echo !value!     
)
REM Pause>Nul  REM ����ʾ���밴�����������
Pause

