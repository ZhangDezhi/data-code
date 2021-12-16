#!/bin/bash
#------------------------------------------
# v1.0
# Create by  :ZhangDezhi
# Create Time:2021-10-22 13:30
# Last Modified  : 2021-10-22 13:31:06
# This is a Script.
#------------------------------------------

#!/bin/sh



STRING=



if [ -z "$STRING"  ]; then

    echo "STRING is empty"

fi



if [ -n "$STRING"  ]; then
    echo "STRING is not empty"

fi


● -z ：判断 string 是否是空串

● -n ：判断 string 是否是非空串



判断字符串为空的方法有三种：
if [ "$str" =  ""  ]
    if [ x"$str" = x  ]
        if [ -z "$str"  ] （-n 为非空）
