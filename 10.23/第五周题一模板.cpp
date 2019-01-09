#include"stdafx.h"
#include<string>
#include<vector>
#include<iostream>
using namespace std;
template <class Type> class List;
template <class Type> class Node{
friend class List<Type>;
public:
	Node(const Type &v):data(v),link(NULL){}
private:
	Type data;
	Node<Type> * link;
};
template<class Type> class List{
public:
	List():head(NULL),tail(NULL){}
	bool add(const Type &v);
	bool remove(const Type &v);
	bool find(const Type &v);
	void printList();
private:
	Node<Type> *head,*tail;
};
template<class Type> bool List<Type>::add(const Type &v){
	if(head==NULL){
		head = new Node<Type>(v);
		tail = head;
	}
	else{
		tail->link = new Node<Type>(v);
		tail = tail->link;
	}
	return true;
}
template<class Type> void List<Type>::printList(){
	Node<Type> *p = head;
	while(p){
		cout<<p->data<<" ";
		p = p->link;
	}
	cout<<endl;
}

vector<string> split(const string &str){
	vector<string> res;
	for(int i=0;i<str.length(); ++i){
		if (str[i]==' ') {
			res.push_back(str.substr(0,i));
			res.push_back(str.substr(i+1,str.length()-i));
		}
	}
	return res; 
}
int main(){
	string str;
	string op,value;
	//输入的格式严格按照题目中的input 格式:add 1 或者:add abc
	cout<<"Type为string类型"<<endl;
	List<string> strList;
	while(getline(cin,str)){ //ctrl+z 结束输入
		vector<string> vec_str = split(str);
		op = vec_str[0];
		value = vec_str[1];
		if(op=="add") cout<<strList.add(value)<<endl;
		if(op=="printList") strList.printList();
	}
	cin.clear();
	cout<<"Type为int类型"<<endl;
	List<int> intList;
	while(getline(cin,str)){
		vector<string> vec_str = split(str);
		op = vec_str[0];
		value = vec_str[1];
		if(op=="add") cout<<intList.add(atoi(value.c_str()))<<endl;
		if(op=="printList") intList.printList();
	}
	
	return 0;
}