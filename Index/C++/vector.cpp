#include<iostream>
#include<stdexcept>
using namespace std;
typedef int T;
class Vector{
	T *data;//data指向保存数据的内存空间，T方便以后在typedef 修改类型,且方便以后改为模板
	int sz;//有多少个元素
	int max;
	void expend(){
			if(sz == max){
			max = max*2;
			T*t = new T[max];
			for(int i=0;i<sz;i++){//将原来的数据搬到t[]中
				t[i] = data[i];
			}
			delete []data;
			data = t;
		}
	}
public:
	friend ostream &operator<<(ostream &o,const Vector&v){
			for(int i=0;i<v.sz;i++){
					o<<v.data[i]<<"  ";
			    }
				return o;
	}

	Vector(int max_size = 5):sz(0),data(0),max(max_size){
			data = new T [max_size];
	}
	~Vector(){	delete []data;}
	Vector (const Vector&v){
			sz = v.sz;
			max = v.max;
			data = new T[v.max];
			for(int i=0;i<sz;i++)
					data[i] = v.data[i];
	}
	Vector &operator = (const Vector&v){
		if(this == &v)return *this;//1.给自己赋值则返回当前对象
		//2.释放原有空间
		delete[]data;
		//3.创建新的空间
		data = new T [v.max];
		//4.复制数据
		sz = v.sz;
		max = v.max;
		for(int i = 0;i<sz;i++)
				data[i] = v.data[i];
		//5.返回当前对象
		return *this;		
	}
	//插入数据
	void insert(const T&d){//防止数据拷贝调用
		//数组满了,扩容
		if(sz == max)
				expend();
		data[sz++] = d;//插入新数据
	}
	//在指定位置
	bool insert(int index,const T&t)
	{
			if(index<0||index>sz)return false;
			if(index == sz) expend();
			else for(int i = sz;i>index;i--)
			{
					data[i] = data[i-1];
					//data[index]=t;
			}
			data[index]=t;
			sz++;
			return true;
	}
	//删除指定位置数据
	bool rease(int index){
		if(index<0||index>sz)return false;	
		for(int i=index;i<sz;i++)
				data[i] = data[i+1];
		sz--;
		return true;	
	}
	//修改指定位值的数据
	bool set(int index,const T&d){
		if(index<0||index>=sz)return false;
		data[index]=d;
		return true;
	}
	//返回指定位置的数据本身
	T& at(int index)throw(out_of_range){
		if(index<0||index>sz)throw out_of_range("out of rang");
		return data[index];
	}
	//返回指定数据所在的位置
	int pos(const T&d){
		for(int i=0;i<sz;i++){
			if(data[i] == d)return i;
		}
		return -1;
	}
	//下标运算符
	T&operator [](int index){
		return data[index];
	}
	//返回长度
	int size(){
		return sz;
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
		v.insert(0,10);
		cout<<v<<endl;
		v.insert(3,30);
		cout<<v<<endl;
		v.insert(7,70);
		cout<<v<<endl;
		v.insert(10,100);
		cout<<v<<endl;
		cout<<"--------------------"<<endl;
		v.rease(0);
		cout<<v<<endl;
		v.rease(6);
		cout<<v<<endl;
		v.rease(2);
		cout<<v<<endl;
		cout<<"----------v--------"<<endl;
		v.set(0,10);
		cout<<v<<endl;
		v.set(5,60);
		cout<<v<<endl;
		v.set(3,40);
		cout<<v<<endl;			
		cout<<"-----------"<<endl;
		v.at(0)=1;
		cout<<v<<endl;
		v.at(3)=4;
		cout<<v<<endl;
		v.at(5)=6;
		cout<<v<<endl;
		cout<<"------------"<<endl;
		cout<<v.pos(6)<<endl;
		cout<<v.pos(0)<<endl;
		cout<<v.pos(3)<<endl;
		return 0;
}
