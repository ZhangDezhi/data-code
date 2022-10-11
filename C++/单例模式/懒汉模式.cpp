#pragma once
 
#include <iostream>
using namespace std;
 
class Singleton{
private:
    Singleton(){
        cout << "创建了一个单例对象" << endl;
    }
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);
    ~Singleton(){
        // 析构函数我们也需要声明成private的
        //因为我们想要这个实例在程序运行的整个过程中都存在
        //所以我们不允许实例自己主动调用析构函数释放对象
        cout << "销毁了一个单例对象" << endl;                                            
    }
         
    static Singleton* instance;  //这是我们的单例对象,它是一个类对象的指针
public:
    static Singleton* getInstance();
                                        
private:
    //定义一个内部类
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
 
    //定义一个内部类的静态对象
    //当该对象销毁的时候，调用析构函数顺便销毁我们的单例对象
    static Garbo _garbo;
};
 
//下面这个静态成员变量在类加载的时候就已经初始化好了
Singleton* Singleton::instance = NULL; 
Singleton::Garbo Singleton::_garbo;     //还需要初始化一个垃圾清理的静态成员变量
 
Singleton* Singleton::getInstance(){
    if(instance == NULL)
        instance = new Singleton();
    return instance;   
}
