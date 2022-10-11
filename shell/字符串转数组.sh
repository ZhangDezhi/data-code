#!/bin/bash
#!Author:ZhangDezhi
# Create Time:2021-05-26 20:26
# Last Modified  : 2021-10-22 13:35:49
# Name:字符串转数组.sh
# Version: v1.0
# Description: This is a Script.
#!/bin/bash
str="A,B,C,D,E,F,G,H"

oldIFS=$IFS
IFS=,
arr=($str)

# echo ${arr}
# echo ${#arr[@]}
echo ${arr[@]}

for ((i=0;i<${#arr[@]};i++))
do
 echo value: ${arr[$i]}
done

IFS=$oldIFS

   # ${#arr[@]} 数组长度
   # ${arr[@]} 数组中的所有值
