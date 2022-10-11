//查找指定类名objectName的控件
QList<QWidget *> widgets = parentWidget.findChildren<QWidget *>("widgetname");
//查找所有QPushButton
QList<QPushButton *> allPButtons = parentWidget.findChildren<QPushButton *>();
//查找一级子控件,不然会一直遍历所有子控件
QList<QPushButton *> childButtons = parentWidget.findChildren<QPushButton *>(QString(), Qt::FindDirectChildrenOnly);