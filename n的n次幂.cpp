#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		long long m;
		cin>>m;
		long long temp=m%4,s=1;
		if(temp==0){
			temp=4;
		}
		for(int j=0;j<temp;j++){
			s*=m;
			s%=10;
		}
		cout<<s<<endl;
	}
	return 0;
}
