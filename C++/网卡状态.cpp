//
//   main.cpp
//
// Created by ZhangDezhi on2021-06-09 22:10 
// Last Modified  : 2021-07-07 17:26:57
// Copyright © 2021  Zero Ltd. All Right reserved
//
//
//总结：
//该程序是測试 ifconfig 命令中 指定网卡 是实用 RUNNING 。
//
//能够配合 ifconfig eth0 up 和 ifconfig eth0 down 測试。
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/if.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>


char *net_detect(char* net_name)
{
    int skfd = 0;
    struct ifreq ifr;

    skfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(skfd < 0) {
        printf("%s:%d Open socket error!\n", __FILE__, __LINE__);
        return NULL;

    }

    strcpy(ifr.ifr_name, net_name);

    if(ioctl(skfd, SIOCGIFFLAGS, &ifr) <0 ) {
        printf("%s:%d IOCTL error!\n", __FILE__, __LINE__);
        printf("Maybe ethernet inferface %s is not valid!", ifr.ifr_name);
        close(skfd);
        return NULL;

    }

    if(ifr.ifr_flags & IFF_RUNNING) {
        return "UP";

    } else {
        return "DOWN";
    }


}
int main()
{
    printf("eth0 %s\n",net_detect("eth0"));
    printf("enp0s31f6 %s\n",net_detect("enp0s31f6"));
    return 0;
}
