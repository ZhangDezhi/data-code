#!/bin/bash
#------------------------------------------
# v1.0
# Create by  :ZhangDezhi
# Create Time:2021-06-03 17:30
# Last Modified  : 2021-06-03 17:30:54
# This is a Script.
#------------------------------------------


function firstroutine {
echo "running johns function"

}


function secondroutine {
echo "running glens function"

}




function thirdroutine {
echo "running adams function"

}


whiptail --title "Test" --checklist --separate-output "Choose:" 20 78 15 \
    "John" "" on \
    "Glen" "" off \
    "Adam" "" off 2>results


while read choice
do
    case $choice in
        John) firstroutine
            ;;
        Glen) secondroutine
            ;;
        Adam) thirdroutine
            ;;
        *)
            ;;
    esac
done < results 
