
public QDateTime qdate = QDateTime.currentDateTime();

datetime = qdate.toString("yyyy年MM月dd日ddddhh:mm:ss");











//QDateTime 转 QString
     QString strBuffer;  
	 QDateTime time;  
	 time = QDateTime::currentDateTime();  
	 strBuffer = time.toString("yyyy-MM-dd hh:mm:ss");  
	// strBuffer = 2010-07-02 17:35:00  

//QString  转 QDateTime

	      QString strBuffer;  
	      QDateTime time;  
	      strBuffer = "2010-07-02 17:35:00";  
	      time = QDateTime::fromString(strBuffer, "yyyy-MM-dd hh:mm:ss");  

//QDateTime 转 time_t
//头文件#include <QDateTime>//seconds为自1970-01-01T00:00:00开始的秒数
  QDateTime dt = QDateTime::fromTime_t (seconds);
  QString strDate = dt.toString(Qt::SystemLocaleLongDate);//日期格式自定义
