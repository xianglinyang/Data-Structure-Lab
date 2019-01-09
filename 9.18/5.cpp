#include<iostream>
using namespace std;
int main(){
	int n,k,i,j,temp;
	cin>>n>>k;
	int *Array;
	Array=new int[n];
	for(j=0;j<n;j++){
		cin>>Array[j];
	}
	for(i=n-1;i>=0;i--){
		for(j=0;j<i;j++){
			if(Array[j]<Array[j+1]){
				temp=Array[j];
				Array[j]=Array[j+1];
				Array[j+1]=temp;
			}
		}
	}
	i=0;
	while(k>0){
		cout<<Array[i++]<<" ";
		k--;
	}
	cout<<endl;
	
}
