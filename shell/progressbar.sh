#!/bin/bash
#------------------------------------------
# v1.0
# Create by  :ZhangDezhi
# Create Time:2021-06-04 08:16
# Last Modified  : 2021-06-04 08:16:18
# This is a Script.
#------------------------------------------

{
    for ((i = 0 ; i <= 100 ; i+=20)); do
        sleep 1
        echo $i
    done

} | whiptail --gauge "Please wait while installing" 6 60 0
