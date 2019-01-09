#pragma once
#ifndef _GRAPH_h
#define _GRAPH_h

#include<iostream>
#include<vector>
using namespace std;

const int DefaultSize = 10;  //ȱʡ�������
template <class NameType, class T> class Graph;//ͼ���ǰ����������
template <class T> class EdgeNode {  //�߽����ඨ��
	//friend class Graph <NameType, T>;
public:	
	int dest;  //�ߵ���һ����λ��
	T cost;  //���ϵ�Ȩֵ
	EdgeNode <T> *link;  //�߽����ָ��

	EdgeNode() { }  //���캯��
	EdgeNode(int d, T c) : dest(d), cost(c), link(NULL)
	{ }  //���캯��
};

template <class NameType, class T> class VertexNode {  //��������ඨ��
	friend class EdgeNode <T>;
	friend class Graph <NameType, T>;
	NameType data;  //��������
	EdgeNode <T> *adj;  //���߱��ͷָ��
};

template <class NameType, class T> class Graph {
	//ͼ���ඨ��
	
private:
	vector<VertexNode<NameType, T>> NodeTable;
	//��������������ͷ��㣩
	int VerticesNum;  //��ǰ������
//	int VerticesMaxNum;  //��󶥵���
	int EdgesNum;  //��ǰ����
	int GetVertexPos(const NameType &vertex);
	void DFS(int v, int Visited[]);
public:
	Graph(): VerticesNum(0), EdgesNum(0){ }
	~Graph() { }  //��������
	void create();
	int GraphEmpty() const { return VerticesNum == 0; }//�ж�ͼ�շ�
	int VerticesNumber() { return VerticesNum; }
	//����ͼ�Ķ�����
	int EdgesNumber() { return EdgesNum; }  //����ͼ�ı���
	T GetWeight(int v1, int v2);  //ȡ�ߵ�Ȩֵ������ע
	int GetFirstNeighbor(int v);  //ȡ����v�ĵ�һ���ڽӶ���
	int GetNextNeighbor(int v1, int v2);	//ȡ����v1��ĳ�ڽӶ���v2����һ���ڽӶ���
    void InsertVertex(const NameType Vertex);	//��ͼ�в���һ���¶���
	void InserEdge(int v1, int v2, T weight);	//��ͼ�в���һ���±�
	void DFS();
	T getVertexName(const int pos);
	void printGraph();
	void delArc(int i, int j);
//	void RemoveVertex(int v);  //��ͼ��ɾ��һ������
//	void RemoveEdge(int v1, int v2);  //��ͼ��ɾ��һ����

};

template <class NameType, class T> int Graph <NameType, T> ::GetVertexPos(const NameType &vertex)
{  //��������vertex��ͼ�е�λ��
	for (int i = 0; i<NodeTable.size(); i++)
		if (NodeTable[i].data == vertex)
			return i;
	return -1;
}



template <class NameType, class T> void Graph<NameType, T> ::create() {
	int  e, n, x, k, j;
	NameType  tail, head;
	T weight;
	cout << "�������붥�����ͱ�����";
	cin >> n >> e;  //���붥�����ͱ���
	cout << "���붥�㣺";
	for (int i = 0; i < n; i++) {
		cin >> x;
		InsertVertex(x);
	}
	cout << "����ߺ�Ȩ�أ�" << endl;
	for (int i = 0; i<e; i++)
	{
		cin >> tail >> head >> weight;
		//��������ߵ������˵���Ȩֵ��Ϣ
		k = tail;
		j = head;
		//	k = GetVertexPos(tail);
		//	j = GetVertexPos(head);  //��ȡһ���������˵��λ��
		InserEdge(k, j, weight);  //����һ����
		InserEdge(j, k, weight);
	}
}

template <class NameType, class T> void Graph<NameType, T> ::InsertVertex(const NameType Vertex) {
	VertexNode<NameType, T> ver;
	ver.data = Vertex;
	ver.adj = NULL;
	NodeTable.push_back(ver);
	VerticesNum++;
}

template <class NameType, class T> void Graph<NameType, T> ::InserEdge(int v1, int v2, T weight) {
	int pos1 = GetVertexPos(v1);
	if (pos1 != -1)
	{
		//ʼ���ڱ�ͷ����߽��  
		EdgeNode<T> * p = new EdgeNode<T>;
		p->dest = v2;
		p->cost = weight;
		p->link = NodeTable[pos1].adj;
		NodeTable[pos1].adj = p;
		EdgesNum++;
		return;
	}
	else {
		InsertVertex(v1);
		InserEdge(v1, v2, weight);
		return;
	}
}


template <class NameType, class T> T Graph <NameType, T> ::GetWeight(int v1, int v2){  //��ȡ��v1��v2Ϊ�����˵��һ���ߵ�Ȩֵ
   //���ñ߲�������ͼ���򷵻�Ȩֵ0
	if (v1 != -1 && v2 != -1)
	{
		EdgeNode <T> *p = NodeTable[v1].adj;
		//������ͷָ��
		while (p != NULL)
			if (p->dest == v2)
				return p->cost;  //�ҵ���Ӧ�ߣ�����Ȩֵ
			else p = p->link;  //��������һ����
	}
}

