//
//   使用main.cpp
//
// Created by ZhangDezhi on2020-08-21 16:46 
// Last Modified  : 2020-08-21 16:47:21
// Copyright © 2020  Zero Ltd. All Right reserved
//
//
// "main.cpp"
#include "single_application.h"
int main(int argc, char *argv[])
{
	SingleApplication app(argc, argv, "some unique key string");
	if (app.isRunning())
	{
		app.sendMessage("message from other instance.");
		return 0;
	}

	MainWindow *mainWindow = new MainWindow();

        // connect message queue to the main window.
	QObject::connect(&app, SIGNAL(messageAvailable(QString)), mainWindow, SLOT(receiveMessage(QString)));

        // show mainwindow.
	mainWindow->show();
	return app.exec();

}
