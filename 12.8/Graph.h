#pragma once
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
const int DefaultSize = 10;
/*class Graph;
class VertexNode {
	friend class Graph;
	friend class EdgeNode;
private:
	EdgeNode *adj;
};
class EdgeNode {
	friend class Graph;
private:
	int dest;
	EdgeNode *link;
public:
	EdgeNode(){}
	EdgeNode(int d):dest(d),link(NULL){}
	~EdgeNode(){}
};
class Graph {
private:
	VertexNode *NodeTable;
	int VerticesNum;
	int VerticesMaxNum;
	int EdgesNum;
	int *count;
public:
	Graph() {
		VerticesNum = 0;
		VerticesMaxNum = DefaultSize;
		EdgesNum = 0;
	}
	~Graph(){
		for (int i = 0; i < VerticesNum; i++) {
			EdgeNode *p = NodeTable[i].adj;
			while (p != NULL) {
				NodeTable[i].adj = p->link;
				delete p;
				p = NodeTable[i].adj;
			}
			delete[]NodeTable;
		}
	}
	void PrintGraph() {
		EdgeNode *p;
		for (int i = 0; i < VerticesNum; i++) {
			p = NodeTable[i].adj;
			while (p) {
				cout << p->dest;
				p = p->link;
			}
		}
	}
	void InsertEdge(int head, int tail, EdgeNode *&p) {
		EdgeNode *q = new EdgeNode();
		q->dest = tail;
		q->link = p;
		p = q;
	}
	void CreateGraph(){
		int e, i;
		char head, tail, bracket;
		ifstream in;
		in.open("data.in.txt");
		in >> e;
		NodeTable = new VertexNode[e];
		VerticesNum = e;
		if (NodeTable == NULL)
			cerr << "存储分配错！" << endl;
		in >> bracket;
		while(1){
			in >> bracket;
			if (bracket == ']') break;
			in >> head >> tail;
			InsertEdge(head,tail,NodeTable[head].adj);
			EdgesNum++;
			in >> bracket;
		}
		count = new int[e];
		EdgeNode *p;
		for (i = 0; i < VerticesNum; i++) count[i] = 0;
		for (i = 0; i < VerticesNum; i++) {
			p = NodeTable[i].adj;
			while (p) {
				count[p->dest]++;
				p = p->link;
			}
		}
		in.close();
	}
	void ToppolOrder() {
		ofstream out;
		out.open("output.txt");
		int top = -1;
		int i;
		for (i = 0; i < VerticesNum; i++)
			if (count[i] == 0) {
				count[i] = top;
				top = i;
			}
		for(i=0;i<VerticesNum;i++){
			if (top == -1) {
				out << "不能完成课程!" << endl;
				out.close();
				return;
			}
			else {
				int j = top;
				top = count[top];
				EdgeNode *l = NodeTable[j].adj;
				while (l) {
					int k = l->dest;
					if (--count[k] == 0) {
						count[k] = top;
						top = k;
					}
					l = l->link;
				}
			}
		}
		out << "能完成课程！" << endl;
		out.close();
	}
};*/
class Graph;
class VertexNode {
	friend class Graph;
	friend class EdgeNode;
private:
	char data;
	EdgeNode *adj;
};
class EdgeNode {
	friend class Graph;
private:
	int dest;
	int weight;
	EdgeNode *link;
public:
	EdgeNode() {}
	EdgeNode(int d) :dest(d), weight(0), link(NULL) {}
	~EdgeNode() {}
};
class Graph {
private:
	//VertexNode *NodeTable;
	vector<VertexNode> NodeTable;
	int VerticesNum;
	int VerticesMaxNum;
	int EdgesNum;
	int *count;
public:
	Graph() {
		VerticesNum = 0;
		VerticesMaxNum = DefaultSize;
		EdgesNum = 0;
	}
	~Graph() {
		for (int i = 0; i < VerticesNum; i++) {
			EdgeNode *p = NodeTable[i].adj;
			while (p != NULL) {
				NodeTable[i].adj = p->link;
				delete p;
				p = NodeTable[i].adj;
			}
			delete[]NodeTable;
		}
	}
	int GetVertexPos(char vertex) {
		for (int i = 0; i < VerticesNum; i++) {
			if (NodeTable[i].data == vertex)
				return i;
		}
		return -1;
	}
	void InsertEdge(char head, char tail, int weight) {
		EdgeNode *q = new EdgeNode, *p;
		int x;

		x = GetVertexPos(head);
		q->dest = GetVertexPos(tail);
		q->weight = weight;
		q->link = NodeTable[x].adj;
		NodeTable[x].adj = q;

		x = GetVertexPos(tail);
		q = new EdgeNode;
		q->dest = GetVertexPos(tail);
		q->weight = weight;
		q->link = NodeTable[x].adj;
		NodeTable[x].adj = q;

	}
	void CreateGraph(istream &in) {
		int e, v, i, weight;
		char head, tail;
		cout << "请输入小区数量以及路径数量：";
		in >> v >> e;//顶点数，边数
		NodeTable = new VertexNode[v];
		VerticesNum = v;
		cout << "请输入路径端点以及其长度：" << endl;
		for (i = 0; i < e; i++) {
			in >> head >> tail >> weight;
			InsertEdge(head, tail, weight);
			EdgesNum++;
		}
	}
	void PrintGraph() {
		EdgeNode *p;
		for (int i = 0; i < VerticesNum; i++) {
			p = NodeTable[i].adj;
			while (p) {
				cout << NodeTable[i].data << "->" << NodeTable[p->dest].data << ":" << p->weight << endl;
				p = p->link;
			}
		}
	}
};