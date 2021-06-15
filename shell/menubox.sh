#!/bin/bash
#------------------------------------------
# v1.0
# Create by  :ZhangDezhi
# Create Time:2021-06-04 08:07
# Last Modified  : 2021-06-04 08:08:10
# This is a Script.
#------------------------------------------

OPTION=$(whiptail --title "Test Menu Dialog" --menu "Choose your option" 15 60 4 \
    "1" "Grilled Spicy Sausage" \
"2" "Grilled Halloumi Cheese" \
"3" "Charcoaled Chicken Wings" \
"4" "Fried Aubergine"  3>&1 1>&2 2>&3)

exitstatus=$?
if [ $exitstatus = 0  ]; then
    echo "Your chosen option:" $OPTION
else
    echo "You chose Cancel."
fi
