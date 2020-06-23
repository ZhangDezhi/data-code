//
//   字符串切割.cpp
//
// Created by ZhangDezhi on2020-06-12 16:39 
// Last Modified  : 2020-06-12 16:42:34
// Copyright © 2020  Zero Ltd. All Right reserved
//
//


QString str = "one ,two,three, four";
cout << str.section(',',1,1).trimmed().toStdString() << endl;  //返回结构为  two


QString str;
QString csv = "forename,middlename,surname,phone";
QString path = "/usr/local/bin/myapp"; // First field is empty
QString::SectionFlag flag = QString::SectionSkipEmpty;

str = csv.section(',', 2, 2);   // str == "surname"
str = path.section('/', 3, 4);  // str == "bin/myapp"
str = path.section('/', 3, 3, flag); // str == "myapp"

str = csv.section(',', -3, -2);  // str == "middlename,surname"
str = path.section('/', -1); // str == "myapp"




QString str = "one, two* three / four / five ^ six";
QStringList sections = str.split(QRegExp("[,*/^]")); //把每一个块装进一个QStringList中
cout << sections.at(3).trimmed().toStdString() << endl;


