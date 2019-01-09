#include<iostream>
#include"linklist.h" 
using namespace std;
class List{
	public:
		List(){Create_List();}
		~List(){clear();}
		void Create_List();
		void Print();
		struct Node{
			int data;
			Node *next;
			Node(const int& d):data(d),next(NULL){}
		};
		Node *head;
		void clear(){
			Node *p=head;
			while(p){
				Node *q=p->next;
				delete p;
				p=q;
			} 
		}
		
};
void List::Create_List(){
	head=new Node(0);
}
void List::Print(){
	for(Node *p=head;p;p=p->next){
		cout<<p->data<<" ";
	}
}

int main(){
	int a;
	List list;
	cin>>a;
	list.head->data=a;
	List::Node *r=list.head;
	while(cin>>a){
		List::Node *p;
		p->data=a;
		p=r->next;
		r=r->next;
	}
	list.Print();
}















