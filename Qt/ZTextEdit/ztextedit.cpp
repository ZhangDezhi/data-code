#include "ztextedit.h"
#include <QPainter>
#include <QDebug>
ZTextEdit::ZTextEdit(QWidget* parent):QTextEdit(parent)
{
    setCursor(Qt::PointingHandCursor);
}

void ZTextEdit::paintEvent(QPaintEvent *event)
{

   QPainter *painter = new QPainter(this->viewport());
  // painter->begin(this->viewport());
    painter->setPen(QPen(Qt::red, 2, Qt::SolidLine));
    painter->drawLine( QPointF(this->viewport()->size().width()-10,0),QPointF(this->viewport()->size().width(),10));
    painter->end();

QTextEdit::paintEvent(event);

}

