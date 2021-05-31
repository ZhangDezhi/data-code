//
//   demo.cpp
//
// Created by ZhangDezhi on2021-05-31 14:58 
// Last Modified  : 2021-05-31 15:19:37
// Copyright © 2021  Zero Ltd. All Right reserved
//
//

#include <cstdio>
typedef void (*func) (int);

void Print(int i){

    printf("%d\n",i);
}

int main() {

    func f = &Print;
    f(1);
    return 0;
}


