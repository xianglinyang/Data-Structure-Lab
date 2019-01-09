#include<iostream>
#include<string>
using namespace std;
int min(int a, int b) {
	return a < b ? a : b;
}
int edit(string str1, string str2) {
	int max1, max2, d, temp, i, j;
	max1 = str1.size()+1;
	max2 = str2.size()+1;
	int **ptr = new int*[max1];
	for (i = 0; i < max1; i++)
		ptr[i] = new int[max2];
	for (i = 0; i < max1; i++)
		ptr[i][0] = i;
	for (i = 0; i < max2; i++)
		ptr[0][i] = i;
	for (i = 1; i < max1; i++) {
		for (j = 1; j < max2; j++) {
			temp = min(ptr[i - 1][j] + 1, ptr[i][j - 1] + 1);
			if (str1[i] == str2[j]) d = 0;
			else d = 1;
			ptr[i][j] = min(temp, ptr[i - 1][j - 1] + d);
		}
	}
		int dis = ptr[max1 - 1][max2 - 1];
		for (i = 0; i < max1; i++) {
			delete[]ptr[i];
			ptr[i] = NULL;
		}
		delete ptr;
		ptr = NULL;
		return dis;
	}

	int main() {
		string str1, str2;
		cin >> str1 >> str2;
		int r = edit(str1, str2);
		cout << "The result is " << r << "." << endl;
		return 0;
	}
