//.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString m_oldStr;
    bool m_isChange;

private:
    Ui::MainWindow *ui;

public slots:
    bool eventFilter(QObject *, QEvent *);
    void updateStr(QString text);
};
#endif // MAINWINDOW_H



//.cpp

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit->installEventFilter(this);                                              //增加事件过滤器
    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(updateStr(QString))); //检测内容改变
    m_oldStr = "";
    m_isChange = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{

    if (event->type() == QEvent::FocusIn) //获得焦点事件
    {
        QPalette p = QPalette();
        p.setColor(QPalette::Base, Qt::green);
        ui->lineEdit->setPalette(p);
    }
    else if (event->type() == QEvent::FocusOut) // 失去焦点事件
    {
        QPalette p = QPalette();
        p.setColor(QPalette::Base, Qt::white);
        ui->lineEdit->setPalette(p);

        QString tmpStr = ui->lineEdit->text();
        if (tmpStr.length() > 0)
        {
            //内容不为空

            if (m_isChange)
            {
                // 当前内容只触发一次

                m_isChange = false;
                QString info = QString("检测到控件失去焦点,内容相比较上次发生改变且不为空 : %1 \n").arg(tmpStr);
                ui->textBrowser->insertPlainText(info);
            }
        }
    }
}

void MainWindow::updateStr(QString text)
{

    if (m_oldStr != text)
    {

        m_isChange = true;
    }
    m_oldStr = text;
    qDebug() << "输入内容:  " << m_oldStr;
}



/*

                 ---+-----------------------------------------+
                   |+----------------+  +------------------+  |
                   || lineText       |  |                  |  |
                   |+----------------+  +------------------+  |
                   |+---------------------------------------+ |
                   ||                                       | |
                   ||          textBrowser                  | |
                   ||                                       | |
                   ||                                       | |
                   |+---------------------------------------+ |
                   +------------------------------------------+

*/
