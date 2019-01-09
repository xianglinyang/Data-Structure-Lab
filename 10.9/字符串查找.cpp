#include<iostream>
#include<string>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	int l1,l2,i=0,j,num,flag=0,m;
	l1=s1.length();
	l2=s2.length();
	int array[26];
	i=0;
	while(i+l1<=l2){
		for(m=0;m<26;m++) array[m]=0;
		for(m=0;m<l1;m++){
		num=s1[m]-'a';
		array[num]+=1;
	    }
		for(int k=0;k<l1;k++){
			array[s2[i+k]-'a']-=1;
		}
		for(j=0;j<26;j++){
			if(array[j]!=0) flag=1;
		}
		if(flag==0){
			cout<<"True"<<endl;
			break;
		}
		else if(i+l1==l2);
		else flag=0;
		i++;
	}
	if(flag) cout<<"False"<<endl;
	return 0;
}
