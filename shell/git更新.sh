#!/bin/bash
#!Author:ZhangDezhi
# Create Time:2020-12-16 19:43
# Last Modified  : 2020-12-16 19:43:33
# Name:git更新.sh
# Version: v1.0
# Description: This is a Script.
# 本地文件是否发生了改变
is_change=$(git status -s)

# 当前分支
branch=$(git symbolic-ref --short -q HEAD)

# git.user.name
guser=$(git config user.name)

if [ 0 -lt ${#is_change} ]; then
remark="update"
git add . && git commit -m "$guser $remark" && git pull origin $branch && git push origin $branch
else
echo "本地没有改变, 正在拉取代码";
git pull origin $branch
fi

