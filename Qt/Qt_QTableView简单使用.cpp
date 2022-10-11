//
//   Qt_QTableView简单使用.cpp
//
// Created by ZhangDezhi on2020-07-23 11:37 
// Last Modified  : 2020-07-23 11:37:25
// Copyright © 2020  Zero Ltd. All Right reserved
//
//

// demo.h
class QStandardItemModel;
 QStandardItemModel* m_model;




//demo.cpp
#include <QStandardItemModel>






    //QStandardItemModel* model = new QStandardItemModel();//也可以临时
    m_model = new QStandardItemModel();

//设置model
   model->setColumnCount(7);/* 设置列数 */
   model->setHeaderData(0, Qt::Horizontal, "周一");
   model->setHeaderData(1, Qt::Horizontal, "周二");
   model->setHeaderData(2, Qt::Horizontal, "周三");
   model->setHeaderData(3, Qt::Horizontal, "周四");
   model->setHeaderData(4, Qt::Horizontal, "周五");
   model->setHeaderData(5, Qt::Horizontal, "周六");
   model->setHeaderData(6, Qt::Horizontal, "周日");
   model->setRowCount(14); /* 设置行数 */
   model->setHeaderData(0, Qt::Vertical, "第1节课");
   ui->tableView->setModel(model);

//设置tableview
    
   ui->tableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);/* 设置列宽在可视界面自适应宽度 */
   ui->tableView->setAlternatingRowColors(true);/* 行颜色交替显示 */
   ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); /* 不允许在图形界面修改内容 */
   ui->tableView->setEditTriggers(QAbstractItemView::SelectRows); 
   ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);  /*设置行选模式*/
   ui->tableView->resizeColumnsToContents();
   ui->tableView->resizeRowsToContents();


// 更新数据 
    model->setItem(0, 0, new QStandardItem("数学"));/* 在表格内加入内容 */

    /* 显示表 */
    ui->tableView->show();
