#include<bits/stdc++.h>
using namespace std;
int a[50]={1,1};
int main(){
	for(int i=2;i<50;i++){
		a[i]=a[i-1]+a[i-2];
	}
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m;
		cout<<a[m-1]<<endl;
	}
	return 0;
}
