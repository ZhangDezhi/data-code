//
//   Qt_定时器.cpp
//
// Created by ZhangDezhi on2020-07-24 22:39 
// Last Modified  : 2020-07-25 07:01:16
// Copyright © 2020  Zero Ltd. All Right reserved
//
//
#include<QTimer>

//新建一个定时器
QTimer *time_clock = new QTimer(parent);

//连接定时器的信号和槽.利用定时器的timeout();
connect(time_clock,SIGNAL(timeout(),this,SLOT(slottimedone())));

time_clock->start(2000);
