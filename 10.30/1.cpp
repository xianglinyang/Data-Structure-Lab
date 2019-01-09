#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string>generate(int n) {
	vector<string> result;
	if (n == 0) {
		result.push_back("");
		return result;
	}
	if (n == 1) {
		result.push_back("()");
		return result;
	}
	for (int i = 1; i <= n; i++) {
		vector<string>left = generate(i - 1);
		vector<string>right = generate(n - i);
		for (int j = 0;j < left.size(); j++) {
			for (int k=0; k<right.size(); k++) {
				result.push_back("(" + left[j] + ")" + right[k]);
			}
		}
	}
	return result;
}
void print(vector<string> result) {
	int size = result.size(), i;
	cout << "[";
	for ( i = 0; i < size - 1; i++) cout << result[i] << ",";
	cout << result[i] << "]" << endl;
}
int main() {
	cout << "n=:";
	int n;
	cin >> n;
	vector<string> Theresult;
	Theresult = generate(n);
	print(Theresult);
	return 0;

}
