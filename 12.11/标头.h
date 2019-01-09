#pragma once
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<fstream>
using namespace std;
class GenList;
typedef struct GenListNode {
	int data;
	int ltag, rtag;
	struct GenListNode *lchild, *rchild;
}GenListNode;
int turn(string s) {
	int i = 0, count = 0;
	if (s[0] == '-') i = 1;
	while (s[i]) { count = count * 10 + s[i] - '0'; i++; }
	if (s[0] == '-') count = -count;
	return count;
}
class GenList {
private:
	GenListNode *root;
public:
	GenList() {
		root = new GenListNode();
		root->data = 0;
		root->lchild = NULL;
		root->rchild = NULL;
	}
	~GenList() {}
	void createList() {
		queue<GenListNode*> s;
		string info;
		ifstream myfile;
		myfile.open("input_12_2.txt");
		myfile >> info;
		if (info == "null") cout << "error" << endl;
		root->data = turn(info);
		s.push(root);
		int i = 1, tag = 1;
		while (s.size() && myfile >> info) {
			GenListNode *p = new GenListNode(), *q;
			q = s.front();
			while (q == NULL) {
				s.pop();
				q = s.front();
			}
			if (info != "null") {
				p->data = turn(info);
				if (q->lchild == NULL&&tag == 1) {
					q->lchild = p;
					s.push(p);
				}
				else {
					q->rchild = p;
					s.push(p);
					s.pop();
				}
				i++;
			}
			else {
				if (q->lchild == NULL&&tag == 1) tag = 2;
				else {
					tag = 1;
					q->rchild = NULL;
					s.pop();
					GenListNode *w;
					w = NULL;
					s.push(w);
				}
			}
		}
		myfile.close();
	}
	int plus(GenListNode *t) {
		if (t == NULL) return 0;
		else return plus(t->lchild) + plus(t -> rchild) + t->data;
	}
	void high_frequency() {
		int *array;
		int temp,i=0,high=0;
		array = new int[100];
		while (i<100) array[i++] = 0;
		stack<GenListNode *> s;
		GenListNode *p = root;
		s.push(p);
		while (s.size()) {
			p = s.top();
			s.pop();
			temp = plus(p);
			array[temp + 50] += 1;
			if (p->rchild) s.push(p->rchild);
			if (p->lchild) s.push(p->lchild);
		}
		for (i = 0; i < 100; i++) if (high < array[i])high = array[i];
		ofstream outfile;
		outfile.open("output_12_2.txt");
		for (i = 0; i < 100; i++) if (array[i] == high) outfile << i - 50 << " ";
		outfile.close();
	}
};