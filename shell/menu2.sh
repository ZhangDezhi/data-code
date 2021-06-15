#!/bin/bash
#------------------------------------------
# v1.0
# Create by  :ZhangDezhi
# Create Time:2021-06-03 17:44
# Last Modified  : 2021-06-03 17:44:41
# This is a Script.
#------------------------------------------


whiptail --title "Test" --checklist --separate-output "Choose:" 20 78 15 \
    "John" "" on \
    "Glen" "" off \
    "Adam" "" off 2>results

while read choice
do
    case $choice in
        John) echo "You chose John"
            ;;
        Glen) echo "You chose Glen"
            ;;
        Adam) echo "You chose Adam"
            ;;
        *)
            ;;
    esac
done < results
