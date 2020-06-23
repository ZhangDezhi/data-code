#include "whirlbutton.h"
#include <QPainter>
#include <QMouseEvent>
#include <math.h>
void whirlbutton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
      QTransform tranform1;
      int originY = whirlbuttonHeigth/2;
      int originX = whirlbuttonWidth/2;


      const int triangle[3][2] =
      {
          { originX-2, 0 },
          { originX+2, 0 },
          { originX, 7 }
      };

      painter.setPen(QPen(Qt::red));
      //painter.setBrush(palette().foreground());
      painter.setBrush(QBrush(Qt::red));
      //draw polygon,triangle.
      painter.drawPolygon(QPolygon(3, &triangle[0][0]));


      //   painter.setWindow(0,0,150,150);
      tranform1.translate(originX,originY);
      tranform1.rotate(degree);
      tranform1.translate(-(originX),-(originY));
      painter.setWorldTransform(tranform1);

      QPen thickPen(palette().foreground(), 1.5);
      QPen midPen(palette().foreground(), 1.0);
      QPen thinPen(palette().foreground(), 0.5);
      QColor niceBlue(150, 150, 200);
      painter.setPen(thinPen);


      //gradually change with degree
      QConicalGradient coneGradient(originX, originY, -90.0);
      coneGradient.setColorAt(0.0, Qt::darkGray);
      coneGradient.setColorAt(0.2, niceBlue);
      coneGradient.setColorAt(1.0, Qt::white);
      coneGradient.setColorAt(1.0, Qt::darkGray);

      unsigned r = 56;
      painter.setBrush(coneGradient);
      painter.drawEllipse((originX-r), (originY-r), r*2, r*2);

      r = 24;
      QRadialGradient haloGradient(originX, originY, r, originX, originY);
      haloGradient.setColorAt(0.0, Qt::lightGray);
      haloGradient.setColorAt(0.8, Qt::darkGray);
      haloGradient.setColorAt(0.9, Qt::white);
      haloGradient.setColorAt(1.0, Qt::black);

      painter.setPen(Qt::NoPen);
      painter.setBrush(haloGradient);

      painter.drawEllipse(originX-r, originY-r, r*2, 2*r);

      unsigned rx = 30,ry = 8;
      QLinearGradient knobGradient(originX-rx, originY-ry,originX-rx, originY+ry);
      knobGradient.setColorAt(0.0, Qt::black);
      knobGradient.setColorAt(0.2, niceBlue);
      knobGradient.setColorAt(0.3, Qt::lightGray);
      knobGradient.setColorAt(0.8, Qt::white);
      knobGradient.setColorAt(1.0, Qt::black);

      painter.setBrush(knobGradient);
      painter.setPen(thinPen);
      painter.drawRoundRect(originX-rx,originY-ry, rx*2, ry*2, 49, 99);


      for (int i = 0; i < 36; ++i)
      {
          if (i%6)
          {
              painter.setPen(midPen);
              painter.drawLine(5,originY, 10,originY);
          }
          else
          {
              painter.setPen(thickPen);
              painter.drawLine(5,originY, 13,originY);

              tranform1.translate(25,originY);
              tranform1.rotate(-90);
              tranform1.translate(-25,-originY);
              painter.setWorldTransform(tranform1);

              painter.drawText(22, originY,QString::number(i/6));
              tranform1.translate(25,originY);
              tranform1.rotate(90);
              tranform1.translate(-25,-originY);
              painter.setWorldTransform(tranform1);

          }

          tranform1.translate(originX,originY);
          tranform1.rotate(-10);
          tranform1.translate(-originX,-originY);
          painter.setWorldTransform(tranform1);
      }
}

whirlbutton::whirlbutton(QWidget *parent) : QWidget(parent)
{
    setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    degree = 90;
}

whirlbutton::~whirlbutton()
{

}

void whirlbutton::setDegree(int deg)
{
    this->degree = deg;
    this->update();
}

int whirlbutton::getDegree()
{
       return(degree);
}

void whirlbutton::mousePressEvent(QMouseEvent *event)
{
    mouseToPosion(event);
     this->update();
}

void whirlbutton::mouseMoveEvent(QMouseEvent *event)
{

    mouseToPosion(event);
    this->update();
}

void whirlbutton::mouseReleaseEvent(QMouseEvent *event)
{
    mouseToPosion(event);
     this->updateDegree();
}

void whirlbutton::mouseToPosion(QMouseEvent *event)
{
    QPoint currentPoint = event->pos();
        double pi = 3.1415927;
        double  x = currentPoint.x() - whirlbuttonHeigth/2;
        double  y = currentPoint.y() - whirlbuttonWidth/2;
        if((x ==0)&&(y<=0))
            degree = 90;
        else if((x==0)&&(y<0))
            degree = 270;
        else if(x>0)
            degree = atan(y/x)*180/pi + 180;
        else if(y>0)
            degree = atan(y/x)*180/pi + 360;
        else
            degree = atan(y/x)*180/pi;
}

QSize whirlbutton::sizeHint() const
{
    QSize size = QSize(whirlbuttonHeigth,whirlbuttonWidth);
     return size;
}

QSize whirlbutton::minimumSizeHint() const
{
    QSize size = QSize(whirlbuttonHeigth,whirlbuttonWidth);
     return size;
}
