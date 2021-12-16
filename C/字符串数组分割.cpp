//
//   main.cpp
//
// Created by ZhangDezhi on2021-06-09 22:10
// Last Modified  : 2021-09-01 15:31:03
// Copyright © 2021  Zero Ltd. All Right reserved
//
//
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main() {


    char * aaa;
    aaa = "999";

    if(*aaa == NULL)
    {
        cout << "-------NULL" << endl;
    }
    else{

        cout << "-------not NULL" << endl;
    }

    cout <<"--------->>> " << strlen(aaa) << endl;

    char * bbb = "NODATA";
    cout << "1-------->>> " << strlen(bbb) << bbb << endl;

    bbb = "ccccc";
    cout << "2-------->>> " << strlen(bbb) << bbb << endl;

    bbb = "cccdddcc";
    cout << "3-------->>> " << strlen(bbb)  <<  bbb  << endl;


    vector<char *> res_split;  //存储分割字符串
    char *name = "camm_12_1212_dfaf";
    char name_a[100];
    strcpy(name_a, name);
    const char split[] = "_";
    char *res = strtok(name_a, split);  // name_a : char[]
    while (res != NULL) {
        res_split.push_back(res);
        cout << res << endl;
        res = strtok(NULL, split);
    }
    cout << "0:   " << res_split.at(0) << endl;
    cout << "1:   " << res_split.at(1) << endl;
    cout << "2:   " << res_split.at(2) << endl;

    char *key = "camm";
    if (count(res_split.begin(), res_split.end(), key))
        cout << "包含 "<< key << endl;
    else
        cout << "不包含"<< key << endl;


    if(find(res_split.begin(),res_split.end(), "12") != res_split.end())
        cout << "----1" << endl;

    for(const auto& item : res_split)
    {
        cout << "---"<< item << endl;
        if(strcmp(item,"12")==0)
        //if(item == "12")
        {
            cout << "找到了: " << item << endl;
            break;
        }
    }


    char *key2 = "aaa";
    if (count(res_split.begin(), res_split.end(), key2))
        cout << "包含 "<< key2 << endl;
    else
        cout << "不包含 "<< key2 << endl;
}
