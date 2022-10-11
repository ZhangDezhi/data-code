<<<<<<< HEAD
#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form)
{
setFixedSize(100, 100);
        ui->setupUi(this);


        this->setAcceptDrops(true); //设置接受拖拽

        //QWindows设置无标题栏窗体
        setWindowFlags(Qt::FramelessWindowHint |Qt::WindowMinimizeButtonHint);


        //QDialog
        setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

        //设置窗体背景颜色。
        QPalette palette(this->palette());
        palette.setColor(QPalette::Background, Qt::yellow);
        this->setPalette(palette);


}

Form::~Form()
{
    delete ui;
}
=======
#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Form)
{
setFixedSize(100, 100);
        ui->setupUi(this);


        this->setAcceptDrops(true); //设置接受拖拽

        //QWindows设置无标题栏窗体
        setWindowFlags(Qt::FramelessWindowHint |Qt::WindowMinimizeButtonHint);


        //QDialog
        setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

        //设置窗体背景颜色。
        QPalette palette(this->palette());
        palette.setColor(QPalette::Background, Qt::yellow);
        this->setPalette(palette);


}

Form::~Form()
{
    delete ui;
}
>>>>>>> e700fe0e77674b3ed5da6e7a7b3aa714665aefef
