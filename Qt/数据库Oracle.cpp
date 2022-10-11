  #include <QSqlDatabase>
#include <QDebug>
#include <QtSql>
#include <QLibrary>
  
  
  QSqlDatabase db=QSqlDatabase::addDatabase("QOCI");
           db.setHostName("10.36.100.3");
           db.setPort(1521);
           db.setDatabaseName("ORCL");
           db.setUserName("xopens");
           db.setPassword("iscs200");
           if(db.open())
           {
               qDebug()<<"success!";
                qDebug()<<db.driverName();
                QSqlQuery query("select * from ALARM_CODE_TAB ");//thinkcmf数据库里的所有表
                while (query.next()) {
                     qDebug() << "------------------1";
                    QString country = query.value(0).toString();
                    qDebug()<<country;
                }

//                QSqlQuery query1("SELECT * FROM ALL_TABLES WHERE OWNER='XOPENS' ");//查询表的内容
//                while (query1.next()) {
//                     qDebug() << "------------------2";
//                    QString country = query1.value(0).toString();//cmf_menu表第1个字段的内容
//                    qDebug()<<country;
//                }

//                qDebug() << "------------------3";
//                QSqlQuery query3;
//                    query3.exec("select * from student");
//                    while(query3.next())
//                    {
//                       qDebug() << query3.value(0).toInt()
//                                                      << query3.value(1).toString();
//                    }
           }else{
               qDebug()<<"failure";
           }