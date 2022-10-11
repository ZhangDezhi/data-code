//方法一:  使用QPrecess 
void MainWindow::reboot()
{

    QString program = QApplication::applicationFilePath();

    QStringList arguments = QApplication::arguments();

    QString workingDirectory = QDir::currentPath();

    QProcess::startDetached(program, arguments, workingDirectory);

    QApplication::exit();

}

// 方法二: 参考 : https://blog.csdn.net/mysunshinexia01/article/details/80556593