#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	int t;
	while(b!=0){
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int main(){
	long long m,n,a[30];
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		long long x;
		for(int j=0;j<n-1;j++){
			x=gcd(a[j],a[j+1]);
			a[j+1]=a[j]*a[j+1]/x;
		}
		cout<<a[n-1]<<endl;
	}	
	return 0;
}
