#include<iostream>
#include"link.h"
int main(){
	List<int> list;
	int n,k;
	cin>>n;
	list.creat(n);
	cin>>k;
	list.swap_2(k);
	list.output();
	return 0;
	
} 
