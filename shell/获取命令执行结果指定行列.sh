#!/bin/bash
#!Author:ZhangDezhi
# Create Time:2021-05-19 09:20
# Last Modified  : 2021-05-19 09:23:09
# Name:获取命令执行结果指定行列.sh
# Version: v1.0

#) awk (从第一行开始计数)
#1.获取第一列
ps -aux | grep watchdog | awk '{print $1}'
#2. 获取第一列，第二列，第三列
ps -aux | grep watchdog | awk '{print $1, $2, $3}'
#3. 获取第一行的第一列，第二列，第三列
ps -aux | grep watchdog | awk 'NR==1{print $1, $2, $3}'
#4. 获取行数NR
ps -aux | grep watchdog | awk 'END{print NR}'
#5. 获取列数NF（这里是获取最后一行的列数，注意每行的列数可能是不同的）
ps -aux | grep watchdog | awk 'END{print NF}'
#6. 获取最后一列
ps -aux | grep watchdog | awk '{print $NF}'
#7. 对文件进行操作
awk '{print $1}' fileName
#8. 指定分隔符（这里以:分割）
ps -aux | grep watchdog |awk  -F':' '{print $1}'
#9. 超出范围不报错
ps -aux | grep watchdog | awk '{print $100}'




#)sed(从第一行开始计数)

#1. 指定第一行(sed -n 指定行数)
ps -aux | grep watchdog | sed -n 2p
#2. 第一至十行
ps -aux | grep watchdog | sed -n 1,10p
#3. 超出范围不报错，第一行是1不能是0，否则报错
ps -aux | grep watchdog | sed -n 1,100p

