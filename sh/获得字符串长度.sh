利用${#str}来获取字符串的长度

str="ABCD"
echo ${#str}


#使用awk
echo ${str} | awk '{print length($0)}'


echo $str | awk -F "" '{print NF}'