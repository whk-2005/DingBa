#include<bits/stdc++.h>
using namespace std;
long long a[60]={1,2};
int main(){
	for(int i=2;i<60;i++){
		a[i]=a[i-1]+a[i-2];
	}
	int n;
	while(cin>>n){
		cout<<a[n-1]<<endl;
	}
	return 0;
}
