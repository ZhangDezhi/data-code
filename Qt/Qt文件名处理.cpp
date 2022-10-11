//
//   Qt文件名处理.cpp
//
// Created by ZhangDezhi on2020-08-21 17:17 
// Last Modified  : 2020-08-21 17:18:13
// Copyright © 2020  Zero Ltd. All Right reserved
//
//
QString file_full, file_name, file_path;  
QFileInfo fi;  
  
file_full = QFileDialog::getOpenFileName(this);  
  
fi = QFileInfo(file_full);  
file_name = fi.fileName();  
file_path = fi.absolutePath();
