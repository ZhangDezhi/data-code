// 参考: https://blog.csdn.net/longking_2008/article/details/7855328
//在项目过程中需要在列表中用图形显示磁盘的使用情况。这用Qt自身的QTableview控件不能完全实现。需要用委托进行重绘。

// 创建一个委托类继承QItemDelegate类

// 然后实现void paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;方法。


//委托根据model数据重绘显示在Qtableview中
void MyDiskDelegate::paint( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const
{  
painter->setFont(CDataPublic::getCustomFont(false, 8));
QPen SZpen(QColor(100,106,123));
painter->setPen(SZpen);

QStyleOptionViewItemV4 opt = setOptions(index, option);
QRect drawRectIcon;
QRect drawRectText;
int   textLength;
if (index.column() == 0)  //第一列
{
  painter->save();
  drawBackground(painter, opt, index);  
  QString driverText = (index.data(Qt::DisplayRole)).toString();
  textLength = driverText.length();
  QString drawText = driverText.left(textLength-1);
  int diskType = driverText.right(1).toInt();
 
  QPixmap driverIcon;
  if (diskType == DeviceType_Disk)
  {
   driverIcon = QPixmap(CDataPublic::getPicResFullPath("DiskIcon.png"));
  }
  else if(diskType == deviceType_mobile)
  {
   driverIcon = QPixmap(CDataPublic::getPicResFullPath("RemoveDiskIcon.png"));
  }
 
  drawRectIcon = QRect(opt.rect.topLeft()+QPoint(10,5), QSize(20,20));
  drawRectText = QRect(drawRectIcon.topRight()+QPoint(3,2), QSize(textLength*16,20));
  if (driverText == tr(""))
  {
             driverText = tr("LocalDisk");
  }

  painter->drawPixmap(drawRectIcon, driverIcon);
  painter->drawText(drawRectText, drawText);
 
  //drawFocus(painter, opt, drawRectText); 
  painter->restore();
}
else if (index.column() == 1) //第二列
{
  painter->save();

  int x = opt.rect.topLeft().x();
  int y = opt.rect.topLeft().y();
  int h = opt.rect.height();
  int w = opt.rect.width();

  if (index.row()%2 == 0)     //画背景
  {  
   painter->setPen(Qt::NoPen);
   painter->fillRect(QRect(x,y,w,h),QColor(255,255,255));
  }

  QPen SZpen(QColor(75, 82, 100));
  painter->setPen(SZpen);
  const QString driverText = (index.data(Qt::DisplayRole)).toString();
  drawRectText = QRect(opt.rect.topLeft()+QPoint(5,5), QSize(150,20));
  drawBackground(painter, opt, index); 
  painter->drawText(drawRectText, driverText);    //画文字  
  //drawFocus(painter, opt, drawRectText); 
  QPen pen;
  pen.setColor(CDataPublic::getBackLineColor());    //画线
  pen.setWidth(1.5);
  painter->setPen(pen);
  painter->drawLine(opt.rect.topLeft(),opt.rect.topLeft()+QPoint(0,opt.rect.height()));
  painter->restore();
}
else if (index.column() == 2)  //第三列
{
  painter->save();   

  int x = opt.rect.topLeft().x();
  int y = opt.rect.topLeft().y();
  int h = opt.rect.height();
  int w = opt.rect.width();

  if (index.row()%2 == 0)     //画背景
  {  
   painter->setPen(Qt::NoPen);
   painter->fillRect(QRect(x,y,w,h),QColor(255,255,255));
  }

  QPen SZpen(QColor(75, 82, 100));
  painter->setPen(SZpen);
  const QString driverText = (index.data(Qt::DisplayRole)).toString();
  drawRectText = QRect(opt.rect.topLeft()+QPoint(5,5), QSize(150,20));
  drawBackground(painter, opt, index);    
  painter->drawText(drawRectText, driverText); 

  QPen pen;
  pen.setColor(CDataPublic::getBackLineColor());    //画线
  pen.setWidth(1.5);
  painter->setPen(pen);
  painter->drawLine(opt.rect.topLeft(),opt.rect.topLeft()+QPoint(0,opt.rect.height()));
  painter->restore();
}
}
