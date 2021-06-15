#!/bin/bash
#------------------------------------------
# v1.0
# Create by  :ZhangDezhi
# Create Time:2021-06-04 14:44
# Last Modified  : 2021-06-04 14:44:58
# This is a Script.
#------------------------------------------
#!/bin/sh
while true2021/06/04 o
    count=`ps -ef|grep node|grep -v grep`
    if [ "$?" != "0"  ]14:44:56 hen
        echo "wdt is running"
        ./wdt 5
    else
        echo "wdt is stop..."
        break
    fi
    sleep 3
done
