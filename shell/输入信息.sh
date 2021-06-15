#!/bin/bash
#------------------------------------------
# v1.0
# Create by  :ZhangDezhi
# Create Time:2021-06-03 17:49
# Last Modified  : 2021-06-03 17:49:26
# This is a Script.
#------------------------------------------
PET=$(whiptail --title "Test Free-form Input Box" --inputbox "What is your pet's name?" 10 60 Wigglebutt 3>&1 1>&2 2>&3)

exitstatus=$?
if [ $exitstatus = 0  ]; then
        echo "Your pet name is:" $PET
    else
            echo "You chose Cancel."
        fi
