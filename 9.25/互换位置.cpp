#include<iostream>
#include"huhuanweizhi.h"
using namespace std;
int main(){
	LinkNode <int> *p,*q,*r,*head;
	head=r=Create_List(4);
	for(;p->link!=NULL;){
		p=r->link;
	    q=p->link;
	    p->link=r;
	    r->link=q;
	    r=q;
	}
	List <int> :: PrintList(LinkNode<int> head);
	return 0;
    
    



   





} 
