#!/bin/bash
#------------------------------------------
# v1.0
# Create by  :ZhangDezhi
# Create Time:2021-06-04 08:06
# Last Modified  : 2021-06-04 08:06:30
# This is a Script.
#------------------------------------------

PASSWORD=$(whiptail --title "Test Password Box" --passwordbox "Enter your password and choose Ok to continue." 10 60 3>&1 1>&2 2>&3)

exitstatus=$?
if [ $exitstatus = 0  ]; then
        echo "Your password is:" $PASSWORD
    else
            echo "You chose Cancel."
        fi
