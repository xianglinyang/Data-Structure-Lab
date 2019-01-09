#ifndef LINK_H_
#define LINK_H_

#include<iostream>
using namespace std;

template <class T> class List;
template <class T> class ListNode{
	friend class List<T>;
private:
	T data;
	ListNode<T> *link;
public:
	ListNode(){link = NULL;}
	ListNode(T a){data = a;link = NULL;}
};
template <class T> class List{
private:
	ListNode<T> *head,*tail;
public:
	List(){head = tail = new ListNode<T>();}
	~List(){};
	void creat(int i);
	void output();
	void swap_1();
	void swap_2(int k);
	int getnum();
};

template <class T>int List<T>::getnum(){
	ListNode<T> *p = head->link;
	int cou = 0;
	for(;p!=NULL;p=p->link) cou++;
	return cou;

}
template <class T>void List<T>::creat(int i)
{
	ListNode<T> *p = new ListNode<T>();
	cin >> p->data;
	head -> link = p;
	tail = tail -> link = p;
	for(int j = 1;j < i;j++){
		p = new ListNode<T>();
		cin >> p->data;
		tail = tail -> link = p;
	}
}
template <class T>void List<T>::output(){
	ListNode<T> *p = head->link;
	for(;p->link!=NULL;p=p->link){
		cout << p->data <<"->";
	}
	cout<<p->data<<endl;
}

template <class T>void List<T>::swap_1()
{
	if(head->link == NULL || head->link->link == NULL){cerr << "No Element can be swapped!";}
	ListNode<T> *p,*q,*Fro;
	q = head->link;
	p = q->link;
	q->link = p->link;
	p->link = q;
	head->link = p;
	for(;q != NULL && p != NULL;){
		Fro = q;
		q = q ->link;
		if(q != NULL){
	p = q->link;
	q->link = p->link;
	p->link = q;
	Fro->link = p;}
	}
}
template <class T>void List<T>::swap_2(int k){
	ListNode<T> *fro,*p,*back;
	fro=head->link;
	p=fro->link;
	back=p->link;
	int i=k-1;
	while(i){
		p->link=head->link;
		head->link=p;
		fro->link=back;
		p=back;
		back=back->link;
		i--;
	}
}	


#endif












