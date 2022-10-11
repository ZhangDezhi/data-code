//首先定义MainWindow中的
protected:
bool eventFilter(QObject *obj, QEvent *e); //函数，它是一个虚函数，权限设置为protected。


bool MainWindow::eventFilter(QObject *obj, QEvent *e)
{
    Q_ASSERT(obj == inputTextEdit);
    if (e->type() == QEvent::KeyPress)
    {
        QKeyEvent *event = static_cast<QKeyEvent*>(e);
        if (event->key() == Qt::Key_Return && (event->modifiers() & Qt::ControlModifier))
        {
            sendMsg(); //发送消息的槽
            return true;
        }
    }
    return false;
}
