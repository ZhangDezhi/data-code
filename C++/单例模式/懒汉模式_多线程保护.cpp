#pragma once
 
#include <iostream>
using namespace std; 
 
class Lock  {  
private:         
    mutex my_mutex;  
public:  
    Lock(mutex my_mutex1) : my_mutex(my_mutex1){  
        m_cs.Lock();  
    }
    ~Lock(){  
         m_cs.Unlock();  
    }  
};  
 
class Singleton{
private:
    Singleton(){
        cout << "������һ����������" << endl;
    }
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
    ~Singleton(){
        // ������������Ҳ��Ҫ������private��
        //��Ϊ������Ҫ���ʵ���ڳ������е����������ж�����
        //�������ǲ�����ʵ���Լ������������������ͷŶ���
        cout << "������һ����������" << endl;                                            
    }
         
    static Singleton* instance;  //�������ǵĵ�������,����һ��������ָ��
public:
    static Singleton* getInstance();
    static mutex my_mutex1;
                                        
private:
    //����һ���ڲ���
    class Garbo{
    public:
        Garbo(){}
        ~Garbo(){
            if(instance != NULL){
                delete instance;
                instance = NULL;
            }
        }
    };
 
    //����һ���ڲ���ľ�̬����
    //���ö������ٵ�ʱ�򣬵�����������˳���������ǵĵ�������
    static Garbo _garbo;
};
 
//���������̬��Ա����������ص�ʱ����Ѿ���ʼ������
Singleton* Singleton::instance = NULL; 
Singleton::Garbo Singleton::_garbo;     //����Ҫ��ʼ��һ����������ľ�̬��Ա����
 
Singleton* Singleton::getInstance(){
    if(instance == NULL){
        Lock lock(my_mutex1); // ����
        if(instance == NULL)
            instance = new Singleton();
    }  
    return instance;
}