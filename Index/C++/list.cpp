#include<iostream>
using namespace std;
class List{
		typedef int T;
		struct Node{//内部类，节点类
				T data;
				Node* next;
				Node(const T&d):data(d),next(0){}					
			//	~Node(){cout<<"~Node"<<endl;}
		};
		Node* head;//成员变量
		int sz;//长度
public:
		List():head(),sz(){}
		void clear(){
			Node *p = head;
			while(p){
				head = p->next;
				delete p;
				p = head;
			}
			head = NULL;
		}
		void insert(const T&d){//插入一个元素
			Node *pn = new Node(d);//n(d);
		//	n.
			pn->next = head;
			head = pn;//&n;
			sz++;
		}
		//在指定位置插入
		bool insert(int index,const T&t){
			if (index<0||index>sz)
					return false;
			if (index == 0)
			{
					insert(t);
					return 0;
			}
			Node *p = new Node (t); 
			Node *pn = head;
			for(int i = 0;i<index-1;i++)
			{
				pn = pn->next;
			}
			//pn->data = t;
			p->next = pn->next;
			pn->next = p;
		
			sz++;
			return true;
		}
		//删除指定位置元素
		bool erase (int index){
			Node *p = head ;
			if(index<0||index>=sz)return false;
			if(index ==0)
			{
					Node*p = head;
					head = head->next;
					delete p;
					sz--;
					return true;//没这一句的后果？
			}

			for(int i=0;i<index-1;i++)
				p = p->next;
			Node *pn = p->next;
			p->next = pn->next;
			delete pn;	
			sz--;
		}
		void travel(){
			Node* p = head;
			while(p){
					cout<<p->data<<"  ";
					p = p->next;
			}
			cout<<endl;
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
		list.erase(0);

		list.travel();
		list.clear();
		return 0;
}
