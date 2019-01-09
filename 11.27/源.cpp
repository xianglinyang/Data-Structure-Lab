#include<iostream>
#include<string>
#include<queue>
using namespace std;
class GenList;
typedef struct GenListNode {
	int data;
	struct GenListNode *lchild, *rchild;
}GenListNode;
int turn(string s) {
	int i = 0, count = 0;
	while (s[i]) { count = count * 10 + s[i] - '0'; i++; }
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
	void createList(istream &in) {
		queue<GenListNode*> s;
		string info;
		in >> info;
		if (info == "null") cout << "error" << endl;
		root->data = turn(info);
		s.push(root);
		int i = 1, tag = 1;
		while (s.size() && in >> info) {
			GenListNode *p = new GenListNode(), *q;
			q = s.front();
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
	}
	void recursion_spread(GenListNode* root) {
		if (root->lchild == NULL&&root->rchild == NULL) return;
		else if (root->lchild == NULL) recursion_spread(root->rchild);
		else if (root->rchild == NULL) {
			root->rchild = root->lchild;
			root->lchild = NULL;
			recursion_spread(root->rchild);
		}
		else {
			GenListNode *p;
			p = root->lchild;
			while (1) {
				if (p->rchild) p = p->rchild;
				else if (p->lchild) p = p->lchild;
				else break;
			}
			p->rchild = root->rchild;
			root->rchild = root->lchild;
			root->lchild = NULL;
			recursion_spread(root->rchild);
		}
	}
	void RecursionSpread() {
		recursion_spread(root);
	}
	void nonrecursion_spread(GenListNode* root) {
		while (root) {
			if (root->lchild == NULL&&root->rchild) root=root->rchild;
			else if (root->rchild == NULL&&root->lchild) {
				root->rchild = root->lchild;
				root->lchild = NULL;
				root = root->rchild;
			}
			else if(root->lchild &&root->rchild ){
				GenListNode *p;
				p = root->lchild;
				while (1) {
					if (p->rchild) p = p->rchild;
					else if (p->lchild) p = p->lchild;
					else break;
				}
				p->rchild = root->rchild;
				root->rchild = root->lchild;
				root->lchild = NULL;
				root = root->rchild;
			}
			else break;
		}
	}
	void NonrecursionSpread() {
		nonrecursion_spread(root);
	}
	void order() {
		while (root) {
			cout << root->data << " ";
			root = root->rchild;
		}
		cout << endl;
	}
};
int main() {
	GenList Tree;
	Tree.createList(cin);
	Tree.RecursionSpread();
	Tree.NonrecursionSpread();
	Tree.order();
	return 0;
}