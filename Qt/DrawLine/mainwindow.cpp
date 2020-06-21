#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(300,300);
    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,[=](){
        static int i = 1;
        double x = 20 * i * 0.1;
        point.setX(x);
        point.setY(x);
        update();
        if(x >= 200)
            timer->stop();
        i++;
    });
    timer->start(50);

    QPointF x;
    x.setX(20);
    x.setY(20);
    QPointF y;
    y.setX(30);
    y.setY(30);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
   Q_UNUSED (event);
    QPainter p(this);
    p.drawLine(QPointF(2,2),point);
    qDebug() << "point: "<<point;
}
