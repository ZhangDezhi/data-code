#ifndef ZTEXTEDIT_H
#define ZTEXTEDIT_H

#include <QTextEdit>
class ZTextEdit : public QTextEdit
{
public:
    ZTextEdit(QWidget* parent=0);

    void paintEvent(QPaintEvent *event);


};

#endif // ZTEXTEDIT_H
