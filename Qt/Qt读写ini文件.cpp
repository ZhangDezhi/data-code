//
//   mian.cpp
//
// Created by ZhangDezhi on2020-07-02 21:01 
// Last Modified  : 2020-07-02 21:11:08
// Copyright © 2020  Zero Ltd. All Right reserved
//
//
/*
 *  .ini 文件是Initialization File的缩写，即初始化文件。后缀名也不一定是".ini"也可以是".cfg"，".conf ”或者是".txt"。
 *
 *
 *  INI文件由节、键、值组成。
 *
 *    +---------------+
 *    |  [节]         |
 *    |  键=值 ;注释  |
 *    +---------------+
 * 
 *
 *
 *
 *
 *
 */


#include <QtCore/QCoreApplication>
#include <QSettings>
int main(int argc, char *argv[])
{

   QCoreApplication a(argc, argv);
   //写入
   //
   //QSettings构造函数的第一个参数是ini文件的路径,
   //第二个参数表示针对ini文件,
   //第三个参数可以缺省
   QSettings *configIniWrite = new QSettings("hahaya.ini", QSettings::IniFormat);
   configIniWrite->setValue("/ip/first", "192.168.0.1");
   configIniWrite->setValue("ip/second", "127.0.0.1");
   configIniWrite->setValue("port/open", "2222");
   delete configIniWrite;



   //读取
   //
   QSettings *configIniRead = new QSettings("hahaya.ini", QSettings::IniFormat);
   QString ipResult = configIniRead->value("/ip/second").toString();
   QString portResult = configIniRead->value("/port/open").toString();
   //打印得到的结果
   qDebug() << ipResult;
   qDebug() << portResult;
   delete configIniRead;

   return a.exec();
}
