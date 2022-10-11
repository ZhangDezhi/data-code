#include<iostream>
using namespace std;
typedef int T;
class List{
private:
	struct Node{//节点
		typedef int T;
		T  data;
		Node *next;
		Node(const T&d):data(d),next(){}		
	};
	Node *head;
	int sz;
public:
		List():head(),sz(){}
		~List(){}
		Node* &getr(int index){//找到目标位值
			if(index<0||index>sz)throw"out";
			if(index == 0)return head;//返回头指针
			Node * p = head;
			for(int i =0;i<index-1;i++)
					p = p->next;
			return p->next;		
		}
		void travle(){
			Node *pn = head;
			while(pn){
				cout<<pn->data<<' ';
				pn = pn->next;
			}
			cout<<endl;
		}
	
		void insert(const T &d){
			Node *pn = new Node(d);
			pn->next = head;
			head = pn;
		//	pn->data = d;
			sz++;
		}
		bool insert(int index,const T &d){
			if(index<0||index>sz)return false;
			Node *pn = new Node(d);
			Node *&r = getr(index);
			pn->next=r;
			r=pn;
			sz++;
			return true;
		}
		bool del(int index){
			if(index<0||index>sz)return false;
			Node *&r = getr(index);
			Node *q = r;
			r = r->next;
			delete q;
			sz--;
			return true;
		}
		void change(int index,const T& d){
			if(index <0||index>sz)throw"out";
			Node *&r = getr(index);
			r->data = d;

		}
		int find(int d){
			Node*p =  head;
			for(int i=0;i<sz;i++)
				{if(p->data == d)return i;
				 p = p->next;
				}
			return -1;
		}
		void remove(int d){
			for(int i=0;i<sz;i++)
			{
				if(find(d)!=-1)del(find(d));
			}
		}

};
int main()
{
		List list;
		list.insert(1);
		list.insert(2);
		list.insert(3);
		list.insert(4);
		list.insert(5);
		list.insert(6);
		list.travle();
		list.insert(0,10);
		list.insert(3,40);
		list.insert(8,80);
		list.insert(10,90);
		list.travle();
		list.del(0);
		list.del(7);
		list.del(8);
		list.travle();
		list.change(2,4);
		list.travle();
		cout<<list.find(5)<<endl;
		list.insert(4);
		list.insert(4);
		list.insert(4);
		list.insert(6);
		list.insert(6);
		list.insert(6);
		list.insert(6);
		list.travle();
		list.remove(4);
		list.remove(6);
		list.travle();

		return 0;
}
