#include<iostream>
#include<vector>
using namespace std;
typedef struct GenListNode {
	int data;
	struct GenListNode *lchild, *rchild;
}GenListNode;
int find(int x,vector<int> mid) {
	int size;
	size = mid.size();
	for (int i = 0; i < size; i++)
		if (mid[i] == x) return i;
}
void create_vector(istream &in,vector<int> mid) {
	int x;
	while (in>>x) {
		mid.push_back(x);
	}
}
class GenList {
private:
	GenListNode *root;
public:
	GenList(){
		root = new GenListNode();
		root->lchild = NULL;
		root->rchild = NULL;
	}
	~GenList(){};
	void createTree(vector<int> pre, vector<int> mid) {
		if (pre.size() == 0) return;
		GenListNode *p, *r;
		root->data = pre[0];
		int i = 1;//遍历一遍节点
		while (i<pre.size()) {
			r = new GenListNode;
			r->lchild = NULL;
			r->rchild = NULL;
			r->data = pre[i++];
			p = root;
			while (1) {
				if (find(r->data, mid) <= find(p->data, mid)) {
					if (p->lchild == NULL) {
						p->lchild = r;
						break;
					}
					else p = p->lchild;
				}
				else {
					if (p->rchild == NULL) {
						p->rchild = r;
						break;
					}
					else p = p->rchild;
				}
			}
		}
	}
	void posorder(GenListNode *root) {
		if (root == NULL) return;
		if (root != NULL) {
			posorder(root->lchild);
			posorder(root->rchild);
			cout << root->data << " ";
		}
	}
	void pos_order() {
		posorder(root);
	}
	void midorder(GenListNode *root) {
		if (root == NULL) return;
		if (root != NULL) {
		    midorder(root->lchild);
			cout << root->data << endl;
			midorder(root->rchild);
		}
	}
	void mid_order() {
		midorder(root);
	}
	void preorder(GenListNode *root) {
		if (root == NULL) return;
		if (root != NULL) {
			cout << root->data << endl;
			preorder(root->lchild);
			preorder(root->rchild);
		}
	}
	void pre_order() {
		preorder(root);
	}



};
int main() {
	vector<int> mid, pre;
	int x,i=0;
	while (cin >> x) {
		pre.push_back(x);
	}
	cin.clear();
	while (cin >> x) mid.push_back(x);
	GenList Tree;
	Tree.createTree(pre, mid);
	//Tree.pre_order();
	//Tree.mid_order();
	Tree.pos_order();
	return 0;
}
