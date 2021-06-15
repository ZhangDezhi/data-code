//
//   main.cpp
//
// Created by ZhangDezhi on2021-06-15 17:23 
// Last Modified  : 2021-06-15 17:24:12
// Copyright © 2021  Zero Ltd. All Right reserved
//
//
#include <QApplication>
#include "mywidget.h"//自定义类的头文件
 
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w; //创建MyWidget的对象
    w.show();

    return a.exec();

}
