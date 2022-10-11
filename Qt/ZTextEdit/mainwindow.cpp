<<<<<<< HEAD
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_form=new Form(this);   //创建提示对象
    m_form->hide();   //隐藏对象
//    m_form->setEnabled(false);


    ui->textEdit->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    //光标位置
        QCursor *cursor;
        //cursor->pos().y()-100;
        //this->pos().x() + ui->textEdit->pos().x() + ui->textEdit->size().width();
        //this->pos().y() + ui->textEdit->pos().y() + ui->textEdit->size().height();
        int x=this->pos().x() + ui->textEdit->pos().x() + ui->textEdit->size().width();
        int y=this->pos().y() + ui->textEdit->pos().y();
        qDebug()<<"x=="<<x<<"y=="<<y;
        if(ui->textEdit==watched){
          //  QEvent::MouseButtonPress
           // if(QEvent::MouseButtonPress==event->type()){
            if(QEvent::Enter==event->type()){
                m_form->setGeometry(x+20,y+20,100,100);

                m_form->show();

                qDebug() <<"OPEN";
            }
            else if(QEvent::Leave==event->type()){
               m_form->close();
                qDebug() << "CLOSE";
          }
        }

        return QObject::eventFilter(watched,event);

}
=======
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_form=new Form(this);   //创建提示对象
    m_form->hide();   //隐藏对象
//    m_form->setEnabled(false);


    ui->textEdit->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    //光标位置
        QCursor *cursor;
        //cursor->pos().y()-100;
        //this->pos().x() + ui->textEdit->pos().x() + ui->textEdit->size().width();
        //this->pos().y() + ui->textEdit->pos().y() + ui->textEdit->size().height();
        int x=this->pos().x() + ui->textEdit->pos().x() + ui->textEdit->size().width();
        int y=this->pos().y() + ui->textEdit->pos().y();
        qDebug()<<"x=="<<x<<"y=="<<y;
        if(ui->textEdit==watched){
          //  QEvent::MouseButtonPress
           // if(QEvent::MouseButtonPress==event->type()){
            if(QEvent::Enter==event->type()){
                m_form->setGeometry(x+20,y+20,100,100);

                m_form->show();

                qDebug() <<"OPEN";
            }
            else if(QEvent::Leave==event->type()){
               m_form->close();
                qDebug() << "CLOSE";
          }
        }

        return QObject::eventFilter(watched,event);

}
>>>>>>> e700fe0e77674b3ed5da6e7a7b3aa714665aefef
