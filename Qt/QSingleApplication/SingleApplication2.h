//
//   SingleApplication2.h
//
// Created by ZhangDezhi on2020-08-21 16:45 
// Last Modified  : 2020-08-21 16:48:11
// Copyright © 2020  Zero Ltd. All Right reserved
//
//方案二：使用Qt中的QSharedMemory,和QTimert实现,
//
// "single_application.h"
#ifndef SINGLE_APPLICATION_H
#define SINGLE_APPLICATION_H

#include <QApplication>
#include <QSharedMemory>

class SingleApplication : public QApplication
{
	Q_OBJECT
public:
	SingleApplication(int &argc, char *argv[], const QString uniqueKey);
	bool isRunning();
	bool sendMessage(const QString &message);
public slots:
	void checkForMessage();
signals:
	void messageAvailable(QString message);
private:
	bool _isRunning;
	QSharedMemory sharedMemory;
};

#endif // SINGLE_APPLICATION_H
