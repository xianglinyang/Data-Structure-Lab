#pragma once
#ifndef _GRAPH_h
#define _GRAPH_h

#include<iostream>
#include<vector>
using namespace std;

const int DefaultSize = 10;  //缺省顶点个数
template <class NameType, class T> class Graph;//图类的前向引用声明
template <class T> class EdgeNode {  //边结点的类定义
	//friend class Graph <NameType, T>;
public:	
	int dest;  //边的另一顶点位置
	T cost;  //边上的权值
	EdgeNode <T> *link;  //边结点后继指针

	EdgeNode() { }  //构造函数
	EdgeNode(int d, T c) : dest(d), cost(c), link(NULL)
	{ }  //构造函数
};

template <class NameType, class T> class VertexNode {  //顶点结点的类定义
	friend class EdgeNode <T>;
	friend class Graph <NameType, T>;
	NameType data;  //顶点名字
	EdgeNode <T> *adj;  //出边表的头指针
};

template <class NameType, class T> class Graph {
	//图的类定义
	
private:
	vector<VertexNode<NameType, T>> NodeTable;
	//顶点表（各边链表的头结点）
	int VerticesNum;  //当前顶点数
//	int VerticesMaxNum;  //最大顶点数
	int EdgesNum;  //当前边数
	int GetVertexPos(const NameType &vertex);
	void DFS(int v, int Visited[]);
public:
	Graph(): VerticesNum(0), EdgesNum(0){ }
	~Graph() { }  //析构函数
	void create();
	int GraphEmpty() const { return VerticesNum == 0; }//判断图空否
	int VerticesNumber() { return VerticesNum; }
	//返回图的顶点数
	int EdgesNumber() { return EdgesNum; }  //返回图的边数
	T GetWeight(int v1, int v2);  //取边的权值，见备注
	int GetFirstNeighbor(int v);  //取顶点v的第一个邻接顶点
	int GetNextNeighbor(int v1, int v2);	//取顶点v1的某邻接顶点v2的下一个邻接顶点
    void InsertVertex(const NameType Vertex);	//在图中插入一个新顶点
	void InserEdge(int v1, int v2, T weight);	//在图中插入一条新边
	void DFS();
	T getVertexName(const int pos);
	void printGraph();
	void delArc(int i, int j);
//	void RemoveVertex(int v);  //在图中删除一个顶点
//	void RemoveEdge(int v1, int v2);  //在图中删除一条边

};

template <class NameType, class T> int Graph <NameType, T> ::GetVertexPos(const NameType &vertex)
{  //给出顶点vertex在图中的位置
	for (int i = 0; i<NodeTable.size(); i++)
		if (NodeTable[i].data == vertex)
			return i;
	return -1;
}



template <class NameType, class T> void Graph<NameType, T> ::create() {
	int  e, n, x, k, j;
	NameType  tail, head;
	T weight;
	cout << "依次输入顶点数和边数：";
	cin >> n >> e;  //输入顶点数和边数
	cout << "输入顶点：";
	for (int i = 0; i < n; i++) {
		cin >> x;
		InsertVertex(x);
	}
	cout << "输入边和权重：" << endl;
	for (int i = 0; i<e; i++)
	{
		cin >> tail >> head >> weight;
		//依次输入边的两个端点与权值信息
		k = tail;
		j = head;
		//	k = GetVertexPos(tail);
		//	j = GetVertexPos(head);  //获取一条边两个端点的位置
		InserEdge(k, j, weight);  //插入一条边
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
		//始终在表头插入边结点  
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


template <class NameType, class T> T Graph <NameType, T> ::GetWeight(int v1, int v2){  //获取以v1与v2为两个端点的一条边的权值
   //若该边不存在于图中则返回权值0
	if (v1 != -1 && v2 != -1)
	{
		EdgeNode <T> *p = NodeTable[v1].adj;
		//边链表头指针
		while (p != NULL)
			if (p->dest == v2)
				return p->cost;  //找到对应边，返回权值
			else p = p->link;  //否则找下一条边
	}
}

template <class NameType, class T> int Graph <NameType, T> ::GetFirstNeighbor(int v)
{  //给出顶点v的第一个邻接顶点的位置
   //如果不存在则返回-1
	if (v != -1)
	{  //v存在
		EdgeNode <T> *p = NodeTable[v].adj;
		//边链表头指针
		if (p != NULL) {
			int x = p->dest;
			for (int i = 0; i < VerticesNumber(); i++) {
				if (x == NodeTable[i].data) return i;
			}
		}
		//若第一个邻接顶点存在，则返回该边的另一个顶点
	}
	return -1;  //若不存在，则返回-1
}

template <class NameType, class T> int Graph <NameType, T> ::GetNextNeighbor(int v1, int v2)
{  //给出顶点v1的某邻接顶点v2的下一个邻接顶点的位置
   //若没有下一个邻接顶点则返回-1
	if (v1 != -1)
	{  //v1存在
		EdgeNode <T> *p = NodeTable[v1].adj;
		//边链表头指针
		while (p != NULL)
		{  //寻找某邻接顶点v2 
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
	int i, *visited = new int[VerticesNumber()];//创建辅助数组
	for (i = 0; i < VerticesNumber(); i++) {//辅助数组初始化
		visited[i] = 0;
	}
	DFS(0, visited);//从第一个开始DFS遍历
}

template <class NameType, class T> void Graph <NameType, T> ::DFS(int v, int visited[])
{  //从顶点v出发
   //按深度优先搜索次序访问所有尚未访问过的顶点
   //辅助数组Visited用于对已访问过的顶点作以访问标记
	cout << NodeTable[v].data;  //输出访问顶点信息
	visited[v] = 1;  //该顶点访问标志修改为已访问过
	int w = GetFirstNeighbor(v);
	//寻找刚刚访问过顶点v的第一个邻接顶点w
	while (w != -1)
	{  //若邻接顶点存在
		
		if (!visited[w]) {  //若该邻接顶点未被访问过
			DFS(w, visited);  //则从邻接顶点w开始进行递归访问
		}
		w = GetNextNeighbor(v, w);
		//寻找顶点v的下一个邻接顶点
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
			if (p->dest == j)//找到结点   
			{
				q = p;
				if (p == NodeTable[pos1].adj)//删除的是头结点   
				{
					NodeTable[pos1].adj = p->link;
				}
				else
				{
					pre->link = p->link;
				}
				delete q;
				break;//结束查找                  
			}
			else//继续查找   
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
			if (p->dest == i)//找到结点   
			{
				q = p;
				if (p == NodeTable[pos2].adj)//删除的是头结点   
				{
					NodeTable[pos2].adj = p->link;
				}
				else
				{
					pre->link = p->link;
				}
				delete q;
				break;//结束查找                  
			}
			else//继续查找   
			{
				pre = p;
				p = p->link;
			}
		}
	}
}

#endif