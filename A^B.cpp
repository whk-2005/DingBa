#include<bits/stdc++.h>
using namespace std;
int power(int a,int n){
	int ans;
	if(n==0) ans=1;
	else{
		ans=power(a*a%1000,n/2)%1000;
		if(n%2==1) ans=ans*a%1000;
	}
	return ans;
}
int main(){
	int m,n;
	while(cin>>m>>n&&(m!=0&&n!=0)){
		int s=power(m,n);
		cout<<s<<endl;
	}
	return 0;
}
