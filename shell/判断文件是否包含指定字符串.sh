#����1 grep

#grep -c ���� file��,��strƥ�������
grep -c str file 

FIND_FILE = "./demo.txt"
FIND_STR = "Hello"
if [$(grep -c "$FIND_STR" $FIND_FILE) -ne '0' ]; then 
echo "The File hans"
exit 0
fi 

#������  cat ��while ��read ��� 

FIND_FILE = "./demo.txt"
FINE_STR = "HELLO"

cat $FIND_FILE | while read line  
do 
if [[$line =~ $FIND_STR ]];then 
echo "�ҵ��ַ���"
fi 
done 
