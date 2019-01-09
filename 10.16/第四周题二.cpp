#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;


int min(int a, int b, int c) {
	int min = a < b ? a : b;
	min = min < c ? min : c; 
	return min;
}
int revise(string str1,string str2) {
	int n, m,i,j;
	n = str1.size();
	m = str2.size();
	int a[20][20];
	memset(a, 0, sizeof(a));
	
	for (i = 0; i <=n; i++) {
		a[i][0] = i;
	}
	for (j = 0; j <=m; j++) {
		a[0][j] = j;
	}
	for (i = 0; i < str1.size(); i++) {
		for (j = 0; j < str2.size(); j++) {
			if (str1[i] == str2[j]) {
				a[i + 1][j + 1] = a[i][j];
			}
			else {
				a[i + 1][j + 1] = min(a[i][j + 1], a[i + 1][j], a[i][j])+1;

			}
		}
	}
	
	return a[n][m];
}

int main()
{
	int min;
	string str1, str2;
	cin >> str1 >> str2;
	min=revise(str1, str2);
	cout << min;
	system("pause");
    return 0;
}

