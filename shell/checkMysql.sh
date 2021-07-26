#!/bin/bash
#!Author:ZhangDezhi
# Create Time:2021-02-07 16:22
# Last Modified  : 2021-02-07 16:24:05
# Name:aaa.sh
# Version: v1.0
# Description: 检查mysql是否正常脚本


# mysql -uxopens -piscs200 -h172.16.4.209 << eof
# select count(*) from xopenshdb.his_event_tab where yymmdd>20210205;
# eof


echo $( mysql -uxopens -piscs200 -h $1 -e"

use xopensdb;

show tables LIKE '%his_event_tab%';

")
# select * from xopenshdb.data202102 where sname='Kytps_CD301AI0' and sdate=18663 and time=0 and flag<50;
# select * from xopenshdb.data202102 where sname='Kytps_CD301AI0' and sdate=18663 and time=0 and flag=55;
# select count(*) from xopenshdb.his_event_tab where yymmdd>20210205;
# show tables;