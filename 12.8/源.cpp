#include<iostream>
#include"Graph.h"
using namespace std;
int main() {
	Graph G;
	G.CreateGraph();
	//G.PrintGraph();
	G.ToppolOrder();
	return 0;
}