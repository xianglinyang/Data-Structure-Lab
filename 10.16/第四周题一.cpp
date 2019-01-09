#include"stdafx.h"
#include<iostream>
#include<string>
using namespace std;
bool is_ip(const string &ip, int p1, int p2, int p3){
	string ip1 = ip.substr(0,p1);
	if (atoi(ip1.c_str())<256){
		string ip2 = ip.substr(p1,p2-p1);
		if(ip2[0]=='0'&&ip2.length()==1 || ip2[0]!='0'&&atoi(ip2.c_str())<256){
			string ip3 = ip.substr(p2,p3-p2);
			if(ip3[0]=='0'&&ip3.length()==1 || ip3[0]!='0'&&atoi(ip3.c_str())<256){
				string ip4 = ip.substr(p3,ip.length()-p3);
				if(ip4[0]=='0'&&ip4.length()==1 || ip4[0]!='0'&&atoi(ip4.c_str())<256){
					return true;
				}
			}
		}
	} 
	return false;
}
int main(){
	int point1,point2,point3;
	int ip_num = 0;
	string ip;
	cin >> ip;
	int ip_len = ip.length();
	for(point1=1; point1<=3 && ip_len-point1 >= 3 ; ++point1){
		for(point2=point1+1; point2<=point1+3 && ip_len-point2 >= 2; ++point2){
			for(point3=point2+1; point3<=point2+3 && ip_len-point3 >= 1; ++point3){
				if(is_ip(ip,point1,point2,point3)){
					string tmp = ip;
					tmp.insert(point1,".");
					tmp.insert(point2+1,".");
					tmp.insert(point3+2,".");
					cout<<tmp<<endl;
					ip_num ++;
				}
			}
				
		}
	}
	cout<<"合法的ip地址有："<<ip_num<<endl;
	return 0;


}