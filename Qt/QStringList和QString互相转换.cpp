//
//   QStringList和QString互相转换.cpp
//
// Created by ZhangDezhi o2020/06/12n2020-06-12 16:43
// Last Modified  : 2020-06-12 16:55:12
// Copyright © 2020  Zero Ltd. All Right reserved
//
//

16:53:37 
2020/06/12 



QStringList fonts;
fonts << "Arial"
      << "Helvetica"
      << "Times"
      << "Courier";
QString str = fonts.join(",");

QString str = "name1,path1;name2,path2;name3,path3";
QStringList list1 = str.split(
    ";");  // 注意，如果str是空字符串，list1会增加一个空字符串到列表里，其size=1，我为此吃过苦头～
for (int i = 0; i < list1.size(); i++) {
	QStringList list2 = list1[i].split(tr(","));
}



