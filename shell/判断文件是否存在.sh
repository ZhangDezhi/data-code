#!/bin/bash
#------------------------------------------
# v1.0
# Create by  :ZhangDezhi
# Create Time:2021-10-22 13:20
# Last Modified  : 2021-10-22 13:24:56
# This is a Script.
#------------------------------------------

# 判断是否有upload文件夹，没有则创建，用于存储图片
if [ ! -d "${CRTDIR}/upload"  ]; then
    mkdir ${CRTDIR}/upload
fi

# 判断是否有logs文件夹，没有则创建，用于存储日志
if [ ! -d "${CRTDIR}/logs"  ]; then
    mkdir ${CRTDIR}/logs
fi

# 判断logs文件夹下是否有upload.log文件，没有则创建，用于记录项目日志
if [ ! -f "${CRTDIR}/logs/upload.log"  ]; then
    touch ${CRTDIR}/logs/upload.log
fi



#!/bin/bash
# 判断文件是否存在不存在、创建文件并输入内容
file="/root/test.txt"

if [ ! -f  $file  ]13:24:45 hen
    echo "ok1" >> $file
else
    cat $file
fi
