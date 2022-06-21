#!/usr/bin/sh


#方法一
#通过 set 命令和位置参数来模拟数组

# 定义数组
set 'word 1' word2 word3

# 输出数组的第一个元素
echo $1

# 输出数组的第二个元素
echo $2

# 输出数组的第三个元素
echo $3

# 输出数组的所有元素
echo $*
echo $@

# 向数组中增加一个元素
set -- "$@" word4
echo $4

# 查看数组元素的个数
echo $#

# 遍历数组元素
for i in do "$@"; do
  echo "$i"
done

# 从数组中删除一个元素
shift
echo $@

# 删除数组的所有元素
set x; shif


#方法二
#使用 eval 命令模拟数组


定义数组并遍历数组元素：

#!/bin/sh
eval a1=word1
eval a2=word2
eval a3=word3
for i in 1 2 3; do
  eval echo "The $i element of array is: \$a$i"
done


根据用户输入的一句话来定义数组并遍历数组元素：

#!/bin/sh
echo "Enter the sentence:"
read str
n=0
for word in $str; do
  n=`expr $n + 1`
  eval a$n="$word"
  eval echo "The $n element of array is: \$a$n"
done