#!/bin/bash
#------------------------------------------
# v1.0
# Create by  :ZhangDezhi
# Create Time:2021-05-31 09:30
# Last Modified  : 2021-05-31 09:34:02
# This is a Script.
#------------------------------------------

function read_dir() {
for file in $(ls $1)
do
    if [ -f $file ]
    then 
        echo $1/$file
    else
        read_dir $1/$file
    fi

    #if [ -d $file ]
    #then 
    #    read_dir  $1/$file
    #else
    #    echo $1/$file
    #fi
}

read_dir "~/Desktop/"
