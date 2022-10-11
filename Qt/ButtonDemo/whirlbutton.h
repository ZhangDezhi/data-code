<<<<<<< HEAD
#ifndef WHIRLBUTTON_H
#define WHIRLBUTTON_H

#include <QColor>
#include <QImage>
#include <QWidget>
#define whirlbuttonHeigth   130
#define whirlbuttonWidth    120
class whirlbutton : public QWidget
{
    Q_OBJECT
public:
     void  paintEvent(QPaintEvent *event);
    explicit whirlbutton(QWidget *parent = 0);

    ~whirlbutton();
        void setDegree(int deg);
        int getDegree();

    signals:
        void updateDegree();
    protected:
        void mousePressEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
        void mouseReleaseEvent(QMouseEvent *event);
        void mouseToPosion(QMouseEvent *event);
        QSize sizeHint() const;
        QSize minimumSizeHint() const;
    private:
        int degree;
};

#endif // WHIRLBUTTON_H
=======
#ifndef WHIRLBUTTON_H
#define WHIRLBUTTON_H

#include <QColor>
#include <QImage>
#include <QWidget>
#define whirlbuttonHeigth   130
#define whirlbuttonWidth    120
class whirlbutton : public QWidget
{
    Q_OBJECT
public:
     void  paintEvent(QPaintEvent *event);
    explicit whirlbutton(QWidget *parent = 0);

    ~whirlbutton();
        void setDegree(int deg);
        int getDegree();

    signals:
        void updateDegree();
    protected:
        void mousePressEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
        void mouseReleaseEvent(QMouseEvent *event);
        void mouseToPosion(QMouseEvent *event);
        QSize sizeHint() const;
        QSize minimumSizeHint() const;
    private:
        int degree;
};

#endif // WHIRLBUTTON_H
>>>>>>> e700fe0e77674b3ed5da6e7a7b3aa714665aefef
