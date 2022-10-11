//
//   时间戳.c
//
// Created by ZhangDezhi on2021-10-28 14:52 
// Last Modified  : 2021-10-28 14:52:49
// Copyright © 2021  Zero Ltd. All Right reserved
//
//
#include "usart.h" #include "time.h"
/* 定义结构体，时间为北京时间格式 */
typedef struct{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
}bj_time;

bj_time timestamp_to_bj_time(time_t timestamp);
time_t bj_time_to_timestamp(bj_time time);

int main(void)
{
    time_t timestamp;
    bj_time time;
    
    uart_init(115200);
    
    timestamp = 1593083510;
    printf("%d\r\n", timestamp);
    
    /* 时间戳转北京时间 */
    time = timestamp_to_bj_time(timestamp);
    /* 2020-6-25 19:11:50 */
    printf("%d-%d-%d %d:%d:%d\r\n",
        time.year, time.month, time.day, time.hour, time.minute, time.second);
    
    /* 北京时间转时间戳 */
    timestamp = bj_time_to_timestamp(time);
    printf("%d\r\n", timestamp);
    
    while(1)
    {
        ;
    }
}

bj_time timestamp_to_bj_time(time_t timestamp)
{
    bj_time time;
    
    struct tm *t;
    
    /* 加上8个小时 */
    timestamp += 8*60*60;
    t = localtime(&timestamp);
    
    /* 日期修正 */
    time.year = t->tm_year + 1900;
    time.month = t->tm_mon + 1;
    time.day = t->tm_mday;
    time.hour = t->tm_hour;
    time.minute = t->tm_min;
    time.second = t->tm_sec;
    
    return time;
}

time_t bj_time_to_timestamp(bj_time time)
{
    struct tm t;
    time_t timestamp = 0;
    
    /* 日期修正 */
    t.tm_year = time.year - 1900;
    t.tm_mon = time.month - 1;
    t.tm_mday = time.day;
    t.tm_hour = time.hour;
    t.tm_min = time.minute;
    t.tm_sec = time.second;

    timestamp = mktime(&t) - 8*60*60;
    return timestamp;
}

