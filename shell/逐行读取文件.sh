# 方法1：while循环中执行效率最高，最常用的方法。
function while_read_LINE_bottm(){
while read LINE
do
echo $LINE
done  < $FILENAME
}


#方法2 ： 重定向法；管道法: cat $FILENAME | while read LINE
Function While_read_LINE(){
cat $FILENAME | while read LINE
do
echo $LINE
done
}

#方法3： 文件描述符法
Function while_read_line_fd(){
Exec 3<&0
Exec 0<$FILENAME
While read LINE
Do
Echo $LINE
Exec 0<&<3
}

# 方法4    for  循环。

function  for_in_file(){
For  i  in  `cat $FILENAME`
do
echo $i
done
}

#-------------------------  使用 cat 命令 有个个坑
# 参考  : https://www.cnblogs.com/gavinwu/p/3140756.html

ver="unknow"
cat ../INSTALL.bat | while read LINE
do
    result=$(echo $LINE | grep "version")
    if [[ "$result" != "" ]]
    then
        echo "包含"
        ver="$LINE"
    fi
done
echo $ver   #得到结果为unknow, 这是因为在进行 cat的过程中， 相当于打开了一个新的shell，变量不在作用范围。

## 修改为
#{{{


    while read LINE
    do
        result=$(echo $LINE | grep "version")
        if [[ "$result" != "" ]]
        then
            ver="$LINE"
        fi
    done < "../INSTALL.bat"
    echo $ver
#}}}
