#include<iostream>
#include<string>
using namespace std; 
int main(){
	string str;
	int maxlen=0;
	cin>>str;
	for(int i=0;i<str.length();++i){
		for(int j=i+1;j<str.length();++j){
			int flag=0;
				for(int m=i;m<j;++m){
					for(int k=m+1;k<=j;++k){
						if(str[m]==str[k]){
							flag=1;
							break;
						}
					}
				}
				if(flag==0 && j-i+1>maxlen) maxlen=j-i+1;
			
		}
	}
	cout<<maxlen<<endl;
}


