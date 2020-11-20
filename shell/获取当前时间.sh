#!bin/bash
time1=$(date)
echo $time1    # 2018年 09月 30日 星期日 15:55:15 CST

time2=$(date "+%Y%m%d%H%M%S")
echo $time2    #输出格式: 20180930155515


time3=$(date "+%Y-%m-%d %H:%M:%S")
echo $time3   # 2018-09-30 15:55:15


time4=$(date "+%Y.%m.%d")
echo $time5   # 2018.09.30

time4=$(date "+%y.%m.%d")
echo $time5   # 18.09.30