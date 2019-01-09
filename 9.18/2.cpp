#include<iostream>
using namespace std;
int main(){
	int n,k,i,j,temp;
	cin>>n>>k;
	int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(j=0;j<n-1;j++){
    	for(i=0;i<n-1-j;i++){
    		if(arr[i]<arr[i+1]){
    			temp=arr[i];
    			arr[i]=arr[i+1];
    			arr[i+1]=temp;
			}
		}
	}
    for(int i=0;i<k;i++)
       cout<<arr[i]<<" ";
    //ÊÍ·ÅarrÊý×é 
    delete[] arr;
    return 0;

}

