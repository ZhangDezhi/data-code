<<<<<<< HEAD
private:
    QTimer *fTimer;//定时器
    QTime  fTimeCount;//计时器

void Widget::on_pushButton_6_clicked()//停止按钮
{
    fTimer->stop();
    int tmMsec=fTimeCount.elapsed();//计算时间差//回最后一次调用start或restart到现在已经经过的毫秒数
    int ms=tmMsec%1000;//计算毫秒数
    int sec=tmMsec/1000;//计算秒数
    QString str=QString::asprintf("流逝时间：%d秒，%d毫秒",sec,ms);
    ui->label_6->setText(str);
}



// Qt 计算两个日期的时间差并以时分秒显示出来
QDateTime begin_time = QDateTime::currentDateTime();             //获取或设置时间
QDateTime end_time = QDateTime::currentDateTime();               //获取或设置时间
QTime m_time;						
m_time.setHMS(0, 0, 0, 0);                                       //初始化数据，时 分 秒 毫秒
m_time.addSecs(begin_time.secsTo(end_time)).toString("hh:mm:ss");//计算时间差(秒)，将时间差加入m_time，格式化输出
=======
private:
    QTimer *fTimer;//定时器
    QTime  fTimeCount;//计时器

void Widget::on_pushButton_6_clicked()//停止按钮
{
    fTimer->stop();
    int tmMsec=fTimeCount.elapsed();//计算时间差//回最后一次调用start或restart到现在已经经过的毫秒数
    int ms=tmMsec%1000;//计算毫秒数
    int sec=tmMsec/1000;//计算秒数
    QString str=QString::asprintf("流逝时间：%d秒，%d毫秒",sec,ms);
    ui->label_6->setText(str);
}



// Qt 计算两个日期的时间差并以时分秒显示出来
QDateTime begin_time = QDateTime::currentDateTime();             //获取或设置时间
QDateTime end_time = QDateTime::currentDateTime();               //获取或设置时间
QTime m_time;						
m_time.setHMS(0, 0, 0, 0);                                       //初始化数据，时 分 秒 毫秒
m_time.addSecs(begin_time.secsTo(end_time)).toString("hh:mm:ss");//计算时间差(秒)，将时间差加入m_time，格式化输出
>>>>>>> e700fe0e77674b3ed5da6e7a7b3aa714665aefef
