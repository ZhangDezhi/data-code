//
//   Qt_DateTime示例.cpp
//
// Created by ZhangDezhi on2020-07-24 22:37 
// Last Modified  : 2020-07-24 22:38:50
// Copyright © 2020  Zero Ltd. All Right reserved
//
//


QLabel *datetime = new QLabel();
QDateTime *datetime = new QDateTime(QDateTime::currentDateTime());
datetime->setText(datatime->date().toString());
datelabel->show();
