#include<iostream>
using namespace std;
typedef int T;
class Vector{
private:
	T *data;
	int sz;
	int max;
	void expend(){
		max = 2*max;
		T *t = new T[max];
		for(int i = 0;i<sz;i++)
				t[i] = data[i];
		delete []data;
		data = t;
	}
public:
	Vector(int max_size = 5):data(0),sz(0),max(max_size){
		data = new T[max];//什么意思？开辟max大小的空间
	}
	~Vector(){}
	friend ostream& operator<<(ostream& os,Vector &m){
		for(int i=0;i<m.sz;i++)
			os<<m.data[i]<<' ';
		cout<<endl;
		return os;
	}
	void insert(const T&d){
		if(sz==max)expend();
		data[sz] =d;
		sz++;
	}
	void insert(int index,const T &d){
		if(index<0||index>sz)throw "out";
		for(int i = sz;i>index;i--)
			data[i] = data[i-1];
		data[index] = d;
		sz++;
	}

};
int main()
{
		Vector v;
		v.insert(1);
		v.insert(2);
		v.insert(3);
		v.insert(4);
		v.insert(5);
		v.insert(6);
		v.insert(7);
		cout<<v<<endl;
		cout<<"------------ "<<endl;
		v.insert(0,10);
		v.insert(2,30);
		v.insert(9,100);
		cout<<v<<endl;

		return 0;
}
