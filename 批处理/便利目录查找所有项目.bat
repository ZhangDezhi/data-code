REM 'GBK
@echo off & color 0A
::ָ����ʵ�ļ���?? 
set DIR="E:\Server\Repository\VMZZ4\smmi"
echo DIR=%DIR%

:: ���� /R ��ʾ��Ҫ�������ļ���,ȥ����ʾ���������ļ���
:: %%f ��һ������,�����ڵ�����,�����������ֻ����һ����ĸ���,ǰ�����%%
:: ��������ͨ���,����ָ����׺��,*.*��ʾ�����ļ�
for /R %DIR% %%f in (*.*) do ( 
echo %%f
)
pause
