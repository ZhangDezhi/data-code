#pragma once
 
#include <iostream>
using namespace std;
 
class Singleton{
private:
    Singleton(){
        cout << "������һ����������" << endl;
    }
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
    ~Singleton(){
        //������������Ҳ��Ҫ������private��
        //��Ϊ������Ҫ���ʵ���ڳ������е����������ж�����
        //�������ǲ�����ʵ���Լ������������������ͷŶ���
        cout << "������һ����������" << endl;
    }
 
 
    static Singleton instance;  //�������ǵĵ�������ע������һ����������������������
public:
    static Singleton* getInstance();
};
 
//���������̬��Ա����������ص�ʱ����Ѿ���ʼ������
Singleton Singleton::instance; 
 
Singleton* Singleton::getInstance(){
    return &instance;
}
