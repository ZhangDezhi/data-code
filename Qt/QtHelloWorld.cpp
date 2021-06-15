//
//   QtMain.cpp
//
// Created by ZhangDezhi on2021-06-15 17:16 
// Last Modified  : 2021-06-15 17:22:09
// Copyright © 2021  Zero Ltd. All Right reserved
//
//
#include <QApplication>
#include <QWidget>
#include <QPushButton>

int main(int argc, char *argv[])
{

    QApplication app(argc,argv); //初始化

    QWidget w; // 创建窗口对象

    QPushButton button("^_^"); 
    button.setParent(&w); //按钮放到创建

    QPushButton button("^-^",&w);

    w.show();//窗口默认隐藏,使之显示

    app.exec();//主事件循环(程序运行等待键盘/鼠标操作)
    return 0;
}
