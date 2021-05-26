#!/bin/bash
#!Author:ZhangDezhi
# Create Time:2021-05-26 20:28
# Last Modified  : 2021-05-26 20:29:06
# Name:基本语句_if.sh
# Version: v1.0
# Description: This is a Script.
read a
read b
if (( $a == $b ))
then
    echo "a和b相等"
else
    echo "a和b不相等，输入错误"
fi



read age
if (( $age <= 2 )); then
    echo "婴儿"
elif (( $age >= 3 && $age <= 8 )); then
    echo "幼儿"
elif (( $age >= 9 && $age <= 17 )); then
    echo "少年"
elif (( $age >= 18 && $age <=25 )); then
    echo "成年"
elif (( $age >= 26 && $age <= 40 )); then
    echo "青年"
elif (( $age >= 41 && $age <= 60 )); then
    echo "中年"
else
    echo "老年"
fi
