//
//   Qt生成随机数.cpp
//
// Created by ZhangDezhi on2020-07-02 13:15 
// Last Modified  : 2020-07-02 13:18:56
// Copyright © 2020  Zero Ltd. All Right reserved
//
//
//方法一
#include <QTime>

QTime time;
time = QTime::currentTime();
qsrand(time.msec() + time.second()*1000);
int n=qrand() % 5;  //产生5以内的随机数

//方法二:
#include <ctime>
qsrand(time(NULL));
int n = qrand()%5;

