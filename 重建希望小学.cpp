#include<bits/stdc++.h>
using namespace std;
int a[40]={1,3};
int main(){
	for(int i=2;i<40;i++){
		a[i]=a[i-1]+a[i-2]*2;
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
