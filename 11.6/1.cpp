#include<iostream>
#include<string>
#include"Queue.h"
using namespace std;
int main() {
	Queue test;
	string command;
	int x;
	while (1) {
		cin >> command;
		if (command == "add") {
			cin >> x;
			test.Add(x);
			cout << "true" << endl;
		}
		if (command == "poll") {
			if (test.poll()) cout << "true" << endl;
			else cout << "false" << endl;
		}
		if (command == "printQueue") {
			test.printQueue();
		}
		if (command == "peek") {
			if (test.peek()) cout << "true" << endl;
			else cout << "false" << endl;
		}
	}
	return 0;

}