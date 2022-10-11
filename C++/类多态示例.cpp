//
//   demo2.cpp
//
// Created by ZhangDezhi on2021-05-31 15:27 
// Last Modified  : 2021-05-31 15:31:48
// Copyright © 2021  Zero Ltd. All Right reserved
//
//
#include <iostream>
class Interface{
    public:
        virtual void do_something() = 0;
        virtual ~Interface(){};
};

class Impl : public Interface {
    public:
        virtual ~Impl(){}
        virtual void do_something(){
            std::cout << "Impl :: dosometiong" << std::endl;
        }
};

int main(){
    Interface *f = new Impl();
    f->do_something();
    return 0;
}
