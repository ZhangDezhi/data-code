#include<iostream>
using namespace std;
int g_n = 100;
class A
{
public:
		A (void):m_r(g_n),m_c(0){
		//m_r = g_n;
		//m_c = 0;
		}
		void show(void)
		{
				cout<<m_r<<","<<m_c<<endl;
		}
private:
		int &m_r;//这里是声明，不是定义，初值是在定义中给出，在构造函数中
		const int m_c;
};
int main(void)
{	
		A a;
		a.show();
		return 0;
}
