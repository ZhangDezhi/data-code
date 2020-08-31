//
//   Qt对话框_选择文件.cpp
//
// Created by ZhangDezhi on2020-08-21 17:15 
// Last Modified  : 2020-08-21 17:19:33
// Copyright © 2020  Zero Ltd. All Right reserved
//
//

void Widget::slotBtnClick()
{
    QString s = QFileDialog::getOpenFileName(
                this,                                //父窗口
                "选择要播放的文件",                  //弹出界面菜单栏
                "/",                                 //初始化目录
                "视频文件 (*.flv *.rmvb *.avi *.mp4);; 所有文件 (*.*);; " //设置打开文件类型, 不同类型间有;;
                );
    qDebug() << "path=" << s;
    if (!s.isEmpty())
    {

    }
}
