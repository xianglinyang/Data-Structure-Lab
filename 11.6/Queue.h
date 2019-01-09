#pragma once
#ifndef QUEUE_INCLUDED_
#define QUEUE_INCLUDED_

#include<iostream>
#include<stack>

using namespace std;
class Queue {
private:
	stack<int> mainQ, helpQ;
public:
	Queue() {}
	~Queue(){}
	bool Add(int x) {
		int temp;
		while (!mainQ.empty()) {
			temp = mainQ.top();
			mainQ.pop();
			helpQ.push(temp);
		}
		mainQ.push(x);
		while (!helpQ.empty()) {
			temp = helpQ.top();
			helpQ.pop();
			mainQ.push(temp);
		}
		return true;
	}
	bool poll() {
		bool x;
		if (mainQ.empty()) return false;
		mainQ.pop();
		return true;
	}
	void printQueue() {
		int temp;
		while (!mainQ.empty()) {
			temp = mainQ.top();
			cout << temp << " ";
			helpQ.push(temp);
			mainQ.pop();
		}
		cout << endl;
		while (!helpQ.empty()) {
			temp = helpQ.top();
			mainQ.push(temp);
			helpQ.pop();
		}
	}
	bool peek() {
		bool x;
		x=!mainQ.empty();
		return x;
	}
};
#endif