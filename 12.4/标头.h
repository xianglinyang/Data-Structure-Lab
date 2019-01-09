#pragma once
#include<iostream>
#include<stack>
using namespace std;
struct HuffmanNode {
	int data;
	int lchild, rchild;
};
typedef struct HuffmanNode HuffmanNode;
void create_huffman_tree(int a[],int n,HuffmanNode nodes[]) {
	int n1, n2;
	int min1, min2;
	int i, j;
	int u, v;
	for (i = 0; i < n; i++) {
		nodes[i].data = -a[i];
		nodes[i].lchild = -1;
		nodes[i].rchild = -1;
	}
	for (i = n; i < 2 * n - 1; i++) {
		n1 = -1;
		min1 = 9999;
		n2 = -1;
		min2 = 9999;
		for (j = 0; j < i; j++) {
			v = nodes[j].data;
			u = -v;
			if (u > 0) {
				if (u < min1) {
					min2 = min1;
					n2 = n1;
					min1 = u;
					n1 = j;
				}
				else if (u < min2) {
					min2 = u;
					n2 = j;
				}
			}
		}
				nodes[i].data = nodes[n1].data + nodes[n2].data;
				nodes[i].lchild = n1;
				nodes[i].rchild = n2;
				nodes[n1].data = -nodes[n1].data;
				nodes[n2].data = -nodes[n2].data;
			}
			nodes[2 * n - 2].data = -nodes[2 * n - 2].data;
}
void create_array(istream &in,int a[]) {
	int x, i = 0;
	while (in >> x) a[i++] = x;
}
int Huffman_count(HuffmanNode nodes[],int n) {
	stack<HuffmanNode> s;
	HuffmanNode p;
	int count = 0;//统计乘积
	int flag = 0;//路径长度
	p = nodes[2 * n - 2];
	do {
		while (1) {   //向左子树走
			if (p.data > 0) {
				s.push(p);
				flag++;
			}	
			if (p.lchild == -1) break;
			else p = nodes[p.lchild];
		}
		while (s.size()) {
			p = s.top();
			s.pop();
			flag--;
			if (p.data > 0) {
				p.data = -p.data;
				s.push(p);
				flag++;
				if (p.rchild == -1);
				else p = nodes[p.rchild];
				break;

			}
			else if (p.lchild == -1 && p.rchild == -1) { 
				count = count - flag*p.data;
			}//叶子结点处理
		}
	} while (s.size());
	return count;
}






