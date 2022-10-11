

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QPainter>
#include <QMouseEvent>

class TransparentWidget : public QWidget
{
    Q_OBJECT
public:
    TransparentWidget(QWidget *parent = 0)
        : QWidget(parent)
    {
        
        setWindowTitle(QString::fromLocal8Bit("透明无边框窗口"));
        setFixedSize(480, 320);
       // 第一步：开启窗口的透明层。
        setWindowFlags(Qt::FramelessWindowHint);/* 注意：如果单纯开启窗口透明层效果，在Windows系统中必须设置, 其他系统可忽略。 */
        setAttribute(Qt::WA_TranslucentBackground);

        QPushButton *button = new QPushButton("Hello world!", this);
        button->setGeometry(5, 5, 80, 40);
    }

// 第二步: 重写paintEvent事件并使用QPainter画透明层
    void paintEvent(QPaintEvent *)
    {
        QPainter painter(this);
         /* 0x20为透明层颜色，可自定义设置为0x0到0xff */
        painter.fillRect(this->rect(), QColor(0, 0, 0, 0x20)); /* 设置透明颜色 */
    }

    void mousePressEvent(QMouseEvent *event)
    {
        if (event->button() == Qt::LeftButton) {
            /* 捕获按下时坐标 */
            m_startPoint = frameGeometry().topLeft() - event->globalPos();
        }
    }

    void mouseMoveEvent(QMouseEvent *event)
    {
         /* 移动窗口 */
        this->move(event->globalPos() + m_startPoint);
    }

private:
    QPoint m_startPoint;
};
