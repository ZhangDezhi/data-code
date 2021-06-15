//
//   main.cpp
//
// Created by ZhangDezhi on2021-06-09 22:10 
// Last Modified  : 2021-06-15 16:11:08
// Copyright © 2021  Zero Ltd. All Right reserved
//
//
#include <iostream>
#include <string.h>

using namespace std;

int main() {

    char *p1 = "I am a student";
    char s1[30],s2[30];
    strcpy(s1,p1);//(方法一)用命令拷贝字符串
    char *p2=s2;//(方法二)将数组s2首地址赋p2
    for (;*p2++=*p1++;); //用指针拷贝字符串
    /*
     * 首先将指针变量p2指向字符串数组s2的首地址,然后通过赋值语句*p2=*p1将字符串由s1中拷贝到s2中,再移动p1,p2到下一个字符单元,依次循环直到字符串结束符'\0'为止
     //等价于
     //
     //    *p1=*p2; // s2[i]=s1[i]，将指针p1所指s1[i]赋给指针p1所指s2[i]。
     //　　p1++; //指针p1加1指向s1的下一个元素
     //　　p2++; //指针p2加1指向s2的下一个元素
     //　　上述语句不断循环，直到p1指向结束字符'\0'=0时，for 语句因条件为假而结束。从而完成字符串s1拷贝到字符数组s2的任务。

     */
    cout<<"s1="<<s1<<endl;
    cout<<"s2="<<s2<<endl;
}
