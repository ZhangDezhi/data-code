set -euo pipefail
# ָ��Ҫ���ɵ��ļ���
file=masserver_tmp
# ָ��������
line_cnt=13

# �����ڱ����룬ÿ��ִ������ļ��Ա�֤�ļ�������ָ������
cat /dev/null > $file

n=0
while [ $n -lt $line_cnt ]; do
	echo -e >> $file
        n=$((n+1))
done
# echo "$n empty lines have been inserted in $file."

m_line=10  #�к�
pingstr="AAAAAAA"
sed -i "${m_line}c${pingstr}"  $file