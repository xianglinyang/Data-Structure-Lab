#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	cout<<"ÇëÊäÈëk:";
	int k;
	double num,median;
	cin>>k;
	vector<double> median1,temp; 
	cin>>num;
	median1.push_back(num);
	while(cin>>num) median1.push_back(num);
	vector<double>::size_type me_size;
	me_size=median1.size();
	int i=0;
	while(i+k<=me_size){
		for(int m=0;m<k;m++){
			temp.push_back(median1[i+m]);
		}
		sort(temp.begin(),temp.end());
		if(k%2) cout<<temp[k/2]<<" ";
		else cout<<(temp[k/2]+temp[k/2-1])/2<<" ";
		temp.clear();
		i++;
	}
	return 0;
	
} 
