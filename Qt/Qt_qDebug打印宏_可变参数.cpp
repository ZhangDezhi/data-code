#ifndef XLOG_H
#define XLOG_H

#include <stdio.h>
#include <QDebug>
#define XLOGD(format, ...)                                                          \
    {                                                                               \
        qDebug("LOG_DEBUG:%s line:%d\t" format, __FILE__, __LINE__, ##__VA_ARGS__); \
    }

#define XLOGI(format, ...)                                                         \
    {                                                                              \
        qDebug("LOG_INFO:%s line:%d\t" format, __FILE__, __LINE__, ##__VA_ARGS__); \
    }
#define XLOGE(format, ...)                                                          \
    {                                                                               \
        qDebug("LOG_ERROR:%s line:%d\t" format, __FILE__, __LINE__, ##__VA_ARGS__); \
    }


    //使用

    XLOGI("program.link() = %d",ret);