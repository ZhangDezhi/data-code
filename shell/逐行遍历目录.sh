#假定目录text下有如下文件
    #目录：dir_1、dir_2、dir_3
    #文件：text_1、text_2

遍历目录下所有的文件是目录还是文件

#if -- if类型：
#!bin/sh
for file in ./*
do
    if test -f $file
    then
        echo $file 是文件
    fi
    if test -d $file
    then
        echo $file 是目录
    fi
done

#if --else 类型:
#!bin/sh
for file in ./*
do
    if test -f $file
    then
        echo $file 是文件
    else
        echo $file 是目录
    fi
done