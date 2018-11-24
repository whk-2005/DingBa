#include<bits/stdc++.h>
using namespace std;
int a[30]={3,7};
int main(){
	for(int i=2;i<30;i++){
		a[i]=a[i-1]*2+a[i-2];
	}
	int c;
	cin>>c;
	for(int i=0;i<c;i++){
		int n;
		cin>>n;
		cout<<a[n-1]<<endl;
	}
	return 0;
}
