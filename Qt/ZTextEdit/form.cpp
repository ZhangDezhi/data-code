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
