#include"stdafx.h"
#include<string>
#include<iostream>
#define min(x, y) ((x)<(y)?(x):(y))
#define max(x, y) ((x)<(y)?(y):(x))
using namespace std;
void manacher(char s[], int length, int rad[]) {
    for (int i=1,j=0,k; i < length; i+=k) {
        while (s[i-j-1] == s[i+j+1]) ++j;
        rad[i] = j;
        for (k = 1; k <= rad[i] && rad[i-k] != rad[i]-k; ++k) { // 利用类似镜像的方法缩短了时间 
            rad[i+k] = min(rad[i-k], rad[i]-k);
        }
        j = max(j-k, 0);
    }
}
const int N = 1100005;
char str[N], cpy[N];
int seq[N];

int main() {
	string str;
	int n;
	cin>>n;
	cin.ignore();
    while (n--){
		getline(cin,str);
        int len = str.length();
        cpy[0] = '(', cpy[1] = '#';
        for (int i=0, j=2; i < len; ++i, j+=2) {
            cpy[j] = str[i];
            cpy[j+1] = '#';
        }
        len = len*2+3;
        cpy[len-1] = ')';
        manacher(cpy, len, seq);
        int Max = 1;
        for (int i = 0; i < len; ++i) {
            Max = max(Max, seq[i]);
        }
        cout <<Max<<endl;
    }
    return 0;
}