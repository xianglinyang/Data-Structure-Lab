#include<iostream> 
#include<string>
using namespace std;
int main(){
	string s;
	cin>>s;
	int k,l,max=1;
	l=s.length();
	int i=0,j=1,flag=0;
	while(j<l){
		for(k=i;k<j;k++){
			if(s[j]==s[k])
			{
				flag=1;
				break;
			}
		}
		if(!flag){
			if(max<j-i+1) max=j-i+1;
			j++;
		}
		else{
			i=k+1;
			j++;
			flag=0;
		}
	}
	cout<<max<<endl;
}
