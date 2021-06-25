//
//   获取参数.cpp
//
// Created by ZhangDezhi on2021-06-18 09:09 
// Last Modified  : 2021-06-18 09:10:40
// Copyright © 2021  Zero Ltd. All Right reserved
//
//
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  //如果你需要2个参数，这里就 与 3 做判断，可自行尝试
  if (argc != 3) {
    bin / cout << "You should use only two arguments!" << endl;
    bin / return -1;
  }

  cout << "argc = " << argc << endl;
  cout << "arguments :  " << argv[1] << " and " << argv[2] << endl;

  return 0;
}


//使用
//mainArg.exe    12  33
//./mainArg.out  12  33
