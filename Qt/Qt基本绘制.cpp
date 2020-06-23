Qt的坐标机制：
Qt的坐标与我们常见的坐标不同，如图，假设下图的矩形就是我们的窗口，矩形左上角顶点即为坐标原点： 

/*
   ___________\  x轴
  |
  |
 \|

 y轴
*/

//绘制矩形
 paint->drawRect(20,20,160,160); 

 //绘制圆和椭圆
 paint->setPen(QPen(Qt::blue,4，Qt::SolidLine));//，这个圆或椭圆是在矩形中，这个矩形的左上角的顶点在坐标轴中的位置为（20，20）
paint->drawEllipse(20,20,210,160);

//绘制圆角矩形
paint->setPen(QPen(Qt::blue,4，Qt::SolidLine));
paint->drawRoundRect(20,20,210,160,50,50);//最后两个参数决定角的圆度。它可以为0到99之间的任意值（99代表最圆）。

//绘制扇形图
QRectF rectangle(10.0, 20.0, 80.0, 60.0);//设定扇形所在的矩形，扇形画在矩形内部后两个参数定义圆的样式。0为起始角度（实际单位为1/16度），500为扇形所展开的角度(单位也为1/16度)。 
int startAngle = 30 * 16;//起始角度，角度可以为负值，如-30*16
int spanAngle = 120 * 16;//覆盖的角度，绘制方向为逆时针方向
QPainter painter(this);
painter.drawPie(rectangle, startAngle, spanAngle);

//绘制弦
paint->setPen(QPen(Qt::green,4,Qt::SolidLine));
paint->drawChord(20,20,210,160,500,1000);


//绘制圆弧
paint->setPen(QPen(Qt::green,4,Qt::SolidLine));
paint->drawArc(20,20,210,160,500,1000);







