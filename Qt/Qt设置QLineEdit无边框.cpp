//
//   Qt设置QLineEdit无边框.cpp
//
// Created by ZhangDezhi on2020-07-03 08:54 
// Last Modified  : 2020-07-03 08:54:35
// Copyright © 2020  Zero Ltd. All Right reserved
//
//
color: rgb(255, 255, 255);
            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 rgb(196,164,0), stop:0.3 rgb(191,152,150), stop:1 rgb(172,140,0));
            border:10px;
            border-radius:10px; /*border-radius控制圆角大小*/
            padding:20px 40px;  


QLineEdit 无边框 
  ui->lEt_Autograph->setStyleSheet("QLineEdit{background-color:transparent}"

                                     "QLineEdit{border-width:0;border-style:outset}");
