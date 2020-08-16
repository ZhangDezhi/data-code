//
//   Qt_QTableView简单使用.cpp
//
// Created by ZhangDezhi on2020-07-23 11:37 
// Last Modified  : 2020-07-23 11:37:25
// Copyright © 2020  Zero Ltd. All Right reserved
//
//
 QStandardItemModel* model = new QStandardItemModel();

    /* 设置列数 */
    model->setColumnCount(7);
    model->setHeaderData(0, Qt::Horizontal, "周一");

    /* 设置行数 */
    model->setRowCount(14);
    model->setHeaderData(0, Qt::Vertical, "第1节课");

    ui->tableView->setModel(model);
    /* 设置列宽在可视界面自适应宽度 */
    ui->tableView->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    /* 行颜色交替显示 */
    ui->tableView->setAlternatingRowColors(true);
    /* 不允许在图形界面修改内容 */
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    /* 在表格内加入内容 */
    model->setItem(0, 0, new QStandardItem("数学"));

    /* 显示表 */
    ui->tableView->show();
