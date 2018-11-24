#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	int t;
	while(b!=0){
		t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		long long a,b,c,d,s,x;
		cin>>a>>b>>c>>d;
		s=a*d+c*b;
		x=gcd(s,(b*d));
		cout<<s/x<<" "<<b*d/x<<endl;
	}
	return 0;
}
