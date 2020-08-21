//
//   ZSingleApplication1.h
//
// Created by ZhangDezhi on2020-08-21 16:43 
// Last Modified  : 2020-08-21 16:47:44
// Copyright © 2020  Zero Ltd. All Right reserved
//
//
//方案一：使用Qt中的QSharedMemory,QLocalServer和QLocalSocket实现(不过需要在你的.pro里加上QT += network)
// "single_application.h"

#ifndef SINGLE_APPLICATION_H
#define SINGLE_APPLICATION_H

#include <QApplication>
#include <QSharedMemory>
#include <QLocalServer>

class SingleApplication : public QApplication

{
	Q_OBJECT
public:

	SingleApplication(int &argc, char *argv[], const QString uniqueKey);
	bool isRunning();
	bool sendMessage(const QString &message);
public slots:
	void receiveMessage();
signals:
	void messageAvailable(QString message);
private:
	bool _isRunning;
	QString _uniqueKey;
	QSharedMemory sharedMemory;
	QLocalServer *localServer;
	static const int timeout = 1000;
};

#endif // SINGLE_APPLICATION_H
