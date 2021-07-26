#!/bin/bash
#------------------------------------------
# v1.0
# Create by  :ZhangDezhi
# Create Time:2021-06-30 08:36
# Last Modified  : 2021-06-30 08:39:42
# This is a Script.
#------------------------------------------
# 距1970年1月1日的天数

#由日期计算天数,
echo $(($(date --date="2008/09/04" +%s)/86400 +1))

# 由天数计算出日期
#date -u -d "1970-01-01 UTC $((14126 * 86400 )) seconds"
date -u -d "1970-01-01 UTC $(($1 * 86400 )) seconds"

# 二
date -d '1970-01-01 UTC '$1' seconds' +"%Y-%m-%d %T %z"
