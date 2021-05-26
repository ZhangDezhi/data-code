#!/bin/bash
#!Author:ZhangDezhi
# Create Time:2021-05-25 10:00
# Last Modified  : 2021-05-25 10:01:23
# Name:判断字符串开头.sh
# Version: v1.0
# Description: This is a Script.
if expr "$target" : '^\[1\]' 
then
    echo "是以[1]开头"
else
    echo "不对"
fi
