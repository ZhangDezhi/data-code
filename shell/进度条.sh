#!/bin/bash
#------------------------------------------
# v1.0
# Create by  :ZhangDezhi
# Create Time:2021-05-31 09:41
# Last Modified  : 2021-05-31 09:43:18
# This is a Script.
#------------------------------------------
#whiptail


msgs=( "Downloading" "Verifying" "Unpacking" "Almost Done" "Done" )

for i in {1..5}; do
    sleep 1
    echo XXX
    echo $(( i * 20 ))
    echo ${msgs[i-1]}
    echo XXX
done |whiptail --gauge "Please wait while installing" 6 60 0

#) 2 简单
{
    for ((i = 0 ; i <= 100 ; i+=20)); do
        sleep 1
        echo $i
    done
} | whiptail --gauge "Please wait while installing" 6 60 0
