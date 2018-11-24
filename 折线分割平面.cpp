#include<bits/stdc++.h>
using namespace std;
long long a[10001]={0,2,7};
int main(){
	for(int i=2;i<10001;i++){
		a[i]=a[i-1]+4*(i-1)+1;
	}
	int c;
	cin>>c;
	for(int i=0;i<c;i++){
		int n;
		cin>>n;
		cout<<a[n]<<endl;
	}
	return 0;
} 
