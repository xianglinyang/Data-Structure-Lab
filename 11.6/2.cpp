/*#include<iostream>
using namespace std;
int queen[20], count;
	bool place(int N) {
		for (int i = 0; i < N; i++)
			if (queen[i] == queen[N] || i - queen[i] == N - queen[N]||i-queen[i]==queen[N]-N) return false;
		return true;
	}
	int valid(int row,int n) {
		if (row == n) ::count++;
		for (int i = 0; i < n; i++) {
			queen[row] = i;
			if (place(row)) valid(row + 1,n);
		}
		return ::count;
	}

int main() {
	int cnt;
	for (int i = 1; i < 21; i++) {
		::count = 0;
		cnt = valid(0, i);
		cout << i << ":" << cnt << endl;
	}
	return 0;
}*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
const int N = 20;
int q[N];
int cont = 0;
//检验第i行的k列上是否可以摆放皇后  
int find(int i, int k)
{
	int j = 1;
	while (j<i)
	{
		//第j行的皇后是否在k列或(j,q[j])与(i,k)是否在斜线上  
		if (q[j] == k || abs(j - i) == abs(q[j] - k))
			return 0;
		j++;
	}
	return 1;
}
void place(int k, int n)
{
	int j;
	if (k > n) cont++;
	else{
		for (j = 1; j <= n; j++)
		{
			if (find(k,j))
			{
				q[k] = j;
				place(k + 1,n);
			}
		}
	}
}

int main(void)
{
		for (int i = 1; i < 21; i++) {
			cont = 0;
			place(1, i);
			cout << i << ":" << cont << endl;
		}
	system("pause");
	return 0;
}
