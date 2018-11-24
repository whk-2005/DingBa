#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
bool cmp(int x,int y){
	return x<y;
}
int main(){
	int a[5],t;
	cin>>t;
	while(t--){
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3,cmp); 
	if(a[0]+a[1]<a[2]){
		cout<<"Impossible!"<<endl;
	}
	else if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2]){
		cout<<"Right triangle"<<endl;
	}
	else if(a[0]*a[0]+a[1]*a[1]>a[2]*a[2]){
		cout<<"Acute triangle"<<endl;
	}
	else{
		cout<<"Obtuse triangle"<<endl;
	}
	}
	return 0;
}
