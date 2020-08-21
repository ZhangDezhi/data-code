//
//   Qt窗口最大化.cpp
//
// Created by ZhangDezhi on2020-08-21 16:26 
// Last Modified  : 2020-08-21 16:33:22
// Copyright © 2020  Zero Ltd. All Right reserved
//
//
(方法一)
window.showFullScreen(); //此方法只对顶级窗口有效. 对子窗口无效
/*
 * 原因说明:
 QT中窗口部件QWidget成员函数showFullScreen();
 是用于将窗口部件全屏显示，但是他只对窗口模式的部件有用。
 子窗口的特征是 Qt::SubWindow，不是独立的窗口。因此对其调用showFullScreen（）无效。

 子窗口使用:
 通过对对子窗口调 用：
 setWindowFlags（Qt::Dialog）；或setWindowFlags（Qt::Window）；
 将其设为窗口模式后，即可调用 showFullScreen();进行全屏显示了。

 子窗口恢复:
 如果要还原为普通窗口，调用setWindowFlags(Qt::subwindow)将子窗口设置为非顶级窗口，再调用showNormal()还原子窗口显示。
 *
 */

(方法二)

setWindowState(Qt::WindowMaximized);


(方法三)
//获得桌面大小(包括任务栏)
desk = QApplication.desktop();
rect = desk.availableGeometry();
self.resize(rect.width()-20,rect.height()-40);

    
