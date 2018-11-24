#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		double l,t1,t2,v1,v2;
		cin>>l>>t1>>t2>>v1>>v2;
		double ti1,ti2;
		ti1=l/v1+t1+t2;
		ti2=l/v2;
		if(ti1!=ti2){
			if(ti1>ti2){
				cout<<"Walk is OK!"<<endl;
			}
			else{
				cout<<"Bike is OK!"<<endl;
			}
		}
		else{
			cout<<"Both are OK!"<<endl;
		}
	}
	return 0;
}
