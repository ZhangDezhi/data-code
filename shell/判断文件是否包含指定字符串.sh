#方法1 grep

#grep -c 返回 file中,与str匹配的行数
grep -c str file 

FIND_FILE = "./demo.txt"
FIND_STR = "Hello"
if [$(grep -c "$FIND_STR" $FIND_FILE) -ne '0' ]; then 
echo "The File hans"
exit 0
fi 

#方法二  cat 、while 、read 组合 

FIND_FILE = "./demo.txt"
FINE_STR = "HELLO"

cat $FIND_FILE | while read line  
do 
if [[$line =~ $FIND_STR ]];then 
echo "找到字符串"
fi 
done 
