//==================================================
//date 2018.2.18
//name 10进制转k进制 
//auther Wang Hukai 
//==================================================
#include<bits/stdc++.h>
using namespace std;
int zh(int a,int k){
	char b[33];
	int i=32;
	b[32]='\0';
	if(a<0){
		cout<<"-";
		a*=-1;
	}
	if(a==0){
		cout<<"0"<<endl;
		return 0;
	}
	static char n[]="0123456789ABCDEF";
	while(a>0){
		i--;
		b[i]=n[a%k];
		a/=k;
	}
	for(int j=i;j<32;j++){
		cout<<b[j];
	}
	cout<<endl;
	return 0;
}
int main(){
	int n,k,a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>k;
		zh(a,k);
	}
	return 0;
}
