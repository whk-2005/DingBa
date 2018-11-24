#include<bits/stdc++.h>
using namespace std;
int a[10000001];
int b[10000001];
int main(){
	for(int i=2;i*i<1000001;i++){
		if(a[i]==0){
			for(int j=i*i;j<100001;j+=i){
				a[j]=1;
			}
		}
	}
	for(int i=2;i<100001;i++){
		if(a[i]==0){
			//cout<<a[i]<<" ";
			b[i]=b[i-1]+1;
		}
		else{
			b[i]=b[i-1];
		}
	}
	int c;
	cin>>c;
	for(int i=0;i<c;i++){
		int n;
		cin>>n;
		cout<<b[n]<<endl;
	}
	return 0;
}
