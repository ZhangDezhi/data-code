//
//   Qt窗口置顶与取消.cpp
//
// Created by ZhangDezhi on2020-08-21 16:34 
// Last Modified  : 2020-08-21 16:34:56
// Copyright © 2020  Zero Ltd. All Right reserved
//
//
void MainWindow::on_windowTopButton_clicked()
{
　　if (m_flags == NULL)
　　{
　　　　m_flags = windowFlags();
　　　　setWindowFlags(m_flags | Qt::WindowStaysOnTopHint);
　　　　this->show();
　　}
　　else
　　{
　　　　m_flags = NULL;
　　　　setWindowFlags(m_flags);
　　　　this->show();
　　}
}


