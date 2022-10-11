#include<iostream>
using namespace std;
class List{
		typedef int T;
		struct Node{
			T data;
			Node* next;		
			Node(const T&d):data(d),next(){}
			//~Node(){cout<<"析构咯"<<endl;}
		};
		Node *head;
		T sz;
public:
		List():head(),sz(){}
		void clear(){
				Node*p = head;
				while(p){
					head = p->next;
					delete p;
					 p = head;
					
				}
				head = NULL;
		  }

		//遍历链表输出
		void travel(){
			Node* p = head;
			while(p){
				cout<<p->data<<"  ";
				p = p->next;
			}
			cout<<endl;
		}
		//插入数据
		void insert(const T&t){
			Node*pn = new Node(t);
			pn->next = head;
			head = pn; 
			sz++;
			//delete pn;
		}
		//在指定位置插入
		
			bool insert(const T&index,const T&d){
			Node *pn = new Node(d);
			if(index<0||index>sz)throw "out";
			if(index == 0)
			{
					
				pn->next = head;
				head = pn;
				sz++;
				return 0;
			}
			Node*p =head;
			for(int i=0;i<index-1;i++)
				p = p->next;
			pn->next = p->next;
			p->next = pn;
			sz++;
			//delete pn;
		}
		//删除指定位置
		bool del(const T&index)
		{
				if(index<0||index>sz)throw "out";
				Node*pn = head;
				if(index == 0){
					Node *p = head;
				//	p = p->next;					
					head = p->next;
					delete p;
					return true;
				}
				for(int i=0;i<index-1;i++)
					pn = pn->next;
				Node *t = pn->next;
				pn->next = t->next;
				return true;
		}
		//修改指定位置
		bool set(const T&index,const T&t){
			if(index<0||index>sz)throw "out";
			Node *p = head;
			if(index == 0)
					{
							head->data = t;
							return true ;
					}
			for(int i = 0;i<index-1;i++)
					p = p->next;
			p->data = t;
			return true;
					
		}



};


int main()
{
		List list;
		list.insert(1);
		list.insert(2);
		list.insert(3);
		list.insert(0,10);
		list.insert(4,20);
		list.del(1);
		list.travel();
		list.set(0,10);
		list.set(4,40);
		list.travel();
		list.clear();

		return 0;
}
