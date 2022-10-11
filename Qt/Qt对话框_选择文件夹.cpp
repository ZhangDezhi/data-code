//
//   Qt对话框_选择文件夹.cpp
//
// Created by ZhangDezhi on2020-08-21 17:12 
// Last Modified  : 2020-08-21 17:15:14
// Copyright © 2020  Zero Ltd. All Right reserved
//
//

void Widget::on_openSrcDirPushButton_clicked()
{
    //文件夹路径
    srcDirPath = QFileDialog::getExistingDirectory(
               this,                  //父窗口,
               "choose src Directory",//弹出菜单标题栏文字,
                "/");                 // 打开初始化目录

    if (srcDirPath.isEmpty())
    {
        return;
    }
    else
    {
        qDebug() << "srcDirPath=" << srcDirPath;
        srcDirPath += "/";
    }
}
