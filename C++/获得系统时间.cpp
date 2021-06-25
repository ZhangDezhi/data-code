/*C program to get current system date and time in Linux.*/

#include <stdio.h>

//方法一需要
#include <time.h>

//方法二需要
#include <windows.h>

//
#include <iostream>

//方法三需要
#include <stdlib.h>

//方法四需要
#include <ctime>
int main() {

    //方法零
    timeval tp;
    gettimeofday(&tp, 0);
    time_t curtime = tp.tv_sec;
    tm *t = localtime(&curtime);
    printf("%02d:%02d:%02d:%03d\n", t->tm_hour, t->tm_min, t->tm_sec,
           tp.tv_usec / 1000);

    //方法一
    //仅仅使用C标准库,只能精确到秒级
    time_t t1 = time(0);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y/%m/%d %X %A 本年第%j天 %z", localtime(&t));
    puts(tmp);

    //方法二
    // 能精确到毫秒,使用零WindowsAPI
    SYSTEMTIME sys;
    GetLocalTime(&sys);
    printf("%4d/%02d/%02d %02d:%02d:%02d.%03d 星期%ld/n", sys, wYear, sys,
           wMonth, sys);

    //方法三
    //利用系统函数,还能修改系统时间

    system("time");

    //方法四
    //将当前事件折算为秒,再运算获得
    time_t now_time;
    now_time = time(NULL);
    cout << now_time;

    time_t T = time(NULL);
    struct tm tm = *localtime(&T);
    printf("System Date is: %02d/%02d/%04d\n", tm.tm_mday, tm.tm_mon + 1,
           tm.tm_year + 1900);
    printf("System Time is: %02d:%02d:%02d\n", tm.tm_hour, tm.tm_min,
           tm.tm_sec);

    //输出:
    // System Date is: 13/03/2014
    // System Time is: 12:40:59

    //
    string time = getTime();
    cout << time << endl;

    return 0;
}

string getTime() {

    time_t timep;
    time(&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
    return tmp;
}

