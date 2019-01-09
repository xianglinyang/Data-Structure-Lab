// TwoStackQueue.cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"

#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>

using namespace std;

template<typename T>
class TwoStackQueue{
private:
    stack<T> stackPush, stackPop;
	void stackPush_to_stackPop(void); //utility function
	void stackPop_to_stackPush(void); // utility function
public:
	bool peek(void); // whether the queue is empty
	bool add(const T& t); // push element into queue
    bool poll(void); // pop element out of queue
	void front(void); // show the head element of the queue
	void printQueue(void); // show all elements of the queue
};

template<typename T>
void TwoStackQueue<T>::stackPush_to_stackPop(void){
    while(!stackPush.empty()){
        stackPop.push(stackPush.top());
        stackPush.pop();
    }
}

template<typename T>
void TwoStackQueue<T>::stackPop_to_stackPush(void){
    while(!stackPop.empty()){
        stackPush.push(stackPop.top());
        stackPop.pop();
    }
}

//check whether the queue is empty or not
template<typename T>
bool TwoStackQueue<T>::peek(void){
	if(stackPush.empty() && stackPop.empty()){
		//cout<<"Queue is empty!"<<endl;
		return true;
	}else{
		//cout<<"Queue is not empty!"<<endl;
		return false;
	}
}

// push element to queue
template<typename T>
bool TwoStackQueue<T>::add(const T& t){
	if(!stackPop.empty()){
		stackPop_to_stackPush();
	}
	//cout<<"push element: "<<t<<endl;
    stackPush.push(t);
	return true;
}

// pop element from queue
template<typename T>
bool TwoStackQueue<T>::poll(void){
	if(!stackPush.empty()){
		stackPush_to_stackPop();
	}
	
	if(!stackPop.empty()){
		//cout<<"pop element: "<<stackPop.top()<<endl;
		stackPop.pop();
		return true;
	}else{
        //cout<<"Queue is empty now,can not pop!"<<endl;
		return false;
    }
}

// show head element of the queue
template<typename T>
void TwoStackQueue<T>::front(void){
	if (!stackPush.empty()){
		stackPush_to_stackPop();
	}

	if (!stackPop.empty()){
		cout<<"head element: "<<stackPop.top()<<endl;
	}else{
		cout<<"Queue is empty now, no head element!"<<endl;
	}
}

// use both stackPush and stackPop when printing
template<typename T>
void TwoStackQueue<T>::printQueue(void){
	if(!stackPush.empty()){
		stackPush_to_stackPop();
	}
	if(!stackPop.empty()){
		cout<<"current queue: ";
		while(!stackPop.empty()){ 
			cout<<stackPop.top()<<" ";
			stackPush.push(stackPop.top());
			stackPop.pop();
		}
		cout<<endl;
	}else{
		cout<<"Queue is empty now, no element to be printed!"<<endl;
	}
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

void showResult(int r){
	if(r)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
}

int main() 
{
    TwoStackQueue<int> queue_int;
    cout<<"Test queue:"<<endl;

	string str,op,value;
	while(getline(cin,str)){
		vector<string> vec_str = split(str);
		op = vec_str[0];
		value = vec_str[1];

		//请在输入完每个命令后多输一个空格，否则会报错
		if(op=="add")
			showResult(queue_int.add(atoi(value.c_str())));
		else if(op=="printQueue") 
			queue_int.printQueue();
		else if(op=="front")
			queue_int.front();
		else if(op=="poll")
			showResult(queue_int.poll());
		else if(op=="peek")
			showResult(queue_int.peek());
		else if(op=="end")
			break;
		else
			cout<<"Command doesn't exist!"<<endl;
	}

    return 0;
}
