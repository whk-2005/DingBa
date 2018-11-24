#include<bits/stdc++.h>
using namespace std;
long long a[50]={3,8};
int main(){
	for(int i=2;i<50;i++){
		a[i]=2*(a[i-1]+a[i-2]);
	}
	int n;
	while(cin>>n){
		cout<<a[n-1]<<endl;
	}
	return 0;
} 
