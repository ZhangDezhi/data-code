//一
QMessageBox::information(NULL, "Title", "Content");

//二
QMessageBox::information(NULL, "Title", "Content",QMessageBox::Yes|QMessageBox::No);


//三
QMessageBox::information(NULL, "Title", "Content",QMessageBox::Yes|QMessageBox::No|
                             QMessageBox::Abort);

//四
QMessageBox:: StandardButton result= QMessageBox::information(NULL, "Title", "Content",QMessageBox::Yes|QMessageBox::No);
switch (result)
{
case QMessageBox::Yes:
    qDebug()<<"Yes";
    break;
case QMessageBox::No:
    qDebug()<<"NO";
    break;
default:
    break;
}

//错误
QMessageBox::critical(NULL, "critical", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
//警告
MessageBox::warning(NULL, "warning", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
//询问
QMessageBox::question(NULL, "question", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
//关于
QMessageBox::about(NULL, "About", "by hjwblog.com");