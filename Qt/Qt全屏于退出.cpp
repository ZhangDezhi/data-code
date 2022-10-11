//
//   Qt全屏于退出.cpp
//
// Created by ZhangDezhi on2020-08-21 16:35 
// Last Modified  : 2020-08-21 16:37:58
// Copyright © 2020  Zero Ltd. All Right reserved
//
//
showFullScreen() // Qt全屏显示函数
showMaximized() // Qt最大化显示函数
showMinimized() // Qt最小化显示函数
resize(x, y) // Qt固定尺寸显示函数
setMaximumSize(w, h) // Qt设置最大尺寸函数
setMinimumSize(w, h) // Qt设置最小尺寸函数

    /*
     *  showFullScreen() 和 showNormal() 只对顶级窗口有效果，对子窗口无效
     *  子窗口全屏方法:
     *  将要全屏的 Qt 子窗口调用 setWindowFlags(Qt::Window) 将其类型提升为顶级窗口模式，然后调用 showFullScreen() 函数将子窗口全屏显示。
     *  当然全屏后还要恢复正常，即调用 setWindowFlags(Qt::subwindow) 将子窗口设置为非顶级窗口，再调用 showNormal() 还原子窗口显示。
     */

    //全屏显示:
VideoWidget->setWindowFlags(Qt::Window);
VideoWidget->showFullScreen();


    //退出全屏:
VideoWidget->setWindowFlags(Qt::SubWindow);
VideoWidget->showNormal();
