@echo off
echo;
echo ��ǰIP��ַ�б�
for /f "tokens=16" %%i in ('ipconfig ^|find /i "ipv4"') do (
set ip=%%i
echo %%i
)

::Ŀǰ�ǻ�ȡ���� ipv4 ��ַ�����һ��
echo;
set url=http://%ip%/
echo ���ɵ�ַ��%url%
