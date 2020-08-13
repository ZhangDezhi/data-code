//
//   Qt使用Mysql查询_事务.cpp
//
// Created by ZhangDezhi on2020-07-02 13:38 
// Last Modified  : 2020-07-02 13:40:09
// Copyright © 2020  Zero Ltd. All Right reserved
//
//  pro 文件里面 加入 QT+= sql

   QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	//主机名就是 localhost 或者 127.0.0.1
    db.setHostName("localhost");
    //端口号
    db.setPort(3306);
    //用户名
    db.setUserName("root");
    //密码
    db.setPassword("root");

    bool ok = db.open();
    if(ok)
    {
        qDebug()<<"ok";
    }
    else
    {
        qDebug()<<"error";
        return;
    }



//方法一
  for(int i = 0;i<8000;i++)
    {

  	 	 QString str = "insert into student.info(NAME,SCORE) values('AHua' ,30)";

    	QSqlQuery query;
    	
   	 	query.exec(str);
    }

/*
 *存入一条数据流程： 打开数据库 -> 插入数据 ->关闭数据库
存入8000条数据流程: (打开数据库 -> 插入数据 ->关闭数据库 )* 8000
其实时间浪费在 打开和关闭数据库
要做到 打开数据库 写入8000条 关闭数据库 就省时间了
 *
 *
 */

//开启事务
    if(db.transaction())
    {
        qDebug()<<"open ok";
    }
    else{
        qDebug()<<"open error";
    }

	//输入插入
    for(int i = 0;i<8000;i++)
    {

  	 	 QString str = "insert into student.info(NAME,SCORE) values('AHua' ,30)";

    	QSqlQuery query;
    	
   	 	query.exec(str);
    }
	//提交事务
    if(db.commit())
    {
        qDebug()<<"commit ok";
    }
    else
        qDebug()<<"commit error";
        //失败以后可以进行回滚

