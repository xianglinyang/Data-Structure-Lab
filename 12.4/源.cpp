#include<iostream>
#include"БъЭЗ.h"
using namespace std;
int main() {
	int n,count,m=0,x;
	int *a;
	cin >> n;
	HuffmanNode *nodes;
	a = new int[10];
	nodes = new HuffmanNode[2 * n - 1];
	create_array(cin, a);
	create_huffman_tree(a, n, nodes);
	count = Huffman_count(nodes, n);
	cout << count << endl;
	return 0;
}