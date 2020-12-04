#!/bin/sh
 
#测试各种字符串比较操作。
#shell中对变量的值添加单引号，爽引号和不添加的区别：对类型来说是无关的，即不是添加了引号就变成了字符串类型，
#单引号不对相关量进行替换，如不对$符号解释成变量引用，从而用对应变量的值替代，双引号则会进行替代
#author:tenfyguo
 
A="$1"
B="$2"
 
echo "输入的原始值：A=$A,B=$B"
 
#判断字符串是否相等
if [ "$A" = "$B" ];then
echo "[ = ]"
fi
 
#判断字符串是否相等，与上面的=等价
if [ "$A" == "$B" ];then
echo "[ == ]"
fi
 
#注意:==的功能在[[]]和[]中的行为是不同的，如下
 
#如果$a以”a”开头(模式匹配)那么将为true 
if [[ "$A" == a* ]];then
echo "[[ ==a* ]]"
fi
 
#如果$a等于a*(字符匹配),那么结果为true
if [[ "$A" == "a*" ]];then
echo "==/"a*/""
fi
 
 
#File globbing(通配) 和word splitting将会发生, 此时的a*会自动匹配到对应的当前以a开头的文件
#如在当前的目录中有个文件：add_crontab.sh,则下面会输出ok
#if [ "add_crontab.sh" == a* ];then 
#echo "ok"
#fi
if [ "$A" == a* ];then
echo "[ ==a* ]"
fi
 
#如果$a等于a*(字符匹配),那么结果为true
if [ "$A" == "a*" ];then
echo "==/"a*/""
fi
 
#字符串不相等
if [ "$A" != "$B" ];then
echo "[ != ]"
fi
 
#字符串不相等
if [[ "$A" != "$B" ]];then
echo "[[ != ]]"
fi
 
#字符串不为空，长度不为0
if [ -n "$A" ];then
echo "[ -n ]"
fi
 
#字符串为空.就是长度为0.
if [ -z "$A" ];then
echo "[ -z ]"
fi
 
#需要转义<，否则认为是一个重定向符号
if [ $A /< $B ];then
echo "[ < ]" 
fi
 
if [[ $A < $B ]];then
echo "[[ < ]]" 
fi
 
#需要转义>，否则认为是一个重定向符号
if [ $A /> $B ];then
echo "[ > ]" 
fi
 
if [[ $A > $B ]];then
echo "[[ > ]]" 
fi

# 忽略大小写比较 

##   借助tr命令来处理
name1="TOm"
name2="tom"
 
temp1=$(echo $name1 | tr [a-z] [A-Z])    # 将name1全部转变成大写再做比较
temp2=$(echo $name2 | tr [a-z] [A-Z])    # 将name2全部转变成大写再做比较
 
if [ x"$temp1" = x"$temp2" ];then        # x$"temp1"前面加x防止其中为空
    echo "OK"
else
    echo "NO"
fi

## 借助grep命令来处理
name="TOM"
 
if echo "$name" | grep -qwi "tom"
then
    echo "OK"
else
    echo "NO"
fi 
#    -q        # 静默的方式，即不会产生输出，成功则$?返回0，刚好走if的条件分支，非常巧妙！
#    -i         # 匹配字符串，但忽略大小写
#    -w       # 按照单词进行匹配 

# 借助shopt命令来处理

name1="TOM"
name2="tom"
 
shopt -s nocasematch   # 打开Bash的开关，忽略大小写
 
case "$name1" in
    $name2)  echo "MATCH"  ;;
         *)  echo "NO"     ;;
esac