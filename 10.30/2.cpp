#include<iostream>  
#include<algorithm>  
#include<stack>
#include<cstdio>
#include<cmath>  
using namespace std;
int temp1 = -1, temp2 = -1;
char s[4] = { 'q','a','b','c' };//为了解题简便，我是从1开始算的  
stack<int> a[4];
int c1 = 0;
int rank1[4];
bool compare(int a1, int b1) {//给栈顶元素排序用  
	if(a[a1].top() >= a[b1].top())
		return true;
	if(a[a1].top()<a[b1].top())
		return false;
	return false;
}
bool move1(int before, int after) {
	if((a[after].top() - a[before].top()) % 2 == 0)
		return false;
	a[after].push(a[before].top());
	a[before].pop();
	temp1 = before; temp2 = after;//记录上一次移动的物块位置  
	printf("%c -> %c\n", s[temp1], s[temp2]);//printf比cout要快  
	c1++;
	return true;
}
int main() {
	int i, N;
	cin >> N;
	a[1].push(N + 1);
	for(i = 0;i<N;i++)
		a[1].push(N - i);
	a[2].push(N+ 2);
	a[3].push(N + 3);
	if(N% 2 == 1) {
		move1(1, 3);
		temp1= 1;
		temp2= 3;
	}
	else{
		move1(1,2);
		temp1 = 1; temp2 = 2;
	}
	for(i= 1;i<= 3;i++)//初始化栈排序表  
		rank1[i] = i;
	int tt;
	while(c1<pow(2, N) - 1) {
		sort(rank1+ 1,rank1+ 4,compare);//按compare函数排序  
		if(temp2==rank1[2]) {
			if (tt == temp1) move1(rank1[3], rank1[2]);
			else move1(rank1[3], rank1[1]);	
		}
		else
			move1(rank1[2], rank1[1]);
		tt= rank1[2];
	}
}
