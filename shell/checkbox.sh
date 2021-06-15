#!/bin/bash
#------------------------------------------
# v1.0
# Create by  :ZhangDezhi
# Create Time:2021-06-04 08:14
# Last Modified  : 2021-06-04 08:15:32
# This is a Script.
#------------------------------------------
DISTROS=$(whiptail --title "Test Checklist Dialog" --checklist \
"Choose preferred Linux distros" 15 60 4 \
"debian" "Venerable Debian" ON \
"ubuntu" "Popular Ubuntu" OFF \
"centos" "Stable CentOS" ON \
"mint" "Rising Star Mint" OFF 3>&1 1>&2 2>&3)

exitstatus=$?
if [ $exitstatus = 0  ]; then
        echo "Your favorite distros are:" $DISTROS
    else
            echo "You chose Cancel."
        fi
