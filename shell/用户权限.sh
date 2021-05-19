#!/bin/bash
#!Author:ZhangDezhi
# Create Time:2021-05-08 13:49
# Last Modified  : 2021-05-08 13:51:18
# Name:用户权限.sh
# Version: v1.0
# Description: This is a Script.


isudo chown -R $(whoami):root /usr/local/share/zsh 
sudo chown -R $(whoami):root /usr/local/share/zsh/* 
