#!/bin/bash
#------------------------------------------
# v1.0
# Create by  :ZhangDezhi
# Create Time:2021-10-22 13:36
# Last Modified  : 2021-10-22 13:36:11
# This is a Script.
#------------------------------------------
seconds=$1
hour=$(echo "${seconds}/3600" | bc)
minute=$(echo "${seconds}/60%60" | bc)
sec=$(echo "${seconds}%60" | bc)
printf "%02d:%02d:%02d" $hour $minute $sec
