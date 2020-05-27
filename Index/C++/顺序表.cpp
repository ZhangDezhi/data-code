#include<iostream>
#include<stdexcept>
using namespace std;
typedef int T;
class vector{
		T *data;//数据
		int sz;//长度
		int max;//容量
		void expend(){
			if(sz == max)
			{
				max = 2*max;//扩大容量
			 	T*t = new T[max];
				for(int i = 0;i<sz;i++)
					 t[i] = data[i];
				delete []data;	
				data = t;
			}
		}
public:
		friend ostream &operator<<(ostream &os,vector&v)//<<重载
		{
			for(int i=0;i<v.sz;i++)
					os<<v.data[i]<<"  ";
			cout<<endl;
		}
		~vector(){//析构
				delete []data;}
		vector(int max_size = 5):sz(),data(),max(max_size){//构造赋初值
				data = new T[max_size];//开辟空间
					}
		vector(const vector &v){//拷被构造
			sz = v.sz;
			max = v.max;
			data = new T[v.max];
			for(int i = 0;i<sz;i++)
					data[i] = v.data[i];
		}
		vector &operator =(const vector&v){
			if(this == &v)return *this;//若自赋值，则返回当前对象
			delete []data;//释放原空间
			data = new T[v.max];//创建新空间
			sz = v.sz;//复制数据
			max = v.max;
			for(int i =0;i<sz;i++)
					data[i] = v.data[i];
			return *this;
		}

		//插入数据
		void insert(const T&d){
			if(sz == max)
					expend();
			data[sz++] = d;
		}

		//指定位置插入
		void insert(int index,const T &d){
			if(index<0||index>sz)throw "out";
			if(sz==max)expend();
			for(int i=sz;i>index;i--)
			{
					data[i] = data[i-1];
			}
			data[index]=d;
			sz++;
		}

		//指定位置删除
		void del(int index)
		{
			if(index<0||index>sz)throw "out";
			for(int i = index;i<sz;i++)
			{
					data[i]=data[i+1];
			}
			sz--;
		}

		//返回指定位置
		T &set(int index){//使用引用为什么能够给v.ser(3)赋值？
			if(index<0||index>sz)throw "out";
			return data[index];	
		}

		//查找数据下标
		int  pos(const T&t)
		{
				for(int i = 0;i<sz;i++)
				{
					if(data[i] == t)
							return i;
				}
				return -1;
		}
};

int main()
{
		vector v;
		v.insert(1);
		v.insert(2);
		v.insert(3);
		v.insert(4);
		cout<<v<<endl;
		v.insert(0,10);
		v.insert(4,50);
		cout<<v<<endl;
		v.del(0);
		v.del(5);
		cout<<v<<endl;
		v.set(3) = 4;
		cout<<v<<endl;
		cout<<v.pos(1)<<endl;
		cout<<v.pos(4)<<endl;
		cout<<v.pos(5)<<endl;


		return 0;
}
