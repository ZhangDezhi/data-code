#include<iostream>
using namespace std;
class M33{
public:
	M33(int (*a)[3]){//数组指针，
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				data[i][j]=a[i][j];
	}
	void print(){
		for(int i=0;i<3;i++)
		{	for(int j=0;j<3;j++)
				cout<<data[i][j]<<'\t';
			cout<<endl;
		}
	}
	friend ostream &operator <<(ostream &o,const M33 &m ){//插入运算符重载格式：ostream &operator <<(ostrea& os ,自定义类名 &m)
		for(int i=0;i<3;i++)
			{for(int j =0;j<3;j++)
				o<<m.data[i][j]<<'\t';
			cout<<endl;
			}
		return o;
	}
	const M33 operator +(const M33 &obj1)const{//
		int a[3][3];	
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				a[i][j] = data[i][j]+obj1.data[i][j];
		return M33 (a);
	}
	const M33 operator +=(const M33 &m){
		return *this = *this +m;
	}
	const M33 operator *(const M33 &m){
		int a[3][3]={0};
		for(int i = 0;i<3;i++)
			for(int j=0;j<3;j++)
				for(int k=0;k<3;k++)
					a[i][j] += data[i][k]*m.data[k][j];		return a;
	}
	const M33 operator *=(const M33& m){
		return *this = *this * m;
	}
	 M33 &operator ++( )
	{
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				data[i][j]++;
		return *this;
			
	}
	const M33 operator ++(int)
	{	
			M33 m = *this ;
			++(*this);
			return m;
	}

private:
	int data[3][3];
};
int main()
{
		int a1[3][3]={1,2,3,4,5,6,7,8,9};
		M33 m1(a1);
	//	m1.print();
		cout<<m1;
		int a2[3][3]={9,8,7,6,5,4,3,2,1};
		M33 m2(a2);
		M33 m3 = m1 + m2;
		m3 += m3;
		cout<<m3;
		m3 = m1*m2;
		cout<<m3;
		m1 *= m2;
		cout<<m1;
		cout<<++m1;
		cout<<m1;
		cout<<m1++;
		cout<<m1;
		return 0;
}
