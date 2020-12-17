//.h

public slots:
bool eventFilter(QObject *, QEvent *); //注意这里


//.cpp

ui->lineEdit2->installEventFilter(this); //在窗体上为lineEdit2安装过滤器

bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->lineEdit1) //首先判断控件(这里指 lineEdit1)
    {
        if (event->type() == QEvent::FocusIn) //然后再判断控件的具体事件 (这里指获得焦点事件)
        {
            QPalette p = QPalette();
            p.setColor(QPalette::Base, Qt::green);
            ui->lineEdit1->setPalette(p);
        }
        else if (event->type() == QEvent::FocusOut) // 这里指 lineEdit1 控件的失去焦点事件
        {
            QPalette p = QPalette();
            p.setColor(QPalette::Base, Qt::white);
            ui->lineEdit1->setPalette(p);
        }
    }
    if (watched == ui->lineEdit2) //这里来处理 lineEdit2 , 和处理lineEdit1 是一样的
    {
        if (event->type() == QEvent::FocusIn)
        {
            QPalette p = QPalette();
            p.setColor(QPalette::Base, Qt::green);
            ui->lineEdit2->setPalette(p);
        }
        else if (event->type() == QEvent::FocusOut)
        {
            QPalette p = QPalette();
            p.setColor(QPalette::Base, Qt::white);
            ui->lineEdit2->setPalette(p);
        }
    }
    return QWidget::eventFilter(watched, event); // 最后将事件交给上层对话框
}