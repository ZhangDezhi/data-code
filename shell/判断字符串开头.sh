#!/bin/bash
#!Author:ZhangDezhi
# Create Time:2021-05-25 10:00
# Last Modified  : 2021-10-22 13:29:47
# Name:判断字符串开头.sh
# Version: v1.0
# Description: This is a Script.
if expr "$target" : '^\[1\]' 
then
    echo "是以[1]开头"
else
    echo "不对"
fi


vech="Bus"
[[ $vech = B*  ]] && echo "Start with B"

vech="Car"
[[ $vech = B*  ]] && echo "Start with B"
[[ $vech = B*  ]] && echo "Start with B" || echo "Not matched"




#!/bin/bash
input="xBus"

if [[ $input = B*  ]]
then
    echo "Start with B"
else
    echo "No match"
fi


#!/bin/bash
input="/path/to/txt/file"
while IFS= read -r var
do
      echo "$var"
  done < "$input"


#!/bin/bash
input="/path/to/txt/file"
while IFS= read -r var
do
    #
    # 如果$var的值已井号开头，则忽略它
    #
    [[ $var =~ ^#.*  ]] && continue
    echo "$var"
done < "$input"


FS='|' read -r t u
do
    # 忽略所有以井号#开头的配置行
    [[ $t =~ ^#.*  ]] && continue
    echo "Working on $t and $u"

done < "$INPUT_FILE"




#!/bin/bash
# 接受CLI参数进行测试,默认值设置为 'Bus'
input="${1:-Bus}"
echo -n "$input starts with 'B' : "
case "$input" in
    B*)
        echo "yes";;
    *)
        echo "no";;
esac