template <class NameType, class T> int Graph <NameType, T> ::GetFirstNeighbor(int v)
{  //��������v�ĵ�һ���ڽӶ����λ��
   //����������򷵻�-1
	if (v != -1)
	{  //v����
		EdgeNode <T> *p = NodeTable[v].adj;
		//������ͷָ��
		if (p != NULL) {
			int x = p->dest;
			for (int i = 0; i < VerticesNumber(); i++) {
				if (x == NodeTable[i].data) return i;
			}
		}
		//����һ���ڽӶ�����ڣ��򷵻ظñߵ���һ������
	}
	return -1;  //�������ڣ��򷵻�-1
}

template <class NameType, class T> int Graph <NameType, T> ::GetNextNeighbor(int v1, int v2)
{  //��������v1��ĳ�ڽӶ���v2����һ���ڽӶ����λ��
   //��û����һ���ڽӶ����򷵻�-1
	if (v1 != -1)
	{  //v1����
		EdgeNode <T> *p = NodeTable[v1].adj;
		//������ͷָ��
		while (p != NULL)
		{  //Ѱ��ĳ�ڽӶ���v2 
			if (p->dest == NodeTable[v2].data && p->link != NULL) {
				int x = p->link->dest;
				for (int i = 0; i < VerticesNumber(); i++) {
					if (x == NodeTable[i].data) return i;
				}
			}

			else p = p->link;
		}
	}
	return -1;
}

template <class NameType, class T> void Graph <NameType, T> ::DFS() {
	int i, *visited = new int[VerticesNumber()];//������������
	for (i = 0; i < VerticesNumber(); i++) {//���������ʼ��
		visited[i] = 0;
	}
	DFS(0, visited);//�ӵ�һ����ʼDFS����
}

template <class NameType, class T> void Graph <NameType, T> ::DFS(int v, int visited[])
{  //�Ӷ���v����
   //��������������������������δ���ʹ��Ķ���
   //��������Visited���ڶ��ѷ��ʹ��Ķ������Է��ʱ��
	cout << NodeTable[v].data;  //������ʶ�����Ϣ
	visited[v] = 1;  //�ö�����ʱ�־�޸�Ϊ�ѷ��ʹ�
	int w = GetFirstNeighbor(v);
	//Ѱ�Ҹոշ��ʹ�����v�ĵ�һ���ڽӶ���w
	while (w != -1)
	{  //���ڽӶ������
		
		if (!visited[w]) {  //�����ڽӶ���δ�����ʹ�
			DFS(w, visited);  //����ڽӶ���w��ʼ���еݹ����
		}
		w = GetNextNeighbor(v, w);
		//Ѱ�Ҷ���v����һ���ڽӶ���
	}
}

template <class NameType, class T> T Graph <NameType, T>::getVertexName(const int pos){
	if (pos >= 0 && pos < NodeTable.size())
		return NodeTable[pos].data;
	//  else  
	//      throw Exception;  
}

template <class NameType, class T> void Graph <NameType, T>::printGraph(){
	for (int i = 0; i<NodeTable.size(); i++)
	{
		cout <<  NodeTable[i].data;
		EdgeNode<T> * p = NodeTable[i].adj;
		while (p != NULL)
		{
			cout << "->" << p->dest   << "(";
			cout << p->cost;
			cout << ")";
			p = p->link;
		}
		cout << endl;
	}
}

template <class NameType, class T> void Graph <NameType, T>::delArc(int i, int j) {
	Graph<int, int> graph;
	int pos1 = GetVertexPos(i);
	int pos2 = GetVertexPos(j);
	if (pos1 != -1)
	{
		EdgeNode<T>* p = NodeTable[pos1].adj;
		EdgeNode<T>* q = NULL;
		EdgeNode<T>* pre = NULL;
		while (p != NULL)
		{
			if (p->dest == j)//�ҵ����   
			{
				q = p;
				if (p == NodeTable[pos1].adj)//ɾ������ͷ���   
				{
					NodeTable[pos1].adj = p->link;
				}
				else
				{
					pre->link = p->link;
				}
				delete q;
				break;//��������                  
			}
			else//��������   
			{
				pre = p;
				p = p->link;
			}
		}
	}
	if (pos2 != -1)
	{
		EdgeNode<T>* p = NodeTable[pos2].adj;
		EdgeNode<T>* q = NULL;
		EdgeNode<T>* pre = NULL;
		while (p != NULL)
		{
			if (p->dest == i)//�ҵ����   
			{
				q = p;
				if (p == NodeTable[pos2].adj)//ɾ������ͷ���   
				{
					NodeTable[pos2].adj = p->link;
				}
				else
				{
					pre->link = p->link;
				}
				delete q;
				break;//��������                  
			}
			else//��������   
			{
				pre = p;
				p = p->link;
			}
		}
	}
}

#endif