����${#str}����ȡ�ַ����ĳ���

str="ABCD"
echo ${#str}


#ʹ��awk
echo ${str} | awk '{print length($0)}'


echo $str | awk -F "" '{print NF}'