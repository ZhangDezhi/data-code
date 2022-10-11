//
//   Qt最大化最小化关闭按钮设置.cpp
//
// Created by ZhangDezhi on2020-08-21 16:38 
// Last Modified  : 2020-08-21 16:40:33
// Copyright © 2020  Zero Ltd. All Right reserved
//
//
// QDialog 添加最大化/最小化按钮(默认没有)
this->setWindowFlags(Qt::Dialog | Qt::WindowMinMaxButtonsHint | Qt::WindowCloseButtonHint);


// 禁制最大化按钮
this->setWindowFlags(windowFlags() &~ Qt::WindowMaximizeButtonHint);
