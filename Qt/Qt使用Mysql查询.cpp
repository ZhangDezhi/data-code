//
//   Qt使用Mysql查询.cpp
//
// Created by ZhangDezhi on2020-07-02 13:19 
// Last Modified  : 2020-07-02 13:38:03
// Copyright © 2020  Zero Ltd. All Right reserved
//
//
// Qt连接mysql需要库: libmysql.dll
//
//pro 文件添加  QT += sql

//查看已经封装的驱动
//
#include <QCoreApplication>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QStringList>
 
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QStringList drivers = QSqlDatabase::drivers();
    qDebug() << drivers;
    return a.exec();


}

//查询数据
#include <iostream>
#include <Qtsql/QSqlDatabase>
#include <Qtsql/QSqlQuery>
#include <QtSql/QSql>
#include <QDebug>
 
int main(int argc, char *argv[])
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");
	db.setDatabaseName("weather");
	db.setUserName("root");
	db.setPassword("123");
	if(db.open())
	{
		QSqlQuery query;
		query.exec("select * from weather");
		while(query.next())
		{
			int id = query.value(0).toInt();
			QString str = query.value(1).toString();
			qDebug() << id << "|" << str;
		}
		db.close();
	}
	else
	{
		qDebug() << "opened error";
	}
	return 0;
}
