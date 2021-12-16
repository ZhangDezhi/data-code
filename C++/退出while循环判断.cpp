//
//   退出while循环判断.cpp
//
// Created by ZhangDezhi on2021-08-26 14:45 
// Last Modified  : 2021-08-26 14:58:56
// Copyright © 2021  Zero Ltd. All Right reserved
//
//

while(1){

    if(it){
        cout << "Try Again? Enter y or n" << endl;
        char c;
        cin >> c;
        if(!cin || c == 'n')
            break; //跳出循环
    }
}
