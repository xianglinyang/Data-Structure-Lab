#include<iostream>
#include<istream>
#include<string>
#define MAXN 10
using namespace std;
class GenTree;
class BinNode {
	friend class GenTree;
private:
	char data;
	BinNode*child[MAXN];
public:
	BinNode() {
		int i=MAXN-1;
		for (; i >= 0; i--) child[i] = NULL;
	}
};
class GenTree {
	friend istream& operator>>(istream &in, GenTree t);
private:
	BinNode *first;//根节点指针
	void CreateBinTree(istream &in, BinNode *&BT);
	void preOrder(BinNode *root) {
		if (root == NULL) return;
		int m = MAXN;
		if (root != NULL) {
			cout << root->data <<" ";
			for (int i = 0; i<m; i++) preOrder(root->child[i]);
		}
	}
public:
	GenTree();
	~GenTree() { }
	void preorder() {
		preOrder(first);
	}

};
GenTree::GenTree() {
	first = new BinNode;
	first->data = 0;
}

void GenTree::CreateBinTree(istream &in, BinNode *&BT) {
	char ch;
	if (first->data == 0) {
		in >> ch;
		first->data = ch;
	}
	BinNode *p = BT;
	BinNode *t = p,*w;
	int count = 0;
	while (in >> ch) {
		if (ch == '(') {
			w = p->child[count];
			CreateBinTree(in, w);
		}
		else if (ch == ')') {
				p->child[count] = NULL;
			    return;
		}
		else if (ch >= 'A'&&ch <= 'Z') {
			BinNode *q;
			q = new BinNode;
			q->data = ch;
			p->child[count] = q;
			count++;
			}
		else if (ch == ',');
		else if (ch == '#')
			return;
	}
}

istream& operator>>(istream &in, GenTree t) {
	t.CreateBinTree(in, t.first);
	return in;
}

int main() {
	GenTree tree;
	cin >> tree;
	tree.preorder();
	return 0;
}