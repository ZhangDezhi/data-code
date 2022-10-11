set -euo pipefail
# 指定要做成的文件名
file=masserver_tmp
# 指定空行数
line_cnt=13

# 适用于本代码，每次执行清空文件以保证文件行数是指定行数
cat /dev/null > $file

n=0
while [ $n -lt $line_cnt ]; do
	echo -e >> $file
        n=$((n+1))
done
# echo "$n empty lines have been inserted in $file."

m_line=10  #行号
pingstr="AAAAAAA"
sed -i "${m_line}c${pingstr}"  $file