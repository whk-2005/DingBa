#include<bits/stdc++.h>
using namespace std;
long long x[60]={1,1};
int main(){
	for(int i=2;i<60;i++){
		x[i]=x[i-1]+x[i-2];
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		cout<<x[b-a]<<endl;
	}
	return 0;
}
