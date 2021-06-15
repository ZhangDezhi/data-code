#!/bin/bash
#------------------------------------------
# v1.0
# Create by  :ZhangDezhi
# Create Time:2021-06-03 17:42
# Last Modified  : 2021-06-03 17:43:35
# This is a Script.
#------------------------------------------


whiptail --menu "Preferred Linux Distro" 10 40 4 \
    debian "Venerable Debian" off  \
    ubuntu "Popular Ubuntu"   on   \
    fedora "Hackish Fedora"   off  \
    centos "Stable Centos"    off  \
    mint "Rising Star Mint"   off  2>distrochoice
