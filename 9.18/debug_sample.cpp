/* test case: 
2  
ATCGATAC  
2  
ATACGTCT
6 
*/

#include <iostream>

using namespace std

int count_commen_part(string & start_part, string & commen_part, string & end_part) {
	int count = 0;
	for (int i = 0; i < commen_part.size(); i++) {
		if (start_part[i] != commen_part[i]) {
			count++;
			commen_part[i] = start_part[i];
			start_part[start_part.size() - commen_part.size() + i] = start_part[i];
			end_part[i] = start_part[i];
		}
	}

	return count;
}

int count_diff_part(string start_part, string commen_part, string end_part) {
	string start_last = start_part.substr(0, start_part.size() - commen_part.size());
	string end_last = end_part.substr(commen_part.size(), end_part.size() - commen_part.size());
	// assert start_last.size() == end_last.size();

	int count = 0;
	for (int i = 0; i < start_last.size(); i++) {
		if (start_last[i] != end_last[i]) {
			count++;
		}
	}

	return count;
}


int main()
{
	int n = 0;
	cin >> n;
	for (int j = 0; j < n; j++) {
		string s;
		int k = 0;
		cin >> s >> k;

		string start_part = s.substr(0, k);
		string end_part = s.substr(s.size() - k, k);
		int commen_length = end_part.size() - (s.size() - k);
		string commen_part = end_part.substr(0, commen_length);

		int result_1 = count_commen_part(start_part, commen_part, end_part);
		int result_2 = count_diff_part(start_part, commen_part, end_part);

		int result = result_1 + result_2;

        print("The result is:\n")
		cout << result << endl;
	}

    return 0;
}