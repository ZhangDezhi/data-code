@echo off
echo ������ӵ�������û���
echo.
for /f "skip=4 tokens=1-3" %%i in ('net user') do (
    if not "%%i"=="����ɹ���ɡ�" echo %%i
    if not "%%j"=="" echo %%j
    if not "%%k"=="" echo %%k
)
echo.
echo ��ǰ��¼�������˻��ǣ�%username%
pause>nul