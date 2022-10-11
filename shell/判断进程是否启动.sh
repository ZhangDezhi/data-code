#! /bin/bash

PROC_NAME=docker
ProcNumber=`ps -ef |grep -w $PROC_NAME|grep -v grep|wc -l`
if [ $ProcNumber -le 0 ];then
   echo "testPro is not run"
   sh /root/shell/docker-start.sh
else
   echo "testPro is  running.."
fi